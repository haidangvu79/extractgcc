#!/bin/bash

# compile and execute gcc programs to check error
if [ -e "error_compilation.txt" ] && [ -e "error_compilation.txt" ]; then
	 echo "File exists"
else
    echo "File does not exist"
	cp rungcc.py execute/
	cd execute
	chmod +x rungcc.py
	python3 rungcc.py
	find -type f ! -name "*.c" -exec rm -f {} \;
	cd ..
fi

# annotate, compile and execute
cd converted
rm *
cd ..
python3 gcc_convert.py 

# Run on MPPA
./compilerun.sh
cd converted
find -type f ! -name "*.c" -exec rm -f {} \;

## run gcc
#cp run.py converted/
#cd converted
#chmod +x run.py
#python3 run.py
#find -type f ! -name "*.c" -exec rm -f {} \;

echo "Done!!!"