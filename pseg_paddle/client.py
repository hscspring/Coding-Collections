import grpc
from proto import pseg_pb2_grpc, pseg_pb2


host = "localhost:12345"


def run():
    with grpc.insecure_channel(host) as channel:
        stub = pseg_pb2_grpc.PartOfSpeechStub(channel)
        text = """
        烟草烟雾对青少年健康危害很大。青少年吸烟会对多个系统特别是呼吸系统和心血管系统产生严重危害。烟草中含有的尼古丁对脑神经有毒害，会造成记忆力减退、精神不振等。尼古丁具有极强的成瘾性，一旦吸烟成瘾，很难戒断。开始吸烟的年龄越早，成年后的吸烟量越大，烟草对其身体造成的危害就越大。
        """
        request = pseg_pb2.PosRequest(text=text)
        response = stub.Predict(request)
    for pair in response.pairs:
        print(pair.word, pair.flag)

if __name__ == '__main__':
    run()
