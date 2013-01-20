/*
 * Ctx.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#include "Log.h"
#include "Ctx.h"

namespace RXMPP {

Ctx::Ctx(Log& log) : ctx(xmpp_ctx_new(NULL, log.get())) {
}

Ctx::~Ctx() {
    xmpp_ctx_free(ctx);
}

} /* namespace RXMPP */
