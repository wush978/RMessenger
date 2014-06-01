AC_INIT([XMPPNotifier], [0.1]) dnl package name, version
                    
dnl Now find the compiler and compiler flags to use
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
 echo "could not determine R_HOME"
 exit 1
fi
CC=`"${R_HOME}/bin/R" CMD config CC`
CPP=`"${R_HOME}/bin/R" CMD config CPP`
CFLAGS=`"${R_HOME}/bin/R" CMD config CFLAGS`
CPPFLAGS=`"${R_HOME}/bin/R" CMD config CPPFLAGS`

AC_PROG_CC
AC_PROG_CPP
    
AC_CHECK_HEADER(OPENSSL_INCLUDES, [], [AC_MSG_ERROR([could not find openssl headers, openssl required])])
AC_CHECK_HEADER(resolv.h, [LIBS="$LIBS -lresolv"], [AC_MSG_ERROR([could not find resolv headers, resolv required])])
PKG_CHECK_MODULES(libxml2, [libxml-2.0 >= 2.7], 
                  [HAVE_LIBXML2="yes"], [])
if test "$HAVE_LIBXML2" = "yes"; then
  LIBS="$LIBS $libxml2_LIBS"
  CFLAGS=$libxml2_CFLAGS
else
  AC_CHECK_HEADER([libxml/parser.h],
                  [HAVE_LIBXML2="yes"],
                  [AC_MSG_ERROR([could not find libxml2, libxml2 required])])
  LIBS="$LIBS -lxml2"
  CFLAGS="-I /usr/include/libxml2"
fi

dnl and do substitution in the src/Makevars.in and src/config.h
AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT()
