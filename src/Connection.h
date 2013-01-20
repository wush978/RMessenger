/*
 * Connection.h
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include "XMPP.h"

namespace RXMPP {

class Connection {

	xmpp_conn_t* conn;

public:
	Connection(Ctx& ctx, const std::string& jid, const std::string& password);
	virtual ~Connection();
	xmpp_conn_t* get() { return conn; }
};

} /* namespace RXMPP */
#endif /* CONNECTION_H_ */
