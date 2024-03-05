# NOTE: this Makefile has been written for OSCS and has nothing to do with
# the original one (Makefile.am).

TARGETS = 01_w_Defects.exe 02_wo_Defects.exe

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

.PHONY: clean

CPPFLAGS    += -Iinclude

LDFLAGS += -lm

01_w_Defects.exe: $(wildcard 01_w_Defects/*.c)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

02_wo_Defects.exe: $(wildcard 01_w_Defects/*.c)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)
