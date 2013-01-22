/*
 * Handler.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: wush
 */

#include "Handler.h"

using Rcpp::Function;

namespace RXMPP {

Handler::Handler(Function f_src) : f(f_src) {
}

Handler::~Handler() {
}

int Handler::call(xmpp_stanza_t * const stanza, void * const userdata) {
	f();
	return 1;
}

int Handler::Wrapper(xmpp_conn_t * const conn,
	     xmpp_stanza_t * const stanza,
	     void * const userdata) {
	Handler* h = reinterpret_cast<Handler*>(userdata);
	return h->call(stanza, userdata);
}



} /* namespace RXMPP */

