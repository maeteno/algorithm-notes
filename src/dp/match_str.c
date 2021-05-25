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

bool isMatch(char *s, char *p);

bool matches(const char *s, const char *p, int sIndex, int pIndex);

void test(char *s, char *p);

int main() {
    //test("aaab", "aa*b");
    test("aaab", "aa*b");
    //test("aaab", "a*b");
}

bool isMatch(char *s, char *p) {
    unsigned long sLen = strlen(s);
    unsigned long pLen = strlen(p);

    bool dp[sLen][pLen];

    for (int sIndex = 0; sIndex < sLen; sIndex++) {
        for (int pIndex = 0; pIndex < pLen; pIndex++) {
            if (p[pIndex] == '*') {
                if (matches(s, p, sIndex, pIndex - 1)) {
                    dp[sIndex][pIndex] = dp[sIndex][pIndex - 1];
                }
            } else {
                if ((matches(s, p, sIndex, pIndex))) {
                    dp[sIndex][pIndex] = dp[sIndex - 1][pIndex - 1];

                    if (sIndex == 0 || pIndex == 0) {
                        dp[sIndex][pIndex] = true;
                    }

                }
            }
        }

        for (int pIndex = 0; pIndex < pLen; pIndex++) {
            printf("%s \t", dp[sIndex][pIndex] ? "true" : "false");
        }

        printf("\n%d,%c,%s\n\n ", sIndex, s[sIndex], p);
    }

    // aab -> a : 110
    // aab -> * => aab -> a : 110
    // aab -> b : 111


//    for (int sIndex = 0; sIndex <= sLen; sIndex++) {
//        for (int pIndex = 0; pIndex <= pLen; pIndex++) {
//            printf("%s \t", dp[sIndex][pIndex] ? "true" : "false");
//        }
//        printf("\n");
//    }

    return dp[sLen - 1][pLen - 1];
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