<?php

function mockData(int $size = 100): array
{
    $data = [];
    $index = 0;
    while($index++ < $size){
        $data[] = rand(1,$size);
    }

    return $data;
}