# 选择排序

```php
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