/*
 * XMPP.Module.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#include "RAgent.h"

using namespace Rcpp;

RCPP_MODULE(agent_module) {

	class_<RXMPP::RAgent>("RAgent")

	.constructor<CharacterVector, CharacterVector, IntegerVector, Function, Function, Function>()

	.field("onConnect", &RXMPP::RAgent::onConnect)
	.field("onDisconnect", &RXMPP::RAgent::onDisconnect)
	.field("onConnFail", &RXMPP::RAgent::onConnFail)

	.method("run", &RXMPP::RAgent::run)
	.method("runOnce", &RXMPP::RAgent::runOnce)
	.method("stop", &RXMPP::RAgent::stop)
	.method("Disconnect", &RXMPP::RAgent::Disconnect)
	.method("send", &RXMPP::RAgent::send)
	.method("addHandler", &RXMPP::RAgent::addHandler)

	;

}


