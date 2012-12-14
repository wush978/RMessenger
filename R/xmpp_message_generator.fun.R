##' Generate xmpp message
##' 
##' @export
##' @param from
##' @param to
##' @param message
##' @param subject
xmpp_message_generator <- function(from, to, message) {
	paste('<message from="',from,'@chat.facebook.com" to="-',to,'@chat.facebook.com" type="chat"><body>',message,'</body></message>', sep='')
}