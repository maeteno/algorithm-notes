<?php

function select(array $data): array
{
    $length = count($data);
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
    return $data;
}
