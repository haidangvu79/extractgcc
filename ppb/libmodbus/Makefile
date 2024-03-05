# This Makefile is specific for OSCS and unrelated to the original Makefile.

TARGETS = tests/unit-test-server tests/random-test-client

all: $(TARGETS)

# Some directories complement this Makefile with their own
-include Makefile.own

tests/unit-test-server: $(sort $(wildcard src/*.c)) tests/unit-test-server.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

tests/unit-test-server: CPPFLAGS += -DIPTOS_LOWDELAY=0x20 -I. -Isrc

tests/random-test-client: $(sort $(wildcard src/*.c)) tests/random-test-client.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

tests/random-test-client: CPPFLAGS += -DIPTOS_LOWDELAY=0x20 -I. -Isrc

clean:
	rm -f $(TARGETS)

.PHONY: clean
