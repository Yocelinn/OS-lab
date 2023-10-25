#!/bin/bash
mkdir mydir
chmod 777 mydir
echo 2023 > myfile
mv moveme mydir/
cp copyme mydir/
cd ./mydir
mv copyme copied
cd ..
cat readme
gcc bad.c 2> err.txt
mkdir gen

if [ $# -eq 0 ] 
then
	a=10
else
	a=$1
fi

while [ $a -gt 0 ]
do
	touch ./gen/$a.txt
	a=$[$a-1]
done			

