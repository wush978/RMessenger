/*
 * Agent.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#include "Log.h"
#include "Ctx.h"
#include "Connection.h"
#include "Stz.h"
#include "Agent.h"
#include <stdexcept>

namespace RXMPP {

Agent* Agent::current_agent(NULL);

Agent::Agent(const std::string& jid, const std::string& password, const xmpp_log_level_t level) {
	xmpp_initialize();
	log = new Log(level);
	ctx = new Ctx(*log);
	conn = new Connection(*ctx, jid, password);
    xmpp_connect_client(conn->get(), NULL, 0, Agent::priConnHandler, ctx->get());
}

Agent::~Agent() {
	delete conn;
	delete ctx;
	delete log;
	xmpp_shutdown();
}

void Agent::run() {
    xmpp_run(ctx->get());
}

void Agent::runOnce(const unsigned long timeout) {
	xmpp_run_once(ctx->get(), timeout);
}

void Agent::stop() {
    xmpp_stop(ctx->get());
}

void Agent::Disconnect() {
	xmpp_disconnect(conn->get());
}


void Agent::priConnHandler(xmpp_conn_t * const conn, const xmpp_conn_event_t status,
		  const int error, xmpp_stream_error_t * const stream_error,
		  void * const userdata) {
	Agent::checkCurrentAgent();
	return current_agent->connectHandler(status, error, stream_error, userdata);
}

void Agent::checkCurrentAgent() {
	if (!current_agent) {
		throw std::invalid_argument("current_agent has not been set!");
	}
}
} /* namespace RXMPP */
