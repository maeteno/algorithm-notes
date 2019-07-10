<?php

function test(callable $func,array $parameter = []): void
{
    $startAt = getMillisecond();
    call_user_func($func,$parameter);
    $endAt = getMillisecond();
    $time = $endAt-$startAt;
    echo "$func 耗时：{$time} 毫秒\n";
}

function getMillisecond() { 
    list($s1, $s2) = explode(' ', microtime()); 
    return (float)sprintf('%.0f', (floatval($s1) + floatval($s2)) * 1000); 
}