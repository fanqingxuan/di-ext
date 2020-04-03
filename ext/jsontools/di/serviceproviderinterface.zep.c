
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the JsonTools Framework.
 *
 * (c) JsonTools Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Should be implemented by service providers, or such components, which
 * register a service in the service container.
 *
 * ```php
 * namespace Acme;
 *
 * use JsonTools\Di\DiInterface;
 * use JsonTools\Di\ServiceProviderInterface;
 *
 * class SomeServiceProvider implements ServiceProviderInterface
 * {
 *     public function register(DiInterface $di)
 *     {
 *         $di->setShared(
 *             'service',
 *             function () {
 *                 // ...
 *             }
 *         );
 *     }
 * }
 * ```
 */
ZEPHIR_INIT_CLASS(JsonTools_Di_ServiceProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(JsonTools\\Di, ServiceProviderInterface, jsontools, di_serviceproviderinterface, jsontools_di_serviceproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Registers a service provider.
 */
ZEPHIR_DOC_METHOD(JsonTools_Di_ServiceProviderInterface, register);

