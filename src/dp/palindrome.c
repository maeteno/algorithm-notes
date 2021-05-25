/**
 * 这是一个动态规划的题目，
 * 动态规划的思想是如何复用子问题的解
 */
#include <stdio.h>
#include <libc.h>
#include <stdbool.h>

char *longestPalindrome(char *s) {
    unsigned long len = strlen(s);
    if (len < 2) {
        return s;
    }

    bool dp[len][len];
    int size = 1;
    int start = 0;

    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
    }

    for (int right = 1; right < len; right++) {
        for (int left = 0; left < right; left++) {
            if (s[left] == s[right]) {
                if (right - left < 3) {
                    dp[left][right] = true;
                } else {
                    dp[left][right] = dp[left + 1][right - 1];
                }
            } else {
                dp[left][right] = false;
            }

            bool b = dp[left][right];
            if (b && right - left >= size) {
                start = left;
                size = right - left;
            }
        }
    }

    s[start + size + 1] = '\0';
    return &s[start];
}

int main() {
    char s[] = "daewasdfdsakl";
    char *r = longestPalindrome(s);
    printf("%s", r);
}

