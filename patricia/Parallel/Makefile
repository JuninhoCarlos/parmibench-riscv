PROCESSORS ?= 3

CC := riscv64-unknown-linux-gnu-gcc
CFLAGS := -static -lpthread -pthread -O2

PARAMS := params.h
OBJS := patricia_parallel_riscv

SRCS := patricia_tool.c patricia_parallel.c patricia_test.c

all: $(OBJS)

patricia_parallel_riscv: $(SRCS) $(PARAMS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

$(PARAMS):
	./gen_defs.sh $(PARAMS) $(PROCESSORS)

clean:
	rm -rf $(OBJS) output* $(PARAMS)

.PHONY: all clean $(PARAMS)
