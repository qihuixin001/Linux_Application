.PHONY:clean

TARGET=wait
LIB=wait.o
SRC=wait.c

$(TARGET):$(LIB)
	gcc -o $(TARGET) $(LIB)
$(LIB):$(SRC)
	gcc -o $(LIB) -c $(SRC)

clean:
	rm -f $(TARGET) $(LIB)

