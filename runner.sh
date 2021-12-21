#!/bin/bash
running=1;
filename=$1;
while(($running))
do
echo "select variant of mergesort";
echo "1 > serial merge sort";
echo "2 > parallel merge sort";
echo "3 > select file";
echo "4 > generate input file";
echo "5 > close";
read -p '>>>' option
echo $option
if(($option == '1'))
then
echo "serial merge sort selected"
g++ Merge_Sort.cpp  -o merge -fopenmp
./merge $filename;
	
elif(($option=='2'))
then
echo "2 selected"
g++ mergeSort_parallel.cpp -o mergep -fopenmp
./mergep $filename;
elif(($option == '3'))
then
ls
echo " ";
read -p 'enter filename : ' fname;
filename=$fname;
echo $filename;
elif(($option =='4'))
then
g++ gentest.cpp -o genfile;
./genfile
echo "file creted ..load file";
elif(($option=='5'))
then
echo "closing program ";
echo "exit status 0";
((running=0));
else
echo "invallid input";
fi
done