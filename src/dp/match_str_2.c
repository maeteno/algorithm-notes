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
    test("aaab", "aa*b");
}

bool isMatch(char *s, char *p) {
    unsigned long sLen = strlen(s);
    unsigned long pLen = strlen(p);

    int sIndex = 0;
    int pIndex = 0;
    bool result = false;
    while (sIndex < sLen && pIndex < pLen) {
        char pChar = p[pIndex];
        char sChar = s[sIndex];

        if (pChar == '*') {
            result = matches(s, p, sIndex, pIndex - 1);
            if (result) {
                sIndex++;
            } else {
                pIndex++;
            }
        } else {
            result = matches(s, p, sIndex, pIndex);
            if (result) {
                sIndex++;
                pIndex++;
            } else {
                break;
            }
        }
    }

    return result && sIndex == sLen && pIndex == pLen;
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