TARGETS=cwe20 cwe20-2 cwe119 cwe190 cwe416 cwe588 cwe761 cwe787

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

CFLAGS ?= -Wall

%: %.c
	$(CC) $(CFLAGS) -o $@ $^
