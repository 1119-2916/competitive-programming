#!/bin/bash

size=$(stat -c %s ./diff)

for i in {2..30}; do
    for j in {1..30}; do
        echo $i $j
        echo $i $j > input
        ./valid.out < input > answer
        ./target.out < input > output
        `diff answer output > diff`
        size=$(stat -c %s ./diff)
        if [ $size != 0 ]; then
            exit 0
        fi
    done
done


