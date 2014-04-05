export CLEAN = make clean
export RUN = make run
export CUR_DIR = $(shell pwd)
export INCLUDE_PATH = ${CUR_DIR}/include
export LD_PATH = ${CUR_DIR}/lib
export CXXFLAGS = -I${INCLUDE_PATH} -std=c++11
export LDFLAGS = -L${LD_PATH}

all: client

client: lib
	$(MAKE) -C pocket-client 

.PHONY: lib
lib:
	$(MAKE) -C lib

.PHONY: unittest
unittest:
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
