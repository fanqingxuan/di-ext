<?php
use JsonTools\Di\DiInterface;
use JsonTools\Di\ServiceProviderInterface;

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
