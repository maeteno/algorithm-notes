//
// Created by 傅双亮 on 2021/5/29.
//
#include <stdio.h>

int count = 0;

int fib(int n) {
    count++;
    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int fib_dp(int n) {
    int result[n + 1];
    result[0] = 1;
    result[1] = 1;

    for (int i = 2; i <= n; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }

    return result[n];
}

int main() {
    int result = fib(40);
    int result_dp = fib_dp(40);

    printf("Result: %d \n count: %d \n", result, count);
    printf("Result DP: %d \n", result_dp);
}

