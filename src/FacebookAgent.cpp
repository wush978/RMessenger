/*
 * FacebookAgent.cpp
 *
 *  Created on: Jan 13, 2013
 *      Author: wush
 */

#include "FacebookAgent.h"

using std::ostream;
using gloox::Message;
using gloox::Client;
using gloox::JID;

//ostream& operator<<(ostream& os, Message::MessageType type) {
//    switch (type) {
//        case Message::Chat:
//            os << "Chat";
//            break;
//        case Message::Error:
//            os << "Error";
//            break;
//        case Message::Groupchat:
//            os << "Groupchat";
//            break;
//        case Message::Headline:
//            os << "Headline";
//            break;
//        case Message::Normal:
//            os << "Normal";
//            break;
//        case Message::Invalid:
//            os << "Invalid";
//            break;
//        default:
//            os << "unknown type";
//            break;
//    }
//    return os;
//}
//
//ostream& operator<<(ostream& os, const Message& stanza) {
//    os << "type:'" << stanza.subtype() <<  "' from:'" << stanza.from().full() << "' body:'" << stanza.body() << "'";
//    return os;
//}

namespace XMPPNotifier {

FacebookAgent::FacebookAgent(const std::string& username, const std::string& password) {
	std::string fbusername(username);
	fbusername.append("@chat.facebook.com");
	JID jid(fbusername);
    client = new Client( jid, "botpwd" );
    connListener = new ConnListener();
    client->registerMessageHandler( this );
    client->registerConnectionListener(connListener);
    client->connect(true);

}

FacebookAgent::~FacebookAgent() {
    delete client;
    delete connListener;
}

void FacebookAgent::handleMessage(const gloox::Message& stanza, gloox::MessageSession* session) {
}

} /* namespace XMPPNotifier */
