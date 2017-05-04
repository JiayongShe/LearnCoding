#!/bin/bash

no1=4
no2=5
let result=no1+no2
echo $result
let no1++
let ++no2
result=$[ no1 + no2 ]
echo $result
result=$[ no1 + 5 ]
echo $result
result=`expr 3 + 4`
echo $result
result=$(expr $no1 + 4)
echo $result


# bc命令用于计算浮点数
echo "4 * 0.56" | bc
no=54;
result=`echo "$no * 1.5" | bc`
echo $result

echo "scale=2;3/8" | bc
no=100
echo "obase=2;$no" | bc
#1100100
no=1100100
echo "obase=10;ibase=2;$no" | bc
#100
# 计算平方以及平方根。
echo "sqrt(100)" | bc #Square root
echo "10^10" | bc #Square

