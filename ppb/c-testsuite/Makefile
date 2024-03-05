SOURCES := $(sort $(wildcard *.c))

TARGETS := $(basename $(SOURCES))

all: $(TARGETS)

%: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGETS)

.PHONY: clean
