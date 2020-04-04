
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the JsonDi Framework.
 *
 * (c) JsonDi Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This class allows to access services in the services container by just only
 * accessing a public property with the same name of a registered service
 *
 * @property \JsonDi\Mvc\Dispatcher|\JsonDi\Mvc\DispatcherInterface $dispatcher
 * @property \JsonDi\Mvc\Router|\JsonDi\Mvc\RouterInterface $router
 * @property \JsonDi\Url|\JsonDi\Url\UrlInterface $url
 * @property \JsonDi\Http\Request|\JsonDi\Http\RequestInterface $request
 * @property \JsonDi\Http\Response|\JsonDi\Http\ResponseInterface $response
 * @property \JsonDi\Http\Response\Cookies|\JsonDi\Http\Response\CookiesInterface $cookies
 * @property \JsonDi\Filter $filter
 * @property \JsonDi\Flash\Direct $flash
 * @property \JsonDi\Flash\Session $flashSession
 * @property \JsonDi\Session\ManagerInterface $session
 * @property \JsonDi\Events\Manager|\JsonDi\Events\ManagerInterface $eventsManager
 * @property \JsonDi\Db\Adapter\AdapterInterface $db
 * @property \JsonDi\Security $security
 * @property \JsonDi\Crypt|\JsonDi\CryptInterface $crypt
 * @property \JsonDi\Tag $tag
 * @property \JsonDi\Escaper|\JsonDi\Escaper\EscaperInterface $escaper
 * @property \JsonDi\Annotations\Adapter\Memory|\JsonDi\Annotations\Adapter $annotations
 * @property \JsonDi\Mvc\Model\Manager|\JsonDi\Mvc\Model\ManagerInterface $modelsManager
 * @property \JsonDi\Mvc\Model\MetaData\Memory|\JsonDi\Mvc\Model\MetadataInterface $modelsMetadata
 * @property \JsonDi\Mvc\Model\Transaction\Manager|\JsonDi\Mvc\Model\Transaction\ManagerInterface $transactionManager
 * @property \JsonDi\Assets\Manager $assets
 * @property \JsonDi\Di|\JsonDi\Di\DiInterface $di
 * @property \JsonDi\Session\Bag|\JsonDi\Session\BagInterface $persistent
 * @property \JsonDi\Mvc\View|\JsonDi\Mvc\ViewInterface $view
 */
ZEPHIR_INIT_CLASS(JsonDi_Di_Injectable) {

	ZEPHIR_REGISTER_CLASS(JsonDi\\Di, Injectable, jsondi, di_injectable, jsondi_di_injectable_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Dependency Injector
	 *
	 * @var DiInterface
	 */
	zend_declare_property_null(jsondi_di_injectable_ce, SL("container"), ZEND_ACC_PROTECTED);

	zend_class_implements(jsondi_di_injectable_ce, 1, jsondi_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Magic method __get
 */
PHP_METHOD(JsonDi_Di_Injectable, __get) {

	zval _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *propertyName_param = NULL, container, service, _0, _1$$4, _3$$4, _4$$4;
	zval propertyName, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&propertyName);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &propertyName_param);

	if (UNEXPECTED(Z_TYPE_P(propertyName_param) != IS_STRING && Z_TYPE_P(propertyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'propertyName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(propertyName_param) == IS_STRING)) {
		zephir_get_strval(&propertyName, propertyName_param);
	} else {
		ZEPHIR_INIT_VAR(&propertyName);
		ZVAL_EMPTY_STRING(&propertyName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&container, &_0);
	if (ZEPHIR_IS_STRING(&propertyName, "di")) {
		zephir_update_property_zval(this_ptr, SL("di"), &container);
		RETURN_CCTOR(&container);
	}
	if (ZEPHIR_IS_STRING(&propertyName, "persistent")) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 1, 0);
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_get_class(&_3$$4, this_ptr, 0);
		zephir_array_fast_append(&_2$$4, &_3$$4);
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "sessionBag");
		ZEPHIR_CALL_METHOD(&_1$$4, &container, "get", NULL, 0, &_3$$4, &_2$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("persistent"), &_1$$4);
		ZEPHIR_OBS_VAR(&_4$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("persistent"), PH_NOISY_CC);
		RETURN_CCTOR(&_4$$4);
	}
	ZEPHIR_CALL_METHOD(&_0, &container, "has", NULL, 0, &propertyName);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&service, &container, "getshared", NULL, 0, &propertyName);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, &propertyName, &service);
		RETURN_CCTOR(&service);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SV(&_5, "Access to undefined property ", &propertyName);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 18, &_5);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

/**
 * Magic method __isset
 */
PHP_METHOD(JsonDi_Di_Injectable, __isset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(JsonDi_Di_Injectable, getDI) {

	zval container, _0, _2$$4, _3$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&container, jsondi_di_ce, "getdefault", &_1, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, jsondi_di_exception_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "internal services");
			ZEPHIR_CALL_CE_STATIC(&_3$$4, jsondi_di_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 12, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "jsondi/Di/Injectable.zep", 124);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&container);

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(JsonDi_Di_Injectable, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

