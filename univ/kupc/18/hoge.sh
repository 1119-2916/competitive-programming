#!/bin/bash
for ((i=1; i < 1000; i++)); do
    echo $i > input
    ./a.out < input >> output
done
