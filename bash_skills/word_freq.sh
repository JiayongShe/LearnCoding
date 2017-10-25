#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

file_name=$1

egrep -o "\b[[:alpha:]]+\b" $file_name |\
    awk '{ count[$0]++ }
END{
    printf("%-14s\t%s\n", "Word", "Count");
    for (word in count) {
        printf("%-14s\t%d\n", word, count[word]);
    }
}'

