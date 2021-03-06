TARGET=all.out
OBJS=test.o src/mystring.o src/number.o src/bit.o

all:$(TARGET)

$(TARGET):$(OBJS)               
	gcc $^ -o $@

%.o:src/%.c 

test.o:test.c                        

clean:
	rm -rf ${OBJS} ${TARGET}
