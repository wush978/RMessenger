/*
 * Stz.cpp
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#include "Ctx.h"
#include "Stz.h"

namespace RXMPP {

Stz::Stz(xmpp_stanza_t* src) : stz(src) {
}

Stz::Stz(Ctx& ctx) : stz(xmpp_stanza_new(ctx.get())) {
}

Stz::Stz(Ctx& ctx, const std::string& name) : stz(xmpp_stanza_new(ctx.get())) {
	xmpp_stanza_set_name(stz, name.c_str());
}

Stz::Stz(Ctx& ctx, const std::string& name, const std::string type) : stz(xmpp_stanza_new(ctx.get())) {
	xmpp_stanza_set_name(stz, name.c_str());
	xmpp_stanza_set_type(stz, type.c_str());
}

void Stz::set(const std::string& key, const std::string& value) {
	xmpp_stanza_set_attribute(stz, key.c_str(), value.c_str());
}

void Stz::setText(const std::string& text) {
	xmpp_stanza_set_text(stz, text.c_str());
}

void Stz::addChild(Stz& child) {
	xmpp_stanza_add_child(stz, child.stz);
}

Stz* Stz::getChild(const std::string& name) {
	xmpp_stanza_t* retval_stz = xmpp_stanza_get_child_by_name(stz, name.c_str());
	return new Stz(retval_stz);
}

const std::string Stz::getText() {
	std::string retval(xmpp_stanza_get_text(stz));
	return retval;
}

Stz::~Stz() {
	xmpp_stanza_release(stz);
}

} /* namespace RXMPP */
