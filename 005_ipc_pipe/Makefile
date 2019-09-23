.PHONY:clean

TARGET=pipe
LIB=pipe.o
SRC=pipe.c

$(TARGET):$(LIB)
	gcc -o $(TARGET) $(LIB)
$(LIB):$(SRC)
	gcc -o $(LIB) -c $(SRC)

clean:
	rm -f $(TARGET) $(LIB)

