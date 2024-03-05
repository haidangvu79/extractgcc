# TOOLS = tools.minimal

HOST_CC   ?= $(CC)  # for compiling Charon to run on host machine (to compile tests)
TARGET_CC ?= $(CC)  # for compiling Charon to run on target machine (to run tests)

all:
	$(MAKE) -C charon-run
	rm -rf tests.bin/*  tests.int/* tests.log/* 
	CHARON_CC=$(HOST_CC) $(MAKE) -C charon-run
	./charon-run/charon_run \
	  --compile_and_run\
	  --tools $(TOOLS) \
	  --tests tests.charon \
	  --test_src_dir tests/de_facto_memory_model/ \
	  --test_bin_dir tests.bin/ \
	  --test_log_dir tests.log/ \
	  --log all.log 

clean:
	$(MAKE) -C charon-run clean
	rm -rf tmp/*
	rm -rf *~
	rm -rf tests.bin/*  tests.int/* tests.log/* 
	rm -rf all.log
