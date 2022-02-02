#!/bin/bash
file=$1
if [[ $file == "" ]] ;then
  file=/dev/ttyACM0
else
	echo "do not input anything"
fi
echo "to cu with "$file
echo "input ~. to exit...."

cu -l /dev/ttyACM0 -s 115200

