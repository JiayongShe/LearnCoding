cat args.txt | xargs -n 1 ./cecho.sh
cat args.txt | xargs -n 2 ./cecho.sh
cat args.txt | xargs ./cecho.sh
cat args.txt | xargs -I {} ./cecho.sh -p {} -l

# 统计某文件夹C程序文件行数
# find source_code_dir_path -type f -name "*.c" -print0 | xargs -0 wc -l
