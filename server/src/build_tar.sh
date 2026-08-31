#!/bin/bash

# 检查是否提供了至少一个参数
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <directory1> [directory2] [...]"
    exit 1
fi

# 遍历所有传入的目录
for dir in "$@"; do
    # 进入指定目录
    cd "$dir" || { echo "无法进入目录: $dir"; continue; }

    # 清理旧文件
    rm -f *.tgz
    # 执行构建操作
    #make clean && 
    make -j2 && make release && make tar
    if [ $? -ne 0 ]; then
        echo "构建失败: $dir"
        continue
    fi

    # 复制生成的文件到../build/
    cp *.tgz ../build/

    # 返回上一级目录
    cd -
done

echo "所有目录构建完成"