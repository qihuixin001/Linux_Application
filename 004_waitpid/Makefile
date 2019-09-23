.PHONY:clean

TARGET=waitpid
LIB=waitpid.o
SRC=waitpid.c

$(TARGET):$(LIB)
	gcc -o $(TARGET) $(LIB)
$(LIB):$(SRC)
	gcc -o $(LIB) -c $(SRC)

clean:
	rm -f $(TARGET) $(LIB)

