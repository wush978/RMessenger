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
#include <map>

namespace RXMPP {

class RAgent: public Agent {

public:
	Rcpp::Function onConnect;
	Rcpp::Function onDisconnect;
	Rcpp::Function onConnFail;
	std::map<std::string, Handler*> handler_container;

public:
	RAgent(const Rcpp::CharacterVector& jid,
			const Rcpp::CharacterVector& password,
			const Rcpp::IntegerVector& level,
			Rcpp::Function on_conn,
			Rcpp::Function on_disconn,
			Rcpp::Function on_conn_fail);
	virtual ~RAgent();

	virtual void connectHandler(const xmpp_conn_event_t status, const int error, xmpp_stream_error_t * const stream_error, void * const userdata);
	virtual void addHandler(Rcpp::Function handler, const std::string& ns, const std::string& name, const std::string& type);
	//virtual void removeHandler(const std::string& ns, const std::string& name, const std::string& type);

	virtual void run();
	virtual void runOnce(const unsigned long timeout = 30);
	virtual void stop();
	virtual void Disconnect();
	virtual void send(const std::string& to, const std::string& body);


private:
	static xmpp_log_level_t getLevel(const Rcpp::IntegerVector& level);
	static const std::string getHandlerKey(const std::string& ns, const std::string& name, const std::string& type) {
		std::string retval(ns);
		retval.append(":").append(name).append(":").append(type);
		return retval;
	}
	static const char* getPtr(const std::string& src);
};

} /* namespace RXMPP */
#endif /* RAGENT_H_ */
