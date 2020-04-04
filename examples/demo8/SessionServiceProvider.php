<?php
use JsonDi\Di\DiInterface;
use JsonDi\Di\ServiceProviderInterface;

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
