/*
 * Connection.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#include "Ctx.h"
#include "Connection.h"

namespace RXMPP {

Connection::Connection(Ctx& ctx, const std::string& jid, const std::string& password)
: conn(xmpp_conn_new(ctx.get())) {
    xmpp_conn_set_jid(conn, jid.c_str());
    xmpp_conn_set_pass(conn, password.c_str());
}

Connection::~Connection() {
	xmpp_conn_release(conn);
}

} /* namespace RXMPP */
