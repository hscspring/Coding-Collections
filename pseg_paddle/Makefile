# from https://www.sandtable.com/using-ssl-with-grpc-in-python/

stubs:
	python -m grpc.tools.protoc -I /usr/local/include -I . --python_out=./ --grpc_python_out=./ ./proto/pseg.proto

client:
	python client.py

server:
	python server.py
