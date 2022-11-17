#!/bin/bash

files=(`find ./*/ -type f -name '*.h'`)

echo "#ifndef EXAMPLES_H" > ./examples.h
echo "#define EXAMPLES_H" >> ./examples.h
echo " " >> ./examples.h

for item in ${files[*]}
do
	echo "#include \""$item"\"" >> ./examples.h 
done

echo " " >> ./examples.h
echo "#endif /* EXAMPLES_H */" >> ./examples.h
