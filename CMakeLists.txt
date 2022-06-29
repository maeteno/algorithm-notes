# 设置Cmake最低版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5.0)

# 设置项目名称
PROJECT(algorithm-notes)

# 打印信息
MESSAGE("config types: ${CMAKE_CONFIGURATION}")

# 设置cpp支持的版本
SET(CMAKE_CXX_STANDARD 11)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
AUX_SOURCE_DIRECTORY(./src DIR_SRCS)

ENABLE_TESTING()

# Tools Lib
ADD_SUBDIRECTORY(src/tools)

# 排序
ADD_SUBDIRECTORY(src/sort/lib) # 添加子目录
ADD_EXECUTABLE(sort.bin src/sort/main.cpp) # 指定生成目标
TARGET_LINK_LIBRARIES(sort.bin sort_lib tools_lib) # 添加链接库

# Tree
ADD_SUBDIRECTORY(src/tree/lib)

# max_heap
ADD_EXECUTABLE(mh.bin src/tree/max_heap.cpp)
TARGET_LINK_LIBRARIES(mh.bin tree_lib tools_lib)
ADD_TEST(NAME mh COMMAND mh.bin)

# BST
ADD_EXECUTABLE(bst.bin src/tree/bst.cpp)
TARGET_LINK_LIBRARIES(bst.bin tree_lib tools_lib)
ADD_TEST(NAME bst COMMAND bst.bin)

# AVL
ADD_EXECUTABLE(avl.bin src/tree/avl.cpp)
TARGET_LINK_LIBRARIES(avl.bin tree_lib tools_lib)
ADD_TEST(NAME avl COMMAND avl.bin)

ADD_EXECUTABLE(avl_demo.bin src/tree/avl_demo.cpp)

# dp
ADD_SUBDIRECTORY(src/dp) # 添加子目录

# leetcode
ADD_SUBDIRECTORY(src/leetcode) # 添加子目录