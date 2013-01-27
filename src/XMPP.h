/*
 * XMPP.h
 *
 *  Created on: Jan 27, 2013
 *      Author: wush
 */

#include <Rcpp.h>
#include "strophe.h"

namespace RXMPP {

	void conn_handler(xmpp_conn_t * const conn, const xmpp_conn_event_t status,
		  const int error, xmpp_stream_error_t * const stream_error,
		  void * const userdata);


}

RcppExport SEXP RXMPP__sendMessage(SEXP username, SEXP password, SEXP to, SEXP message, SEXP log_level, SEXP timeout);


