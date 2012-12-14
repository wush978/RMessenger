##' Login facebook
##' 
##' Login and send message to a facebook user with his/her fbid via XMPP
##' The authentication is based on DIGEST-MD5 authentication mechanism
##' 
##' @export
##' @param username
##' @param password
##' @return error message or TRUE
facebook_message <- function(username = "", password = "", fbid = "", message = "") {
	con <- xmpp_auth_sasl_digest_md5(username, password, "chat.facebook.com", 5222)

	write.socket(con, '<stream:stream xmlns:stream="http://etherx.jabber.org/streams" version="1.0" xmlns="jabber:client" to="chat.facebook.com" xml:lang="en" xmlns:xml="http://www.w3.org/XML/1998/namespace">')
	check_retval(con, "facebook_stream")
	
 	write.socket(con, '<iq type="set" id="3"><bind xmlns="urn:ietf:params:xml:ns:xmpp-bind"><resource>fb_xmpp_script</resource></bind></iq>')
 	check_retval(con, "facebook_resource")
	
	write.socket(con, '<iq type="set" id="4" to="chat.facebook.com"><session xmlns="urn:ietf:params:xml:ns:xmpp-session"/></iq>')
	check_retval(con, "facebook_session")
	
	write.socket(con, xmpp_message_generator(from=username, to=fbid, message))	

	close.socket(con)
}