export CC = gcc
export CXX = g++
export CLEAN = make clean
export RUN = make run
export CUR_DIR = $(shell pwd)
export DEBUG = TRUE
export INCLUDE_PATH = ${CUR_DIR}/include
export LD_PATH = ${CUR_DIR}/lib
export CXXFLAGS = -I${INCLUDE_PATH} -m64 -pipe -std=c++11 -g -D_REENTRANT -Wall -W -fPIE
export LDFLAGS = -L${LD_PATH} -llodepng -m64 -lpthread
ifeq ($(DEBUG), TRUE)
export BUILD_PATH = ${CUR_DIR}/build/debug
else
export BUILD_PATH = ${CUR_DIR}/build/release
CXXFLAGS += -DNDEBUG
endif

all: client

client: lib
	$(MAKE) -C pocket-client 

.PHONY: lib
lib:
	$(MAKE) -C lib

unittest: lib
	$(MAKE) -C test


test: unittest
	$(RUN) -C test

run: all
	$(RUN) -C pocket-client

.PHONY: clean
clean:
	$(CLEAN) -C pocket-client
	$(CLEAN) -C test
	$(CLEAN) -C lib
