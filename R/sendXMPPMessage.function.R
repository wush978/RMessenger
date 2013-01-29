#'@title Send Message
#'
#'@description This function sends a message via XMPP protocol.
#'
#'@param jid single length character such as "xxxxxx@@chat.facebook.com" or "xxxxx@@gmail.com"
#'@param password single length character which is the password for \code{jid}
#'@param to single length character which is the jid of receiver such as "-<fbid>@@chat.facebook.com" or "xxxx@@gmail.com"
#'@param message multiple length character, the messages to \code{to}.
#'@param log_level level of displayed message to R console. One of \code{\link{XMPP_LEVEL_DEBUG}}, 
#'  \code{\link{XMPP_LEVEL_INFO}}, \code{\link{XMPP_LEVEL_WARN}}, and \code{\link{XMPP_LEVEL_ERROR}}
#'@param timeout time(seconds) to wait for sending message. The longest time for blocking is \code{2*timeout}
#'@examples
#'# not run
#'# sendXMPPMessage("xxx@@chat.facebook.com", "xxx", "-12345xxx1324@@chat.facebook.com", "test message via R")
#'@export
#'@seealso \code{\link{facebookMessage}} for sending message via facebook
sendXMPPMessage <- function(jid, password, to, message, log_level = XMPP_LEVEL_ERROR, timeout = 15) {
	.Call("RXMPP__sendMessage", jid, password, to, enc2utf8(message), log_level, timeout);
}
