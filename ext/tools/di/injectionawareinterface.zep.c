
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Tools Framework.
 *
 * (c) Tools Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This interface must be implemented in those classes that uses internally the
 * Tools\Di that creates them
 */
ZEPHIR_INIT_CLASS(Tools_Di_InjectionAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Tools\\Di, InjectionAwareInterface, tools, di_injectionawareinterface, tools_di_injectionawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
ZEPHIR_DOC_METHOD(Tools_Di_InjectionAwareInterface, setDI);

/**
 * Returns the internal dependency injector
 */
ZEPHIR_DOC_METHOD(Tools_Di_InjectionAwareInterface, getDI);

