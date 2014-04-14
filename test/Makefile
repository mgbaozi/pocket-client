tests = config_test resource_test

all: $(tests)

config_test: config_test.cc ../pocket-client/model/config.cc
	$(CXX) config_test.cc ../pocket-client/model/config.cc -I../pocket-client/model/ $(CXXFLAGS) $(LDFLAGS) -o config_test

resource_test: resource_test.cc ../pocket-client/model/*.cc
	$(CXX) resource_test.cc ../pocket-client/model/*.cc -I ../pocket-client/model -I ../pocket-client/base $(CXXFLAGS) $(LDFLAGS) -o resource_test

.PHONY: examples
examples:
	cp -r ../examples/* ./

run: all examples
	./config_test
	./resource_test

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(tests)
	rm -f config.json
	rm -rf data
