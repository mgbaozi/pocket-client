ifeq ($(shell uname), Darwin)
RUN_CMD = open $(BUILD_PATH)/pocket-client.app
else
RUN_CMD = $(BUILD_PATH)/pocket-client
endif

all: model main

.PHONY: model
model:
	$(MAKE) -C model

QtMakefile: pocket-client.pro
	qmake -o QtMakefile

main: QtMakefile
	$(MAKE) -f QtMakefile

.PHONY: run
run:
	$(RUN_CMD)

.PHONY: clean
clean:
	$(MAKE) -f QtMakefile clean
	$(CLEAN) -C model
	rm -f $(BUILD_PATH)/PocketClient
