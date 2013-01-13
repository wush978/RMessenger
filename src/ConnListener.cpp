/*
 * ConnListener.cpp
 *
 *  Created on: Jan 13, 2013
 *      Author: wush
 */

#include "ConnListener.h"

namespace XMPPNotifier {

void ConnListener::onConnect() {
	Rcpp::Rcout << "ConnListener::onConnect()" << std::endl;
}

void ConnListener::onDisconnect(gloox::ConnectionError e) {
	Rcpp::Rcout << "ConnListener::onDisconnect() " << e << std::endl;
	throw e;
}

bool ConnListener::onTLSConnect(const gloox::CertInfo& info) {
	Rcpp::Rcout << "ConnListener::onTLSConnect()" << std::endl;
	return true;
}

} /* namespace XMPPNotifier */
