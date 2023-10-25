#!/bin/bash
#First you can use grep (-n) to find the number of lines of string.
#Then you can use awk to separate the answer.
aa="$1" #aa is the read-in file
str="$2"
bb="$3" #bb is the write-out file
touch cc
grep -n $str $aa > cc
awk -F ':|:' '{print $1}' cc > $bb
rm cc
