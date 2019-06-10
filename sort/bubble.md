# 冒泡排序

冒泡排序是的思路是数据两两比较，将大的或者小的交换位置。

```php
for($i = 1; $i < $length;$i++){
    for($j = 0; $j < $length - $i;$j++){
        if($data[$j] > $data[$j+1]){
            $tmp = $data[$j];
            $data[$j] = $data[$j+1];
            $data[$j+1]  = $tmp;
        }
    }
}
```