/*
 * XMPP.init.c
 *
 *  Created on: Jan 20, 2013
 *      Author: wush
 */

#include <R.h>
#include <Rdefines.h>
#include <strophe.h>

SEXP RXMPP__initialize() {
	xmpp_initialize();
	return R_NilValue;
}

SEXP RXMPP__shutdown() {
	xmpp_shutdown();
	return R_NilValue;
}
