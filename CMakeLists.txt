# 设置Cmake最低版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5.0)

# 设置项目名称
PROJECT(algrithm-notes)

# 打印信息
MESSAGE("config types: ${CMAKE_CONFIGRATION}")

# 设置cpp支持的版本
SET(CMAKE_CXX_STANDARD 11)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
AUX_SOURCE_DIRECTORY(./src DIR_SRCS)

# Tools Lib
ADD_SUBDIRECTORY(src/tools)

# 排序
ADD_SUBDIRECTORY(src/sort/lib) # 添加子目录
ADD_EXECUTABLE(sort src/sort/main.cpp) # 指定生成目标
TARGET_LINK_LIBRARIES(sort sort_lib tools_lib) # 添加链接库

# Tree
ADD_SUBDIRECTORY(src/tree/lib)
ADD_EXECUTABLE(tree src/tree/main.cpp)
TARGET_LINK_LIBRARIES(tree tree_lib tools_lib)
