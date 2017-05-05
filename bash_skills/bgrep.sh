#!/usr/bin/env bash
# 以上方式会通过$PATH来找bash所在的目录，可移植性更强
# 同样，存在潜在的安全问题（恶意程序植入[以bash之名]）
if [ $# -lt 1 ]; then
    echo "Usage: `basename $0` content_to_be_grep"
    exit 1
fi

find . -name "*.h" \
    -o -name "*.hpp" \
    -o -name "*.c" \
    -o -name "*.cc" \
    -o -name "*.cpp" \
    -o -name "*.proto" \
    -o -name "*.java" \
    -o -name "*.php" \
    -o -name "BUILD" \
    | xargs grep $@ --color=auto -n
