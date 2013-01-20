/*
 * RAgent.h
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#ifndef RAGENT_H_
#define RAGENT_H_

#include "Agent.h"
#include <Rcpp.h>

namespace RXMPP {

class RAgent: public Agent {
public:
	RAgent(const Rcpp::CharacterVector& jid, const Rcpp::CharacterVector& password, const Rcpp::IntegerVector& level);
	virtual ~RAgent();

	virtual void connectHandler(const xmpp_conn_event_t status, const int error, xmpp_stream_error_t * const stream_error, void * const userdata);

	void disConnect();

private:
	static xmpp_log_level_t getLevel(const Rcpp::IntegerVector& level);
};

} /* namespace RXMPP */
#endif /* RAGENT_H_ */
