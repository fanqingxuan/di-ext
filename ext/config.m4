PHP_ARG_ENABLE(jsondi, whether to enable jsondi, [ --enable-jsondi   Enable Jsondi])

if test "$PHP_JSONDI" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, JSONDI_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_JSONDI, 1, [Whether you have Jsondi])
	jsondi_sources="jsondi.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c jsondi/collection.zep.c
	jsondi/config.zep.c
	jsondi/di/injectionawareinterface.zep.c
	jsondi/exception.zep.c
	jsondi/di/diinterface.zep.c
	jsondi/di/exception.zep.c
	jsondi/di/serviceinterface.zep.c
	jsondi/config/adapter/ini.zep.c
	jsondi/config/adapter/php.zep.c
	jsondi/di.zep.c
	jsondi/di/abstractinjectionaware.zep.c
	jsondi/di/exception/serviceresolutionexception.zep.c
	jsondi/di/injectable.zep.c
	jsondi/di/service.zep.c
	jsondi/di/service/builder.zep.c
	jsondi/di/serviceproviderinterface.zep.c
	jsondi/helper/json.zep.c "
	PHP_NEW_EXTENSION(jsondi, $jsondi_sources, $ext_shared,, )
	PHP_SUBST(JSONDI_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([jsondi], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([jsondi], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/jsondi], [php_JSONDI.h])

fi
