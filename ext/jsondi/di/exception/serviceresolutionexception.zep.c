
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the JsonDi Framework.
 *
 * (c) JsonDi Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
  * JsonDi\Di\Exception\ServiceResolutionException
  */
ZEPHIR_INIT_CLASS(JsonDi_Di_Exception_ServiceResolutionException) {

	ZEPHIR_REGISTER_CLASS_EX(JsonDi\\Di\\Exception, ServiceResolutionException, jsondi, di_exception_serviceresolutionexception, jsondi_di_exception_ce, NULL, 0);

	return SUCCESS;

}

