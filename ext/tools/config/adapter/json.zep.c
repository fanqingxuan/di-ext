
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Tools Framework.
 *
 * (c) Tools Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Reads JSON files and converts them to Tools\Config objects.
 *
 * Given the following configuration file:
 *
 *```json
 * {"datas":{"baseuri":"\/datas\/"},"models":{"metadata":"memory"}}
 *```
 *
 * You can read it as follows:
 *
 *```php
 * use Tools\Config\Adapter\Json;
 *
 * $config = new Json("path/config.json");
 *
 * echo $config->datas->baseuri;
 * echo $config->models->metadata;
 *```
 */
ZEPHIR_INIT_CLASS(Tools_Config_Adapter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Tools\\Config\\Adapter, Json, tools, config_adapter_json, tools_config_ce, tools_config_adapter_json_method_entry, 0);

	return SUCCESS;

}

/**
 * Tools\Config\Adapter\Json constructor
 */
PHP_METHOD(Tools_Config_Adapter_Json, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *filePath_param = NULL, _1, _3, _4;
	zval filePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
		ZVAL_EMPTY_STRING(&filePath);
	}


	ZEPHIR_INIT_VAR(&_3);
	zephir_file_get_contents(&_3, &filePath);
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_CE_STATIC(&_1, tools_helper_json_ce, "decode", &_2, 15, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, tools_config_adapter_json_ce, getThis(), "__construct", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

