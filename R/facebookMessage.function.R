#   Copyright (C) 2013 Wush Wu
#
#
#   This software is provided AS-IS with no warranty, either express or
#   implied.
# 
#   This software is distributed under license and may not be copied,
#   modified or distributed except as expressly authorized under the
#   terms of the license contained in the file LICENSE.txt in this
#   distribution.

	
#'@title Send Facebook Message
#'
#'@description A helper to send message via facebook
#'
#'@param username facebook username
#'@param password password for login
#'@param fbid to a string of number of fbid
#'@param message message to send
#'@param log_level level of displayed message. One of \code{\link{XMPP_LEVEL_DEBUG}}, \code{\link{XMPP_LEVEL_INFO}}, \code{\link{XMPP_LEVEL_WARN}}, and \code{\link{XMPP_LEVEL_ERROR}}
#'@param timeout time to wait for sending message. The longest time for hanging is 2*timeout
#'@examples
#'\dontrun{
#'facebookMessage("wush", "shouldnotbehere", "12345678", "RMessenger testing message")
#'}
#'@export
#'@seealso \code{\link{sendXMPPMessage}}
facebookMessage <- function(username, password, fbid, message, log_level = XMPP_LEVEL_ERROR, timeout=15) {
	username <- paste(username, "@chat.facebook.com", sep="")
	fbid <- paste("-", fbid, "@chat.facebook.com", sep="")
	sendXMPPMessage(username, password, fbid, message, log_level, timeout)
}
