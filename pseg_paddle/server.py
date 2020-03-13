from concurrent import futures
from functools import wraps
from dataclasses import dataclass, asdict

import grpc
from grpc import StatusCode

import jieba
import jieba.posseg as pseg

from proto import pseg_pb2_grpc, pseg_pb2
from config import logger


jieba.enable_paddle()


@dataclass
class Pair:
    word: str
    flag: str


def predict_pos(text: str) -> list:
    pairs = []
    for pair in pseg.cut(text, use_paddle=True):
        pair = Pair(pair.word, pair.flag)
        item = asdict(pair)
        pairs.append(item)
    return pairs


def raise_grpc_error(capture, grpc_status_code):
    def _raise_grpc_error(func):
        @wraps(func)
        def wrapper(self, request, context):
            try:
                return func(self, request, context)
            except capture as e:
                context.set_code(grpc_status_code)
                context.set_details("Maybe RPC Error.")
        return wrapper
    return _raise_grpc_error


def deco_log_error(logger):
    def _deco_log_error(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            try:
                return func(*args, **kwargs)
            except Exception as e:
                if logger:
                    logger.exception(e)
                raise e
        return wrapper
    return _deco_log_error


class PosService(pseg_pb2_grpc.PartOfSpeechServicer):
    @raise_grpc_error(Exception, StatusCode.INTERNAL)
    def Predict(self, request, context):
        result = {"pairs": predict_pos(request.text)}
        return pseg_pb2.PosResponse(**result)


def serve(host, port):
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    pseg_pb2_grpc.add_PartOfSpeechServicer_to_server(PosService(), server)
    server.add_insecure_port('{}:{}'.format(host, port))
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    logger.info("Pseg serving at port %d..." % 12345)
    serve("0.0.0.0", 12345)
