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
#include "strlen.h"
#include "stdbool.h"

bool isMatch(char *s, char *p);

bool matches(const char *s, const char *p, int sIndex, int pIndex);

void test(char *s, char *p);

int main() {
    //test("aaab", "aa*c*b");
    test("a", "aa*c*b");
}

bool isMatch(char *s, char *p) {
    unsigned long sLen = strlen(s);
    unsigned long pLen = strlen(p);

    bool dp[sLen + 1][pLen + 1];

    for (int sIndex = 0; sIndex < sLen; sIndex++) {
        for (int pIndex = 1; pIndex < pLen; pIndex++) {
            if (p[pIndex] == '*') {
                dp[sIndex][pIndex] = dp[sIndex][pIndex - 2];

                if (matches(s, p, sIndex, pIndex - 1)) {
                    dp[sIndex][pIndex] = dp[sIndex][pIndex - 1];
                }
            } else {
                if ((matches(s, p, sIndex, pIndex))) {
                    dp[sIndex][pIndex - 1] = dp[sIndex - 1][pIndex - 2];
                } else {
                    dp[sIndex][pIndex] = false;
                }
            }
        }

        printf("%d\n%c\n%s\n", sIndex, s[sIndex], p);
        for (int pIndex = 0; pIndex < pLen; pIndex++) {
            printf("%s \t", dp[sIndex][pIndex] ? "true" : "false");
        }
        printf("\n");
    }

    printf("\n");
    for (int sIndex = 0; sIndex <= sLen; sIndex++) {
        for (int pIndex = 0; pIndex <= pLen; pIndex++) {
            printf("%s \t", dp[sIndex][pIndex] ? "true" : "false");
        }
        printf("\n");
    }

    return dp[sLen][pLen];
}

bool matches(const char *s, const char *p, int sIndex, int pIndex) {
    if (p[pIndex] == '.') {
        return true;
    }

    return s[sIndex] == p[pIndex];
}

void test(char *s, char *p) {
    bool r = isMatch(s, p);
    printf("%s <=> %s: %s\n", s, p, r ? "true" : "false");
    printf("\n");
}