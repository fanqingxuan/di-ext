
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Tools Framework.
 *
 * (c) Tools Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This abstract class offers common access to the DI in a class
 */
ZEPHIR_INIT_CLASS(Tools_Di_AbstractInjectionAware) {

	ZEPHIR_REGISTER_CLASS(Tools\\Di, AbstractInjectionAware, tools, di_abstractinjectionaware, tools_di_abstractinjectionaware_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Dependency Injector
	 *
	 * @var DiInterface
	 */
	zend_declare_property_null(tools_di_abstractinjectionaware_ce, SL("container"), ZEND_ACC_PROTECTED);

	zend_class_implements(tools_di_abstractinjectionaware_ce, 1, tools_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Tools_Di_AbstractInjectionAware, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Tools_Di_AbstractInjectionAware, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

