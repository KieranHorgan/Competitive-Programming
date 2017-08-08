#!/bin/bash
g++ -std=c++14 nowruz.cpp -o nowruz
for i in {01..10}
do
	echo "$i started"
	./nowruz < tests/$i.in > sol/$i.out
	echo "$i done"
done
