TARGET=all.out
OBJS=test.o src/mystring.o src/number.o src/bit.o
TOPDIR=${PWD}

CFLAGS=-I${TOPDIR}/include

all:$(TARGET)

$(TARGET):$(OBJS)               
	gcc $^ -o $@

%.o:src/%.c 

test.o:test.c                        

clean:
	rm -rf ${OBJS} ${TARGET}
