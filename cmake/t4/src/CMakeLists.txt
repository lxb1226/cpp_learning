LINK_DIRECTORIES(/tmp/t2/usr/lib)
ADD_EXECUTABLE(main main.c)

# LINK_DIRECTORIES
# 这个指令添加非标准的共享库搜索路径

# TARGET_LINK_LIBRARIES
# 这个指令用来为target添加需要链接的共享库

#TARGET_LINK_LIBRARIES(main libhello.so)
TARGET_LINK_LIBRARIES(main libhello.a)

# FIND_PATH用来在指定路径中搜索文件名
# FIND_PATH(myHeader NAMES hello.h PATHS /usr/include
#/usr/include/hello)