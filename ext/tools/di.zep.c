
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Tools\Di is a component that implements Dependency Injection/Service
 * Location of services and it's itself a container for them.
 *
 * Since Tools is highly decoupled, Tools\Di is essential to integrate the
 * different components of the framework. The developer can also use this
 * component to inject dependencies and manage global instances of the different
 * classes used in the application.
 *
 * Basically, this component implements the `Inversion of Control` pattern.
 * Applying this, the objects do not receive their dependencies using setters or
 * constructors, but requesting a service dependency injector. This reduces the
 * overall complexity, since there is only one way to get the required
 * dependencies within a component.
 *
 * Additionally, this pattern increases testability in the code, thus making it
 * less prone to errors.
 *
 *```php
 * use Tools\Di;
 *
 * $di = new Di();
 *
 * // Using a string definition
 * $di->set("request", Request::class, true);
 *
 * // Using an anonymous function
 * $di->setShared(
 *     "request",
 *     function () {
 *         return new Request();
 *     }
 * );
 *
 * $request = $di->getRequest();
 *```
 */
ZEPHIR_INIT_CLASS(Tools_Di) {

	ZEPHIR_REGISTER_CLASS(Tools, Di, tools, di, tools_di_method_entry, 0);

	/**
	 * List of registered services
	 */
	zend_declare_property_null(tools_di_ce, SL("services"), ZEND_ACC_PROTECTED);

	/**
	 * List of shared instances
	 */
	zend_declare_property_null(tools_di_ce, SL("sharedInstances"), ZEND_ACC_PROTECTED);

	/**
	 * Latest DI build
	 */
	zend_declare_property_null(tools_di_ce, SL("_default"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_class_implements(tools_di_ce, 1, tools_di_diinterface_ce);
	return SUCCESS;

}

/**
 * Tools\Di constructor
 */
PHP_METHOD(Tools_Di, __construct) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, tools_di_ce, SL("_default"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_update_static_property_ce(tools_di_ce, ZEND_STRL("_default"), this_ptr);
	}

}

/**
 * Magic method to get or set services using setters/getters
 */
PHP_METHOD(Tools_Di, __call) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval arguments;
	zval *method_param = NULL, *arguments_param = NULL, instance, possibleService, definition, _7, _0$$3, _1$$3, _3$$3, _4$$6, _5$$6, _6$$6;
	zval method, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&possibleService);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments_param);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}


	if (zephir_start_with_str(&method, SL("get"))) {
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_substr(&_1$$3, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&possibleService, "lcfirst", &_2, 16, &_1$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_3$$3, &possibleService)) {
			ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, 0, &possibleService, &arguments);
			zephir_check_call_status();
			RETURN_CCTOR(&instance);
		}
	}
	if (zephir_start_with_str(&method, SL("set"))) {
		ZEPHIR_OBS_VAR(&definition);
		if (zephir_array_isset_long_fetch(&definition, &arguments, 0, 0)) {
			ZVAL_LONG(&_4$$6, 3);
			ZEPHIR_INIT_VAR(&_5$$6);
			zephir_substr(&_5$$6, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_FUNCTION(&_6$$6, "lcfirst", &_2, 16, &_5$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_6$$6, &definition);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, tools_di_exception_ce);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SVS(&_8, "Call to undefined method or service '", &method, "'");
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 12, &_8);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_7, "tools/Di.zep", 120);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 */
PHP_METHOD(Tools_Di, attempt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *name_param = NULL, *definition, definition_sub, *shared_param = NULL, _0, _1, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);

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
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, tools_di_service_ce);
	if (shared) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 17, definition, &_2);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("services"), &name, &_1);
	zephir_read_property(&_3, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "tools/Di.zep", 136);
	RETURN_CTOR(&_4);

}

/**
 * Resolves the service based on its configuration
 */
