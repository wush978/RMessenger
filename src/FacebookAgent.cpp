/*
 * FacebookAgent.cpp
 *
 *  Created on: Jan 13, 2013
 *      Author: wush
 */

#include "FacebookAgent.h"

using namespace gloox;
using std::endl;

namespace XMPPNotifier {

const LogLevel FacebookAgent::log_level = LogLevelDebug;
const int FacebookAgent::log_area = LogAreaAll;

ConnectionError TestConnectionTCPClient::connect() {
	m_logInstance.dbg(LogAreaClassConnectionTCPClient, "TestConnectionTCPClient::connect");

    m_sendMutex.lock();
// FIXME CHECKME
    if( !m_handler )
    {
      m_sendMutex.unlock();
      return ConnNotConnected;
    }

    if( m_socket >= 0 && m_state > StateDisconnected )
    {
      m_sendMutex.unlock();
      return ConnNoError;
    }

    m_state = StateConnecting;

    if( m_socket < 0 )
    {
      if( m_port == -1 )
        m_socket = DNS::connect( m_server, m_logInstance );
      else
        m_socket = DNS::connect( m_server, m_port, m_logInstance );
    }

    m_sendMutex.unlock();

    if( m_socket < 0 )
    {
      switch( m_socket )
      {
        case -ConnConnectionRefused:
          m_logInstance.err( LogAreaClassConnectionTCPClient,
                             m_server + ": connection refused" );
          break;
        case -ConnDnsError:
          m_logInstance.err( LogAreaClassConnectionTCPClient,
                             m_server + ": host not found" );
          break;
        default:
          m_logInstance.err( LogAreaClassConnectionTCPClient,
                             "Unknown error condition" );
          break;
      }
      m_handler->handleDisconnect( this, (ConnectionError)-m_socket );
      return (ConnectionError)-m_socket;
    }
    else
    {
      m_logInstance.dbg(LogAreaClassConnectionTCPClient, "m_state = StateConnected");
      m_state = StateConnected;
    }

    m_cancel = false;
    m_logInstance.dbg(LogAreaClassConnectionTCPClient, typeid(*m_handler).name());
	m_handler->handleConnect( this );
    return ConnNoError;
}

FacebookAgent::FacebookAgent(const std::string& username, const std::string& password, std::ostream& ostream)
: client(0), os(ostream) {
	gloox::JID jid(fb(username));
	client = new TestClient(jid, password);
	client->setCompression(false);
	client->disableRoster();
	client->setConnectionImpl(new TestConnectionTCPClient(client, client->logInstance(), client->server(), client->port()));
	client->registerConnectionListener(this);
	client->registerMessageHandler(this);
	client->logInstance().registerLogHandler(FacebookAgent::log_level, FacebookAgent::log_area, this);
}

FacebookAgent::~FacebookAgent() {
	if (client) {
		delete client;
	}
}

/* exposed R functions */

void FacebookAgent::sendMsg(const std::string& username, const std::string& message) {
	target_jid = JID(fb(username));
	this->message.assign(message);
	client->connect(true);
}


/* LogHandler */

void FacebookAgent::handleLog( gloox::LogLevel level, gloox::LogArea area, const std::string& message ) {
	os << "[log]" << message << endl;
}

/* private methods */

const std::string FacebookAgent::fb(const std::string& src) {
	std::string retval(src);
	retval.append("@chat.facebook.com");
	return retval;
}

} /* namespace XMPPNotifier */
