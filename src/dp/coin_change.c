/**
 * https://leetcode-cn.com/problems/coin-change/
 * 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 你可以认为每种硬币的数量是无限的。
 */
#include "stdio.h"

/**
 * 获取最小组合数量
 *
 * @param coins 硬币列表
 * @param coinsSize 硬币大小
 * @param amount 总金额
 * @return
 */
int coinChange(const int *coins, int coinsSize, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    // Onm
    for (int i = 1; i <= amount; i++) {
        dp[i] = amount + 1; // 设置一个大值，表示该金额无法组合
        for (int j = 0; j < coinsSize; j++) {
            int coinValue = coins[j];
            if (coinValue <= i) {
                dp[i] = (dp[i - coinValue] + 1) < dp[i] ? (dp[i - coinValue] + 1) : dp[i];
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int coins[] = {2, 3, 7};
    int size = coinChange(coins, 3, 19);
    printf("size: %d", size);
}