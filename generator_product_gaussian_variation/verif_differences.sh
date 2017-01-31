#!/bin/bash

list=$(ls ./product_res/*.txt)
for i in $list
do
    for j in $list
    do
	diff $i $j > difference.txt 
	if [ -s difference.txt ]; then 
	    echo " $i and $j are different " >> compare_res.txt
	else
	    echo " $i and $j are the same " >> compare_res.txt
	fi
    done
done

rm difference.txt