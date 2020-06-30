# Swing Makefile

uname_s := $(shell sh -c 'uname -s 2>/dev/null || echo none')
uname_m := $(shell sh -c 'uname -m 2>/dev/null || echo none')

WARN ?= -Wall -Wextra
OPTIMIZATION ?= -O2
DEBUG ?= -g -ggdb
STD = -std=c11

CC = gcc
CFLAGS = $(STD) $(OPTIMIZATION) $(WARN) $(DEBUG)

RM = rm -f

SRC = $(wildcard src/*.c)
# SRC = src/swing.c src/swg_log.c
OBJ = $(SRC:.c=.o)

all: swing
.PHONY: all

swing: $(OBJ)
	$(CC) $(CFLAGS) -o swing $(OBJ)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./swing
.PHONY: run

noopt:
	@$(MAKE) OPTIMIZATION="-O0"
.PHONY: noopt

clean:
	$(RM) swing $(OBJ)
.PHONY: clean