PHP_METHOD(Tools_Di, get) {

	zend_bool _1$$3, _11$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, parameters_sub, __$null, service, isShared, instance, _0, _2$$3, _3$$4, _4$$4, _5$$6, _6$$6, _7$$8, _9$$11;
	zval name, _8$$8, _10$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&isShared);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);

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
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&instance);
	ZVAL_NULL(&instance);
	ZEPHIR_OBS_VAR(&service);
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&service, &_0, &name, 0)) {
		ZEPHIR_CALL_METHOD(&isShared, &service, "isshared", NULL, 0);
		zephir_check_call_status();
		_1$$3 = zephir_is_true(&isShared);
		if (_1$$3) {
			zephir_read_property(&_2$$3, this_ptr, SL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
			_1$$3 = zephir_array_isset(&_2$$3, &name);
		}
		if (_1$$3) {
			zephir_read_property(&_3$$4, this_ptr, SL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_4$$4, &_3$$4, &name, PH_NOISY | PH_READONLY, "tools/Di.zep", 154);
			RETURN_CTOR(&_4$$4);
		}
	}
	if (Z_TYPE_P(&instance) != IS_OBJECT) {
		if (Z_TYPE_P(&service) != IS_NULL) {

			/* try_start_1: */

				ZEPHIR_CALL_METHOD(&instance, &service, "resolve", NULL, 0, parameters, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);

			try_end_1:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_5$$6);
				ZVAL_OBJ(&_5$$6, EG(exception));
				Z_ADDREF_P(&_5$$6);
				ZEPHIR_INIT_VAR(&_6$$6);
				if (zephir_instance_of_ev(&_5$$6, tools_di_exception_serviceresolutionexception_ce)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&_6$$6, &_5$$6);
					ZEPHIR_INIT_VAR(&_7$$8);
					object_init_ex(&_7$$8, tools_di_exception_ce);
					ZEPHIR_INIT_VAR(&_8$$8);
					ZEPHIR_CONCAT_SVS(&_8$$8, "Service '", &name, "' cannot be resolved");
					ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", NULL, 12, &_8$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$8, "tools/Di.zep", 167);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_is_true(&isShared)) {
				zephir_update_property_array(this_ptr, SL("sharedInstances"), &name, &instance);
			}
		} else {
			if (UNEXPECTED(!(zephir_class_exists(&name, 1)))) {
				ZEPHIR_INIT_VAR(&_9$$11);
				object_init_ex(&_9$$11, tools_di_exception_ce);
				ZEPHIR_INIT_VAR(&_10$$11);
				ZEPHIR_CONCAT_SVS(&_10$$11, "Service '", &name, "' wasn't found in the dependency injection container");
				ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", NULL, 12, &_10$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$11, "tools/Di.zep", 182);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_11$$10 = Z_TYPE_P(parameters) == IS_ARRAY;
			if (_11$$10) {
				_11$$10 = ((zephir_fast_count_int(parameters)) ? 1 : 0);
			}
			if (_11$$10) {
				ZEPHIR_INIT_NVAR(&instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &name, parameters);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &name);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(&instance) == IS_OBJECT) {
		if (zephir_instance_of_ev(&instance, tools_di_injectionawareinterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &instance, "setdi", NULL, 0, this_ptr);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&instance);

}

PHP_METHOD(Tools_Di, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, parameters_sub, __$null, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);

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
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZVAL_NULL(&_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &name, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the latest DI created
 */
PHP_METHOD(Tools_Di, getDefault) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, tools_di_ce, SL("_default"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * Returns a service definition without resolving
 */
PHP_METHOD(Tools_Di, getRaw) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, service, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

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


	ZEPHIR_OBS_VAR(&service);
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&service, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, tools_di_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Service '", &name, "' wasn't found in the dependency injection container");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 12, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "tools/Di.zep", 230);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(&service, "getdefinition", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a Tools\Di\Service instance
 */
PHP_METHOD(Tools_Di, getService) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, service, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

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


	ZEPHIR_OBS_VAR(&service);
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&service, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, tools_di_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Service '", &name, "' wasn't found in the dependency injection container");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 12, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "tools/Di.zep", 246);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&service);

}

/**
 * Return the services registered in the DI
 */
PHP_METHOD(Tools_Di, getServices) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "services");

}

/**
 * Resolves a service, the resolved service is stored in the DI, subsequent
 * requests for this service will return the same instance
 */
PHP_METHOD(Tools_Di, getShared) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, parameters_sub, __$null, instance, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);

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
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_OBS_VAR(&instance);
	zephir_read_property(&_0, this_ptr, SL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&instance, &_0, &name, 0))) {
		ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, 0, &name, parameters);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("sharedInstances"), &name, &instance);
	}
	RETURN_CCTOR(&instance);

}

/**
 * Loads services from a Config object.
 */
PHP_METHOD(Tools_Di, loadFromConfig) {

	zend_bool _4$$3, _8$$4;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, services, name, service, *_0, _1, _5$$3, _6$$3, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_CALL_METHOD(&services, config, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&services, 0, "tools/Di.zep", 296);
	if (Z_TYPE_P(&services) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&services), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _0);
			_4$$3 = zephir_array_isset_string(&service, SL("shared"));
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&_5$$3);
				zephir_array_fetch_string(&_5$$3, &service, SL("shared"), PH_NOISY, "tools/Di.zep", 294);
				_4$$3 = zephir_is_true(&_5$$3);
			}
			ZVAL_BOOL(&_6$$3, _4$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_7, 0, &name, &service, &_6$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &services, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &services, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &services, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, &services, "current", NULL, 0);
			zephir_check_call_status();
				_8$$4 = zephir_array_isset_string(&service, SL("shared"));
				if (_8$$4) {
					ZEPHIR_OBS_NVAR(&_9$$4);
					zephir_array_fetch_string(&_9$$4, &service, SL("shared"), PH_NOISY, "tools/Di.zep", 294);
					_8$$4 = zephir_is_true(&_9$$4);
				}
				ZVAL_BOOL(&_10$$4, _8$$4);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_7, 0, &name, &service, &_10$$4);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &services, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();

}

