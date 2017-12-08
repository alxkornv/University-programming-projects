#!/bin/bash

NUM_SIGNALS=0

handler(){
NUM_SIGNALS=`expr $NUM_SIGNALS + 1`
if [ $NUM_SIGNALS -eq 3 ]
then
	echo -e "Количество файлов в очерди на печать \n"
	wc -l /media/alex/LINUXFILES/filenames.txt | cut -d" " -f1
fi
}

trap "handler" SIGINT


cd /media/alex/LINUXFILES/my_spool 

if [ -z `ls -A .` ]
then
	echo "Spooling folder is empty"
   	exit 1
fi

ls -d -1 $PWD/* > /media/alex/LINUXFILES/filenames.txt
echo -e "Файлы в очереди на печать: \n"
cat /media/alex/LINUXFILES/filenames.txt
echo -e "\n"
(
cd /media/alex/LINUXFILES
for line in `cat filenames.txt`
do
	cat $line
done
)

sleep 5
sleep 5
sleep 5
sleep 1


