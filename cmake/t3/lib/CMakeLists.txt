SET(LIBHELLO_SRC hello.c)

# ADD_LIBRARY用来编译共享库
# 类型有三种
# SHARED:动态库
# STATIC：静态库
# MODULE：在使用dyld的系统有效，如果不支持dyld，则被当做SHARED对待

# 添加动态库
ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})
# 添加静态库
ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC})

# SET_TARGET_PROPERTIES可以用来设置输出的名称，对于动态库，还可以用来指定动态库版本和API版本
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")
GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
# 防止被清除
SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
# 实现动态库版本号
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

# 注意，静态库要使用ARCHIVE关键字
INSTALL(TARGETS hello hello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
INSTALL(FILES hello.h DESTINATION include/hello)
MESSAGE(STATUS "This is the hello_static OUTPUT_NAME:" ${OUTPUT_NAME})