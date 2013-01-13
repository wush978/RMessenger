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

FacebookAgent::FacebookAgent(const std::string& username, const std::string& password, std::ostream& ostream)
: client(0), os(ostream) {
	gloox::JID jid(fb(username));
	client = new Client(jid, password);
	client->setCompression(false);
	client->disableRoster();
	client->registerConnectionListener(this);
	client->registerMessageHandler(this);
	client->logInstance().registerLogHandler(FacebookAgent::log_level, FacebookAgent::log_area, this);
	if (client->compression())
		os << "Compression is On" << endl;
	else
		os << "Compression is Off" << endl;
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
