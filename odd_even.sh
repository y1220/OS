#!/bin/bash

# Control if the number of parameters is correct (i.e., at least one parameter is needed) 
if [ $# -lt 1 ]
then
   echo "Usage: ./prog.sh <FILE>"
   exit 1
fi

# read a file link by line
while read line; do
	# compute number of words in a line
	n=$(echo $line | wc -w)
	# odd -> lowercase
	if [ $[$n%2] -eq 1 ]; then
		echo $line | tr [A-Z] [a-z]
    fi
    # even -> uppercase
    if [ $[$n%2] -eq 0 ]; then
    	echo $line | tr [a-z] [A-Z]
    fi
# override a file
done < $1 

exit 0
