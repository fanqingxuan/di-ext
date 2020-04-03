
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the JsonTools Framework.
 *
 * (c) JsonTools Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * JsonTools\Exception
 *
 * All framework exceptions should use or extend this exception
 */
ZEPHIR_INIT_CLASS(JsonTools_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(JsonTools, Exception, jsontools, exception, zend_exception_get_default(TSRMLS_C), jsontools_exception_method_entry, 0);

	zend_class_implements(jsontools_exception_ce, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

PHP_METHOD(JsonTools_Exception, containerServiceNotFound) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *service_param = NULL;
	zval service;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service_param);

	if (UNEXPECTED(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(&service, service_param);
	} else {
		ZEPHIR_INIT_VAR(&service);
		ZVAL_EMPTY_STRING(&service);
	}


	ZEPHIR_CONCAT_SV(return_value, "A dependency injection container is required to access ", &service);
	RETURN_MM();

}
