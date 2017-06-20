# !/bin/bash
# 文件名: remove_duplicates.sh
# 用途: 查找并删除重复文件，每一个文件只保留一份
ls -lS --time-style=long-iso | awk 'BEGIN {
    getline; getline;
    name1=$8; size1=$5;
}

{
    name2=$8; size2=$5
    if (size1==size2) {
        "md5sum "name1 | getline line;split(line,a); csum1=a[1];
        "md5sum "name2 | getline line;split(line,a); csum2=a[1];
        if ( csum1==csum2 ) {
            print name1; print name2
        }
    }
    size1=size2; name1=name2;
}' | sort -u  > duplicate_files
cat duplicate_files |\
xargs md5sum |\
sort | uniq -w 32 |\
awk '{
    print $2
}' | sort -u > duplicate_sample

#echo Removing..
comm duplicate_files duplicate_sample -2 -3 | tee /dev/stderr | xargs rm
echo Removed duplicates files successfully.


