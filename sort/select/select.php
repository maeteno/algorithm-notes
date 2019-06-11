<?php

$data = [];
$index = 0;
while($index++ < 100){
    $data[] = rand(1,100);
}
echo json_encode($data) . PHP_EOL;

$length = count($data);
for($i = 0;$i < $length;$i++){
    $tmpIndex = $i;
    for($j = $i+1;$j < $length; $j++){
        if($data[$i] > $data[$j]){
            $tmpIndex = $j;
        }
    }

    if($tmpIndex != $i){
        $tmp = $data[$tmpIndex];
        $data[$tmpIndex] = $data[$i];
        $data[$i]  = $tmp;
    }
}
echo json_encode($data) . PHP_EOL;