export CLEAN = make clean
export RUN = make run
all: client

.PHONY: client 
client:
	$(MAKE) -C pocket-client 

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
