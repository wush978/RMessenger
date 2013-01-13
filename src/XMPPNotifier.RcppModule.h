/*
 * XMPPNotifier.RcppModule.h
 *
 *  Created on: Jan 13, 2013
 *      Author: wush
 */

#ifndef XMPPNOTIFIER_RCPPMODULE_H_
#define XMPPNOTIFIER_RCPPMODULE_H_

class RFacebookAgent : public XMPPNotifier::FacebookAgent {
public:
	RFacebookAgent(const std::string& username, const std::string& password) :
	XMPPNotifier::FacebookAgent(username, password, Rcpp::Rcout) { }
	virtual ~RFacebookAgent() { }
	void sendMsg(const std::string& username, const std::string& message) {
		XMPPNotifier::FacebookAgent::sendMsg(username, message);
	}
};

RCPP_MODULE(FacebookAgent) {
	using namespace Rcpp;

	class_<RFacebookAgent>("FacebookAgent")

	.constructor<std::string, std::string>()

	.method( "sendMsg", &RFacebookAgent::sendMsg )
	;
}

#endif /* XMPPNOTIFIER_RCPPMODULE_H_ */
