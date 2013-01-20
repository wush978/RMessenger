/*
 * Log.h
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#ifndef LOG_H_
#define LOG_H_

#include "XMPP.h"

namespace RXMPP {

class Log {

	xmpp_log_t* log;

public:
	Log(const xmpp_log_level_t level) : log(xmpp_get_default_logger(level)) { }
	virtual ~Log() { }

	xmpp_log_t* get() {return log;}
};

} /* namespace RXMPP */
#endif /* LOG_H_ */
