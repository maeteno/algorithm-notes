# 选择排序

选择排序有两层循环，

## 排序过程

1. 每次排序时找到最小（大）的元素和头部元素交换位置

# 动图演示

![](../_images/select.gif)

# 示例代码
```php
// PHP 代码
for($i = 0;$i < $length;$i++){
    for($j = $i+1;$j < $length; $j++){
        if($data[$i] > $data[$j]){
            $tmp = $data[$i];
            $data[$i] = $data[$j];
            $data[$j]  = $tmp;
        }
    }
}
```