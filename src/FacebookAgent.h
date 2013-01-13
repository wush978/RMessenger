/*
 * FacebookAgent.h
 *
 *  Created on: Jan 13, 2013
 *      Author: wush
 */

#ifndef FACEBOOKAGENT_H_
#define FACEBOOKAGENT_H_

#include <Rcpp.h>
#include <gloox/client.h>
#include <gloox/message.h>
#include <gloox/messagehandler.h>
#include "ConnListener.h"

namespace XMPPNotifier {

class FacebookAgent : public gloox::MessageHandler {
	gloox::Client* client;
	ConnListener* connListener;
public:
	FacebookAgent(const std::string& username, const std::string& password);
	virtual ~FacebookAgent();
	virtual void handleMessage(const gloox::Message& stanza, gloox::MessageSession* session = 0);
	void sendMsg(const std::string& receiver, const std::string& message_body);
};

} /* namespace XMPPNotifier */
#endif /* FACEBOOKAGENT_H_ */
