all: model main

.PHONY: model
model:
	$(MAKE) -C model

main: pocket-client.cc
	g++ pocket-client.cc -o ../build/debug/pocket-client

run: all
	../build/debug/pocket-client

.PHONY: clean
clean:
	$(CLEAN) -C model
	rm -f ../build/debug/pocket-client
