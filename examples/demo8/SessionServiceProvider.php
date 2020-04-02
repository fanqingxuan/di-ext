<?php
use JsonTools\Di\DiInterface;
use JsonTools\Di\ServiceProviderInterface;

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
