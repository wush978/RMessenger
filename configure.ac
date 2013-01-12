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
          
     dnl and do substitution in the src/Makevars.in and src/config.h
     AC_CONFIG_SUBDIRS([src/gloox-1.0])
     AC_CONFIG_FILES([src/Makevars])
     AC_OUTPUT

