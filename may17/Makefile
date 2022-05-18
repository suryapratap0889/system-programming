BIN = bin/
OBJ = obj/
INC = include/
SRC = src/
CFLAG = -c
OFLAG = -o
all: build-server build-client

build-server: ${OBJ}func.o
		g++ ${OFLAG} ${BIN}server24 ${SRC}server.cpp ${OBJ}func.o
$(OBJ)func.o:
		g++ ${CFLAG} ${OFLAG} ${OBJ}func.o ${SRC}func.cpp

build-client:
		g++ ${OFLAG} ${BIN}client24 ${SRC}client.cpp

start-server:
		./${BIN}server24
start-client:
		./${BIN}client24
clean:
		rm ${OBJ}func.o
		rm ${BIN}client24
		rm ${BIN}server24
