/*
 * Agent.h
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#ifndef AGENT_H_
#define AGENT_H_

#include "XMPP.h"

namespace RXMPP {

class Agent {

protected:
	Log* log;
	Ctx* ctx;
	Connection* conn;
	bool is_continue;
	static Agent* current_agent;

public:
	Agent(const std::string& jid, const std::string& password, const xmpp_log_level_t level = XMPP_LEVEL_DEBUG);
	virtual ~Agent();
	virtual void connectHandler(const xmpp_conn_event_t status,
		const int error, xmpp_stream_error_t * const stream_error,
		void * const userdata) = 0;
	virtual void run(const int timeout);
	virtual void runOnce(const unsigned long timeout = 30);
	virtual void stop();
	virtual void Disconnect();

private:
	static void priConnHandler(xmpp_conn_t * const conn, const xmpp_conn_event_t status,
			  const int error, xmpp_stream_error_t * const stream_error,
			  void * const userdata);

	static void checkCurrentAgent();
};

} /* namespace RXMPP */
#endif /* AGENT_H_ */
