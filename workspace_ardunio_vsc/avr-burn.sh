#!/bin/bash
file=$1
if [[ $file == "" ]] ;then
  file=build/atmega2560.hex
else
	echo "do not input anything"
fi
echo "to burn file "$file

avrdude -pm2560 -cstk500v2 -P/dev/ttyACM0 -b115200 -D -Uflash:w:$file
