 #!/bin/bash
 #文件名: sleep.sh
 # tput 处理终端相关命令
 echo -n Count:
 tput sc
 count=0;
 while true;
 do
     if [ $count -lt 40 ];
     then
         let count++;
         sleep 1;
         tput rc
         tput ed
         echo -n $count;
     else exit 0;
     fi
 done
