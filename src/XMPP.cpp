/*
 * XMPP.cpp
 *
 *  Created on: Jan 27, 2013
 *      Author: wush
 */

#include <ctime>
#include <memory>
#include "XMPP.h"

using namespace Rcpp;
typedef std::vector<std::string> StrVec;

namespace RXMPP {

	struct Context {
		xmpp_ctx_t* ctx;
		Context(const xmpp_log_level_t log_level) : ctx(xmpp_ctx_new(NULL, xmpp_get_default_logger(log_level))) { }
		~Context() { xmpp_ctx_free(ctx); }
	};

	struct Connection {
		xmpp_conn_t* conn;
		Connection(Context& ctx) : conn(xmpp_conn_new(ctx.ctx)) { }
		Connection(xmpp_ctx_t* ctx) : conn(xmpp_conn_new(ctx)) { }
		~Connection() {xmpp_conn_release(conn);}
	};

	struct Stanza {
		xmpp_stanza_t* stz;
		Stanza(xmpp_ctx_t* ctx) : stz(xmpp_stanza_new(ctx)) { }
		~Stanza() { xmpp_stanza_release(stz); }
	};

	struct UserData {
		xmpp_ctx_t *ctx;
		StrVec* message_vec;
		const char* to;
		bool is_connect;
		bool is_send;
	};


	void conn_handler(xmpp_conn_t * const conn, const xmpp_conn_event_t status,
			  const int error, xmpp_stream_error_t * const stream_error,
			  void * const userdata)
	{
	    UserData* data = reinterpret_cast<UserData *>(userdata);
		if (status == XMPP_CONN_CONNECT) {
			data->is_connect = true;
			return;
		}
		else {
			xmpp_stop(data->ctx);
			return;
		}
	}

	void send_message(Context& ctx, Connection& conn, UserData& data) {
		if (data.is_send || !data.is_connect) {
			throw std::logic_error("data should not be sent and connection should be establish");
		}
		const StrVec& message_vec(*(data.message_vec));
		for(StrVec::const_iterator i = message_vec.begin();i != message_vec.end();i++) {
			std::auto_ptr<Stanza>
				msg(new Stanza(ctx.ctx)),
				body(new Stanza(ctx.ctx)),
				text(new Stanza(ctx.ctx));
			xmpp_stanza_set_name(msg->stz, "message");
			xmpp_stanza_set_type(msg->stz, "chat");
			xmpp_stanza_set_attribute(msg->stz, "to", data.to);
			xmpp_stanza_set_name(body->stz, "body");
			xmpp_stanza_set_text(text->stz, i->c_str());
			xmpp_stanza_add_child(body->stz, text->stz);
			xmpp_stanza_add_child(msg->stz, body->stz);
			xmpp_send(conn.conn, msg->stz);
		}
		data.is_send = true;
	}
}

SEXP RXMPP__sendMessage(SEXP Rusername, SEXP Rpassword, SEXP Rto, SEXP Rmessage, SEXP Rlog_level, SEXP Rtimeout) {
	BEGIN_RCPP
	xmpp_initialize();

	xmpp_log_level_t log_level;
	switch (as<int>(Rlog_level)) {
	case 0:
		log_level = XMPP_LEVEL_DEBUG;
		break;
	case 1:
		log_level = XMPP_LEVEL_INFO;
		break;
	case 2:
		log_level = XMPP_LEVEL_WARN;
		break;
	case 3:
		log_level = XMPP_LEVEL_ERROR;
		break;
	default:
		throw std::invalid_argument("log_level out of range(one of {0L, 1L, 2L, 3L})");
	}
	std::string
		username(as<std::string>(Rusername)),
		password(as<std::string>(Rpassword)),
		to(as<std::string>(Rto));
	StrVec message(as<StrVec>(Rmessage));
	int timeout (as<int>(Rtimeout));
	const unsigned long cast_timeout = timeout;

	// initialization
	std::auto_ptr<RXMPP::Context> ctx(new RXMPP::Context(log_level));
	if (ctx->ctx == NULL)
		throw std::runtime_error("xmpp_ctx_new failed");
	std::auto_ptr<RXMPP::Connection> conn(new RXMPP::Connection(ctx->ctx));
	if (conn->conn == NULL) {
		throw std::runtime_error("xmpp_conn_new failed");
	}

	// setting username/password
	xmpp_conn_set_jid(conn->conn, username.c_str());
	xmpp_conn_set_pass(conn->conn, password.c_str());
	RXMPP::UserData data;
	data.ctx = ctx->ctx;
	data.message_vec = &message;
	data.to = to.c_str();
	data.is_connect = false;
	data.is_send = false;
	xmpp_connect_client(conn->conn, NULL, 0, &RXMPP::conn_handler, &data);

	time_t start_time = time(NULL);
	time_t current_time = time(NULL);
	while(difftime(current_time, start_time) < timeout) {
		xmpp_run_once(ctx->ctx, cast_timeout);
		current_time = time(NULL);
		if (!data.is_connect)
			continue;
		if (!data.is_send)
			RXMPP::send_message(*ctx.get(), *conn.get(), data);
	}
	xmpp_shutdown();
	END_RCPP
}

