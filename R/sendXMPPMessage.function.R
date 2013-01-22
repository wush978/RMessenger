#'Send XMPP Message
#'
#'@param jid string such as "xxxxxx@@chat.facebook.com"
#'@param password password for login
#'@param to "-<fbid>@@chat.facebook.com"
#'@param message message to send
#'@param log_level level of displayed message. One of XMPP_LEVEL_DEBUG, XMPP_LEVEL_INFO, XMPP_LEVEL_WARN, and XMPP_LEVEL_ERROR
#'@examples
#'sendXMPPMessage("xxx@@chat.facebook.com", "xxx", "-12345xxx1324@@chat.facebook.com", "test message via R")
#'@export
#'
sendXMPPMessage <- function(jid, password, to, message, log_level = XMPP_LEVEL_ERROR) {
	agent <- new("Rcpp_RAgent", jid, password, log_level, 
							 function() { 
							 		agent$send(to, message)
							 }, function() {
							 		agent$stop()
							 		agent$Disconnect()
							 }, function() {
							 		agent$stop()
							 		agent$Disconnect()
							 })
	agent$addHandler( function() {
		agent$stop()
	}, "", "iq", "set")
	agent$run()
	agent$Disconnect()
}