.response_encode <- function(response) {
	header <- "<response xmlns='urn:ietf:params:xml:ns:xmpp-sasl'>"
	footer <- "</response>"
	input <- ""
	for(name in names(response)) {
		if (nchar(input)) {
			input <- paste(input, paste(name, response[[name]], sep="="), sep=",")
		} else {
			input <- paste(name, response[[name]], sep="=")
		}
	}
	paste(header, base64Encode(input), footer, sep="")
}

##'authenticate to XMPP server with SASL DIGEST-MD5
##' 
##'@export
##'@param username
##'@param password
##'@param host
##'@param port
##'@return socket connection
xmpp_auth_sasl_digest_md5 <- function (username, password, host, port) {
  con <- make.socket(host=host, port=port)
  tryCatch({
  	write.socket(socket=con, string=paste('<stream:stream xmlns:stream="http://etherx.jabber.org/streams" version="1.0" xmlns="jabber:client" to="', host , '" xml:lang="en" xmlns:xml="http://www.w3.org/XML/1998/namespace">', sep=''))
  	check_retval(con, "digest-md5")
  	write.socket(con, '<auth xmlns="urn:ietf:params:xml:ns:xmpp-sasl" mechanism="DIGEST-MD5"/>')
  	retval <- check_retval(con, "challenge", is.return=TRUE)
  	challenge <- parse_challenge(retval)
  	response <- list(
  		username = username, 
  		realm = challenge$realm, 
  		nonce = challenge$nonce, 
  		cnonce = gen_string(sample(10:20, 1)), 
  		nc = "00000001",
  		qop = "auth",
  		"digest-uri" = paste("xmpp", challenge$realm, sep="/"),
  		charset = "utf-8"
  	)
  	response$response <- digest_md5(password, response)
  	write.socket(con, .response_encode(response))
  	retval <- check_retval(con, "challenge", is.return = TRUE)
  	challenge <- parse_challenge(retval)
  	if (!is.element("rspauth", names(challenge))) stop("failed in step three: there is no rspauth")
  	write.socket(con, "<response xmlns='urn:ietf:params:xml:ns:xmpp-sasl'/>")
  	check_retval(con, "success")
  	return(con)
  	# 			close.socket(con)
  }, error = function(e) {
  	close.socket(con)
  	stop(e)
  })
}
