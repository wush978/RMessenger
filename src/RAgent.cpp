/*
 * RAgent.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#include <memory>
#include "Connection.h"
#include "RAgent.h"
#include "Stz.h"
#include "Handler.h"

using Rcpp::as;
using Rcpp::Function;
using Rcpp::Rcout;
using std::endl;
using std::auto_ptr;

namespace RXMPP {

RAgent::RAgent(
		const Rcpp::CharacterVector& jid,
		const Rcpp::CharacterVector& password,
		const Rcpp::IntegerVector& level,
		Function on_conn,
		Function on_disconn,
		Function on_conn_fail)
: Agent(as<std::string>(jid), as<std::string>(password), RAgent::getLevel(level)),
  onConnect(on_conn), onDisconnect(on_disconn), onConnFail(on_conn_fail) {
	Agent::current_agent = this;
}

RAgent::~RAgent() {
}

void RAgent::connectHandler(const xmpp_conn_event_t status, const int error, xmpp_stream_error_t * const stream_error, void * const userdata) {
	switch (status) {
	case XMPP_CONN_CONNECT:
		this->onConnect();
		break;
	case XMPP_CONN_DISCONNECT:
		this->onDisconnect();
		break;
	case XMPP_CONN_FAIL:
		this->onConnFail();
		break;
	}
}

void RAgent::addHandler(Rcpp::Function handler, const std::string& ns, const std::string& name, const std::string& type) {
	std::string key(RAgent::getHandlerKey(ns, name, type));
	if (handler_container.find(key) != handler_container.end()) {
		throw std::logic_error("duplicated set handler");
	}
	Handler* retval(new Handler(handler));
	handler_container[key] = retval;
	const char
		*pns(RAgent::getPtr(ns)),
		*pname(RAgent::getPtr(name)),
		*ptype(RAgent::getPtr(type));

	xmpp_handler_add(this->conn->get(),
			Handler::Wrapper,
			pns,
			pname,
			ptype,
			retval);
}

void RAgent::run(const int timeout) {
	return Agent::run(timeout);
}

void RAgent::runOnce(const unsigned long timeout) {
	return Agent::runOnce();
}

void RAgent::stop() {
	return Agent::stop();
}

void RAgent::Disconnect() {
	return Agent::Disconnect();
}

void RAgent::send(const std::string& to, const std::string& body_msg) {
	Stz reply(*ctx, "message", "chat"), body(*ctx, "body"), text(*ctx);
	reply.set("to", to.c_str());
	text.setText(body_msg);
	body.addChild(text);
	reply.addChild(body);
	xmpp_send(conn->get(), reply.get());
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

const char* RAgent::getPtr(const std::string& src) {
	if (src.size())
		return src.c_str();
	else
		return NULL;
}

} /* namespace RXMPP */
