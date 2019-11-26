
CC := $(CROSS_COMPILE)riscv64-unknown-linux-gnu-gcc
CFLAGS := -lpthread -pthread -O3

OBJS := bitcount_riscv

all: $(OBJS)

bitcount_riscv: bit_count.c $(PARAMS)
	$(CC) -static $(CFLAGS) $^ -o $@


clean:
	rm -rf $(OBJS) output* $(PARAMS)

.PHONY: all clean $(PARAMS)