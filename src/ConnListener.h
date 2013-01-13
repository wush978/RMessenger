/*
 * ConnListener.h
 *
 *  Created on: Jan 13, 2013
 *      Author: wush
 *
 *  Reference: https://github.com/knatten/blog.knatten.org/blob/master/gloox/bot.cpp
 */

#ifndef CONNLISTENER_H_
#define CONNLISTENER_H_

#include <Rcpp.h>
#include <gloox/connectionlistener.h>
#include <gloox/clientbase.h>

namespace XMPPNotifier {

class ConnListener : public gloox::ConnectionListener {
public:
	virtual void onConnect();
	virtual void onDisconnect(gloox::ConnectionError e);
	virtual bool onTLSConnect(const gloox::CertInfo& info);
};

} /* namespace XMPPNotifier */
#endif /* CONNLISTENER_H_ */
