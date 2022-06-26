# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
AUX_SOURCE_DIRECTORY(. DIR_LIB_SRCS)

# 生成执行文件
ADD_EXECUTABLE(match-str.bin match_str.c)

ADD_EXECUTABLE(match_str_2.bin match_str_2.c)

ADD_EXECUTABLE(palindrome.bin palindrome.c)

ADD_EXECUTABLE(coin_change.bin coin_change.c)

ADD_EXECUTABLE(fib.bin fib.c)
