
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * This file is part of the JsonTools Framework.
 *
 * (c) JsonTools Team <team@datas.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * JsonTools\Di\Service\Builder
 *
 * This class builds instances based on complex definitions
 */
ZEPHIR_INIT_CLASS(JsonTools_Di_Service_Builder) {

	ZEPHIR_REGISTER_CLASS(JsonTools\\Di\\Service, Builder, jsontools, di_service_builder, jsontools_di_service_builder_method_entry, 0);

	return SUCCESS;

}

/**
 * Builds a service using a complex service definition
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(JsonTools_Di_Service_Builder, build) {

	zend_string *_5$$10, *_29$$25;
	zend_ulong _4$$10, _28$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_8 = NULL, *_37 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *container, container_sub, *definition_param = NULL, *parameters = NULL, parameters_sub, __$null, className, arguments, paramCalls, methodPosition, method, methodName, methodCall, instance, propertyPosition, property, propertyName, propertyValue, _0$$8, *_2$$10, _3$$10, _6$$14, _7$$14, _9$$15, _10$$15, _11$$17, _12$$17, _13$$18, _14$$18, _15$$13, _16$$20, _17$$20, _18$$21, _19$$21, _20$$19, _25$$19, _21$$23, _22$$23, _23$$24, _24$$24, *_26$$25, _27$$25, _30$$29, _31$$29, _32$$30, _33$$30, _34$$31, _35$$31, _36$$28, _38$$33, _39$$33, _40$$34, _41$$34, _42$$35, _43$$35, _44$$32;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&paramCalls);
	ZVAL_UNDEF(&methodPosition);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&methodCall);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&propertyPosition);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&propertyName);
	ZVAL_UNDEF(&propertyValue);
	ZVAL_UNDEF(&_0$$8);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_30$$29);
	ZVAL_UNDEF(&_31$$29);
	ZVAL_UNDEF(&_32$$30);
	ZVAL_UNDEF(&_33$$30);
	ZVAL_UNDEF(&_34$$31);
	ZVAL_UNDEF(&_35$$31);
	ZVAL_UNDEF(&_36$$28);
	ZVAL_UNDEF(&_38$$33);
	ZVAL_UNDEF(&_39$$33);
	ZVAL_UNDEF(&_40$$34);
	ZVAL_UNDEF(&_41$$34);
	ZVAL_UNDEF(&_42$$35);
	ZVAL_UNDEF(&_43$$35);
	ZVAL_UNDEF(&_44$$32);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &container, &definition_param, &parameters);

	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_OBS_VAR(&className);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&className, &definition, SL("className"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jsontools_di_exception_ce, "Invalid service definition. Missing 'className' parameter", "jsontools/Di/Service/Builder.zep", 41);
		return;
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		if (zephir_fast_count_int(parameters)) {
			ZEPHIR_INIT_VAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, parameters);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_OBS_VAR(&arguments);
		if (zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 0)) {
			ZEPHIR_CALL_METHOD(&_0$$8, this_ptr, "buildparameters", &_1, 20, container, &arguments);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, &_0$$8);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(&paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, &definition, SL("calls"), 0)) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jsontools_di_exception_ce, "The definition has setter injection parameters but the constructor didn't return an instance", "jsontools/Di/Service/Builder.zep", 83);
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jsontools_di_exception_ce, "Setter injection parameters must be an array", "jsontools/Di/Service/Builder.zep", 89);
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "jsontools/Di/Service/Builder.zep", 148);
		if (Z_TYPE_P(&paramCalls) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _4$$10, _5$$10, _2$$10)
			{
				ZEPHIR_INIT_NVAR(&methodPosition);
				if (_5$$10 != NULL) { 
					ZVAL_STR_COPY(&methodPosition, _5$$10);
				} else {
					ZVAL_LONG(&methodPosition, _4$$10);
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _2$$10);
				if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_6$$14);
					object_init_ex(&_6$$14, jsontools_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_7$$14);
					ZEPHIR_CONCAT_SV(&_7$$14, "Method call must be an array on position ", &methodPosition);
					ZEPHIR_CALL_METHOD(NULL, &_6$$14, "__construct", &_8, 12, &_7$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$14, "jsontools/Di/Service/Builder.zep", 103);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methodName);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0)))) {
					ZEPHIR_INIT_NVAR(&_9$$15);
					object_init_ex(&_9$$15, jsontools_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_10$$15);
					ZEPHIR_CONCAT_SV(&_10$$15, "The method name is required on position ", &methodPosition);
					ZEPHIR_CALL_METHOD(NULL, &_9$$15, "__construct", &_8, 12, &_10$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$15, "jsontools/Di/Service/Builder.zep", 112);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&methodCall);
				zephir_create_array(&methodCall, 2, 0);
				zephir_array_fast_append(&methodCall, &instance);
				zephir_array_fast_append(&methodCall, &methodName);
				ZEPHIR_OBS_NVAR(&arguments);
				if (zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0)) {
					if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_11$$17);
						object_init_ex(&_11$$17, jsontools_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_12$$17);
						ZEPHIR_CONCAT_SV(&_12$$17, "Call arguments must be an array ", &methodPosition);
						ZEPHIR_CALL_METHOD(NULL, &_11$$17, "__construct", &_8, 12, &_12$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$17, "jsontools/Di/Service/Builder.zep", 124);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_fast_count_int(&arguments)) {
						ZEPHIR_INIT_NVAR(&_13$$18);
						ZEPHIR_CALL_METHOD(&_14$$18, this_ptr, "buildparameters", &_1, 20, container, &arguments);
						zephir_check_call_status();
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_13$$18, &methodCall, &_14$$18);
						zephir_check_call_status();
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_15$$13);
				ZEPHIR_CALL_USER_FUNC(&_15$$13, &methodCall);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramCalls, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$10, &paramCalls, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&methodPosition, &paramCalls, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&method, &paramCalls, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_16$$20);
						object_init_ex(&_16$$20, jsontools_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_17$$20);
						ZEPHIR_CONCAT_SV(&_17$$20, "Method call must be an array on position ", &methodPosition);
						ZEPHIR_CALL_METHOD(NULL, &_16$$20, "__construct", &_8, 12, &_17$$20);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$20, "jsontools/Di/Service/Builder.zep", 103);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&methodName);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0)))) {
						ZEPHIR_INIT_NVAR(&_18$$21);
						object_init_ex(&_18$$21, jsontools_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_19$$21);
						ZEPHIR_CONCAT_SV(&_19$$21, "The method name is required on position ", &methodPosition);
						ZEPHIR_CALL_METHOD(NULL, &_18$$21, "__construct", &_8, 12, &_19$$21);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$21, "jsontools/Di/Service/Builder.zep", 112);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_20$$19);
					zephir_create_array(&_20$$19, 2, 0);
					zephir_array_fast_append(&_20$$19, &instance);
					zephir_array_fast_append(&_20$$19, &methodName);
					ZEPHIR_CPY_WRT(&methodCall, &_20$$19);
					ZEPHIR_OBS_NVAR(&arguments);
					if (zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0)) {
						if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
							ZEPHIR_INIT_NVAR(&_21$$23);
							object_init_ex(&_21$$23, jsontools_di_exception_ce);
							ZEPHIR_INIT_NVAR(&_22$$23);
							ZEPHIR_CONCAT_SV(&_22$$23, "Call arguments must be an array ", &methodPosition);
							ZEPHIR_CALL_METHOD(NULL, &_21$$23, "__construct", &_8, 12, &_22$$23);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$23, "jsontools/Di/Service/Builder.zep", 124);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (zephir_fast_count_int(&arguments)) {
							ZEPHIR_INIT_NVAR(&_23$$24);
							ZEPHIR_CALL_METHOD(&_24$$24, this_ptr, "buildparameters", &_1, 20, container, &arguments);
							zephir_check_call_status();
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_23$$24, &methodCall, &_24$$24);
							zephir_check_call_status();
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&_25$$19);
					ZEPHIR_CALL_USER_FUNC(&_25$$19, &methodCall);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &paramCalls, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_INIT_NVAR(&methodPosition);
	}
	ZEPHIR_OBS_NVAR(&paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, &definition, SL("properties"), 0)) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jsontools_di_exception_ce, "The definition has properties injection parameters but the constructor didn't return an instance", "jsontools/Di/Service/Builder.zep", 158);
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jsontools_di_exception_ce, "Setter injection parameters must be an array", "jsontools/Di/Service/Builder.zep", 164);
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "jsontools/Di/Service/Builder.zep", 208);
		if (Z_TYPE_P(&paramCalls) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _28$$25, _29$$25, _26$$25)
			{
				ZEPHIR_INIT_NVAR(&propertyPosition);
				if (_29$$25 != NULL) { 
					ZVAL_STR_COPY(&propertyPosition, _29$$25);
				} else {
					ZVAL_LONG(&propertyPosition, _28$$25);
				}
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _26$$25);
				if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_30$$29);
					object_init_ex(&_30$$29, jsontools_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_31$$29);
					ZEPHIR_CONCAT_SV(&_31$$29, "Property must be an array on position ", &propertyPosition);
					ZEPHIR_CALL_METHOD(NULL, &_30$$29, "__construct", &_8, 12, &_31$$29);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_30$$29, "jsontools/Di/Service/Builder.zep", 178);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyName);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0)))) {
					ZEPHIR_INIT_NVAR(&_32$$30);
					object_init_ex(&_32$$30, jsontools_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_33$$30);
					ZEPHIR_CONCAT_SV(&_33$$30, "The property name is required on position ", &propertyPosition);
					ZEPHIR_CALL_METHOD(NULL, &_32$$30, "__construct", &_8, 12, &_33$$30);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$30, "jsontools/Di/Service/Builder.zep", 187);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyValue);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0)))) {
					ZEPHIR_INIT_NVAR(&_34$$31);
					object_init_ex(&_34$$31, jsontools_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_35$$31);
					ZEPHIR_CONCAT_SV(&_35$$31, "The property value is required on position ", &propertyPosition);
					ZEPHIR_CALL_METHOD(NULL, &_34$$31, "__construct", &_8, 12, &_35$$31);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_34$$31, "jsontools/Di/Service/Builder.zep", 196);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_36$$28, this_ptr, "buildparameter", &_37, 21, container, &propertyPosition, &propertyValue);
				zephir_check_call_status();
				zephir_update_property_zval_zval(&instance, &propertyName, &_36$$28);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramCalls, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_27$$25, &paramCalls, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_27$$25)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&propertyPosition, &paramCalls, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&property, &paramCalls, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_38$$33);
						object_init_ex(&_38$$33, jsontools_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_39$$33);
						ZEPHIR_CONCAT_SV(&_39$$33, "Property must be an array on position ", &propertyPosition);
						ZEPHIR_CALL_METHOD(NULL, &_38$$33, "__construct", &_8, 12, &_39$$33);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_38$$33, "jsontools/Di/Service/Builder.zep", 178);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyName);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0)))) {
						ZEPHIR_INIT_NVAR(&_40$$34);
						object_init_ex(&_40$$34, jsontools_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_41$$34);
						ZEPHIR_CONCAT_SV(&_41$$34, "The property name is required on position ", &propertyPosition);
						ZEPHIR_CALL_METHOD(NULL, &_40$$34, "__construct", &_8, 12, &_41$$34);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_40$$34, "jsontools/Di/Service/Builder.zep", 187);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyValue);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0)))) {
						ZEPHIR_INIT_NVAR(&_42$$35);
						object_init_ex(&_42$$35, jsontools_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_43$$35);
						ZEPHIR_CONCAT_SV(&_43$$35, "The property value is required on position ", &propertyPosition);
						ZEPHIR_CALL_METHOD(NULL, &_42$$35, "__construct", &_8, 12, &_43$$35);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_42$$35, "jsontools/Di/Service/Builder.zep", 196);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_44$$32, this_ptr, "buildparameter", &_37, 21, container, &propertyPosition, &propertyValue);
					zephir_check_call_status();
					zephir_update_property_zval_zval(&instance, &propertyName, &_44$$32);
				ZEPHIR_CALL_METHOD(NULL, &paramCalls, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&property);
		ZEPHIR_INIT_NVAR(&propertyPosition);
	}
	RETURN_CCTOR(&instance);

}

/**
 * Resolves a constructor/call parameter
 *
 * @return mixed
 */
