
build:
	gcc server.c -o server -pthread -lsctp
	gcc client.c -o client -lsctp
	gcc client_2.c -o client_2 -lsctp

run: build
	@echo "build over"