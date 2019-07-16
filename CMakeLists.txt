# 设置Cmake最低版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5.0)
# 设置项目名称
PROJECT(c-plus-study)
# 打印信息
MESSAGE("config types: ${CMAKE_CONFIGRATION}")

# 设置cpp支持的版本
SET(CMAKE_CXX_STANDARD 11)

# 其他设置
SET(OUTPUT_ROOT ./output)
SET(SET_TARGET_PROPERTIES ./target)
SET(CMAKE_INSTALL_PREFIX /usr/local)

# 添加编译的子目录，子目录需要有CMakeLists.txt文件
ADD_SUBDIRECTORY(src/sort)