PHP_METHOD(JsonTools_Di_Service_Builder, buildParameter) {

	zval _2$$3, _5$$5, _8$$8, _11$$10, _14$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval argument;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, *position_param = NULL, *argument_param = NULL, type, name, value, instanceArguments, _0$$3, _1$$3, _3$$5, _4$$5, _6$$8, _7$$8, _9$$10, _10$$10, _12$$13, _13$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&instanceArguments);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_14$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &container, &position_param, &argument_param);

	position = zephir_get_intval(position_param);
	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);


	ZEPHIR_OBS_VAR(&type);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&type, &argument, SL("type"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, jsontools_di_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_LONG(&_1$$3, position);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Argument at position ", &_1$$3, " must have a type");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 12, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "jsontools/Di/Service/Builder.zep", 228);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(&type, "service")) {
			ZEPHIR_OBS_VAR(&name);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&name, &argument, SL("name"), 0)))) {
				ZEPHIR_INIT_VAR(&_3$$5);
				object_init_ex(&_3$$5, jsontools_di_exception_ce);
				ZEPHIR_INIT_VAR(&_4$$5);
				ZVAL_LONG(&_4$$5, position);
				ZEPHIR_INIT_VAR(&_5$$5);
				ZEPHIR_CONCAT_SV(&_5$$5, "Service 'name' is required in parameter on position ", &_4$$5);
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 12, &_5$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$5, "jsontools/Di/Service/Builder.zep", 241);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jsontools_di_exception_ce, "The dependency injector container is not valid", "jsontools/Di/Service/Builder.zep", 247);
				return;
			}
			ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "parameter")) {
			ZEPHIR_OBS_VAR(&value);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&value, &argument, SL("value"), 0)))) {
				ZEPHIR_INIT_VAR(&_6$$8);
				object_init_ex(&_6$$8, jsontools_di_exception_ce);
				ZEPHIR_INIT_VAR(&_7$$8);
				ZVAL_LONG(&_7$$8, position);
				ZEPHIR_INIT_VAR(&_8$$8);
				ZEPHIR_CONCAT_SV(&_8$$8, "Service 'value' is required in parameter on position ", &_7$$8);
				ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", NULL, 12, &_8$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$8, "jsontools/Di/Service/Builder.zep", 259);
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&value);
		}
		if (ZEPHIR_IS_STRING(&type, "instance")) {
			ZEPHIR_OBS_NVAR(&name);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&name, &argument, SL("className"), 0)))) {
				ZEPHIR_INIT_VAR(&_9$$10);
				object_init_ex(&_9$$10, jsontools_di_exception_ce);
				ZEPHIR_INIT_VAR(&_10$$10);
				ZVAL_LONG(&_10$$10, position);
				ZEPHIR_INIT_VAR(&_11$$10);
				ZEPHIR_CONCAT_SV(&_11$$10, "Service 'className' is required in parameter on position ", &_10$$10);
				ZEPHIR_CALL_METHOD(NULL, &_9$$10, "__construct", NULL, 12, &_11$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$10, "jsontools/Di/Service/Builder.zep", 272);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jsontools_di_exception_ce, "The dependency injector container is not valid", "jsontools/Di/Service/Builder.zep", 278);
				return;
			}
			ZEPHIR_OBS_VAR(&instanceArguments);
			if (zephir_array_isset_string_fetch(&instanceArguments, &argument, SL("arguments"), 0)) {
				ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name, &instanceArguments);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_12$$13);
		object_init_ex(&_12$$13, jsontools_di_exception_ce);
		ZEPHIR_INIT_VAR(&_13$$13);
		ZVAL_LONG(&_13$$13, position);
		ZEPHIR_INIT_VAR(&_14$$13);
		ZEPHIR_CONCAT_SV(&_14$$13, "Unknown service type in parameter on position ", &_13$$13);
		ZEPHIR_CALL_METHOD(NULL, &_12$$13, "__construct", NULL, 12, &_14$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$13, "jsontools/Di/Service/Builder.zep", 300);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Resolves an array of parameters
 */
PHP_METHOD(JsonTools_Di_Service_Builder, buildParameters) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, buildArguments;
	zval *container, container_sub, *arguments_param = NULL, position, argument, *_0, _1, _4$$3, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&buildArguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &container, &arguments_param);

	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);


	ZEPHIR_INIT_VAR(&buildArguments);
	array_init(&buildArguments);
	zephir_is_iterable(&arguments, 0, "jsontools/Di/Service/Builder.zep", 322);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arguments), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&position, _3);
			} else {
				ZVAL_LONG(&position, _2);
			}
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _0);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "buildparameter", &_5, 21, container, &position, &argument);
			zephir_check_call_status();
			zephir_array_append(&buildArguments, &_4$$3, PH_SEPARATE, "jsontools/Di/Service/Builder.zep", 319);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&position, &arguments, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&argument, &arguments, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "buildparameter", &_5, 21, container, &position, &argument);
				zephir_check_call_status();
				zephir_array_append(&buildArguments, &_6$$4, PH_SEPARATE, "jsontools/Di/Service/Builder.zep", 319);
			ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_NVAR(&position);
	RETURN_CTOR(&buildArguments);

}

