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

# 添加子目录
ADD_SUBDIRECTORY(src/sort)

# 指定生成目标
ADD_EXECUTABLE(Main src/main.cpp)

# 添加链接库
TARGET_LINK_LIBRARIES(Main Bubble)
