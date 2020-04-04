<?php
use JsonDi\Di;
use JsonDi\Config;

class Test
{
}

$di = new Di;
//注入的方式
$di->set('test', 'Test');
$di->set("test2", function () {
    return new Test;
});
$di->set("test3", Test::class);
$di->set('test4', new Test);

var_dump($di->get('test'), $di->test2, $di->getTest3(), $di['test4']);
