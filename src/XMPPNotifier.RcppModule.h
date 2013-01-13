/*
 * XMPPNotifier.RcppModule.h
 *
 *  Created on: Jan 13, 2013
 *      Author: wush
 */

#ifndef XMPPNOTIFIER_RCPPMODULE_H_
#define XMPPNOTIFIER_RCPPMODULE_H_

RCPP_MODULE(FacebookAgent) {
	using namespace Rcpp;

	class_<XMPPNotifier::FacebookAgent>("FacebookAgent")

	.constructor<std::string, std::string, std::string>()

	.method( "sendMsg", &XMPPNotifier::FacebookAgent::sendMsg )
	;
}

#endif /* XMPPNOTIFIER_RCPPMODULE_H_ */
