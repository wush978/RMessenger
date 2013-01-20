/*
 * Agent.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#include "Log.h"
#include "Ctx.h"
#include "Connection.h"
#include "Agent.h"
#include <stdexcept>

namespace RXMPP {

Agent* Agent::current_agent(NULL);

Agent::Agent(const std::string& jid, const std::string& password, const xmpp_log_level_t level)
: log(new Log(level)), ctx(new Ctx(*log)), conn(new Connection(*ctx, jid, password)) {
	Agent::current_agent = this;
    xmpp_connect_client(conn->get(), NULL, 0, Agent::priConnHandler, ctx->get());
    xmpp_run(ctx->get());
}

Agent::~Agent() {
	delete conn;
	delete ctx;
	delete log;
}

void Agent::priConnHandler(xmpp_conn_t * const conn, const xmpp_conn_event_t status,
		  const int error, xmpp_stream_error_t * const stream_error,
		  void * const userdata) {
	if (!current_agent) {
		throw std::invalid_argument("current_agent has not been set!");
	}
	return current_agent->connectHandler(status, error, stream_error, userdata);
}


} /* namespace RXMPP */
