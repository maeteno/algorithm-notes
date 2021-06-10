#include "stdio.h"

int removeElement(int *nums, int numsSize, int val) {
    int size = 0;
    int i, j = 0;

    while (j < numsSize) {
        if (nums[j] == val) {
            i = j;
            while (++j < numsSize){
                if(nums[j] != val){
                    break;
                }
            }

            // 表示最后一个元素都是0
            if(j >= numsSize){
                return size;
            }

            size++;
            nums[i] = nums[j];
            nums[j] = val;

            j = i + 1;

        } else {
            size++;
            j++;
        }
    }

    return size;
}

int main() {
    int test[] = {0, 1, 0, 3, 12};
    int size = removeElement(test, 5, 1);

    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d \t", test[i]);
    }
}