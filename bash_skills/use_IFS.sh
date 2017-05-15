#!/bin/env bash
# IFS: internal field separator, 一般系统默认为 空格
data="name,sex,rollno,location"""

oldIFS=$IFS
IFS=, #now,
for item in $data
do
    echo Item: $item
done
IFS=$oldIFS
