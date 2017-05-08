#!/usr/bin/env bash
declare -A fruits_value
fruits_value=([apple]='100dollars' [orange]='150 dollars')
echo "Apple costs ${fruits_value[apple]}"
#我们可以用下面的方法获取数组的索引列表：
#echo ${!array_var[*]}
#echo ${!array_var[@]
echo ${!fruits_value[*]}
