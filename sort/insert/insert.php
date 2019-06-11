<?php

$data = [];
$index = 0;
while($index++ < 100){
    $data[] = rand(1,100);
}
echo json_encode($data) . PHP_EOL;

$length = count($data);

$result = [];

for($i = 0; $i < $length; $i++){
    $tmp = $data[$i];
    for($j = 0 ; $j < $i; $j++){
        
    }
}
