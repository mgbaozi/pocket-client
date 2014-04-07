all: model main

.PHONY: model
model:
	$(MAKE) -C model

main: pocket-client.cc
	$(CXX) pocket-client.cc $(CXXFLAGS) $(LDFLAGS) -o $(BUILD_PATH)/pocket-client

run: all
	$(BUILD_PATH)/pocket-client

.PHONY: clean
clean:
	$(CLEAN) -C model
	rm -f $(BUILD_PATH)/pocket-client
