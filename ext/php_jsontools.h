
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_JSONTOOLS_H
#define PHP_JSONTOOLS_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_JSONTOOLS_NAME        "jsontools"
#define PHP_JSONTOOLS_VERSION     "1.0.0"
#define PHP_JSONTOOLS_EXTNAME     "jsontools"
#define PHP_JSONTOOLS_AUTHOR      "Json"
#define PHP_JSONTOOLS_ZEPVERSION  "0.12.12-1094502"
#define PHP_JSONTOOLS_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(jsontools)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(jsontools)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(jsontools)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(jsontools, v)
#else
	#define ZEPHIR_GLOBAL(v) (jsontools_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_jsontools_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(jsontools_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(jsontools_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def jsontools_globals
#define zend_zephir_globals_def zend_jsontools_globals

extern zend_module_entry jsontools_module_entry;
#define phpext_jsontools_ptr &jsontools_module_entry

#endif
