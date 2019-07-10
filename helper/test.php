<?php

function test(callable $func,array $parameter = []): void
{
    $startAt = microtime(true);
    call_user_func($func,$parameter);
    $endAt = microtime(true);
    $time = (($endAt-$startAt)*1000);
    echo "$func 耗时：{$time} 毫秒\n";
}