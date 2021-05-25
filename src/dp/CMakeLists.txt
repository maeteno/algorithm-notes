# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
AUX_SOURCE_DIRECTORY(. DIR_LIB_SRCS)

# 生成执行文件
ADD_EXECUTABLE(match-str match_str.c)

ADD_EXECUTABLE(match_str_2 match_str_2.c)

ADD_EXECUTABLE(palindrome palindrome.c)

# 生成执行文件
ADD_EXECUTABLE(coin-change coin_change.c)