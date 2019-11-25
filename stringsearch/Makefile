PROCESSORS ?= 4

CC := $(CROSS_COMPILE)gcc
CROSS := riscv64-unknown-linux-gnu-gcc
CFLAGS := -lpthread -pthread -O2

PARAMS := params.h
OBJS := parallel_stringsearch parallel_stringsearch_riscv

SRCS := bmhasrch.c  bmhisrch.c  bmhsrch.c  parallel_stringsearch.c

all: $(OBJS)

parallel_stringsearch: $(SRCS) $(PARAMS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

parallel_stringsearch_riscv: $(SRCS) $(PARAMS)
	$(CROSS) $(CFLAGS) -static $(SRCS) -o $@


$(PARAMS):
	./gen_defs.sh $(PARAMS) $(PROCESSORS)

clean:
	rm -rf $(OBJS) output* $(PARAMS)

.PHONY: all clean $(PARAMS)
