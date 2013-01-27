#'Send Facebook Message
#'
#'@param username facebook username
#'@param password password for login
#'@param fbid to a string of number of fbid
#'@param message message to send
#'@param log_level level of displayed message. One of XMPP_LEVEL_DEBUG, XMPP_LEVEL_INFO, XMPP_LEVEL_WARN, and XMPP_LEVEL_ERROR
#'@param timeout time to wait for sending message. The longest time for hanging is 2*timeout
#'@examples
#'# not run
#'# facebookMessage("wush", "shouldnotbehere", "12345678", "RMessenger testing message")
#'@export
facebookMessage <- function(username, password, fbid, message, log_level = XMPP_LEVEL_ERROR, timeout=15) {
	username <- paste(username, "@chat.facebook.com", sep="")
	fbid <- paste("-", fbid, "@chat.facebook.com", sep="")
	sendXMPPMessage(username, password, fbid, message, log_level, timeout)
}
