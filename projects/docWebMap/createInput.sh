#!/bin/bash
touch "$1"
xclip -o > "$1"
ARG2=${2:-nv}
if [ $ARG2 = 'ins' ]
then
	vim "$1"
elif [ $ARG2 = 'view' ]
then
	less -FX "$1"
elif [ $ARG2 = 'nv' ]
then
	echo Input file created.
else
	echo Unknown second arguement.	
fi
