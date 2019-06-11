# 选择排序

选择排序有两层循环，

## 排序过程

1. 每次排序时找到最小（大）的元素和头部元素交换位置

# 动图演示

![](../_images/select.gif)

# 示例代码
```php
// PHP 代码
for($i = 0;$i < $length - 1;$i++){
    $tmpIndex = $i;
    $tmpVal = $data[$i];
    for($j = $i;$j < $length; $j++){
        if($tmpVal > $data[$j]){
            $tmpVal = $data[$j];
            $tmpIndex = $j;
        }
    }

    if($tmpIndex != $i){
        $data[$tmpIndex] = $data[$i];
        $data[$i]  = $tmpVal;
    }
}
```