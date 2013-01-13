/*
 * FacebookAgent.h
 *
 *  Created on: Jan 13, 2013
 *      Author: wush
 */

#ifndef FACEBOOKAGENT_H_
#define FACEBOOKAGENT_H_

#include <map>
#include <iostream>
#include <gloox/client.h>
#include <gloox/message.h>
#include <gloox/messagehandler.h>
#include <gloox/messagesessionhandler.h>
#include <gloox/loghandler.h>
#include <gloox/connectionlistener.h>
#include <gloox/rostermanager.h>
#include <gloox/iqhandler.h>

namespace XMPPNotifier {

class FacebookAgent :
public gloox::LogHandler, gloox::ConnectionListener, gloox::MessageHandler {

	gloox::Client* client;
	gloox::JID target_jid;
	std::string message;

protected:
	std::ostream& os;

public:
	/**
	 * Constructor, login with username/password
	 */
	FacebookAgent(const std::string& username, const std::string& password, std::ostream& ostream);

	virtual ~FacebookAgent();

	/* exposed R functions */

	void sendMsg(const std::string& username, const std::string& message);

	/* LogHandler */

	virtual void handleLog( gloox::LogLevel level, gloox::LogArea area, const std::string& message );

	/* ConnectionListener */

	virtual void onConnect() {
		os << "onConnect" << std::endl;
	}

	virtual void onDisconnect(gloox::ConnectionError e) {
		if (e == gloox::ConnAuthenticationFailed) {
			os << "authError:" << client->authError() << std::endl;
		}
		os << "connError:" << e << std::endl;
	}

	virtual bool onTLSConnect( const gloox::CertInfo& info ) {
		os << "onTLSConnect" << std::endl;
		return true;
	}

	virtual void onResourceBind( const std::string& resource ) {
		os << resource << std::endl;
	}
	/* MessageHandler */

	virtual void handleMessage( const gloox::Message& stanza, gloox::MessageSession* session = 0 ) {
		gloox::Message msg(stanza.subtype(), stanza.from(), "Tell me more about " + stanza.body());
		client->send(msg);
	}

private:
	/* close copy constructor and assignment */
	FacebookAgent(const FacebookAgent&);
	void operator=(const FacebookAgent&);

	const static gloox::LogLevel log_level;
	const static int log_area;

	/* facebook server */
	const std::string fb(const std::string& src);

	/* name query */
	const std::string getDisplayName(const gloox::JID &jid) {
		return jid.bare();
	}
};

} /* namespace XMPPNotifier */
#endif /* FACEBOOKAGENT_H_ */
