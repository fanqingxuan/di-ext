<?php
use Tools\Di\DiInterface;
use Tools\Di\ServiceProviderInterface;

class SessionServiceProvider implements ServiceProviderInterface
{
    public function register(DiInterface $di):void
    {
        $di->set(
            'session',
            StdClass::class
        );
    }
}
