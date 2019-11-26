
CC := $(CROSS_COMPILE)riscv64-unknown-linux-gnu-gcc
CFLAGS := -lpthread -pthread -O3

OBJS := matrix_mult_riscv

all: $(OBJS)

matrix_mult_riscv: matrix_mult.c $(PARAMS)
	$(CC) -static $(CFLAGS) $^ -o $@


clean:
	rm -rf $(OBJS) output* $(PARAMS)

.PHONY: all clean $(PARAMS)