#'@useDynLib XMPPNotifier
.onLoad <- function(libname, pkgname) {
	.Call("RXMPP__initialize")
}


.onUnload <- function(libpath) {
	.Call("RXMPP__shutdown")
}