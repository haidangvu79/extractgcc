# This Makefile is specific for OSCS and unrelated to the original Makefile.

TARGETS := test-reader test-version run-dumper run-emitter \
           run-parser-test-suite run-scanner

all: $(TARGETS)

CPPFLAGS += \
  -Iinclude \
  -DHAVE_CONFIG_H \
  -DYAML_DECLARE_STATIC \

COMMON_SRCS=\
  src/api.c \
  src/dumper.c \
  src/emitter.c \
  src/loader.c \
  src/parser.c \
  src/reader.c \
  src/scanner.c \
  src/writer.c \

run-dumper: $(COMMON_SRCS) tests/run-dumper.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run-emitter: $(COMMON_SRCS) tests/run-emitter.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run-emitter-test-suite: $(COMMON_SRCS) tests/run-emitter-test-suite.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run-parser: $(COMMON_SRCS) tests/run-parser.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run-parser-test-suite: $(COMMON_SRCS) tests/run-parser-test-suite.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run-scanner: $(COMMON_SRCS) tests/run-scanner.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test-reader: $(COMMON_SRCS) tests/test-reader.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test-version: $(COMMON_SRCS) tests/test-version.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGETS)

.PHONY: clean
