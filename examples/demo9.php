<?php
use JsonDi\Di;

class Test
{
    public $name;
}

$container = new Di;
$container->set("hello", Test::class, true);
$d = $container->getHello();
$d->name="abcd";
$container->setShared("hello", Test::class);
$dd = $container->getHello();
$dd->name="ABCD";
var_dump("<hr/>", $d, $dd, DI::getDefault()->getHello());
