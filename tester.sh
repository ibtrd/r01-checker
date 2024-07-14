#!/bin/bash

make

if [ $# -gt 0 ]
then
	SIZE=$1
else
	SIZE=4
fi

# // ARG=

while [ 1 ]
do
	ARG=$(python3 generator.py $SIZE | head -1)
	echo -n $ARG " "
	../rush-01 "$ARG" | ./checker "$ARG" 1>/dev/null
	if [ $? -eq 0 ]
	then
		echo -e "✅ \033[30;42;1m SUCESS \033[0m"
	else
		echo -e "❌ \033[30;41;1m FAILURE \033[0m"
		exit 1
	fi
done
