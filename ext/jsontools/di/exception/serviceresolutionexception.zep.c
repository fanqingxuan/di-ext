
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
 * This file is part of the JsonTools Framework.
 *
 * (c) JsonTools Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
  * JsonTools\Di\Exception\ServiceResolutionException
  */
ZEPHIR_INIT_CLASS(JsonTools_Di_Exception_ServiceResolutionException) {

	ZEPHIR_REGISTER_CLASS_EX(JsonTools\\Di\\Exception, ServiceResolutionException, jsontools, di_exception_serviceresolutionexception, jsontools_di_exception_ce, NULL, 0);

	return SUCCESS;

}

