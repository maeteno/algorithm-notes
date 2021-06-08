#include "stdio.h"

/**
 *
 * @param nums
 * @param numsSize
 */
void moveZeroes(int *nums, int numsSize) {
    int i, j = 0;
    while (j < numsSize) {
        if (nums[j] == 0) {
            i = j;

            while (++j < numsSize){
                if(nums[j] != 0){
                    break;
                }
            }

            // 表示最后一个元素都是0
            if(j >= numsSize){
                return;
            }

            nums[i] = nums[j];
            nums[j] = 0;

            j = i + 1;
        } else {
            j++;
        }
    }
}

int main() {
    int test[] = {0, 1, 0, 3, 12};
    moveZeroes(test, 5);

    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d \t", test[i]);
    }
}