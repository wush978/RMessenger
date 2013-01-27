#'Send XMPP Message
#'
#'@param jid string such as "xxxxxx@@chat.facebook.com"
#'@param password password for login
#'@param to "-<fbid>@@chat.facebook.com"
#'@param message message to send
#'@param log_level level of displayed message. One of XMPP_LEVEL_DEBUG, XMPP_LEVEL_INFO, XMPP_LEVEL_WARN, and XMPP_LEVEL_ERROR
#'@param timeout time to wait for sending message. The longest time for hanging is 2*timeout
#'@examples
#'sendXMPPMessage("xxx@@chat.facebook.com", "xxx", "-12345xxx1324@@chat.facebook.com", "test message via R")
#'@export
#'
sendXMPPMessage <- function(jid, password, to, message, log_level = XMPP_LEVEL_ERROR, timeout = 15) {
	.Call("RXMPP__sendMessage", jid, password, to, enc2utf8(message), log_level, timeout);
}
