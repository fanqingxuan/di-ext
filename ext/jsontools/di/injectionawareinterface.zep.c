
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
 * This interface must be implemented in those classes that uses internally the
 * JsonTools\Di that creates them
 */
ZEPHIR_INIT_CLASS(JsonTools_Di_InjectionAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(JsonTools\\Di, InjectionAwareInterface, jsontools, di_injectionawareinterface, jsontools_di_injectionawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
ZEPHIR_DOC_METHOD(JsonTools_Di_InjectionAwareInterface, setDI);

/**
 * Returns the internal dependency injector
 */
ZEPHIR_DOC_METHOD(JsonTools_Di_InjectionAwareInterface, getDI);

