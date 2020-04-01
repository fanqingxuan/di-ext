
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
 * This file is part of the Tools Framework.
 *
 * (c) Tools Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
  * Tools\Di\Exception\ServiceResolutionException
  */
ZEPHIR_INIT_CLASS(Tools_Di_Exception_ServiceResolutionException) {

	ZEPHIR_REGISTER_CLASS_EX(Tools\\Di\\Exception, ServiceResolutionException, tools, di_exception_serviceresolutionexception, tools_di_exception_ce, NULL, 0);

	return SUCCESS;

}

