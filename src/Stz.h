/*
 * Stz.h
 *
 *  Created on: Jan 21, 2013
 *      Author: wush
 */

#ifndef STZ_H_
#define STZ_H_

#include "XMPP.h"

namespace RXMPP {

class Stz {
	xmpp_stanza_t* stz;
public:
	Stz(xmpp_stanza_t* src);
	Stz(Ctx&);
	Stz(Ctx&, const std::string& name);
	Stz(Ctx&, const std::string& name, const std::string type);
	xmpp_stanza_t* get() { return stz; }
	void set(const std::string& key, const std::string& value);
	void setText(const std::string& text);
	void addChild(Stz&);
	Stz* getChild(const std::string& name);
	const std::string getText();
	virtual ~Stz();
private:
	Stz(Stz&);
	void operator=(Stz&);
};

} /* namespace RXMPP */
#endif /* STZ_H_ */
