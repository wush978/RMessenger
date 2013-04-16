/*
 * XMPP.h
 *
 *  Created on: Jan 27, 2013
 *  Copyright (C) 2013 Wush Wu
 *
**  This software is provided AS-IS with no warranty, either express or
**  implied.
**
**  This software is distributed under license and may not be copied,
**  modified or distributed except as expressly authorized under the
**  terms of the license contained in the file LICENSE.txt in this
**  distribution.
*/

#include <Rcpp.h>
#include "strophe.h"

namespace RXMPP {

	void conn_handler(xmpp_conn_t * const conn, const xmpp_conn_event_t status,
		  const int error, xmpp_stream_error_t * const stream_error,
		  void * const userdata);


}

RcppExport SEXP RXMPP__sendMessage(SEXP username, SEXP password, SEXP to, SEXP message, SEXP log_level, SEXP timeout);


