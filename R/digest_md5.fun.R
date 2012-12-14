.md5 <- function(str, raw = FALSE) {
	digest(str, algo="md5", serialize=FALSE, raw = raw)
}

digest_md5 <- function(password, response) {
	HA1data <- paste(response$username, response$realm, password, sep=":")
	Y <- .md5(HA1data, TRUE)
	Y <- c(Y, charToRaw(paste("", response$nonce, response$cnonce, sep=":")))
	HA1 <- .md5(Y)
	HA2 <- .md5(paste("AUTHENTICATE", response[["digest-uri"]], sep=":"))
	.md5(paste(HA1, response$nonce, response$nc, response$cnonce, response$qop, HA2, sep=":"))
}