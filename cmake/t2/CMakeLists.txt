PROJECT(HELLO)
# 如何安装
# INSTALL指令用于定义安装规则，安装的内容可以包括目标二进制、动态库、静态库以及文件、目录、脚本等
# 目标文件的安装：
# INSTALL(TARGETS targets...
#       [[ARCHIVE|LIBRARY|RUNTIME]
#           [DESTINATION <dir>]
#           [PERMISSIONS permissions...]
#           [CONFIGURATIONS
#       [Debug|Release|...]]
#           [COMPONENT <component>]
#           [OPTIONAL]
#           ] [...])
# 参数中的TARGETS后面跟的就是我们通过ADD_EXECUTABLE或者ADD_LIBRARY定义的目标文件，可能是可执行二进制、动态库、静态库
# 目标类型有三种：ARCHIVE特指静态库，LIBRARY特指动态库，RUNTIME特指可执行目标二进制
# DESTINATION定义了安装的路径，如果路径以/开头，那么指的是绝对路径

# 例子
# INSTALL(TARGETS myrun mylib mystaticlib
#           RUNTIME DESTINATION bin
#           LIBRARY DESTINATION lib
#           ARCHIVE DESTINATION libstatic
#)
# 这个例子会把
# 可执行二进制myrun安装到${CMAKE_INSTALL_PREFIX}/bin目录
# 动态库libmylib安装到${CMAKE_INSTALL_PREFIX}/lib目录
# 静态库libmystaticlib安装到${CMAKE_INSTALL_PREFIX}/libstatic目录


## 普通文件的安装
# INSTALL(FILES files... DESTINATION <dir>
#           [PERMISSIONS permissions...]
#           [CONFIGURATIONS [Debug|Release|...]]
#           [COMPONENT <component>]
#           [RENAME <name>] [OPTIONAL])
# 可用于安装一般文件，并可以指定访问权限，文件名是此指令所在路径下的相对路径。

# 非目标文件的可执行程序安装(比如脚本之类)：
# INSTALL(PROGRAMS files... DESTINATION <dir>
#           [PERMISSIONS permissions...]
#           [CONFIGURATIONS [Debug|Release|...]]
#           [COMPONENT <component>]
#           [RENAME <name>] [OPTIONAL])

## 目录的安装
# INSTALL(DIRECTORY dirs... DESTINATION <dir>
#       [FILE_PERMISSIONS permissions...]
#       [DIRECTORY_PERMISSIONS permissions...]
#       [USE_SOURCE_PERMISSIONS]
#       [CONFIGURATIONS [Debug|Release|...]]
#       [COMPONENT <component>]
#       [[PATTERN <pattern> | REGEX <regex>]
#       [EXCLUDE] [PERMISSIONS permissions...]] [...])

# DIRECTORY 后面连接的是所在Source目录的相对路径。但是目录名以/结尾和不以/结尾有着很大的区别。
# PATTERN用于使用正则表达式进行过滤
# PERMISSIONS 用于指定PATTERN过滤后的文件权限
INSTALL(FILES COPYRIGHT README DESTINATION share/doc/cmake/t2)
INSTALL(PROGRAMS runhello.sh DESTINATION bin)
INSTALL(DIRECTORY doc/ DESTINATION share/doc/cmake/t2)

# 安装时运行命令
# cmake -DCMAKE_INSTALL_PREFIX=....

# 这个命令用于向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置
# 这个例子定义了将src子目录加入工程，并指定编译输出（包含编译中间结果）路径为bin目录
# 如果不进行bin目录的指定，那么编译结果（包括中间结果）都将存放在build/src目录（这个目录跟原有的src目录对应），指定bin目录后
# 相当于在编译时将src重命名为bin，所有的中间结果和目标二进制都将存放在bin目录
ADD_SUBDIRECTORY(src bin)