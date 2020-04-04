
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "jsondi.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *jsondi_di_injectionawareinterface_ce;
zend_class_entry *jsondi_di_diinterface_ce;
zend_class_entry *jsondi_di_serviceinterface_ce;
zend_class_entry *jsondi_di_serviceproviderinterface_ce;
zend_class_entry *jsondi_collection_ce;
zend_class_entry *jsondi_config_ce;
zend_class_entry *jsondi_exception_ce;
zend_class_entry *jsondi_di_exception_ce;
zend_class_entry *jsondi_config_adapter_ini_ce;
zend_class_entry *jsondi_config_adapter_php_ce;
zend_class_entry *jsondi_di_abstractinjectionaware_ce;
zend_class_entry *jsondi_di_ce;
zend_class_entry *jsondi_di_exception_serviceresolutionexception_ce;
zend_class_entry *jsondi_di_injectable_ce;
zend_class_entry *jsondi_di_service_builder_ce;
zend_class_entry *jsondi_di_service_ce;
zend_class_entry *jsondi_helper_json_ce;

ZEND_DECLARE_MODULE_GLOBALS(jsondi)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(jsondi)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(JsonDi_Di_InjectionAwareInterface);
	ZEPHIR_INIT(JsonDi_Di_DiInterface);
	ZEPHIR_INIT(JsonDi_Di_ServiceInterface);
	ZEPHIR_INIT(JsonDi_Di_ServiceProviderInterface);
	ZEPHIR_INIT(JsonDi_Collection);
	ZEPHIR_INIT(JsonDi_Config);
	ZEPHIR_INIT(JsonDi_Exception);
	ZEPHIR_INIT(JsonDi_Di_Exception);
	ZEPHIR_INIT(JsonDi_Config_Adapter_Ini);
	ZEPHIR_INIT(JsonDi_Config_Adapter_Php);
	ZEPHIR_INIT(JsonDi_Di);
	ZEPHIR_INIT(JsonDi_Di_AbstractInjectionAware);
	ZEPHIR_INIT(JsonDi_Di_Exception_ServiceResolutionException);
	ZEPHIR_INIT(JsonDi_Di_Injectable);
	ZEPHIR_INIT(JsonDi_Di_Service);
	ZEPHIR_INIT(JsonDi_Di_Service_Builder);
	ZEPHIR_INIT(JsonDi_Helper_Json);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(jsondi)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_jsondi_globals *jsondi_globals TSRMLS_DC)
{
	jsondi_globals->initialized = 0;

	/* Cache Enabled */
	jsondi_globals->cache_enabled = 1;

	/* Recursive Lock */
	jsondi_globals->recursive_lock = 0;

	/* Static cache */
	memset(jsondi_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_jsondi_globals *jsondi_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(jsondi)
{
	zend_jsondi_globals *jsondi_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	jsondi_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(jsondi_globals_ptr);
	zephir_initialize_memory(jsondi_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(jsondi)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(jsondi)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_JSONDI_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_JSONDI_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_JSONDI_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_JSONDI_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_JSONDI_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(jsondi)
{
	php_zephir_init_globals(jsondi_globals);
	php_zephir_init_module_globals(jsondi_globals);
}

static PHP_GSHUTDOWN_FUNCTION(jsondi)
{
	
}


zend_function_entry php_jsondi_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_jsondi_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry jsondi_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_jsondi_deps,
	PHP_JSONDI_EXTNAME,
	php_jsondi_functions,
	PHP_MINIT(jsondi),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(jsondi),
#else
	NULL,
#endif
	PHP_RINIT(jsondi),
	PHP_RSHUTDOWN(jsondi),
	PHP_MINFO(jsondi),
	PHP_JSONDI_VERSION,
	ZEND_MODULE_GLOBALS(jsondi),
	PHP_GINIT(jsondi),
	PHP_GSHUTDOWN(jsondi),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(jsondi),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_JSONDI
ZEND_GET_MODULE(jsondi)
#endif
