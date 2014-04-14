all: model main

.PHONY: model
model:
	$(MAKE) -C model

main: PocketClient.cc
	$(CXX) PocketClient.cc $(CXXFLAGS) $(LDFLAGS) -o $(BUILD_PATH)/PocketClient

run: all
	$(BUILD_PATH)/PocketClient

.PHONY: clean
clean:
	$(CLEAN) -C model
	rm -f $(BUILD_PATH)/PocketClient