/**
 * Loads services from a php config file.
 *
 * ```php
 * $di->loadFromPhp("path/services.php");
 * ```
 *
 * And the services can be specified in the file as:
 *
 * ```php
 * return [
 *      'myComponent' => [
 *          'className' => '\Acme\Components\MyComponent',
 *          'shared' => true,
 *      ],
 *      'group' => [
 *          'className' => '\Acme\Group',
 *          'arguments' => [
 *              [
 *                  'type' => 'service',
 *                  'service' => 'myComponent',
 *              ],
 *          ],
 *      ],
 *      'user' => [
 *          'className' => '\Acme\User',
 *      ],
 * ];
 * ```
 *
 * @link https://docs.datas.io/en/latest/reference/di.html
 */
PHP_METHOD(Tools_Di, loadFromPhp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, services;
	zval filePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&services);

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


	ZEPHIR_INIT_VAR(&services);
	object_init_ex(&services, tools_config_adapter_php_ce);
	ZEPHIR_CALL_METHOD(NULL, &services, "__construct", NULL, 18, &filePath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfromconfig", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether the DI contains a service by a name
 */
PHP_METHOD(Tools_Di, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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


	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * Allows to obtain a shared service using the array syntax
 *
 *```php
 * var_dump($di["request"]);
 *```
 */
PHP_METHOD(Tools_Di, offsetGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a service is registered using the array syntax
 */
PHP_METHOD(Tools_Di, offsetExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to register a shared service using the array syntax
 *
 *```php
 * $di["request"] = new \Tools\Http\Request();
 *```
 */
PHP_METHOD(Tools_Di, offsetSet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *definition, definition_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&definition_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &definition);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, name, definition);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a service from the services container using the array syntax
 */
PHP_METHOD(Tools_Di, offsetUnset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a service provider.
 *
 * ```php
 * use Tools\Di\DiInterface;
 * use Tools\Di\ServiceProviderInterface;
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
PHP_METHOD(Tools_Di, register) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider, provider_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);



	ZEPHIR_CALL_METHOD(NULL, provider, "register", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a service in the services container
 * It also removes any shared instance created for the service
 */
PHP_METHOD(Tools_Di, remove) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, services, _0, sharedInstances;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&sharedInstances);

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


	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&services, &_0);
	zephir_array_unset(&services, &name, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("services"), &services);
	zephir_read_property(&_0, this_ptr, SL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sharedInstances, &_0);
	zephir_array_unset(&sharedInstances, &name, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("sharedInstances"), &sharedInstances);
	ZEPHIR_MM_RESTORE();

}

/**
 * Resets the internal default DI
 */
PHP_METHOD(Tools_Di, reset) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zephir_update_static_property_ce(tools_di_ce, ZEND_STRL("_default"), &__$null);

}

/**
 * Registers a service in the services container
 */
PHP_METHOD(Tools_Di, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *name_param = NULL, *definition, definition_sub, *shared_param = NULL, _0, _1, _2, _3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);

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
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, tools_di_service_ce);
	if (shared) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 17, definition, &_1);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("services"), &name, &_0);
	zephir_read_property(&_2, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name, PH_NOISY | PH_READONLY, "tools/Di.zep", 447);
	RETURN_CTOR(&_3);

}

PHP_METHOD(Tools_Di, __set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *definition, definition_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &name, definition);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set a default dependency injection container to be obtained into static
 * methods
 */
PHP_METHOD(Tools_Di, setDefault) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &container);



	zephir_update_static_property_ce(tools_di_ce, ZEND_STRL("_default"), container);

}

/**
 * Sets a service using a raw Tools\Di\Service definition
 */
PHP_METHOD(Tools_Di, setService) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *rawDefinition, rawDefinition_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&rawDefinition_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &rawDefinition);

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


	zephir_update_property_array(this_ptr, SL("services"), &name, rawDefinition);
	RETVAL_ZVAL(rawDefinition, 1, 0);
	RETURN_MM();

}

/**
 * Registers an "always shared" service in the services container
 */
PHP_METHOD(Tools_Di, setShared) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *definition, definition_sub, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

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


	ZVAL_BOOL(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &name, definition, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

