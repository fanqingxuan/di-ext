PHP_ARG_ENABLE(jsontools, whether to enable jsontools, [ --enable-jsontools   Enable Jsontools])

if test "$PHP_JSONTOOLS" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, JSONTOOLS_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_JSONTOOLS, 1, [Whether you have Jsontools])
	jsontools_sources="jsontools.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c jsontools/collection.zep.c
	jsontools/config.zep.c
	jsontools/di/injectionawareinterface.zep.c
	jsontools/exception.zep.c
	jsontools/di/diinterface.zep.c
	jsontools/di/exception.zep.c
	jsontools/di/serviceinterface.zep.c
	jsontools/config/adapter/ini.zep.c
	jsontools/config/adapter/php.zep.c
	jsontools/di.zep.c
	jsontools/di/abstractinjectionaware.zep.c
	jsontools/di/exception/serviceresolutionexception.zep.c
	jsontools/di/injectable.zep.c
	jsontools/di/service.zep.c
	jsontools/di/service/builder.zep.c
	jsontools/di/serviceproviderinterface.zep.c
	jsontools/helper/json.zep.c "
	PHP_NEW_EXTENSION(jsontools, $jsontools_sources, $ext_shared,, )
	PHP_SUBST(JSONTOOLS_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([jsontools], [pcre])
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
					PHP_ADD_EXTENSION_DEP([jsontools], [json])
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

	PHP_INSTALL_HEADERS([ext/jsontools], [php_JSONTOOLS.h])

fi
