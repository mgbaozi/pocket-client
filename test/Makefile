tests = config_test config_change_test

all: $(tests)

config_test: config_test.cc ../pocket-client/model/config.cc
	g++ config_test.cc ../pocket-client/model/config.cc -I../pocket-client/model/ $(CXXFLAGS) -o config_test

config_change_test: config_change_test.cc ../pocket-client/model/config.cc
	g++ config_change_test.cc ../pocket-client/model/config.cc -I../pocket-client/model/ $(CXXFLAGS) -o config_change_test
	
.PHONY: examples
examples:
	cp ../examples/* ./

run: all examples
	./config_test
	./config_change_test

.PHONY: clean
clean:
	rm  -f *.o
	rm  -f $(tests)
	rm  -f config.json
