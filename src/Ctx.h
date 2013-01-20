/*
 * Ctx.h
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#ifndef CTX_H_
#define CTX_H_

#include "XMPP.h"

namespace RXMPP {

class Ctx {

	xmpp_ctx_t* ctx;

public:
	Ctx(Log&);
	virtual ~Ctx();

	xmpp_ctx_t* get() { return ctx; }
};

} /* namespace RXMPP */
#endif /* CTX_H_ */
