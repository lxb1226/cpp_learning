# 这个指令用来定义工程名称，并可以指定工程支持的语言
PROJECT(HELLO)
# SET指令可以用来显式的定义变量
SET(SRC_LIST main.c)
# 这个指令用于向终端输出用户定义的信息
MESSAGE(STATUS "This is BINARY dir" ${HELLO_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir" ${HELLO_SOURCE_DIR})

# 这个指令定义了整个工程会生成一个文件名为hello的可执行文件
ADD_EXECUTABLE(hello ${SRC_LIST})

# 基本语法规则
# 1.变量使用${}方式取值，但是在IF控制语句是直接使用变量名
# 2.指令(参数1 参数2 ...)
# 3.指令是大小写无关的，参数和变量是大小写相关的。
