#!/bin/bash/
# 在.bashrc中加入该函数后，可以方便的添加环境变量了（prepend PATH /home/xxx/bin）
prepend() { [ -d "$2" ] && eval $1=\"$2':'\$$1\" && export $1; }
