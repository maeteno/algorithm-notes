/**
 * https://leetcode-cn.com/problems/regular-expression-matching/
 *
 * 给你一个字符串s和一个字符规律 p，请你来实现一个支持 '.'和'*'的正则表达式匹配。
 *
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖整个字符串s的，而不是部分字符串。
 */
#include "stdio.h"
#include <string.h>
#include "stdbool.h"

bool matches(char *s, char *p, int sIndex, int pIndex);

bool isMatch(char *s, char *p) {
    unsigned long sLen = strlen(s);
    unsigned long pLen = strlen(p);

    bool dp[sLen + 1][pLen + 1];
    dp[0][0] = true;

    for (int sIndex = 0; sIndex < sLen; sIndex++) {
        for (int pIndex = 1; pIndex < pLen; pIndex++) {
            if (p[pIndex - 1] == '*') {
                dp[sIndex][pIndex] = dp[sIndex][pIndex - 2];
                if (matches(s, p, sIndex, pIndex - 1)) {
                    dp[sIndex][pIndex] = dp[sIndex][pIndex] || dp[sIndex - 1][pIndex];
                }
            } else {
                if (matches(s, p, sIndex, pIndex)) {
                    dp[sIndex][pIndex] = dp[sIndex - 1][pIndex - 1];
                }
            }
        }
    }

    return dp[sLen][pLen];
}

bool matches(char *s, char *p, int sIndex, int pIndex) {
    if (sIndex == 0) {
        return false;
    }
    if (p[pIndex - 1] == '.') {
        return true;
    }
    return s[sIndex - 1] == p[pIndex - 1];
}

int main() {
    bool r = isMatch("aab", "aab");
    printf("isMatch(\"aab\", \"aab\"): %d\n", r);
}