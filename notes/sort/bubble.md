# 冒泡排序

冒泡排序是的思路是数据两两比较，将大的或者小的交换位置。

# 动图演示

![](../_images/bubble.gif)

# 示例代码
```cpp
// 冒泡排序
void sort::bubble(int data[], int len) {
    for (int i = len - 1; i > 0 ; --i) {
        for (int j = 0; j < i; ++ j) {
            if(data[j] > data[j+1]){
                int tmp = data[j];
                data[j] = data[j +1];
                data[j+1] = tmp;
            }
        }
    }
}
```