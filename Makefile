
# Makefile to run tests from

# Detect OS
UNAME_S = $(shell uname -s)

# Apple
ifeq ($(UNAME_S),Darwin)
	cc = clang++
# Others
else
	cc = g++
endif

ld_flags = -std=c++17 -Wall -Iinclude
cc_output = $^ -o $@
cc_link = ${cc} ${ld_flags}


.PHONY = clean test

all : test_main

test_main : tests/test_main.cc | tests/doctest.h include/sprintf_bytes.h include/printf_bytes.h
	${cc_link} ${cc_output}

test : test_main
	@./$<

clean :
	${RM} test_main