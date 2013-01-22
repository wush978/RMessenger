/*
 * Handler.h
 *
 *  Created on: Jan 22, 2013
 *      Author: wush
 */

#ifndef HANDLER_H_
#define HANDLER_H_

#include <Rcpp.h>
#include "XMPP.h"

namespace RXMPP {

class Handler {
	Rcpp::Function f;
public:
	Handler(Rcpp::Function f_src);
	virtual ~Handler();
	int call(xmpp_stanza_t * const stanza, void * const userdata);
	static int Wrapper(xmpp_conn_t * const conn,
		     xmpp_stanza_t * const stanza,
		     void * const userdata);

};

} /* namespace RXMPP */

#endif /* HANDLER_H_ */
