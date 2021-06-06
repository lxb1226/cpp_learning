PROJECT(NEWHELLO)
cmake_minimum_required(VERSION 3.10)

# INCLUDE_DIRECTORIES
# 这条指令用来向工程添加多个特定的头文件搜索路径，路径之间用空格分隔，如果路径中包含了空格，可以使用双引号括起来。
# 默认的行为是追加到当前的头文件搜索路径的后面，你可以通过两种方式来进行控制搜索路径添加的方式
INCLUDE_DIRECTORIES(/tmp/t2/usr/include/hello)
ADD_SUBDIRECTORY(src)