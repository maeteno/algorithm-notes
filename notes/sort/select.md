# 选择排序

选择排序有两层循环，

## 排序过程

1. 每次排序时找到最小（大）的元素和头部元素交换位置

# 动图演示

![](../_images/select.gif)

# 示例代码
```cpp
// 选择排序
void sort::select(int data[], int len) {
    int tmp, index;
    for (int i = 0; i < len - 1; i++) {
        tmp = data[i];
        index = i;
        for (int j = i; j < len; ++j) {
            if (data[j] < tmp) {
                tmp = data[j];
                index = j;
            }
        }

        if (index != i) {
            data[index] = data[i];
            data[i] = tmp;
        }
    }
}
```