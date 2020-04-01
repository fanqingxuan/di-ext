<?php
use Tools\Di\DiInterface;
use Tools\Di\ServiceProviderInterface;

class ConfigServiceProvider implements ServiceProviderInterface
{
    public function register(DiInterface $di):void
    {
        $di->set(
            'config',
            function () {
                return array(
                     'database' =>  array(),
                     'session'  =>  array()
                 );
            }
        );
    }
}
