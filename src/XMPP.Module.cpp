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

	.constructor<CharacterVector, CharacterVector, IntegerVector>()

	.method("disconnect", &RXMPP::RAgent::disConnect)

	;

}


