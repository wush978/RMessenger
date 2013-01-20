/*
 * RAgent.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#include "Connection.h"
#include "RAgent.h"

using Rcpp::as;

namespace RXMPP {

RAgent::RAgent(const Rcpp::CharacterVector& jid, const Rcpp::CharacterVector& password, const Rcpp::IntegerVector& level)
: Agent(as<std::string>(jid), as<std::string>(password), RAgent::getLevel(level)) {
}

RAgent::~RAgent() {
}

void RAgent::connectHandler(const xmpp_conn_event_t status, const int error, xmpp_stream_error_t * const stream_error, void * const userdata) {

}

void RAgent::disConnect() {
	xmpp_disconnect(conn->get());
}

xmpp_log_level_t RAgent::getLevel(const Rcpp::IntegerVector& level) {
	int lv(as<int>(level));
	xmpp_log_level_t retval;
	switch (lv) {
	case 0:
		retval = XMPP_LEVEL_DEBUG;
		break;
	case 1:
	    retval = XMPP_LEVEL_INFO;
	    break;
	case 2:
		retval = XMPP_LEVEL_WARN;
		break;
	case 3:
		retval = XMPP_LEVEL_ERROR;
		break;
	default:
		throw std::invalid_argument("wrong xmpp_log_level");
	}
	return retval;
}

} /* namespace RXMPP */
