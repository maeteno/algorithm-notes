<?php

$data = [];
$index = 0;
while($index++ < 100){
    $data[] = rand(1,100);
}

echo json_encode($data) . PHP_EOL;
$length = count($data);
for($i = 1; $i < $length;$i++){
    for($j = 0; $j < $length - $i;$j++){
        if($data[$j] > $data[$j+1]){
            $tmp = $data[$j];
            $data[$j] = $data[$j+1];
            $data[$j+1]  = $tmp;
        }
    }
}
echo json_encode($data) . PHP_EOL;