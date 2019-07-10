<?php

include_once "./helper/mock.php";
include_once "./helper/test.php";
include_once "./sort/select/select.php";
include_once "./sort/insert/insert.php";

$data = mockData(10000);

test('select',$data);
test('insert',$data);