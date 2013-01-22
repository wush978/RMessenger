#'@useDynLib XMPPNotifier
.onLoad <- function(libname, pkgname) {
	.Call("RXMPP__initialize")
}


.onUnload <- function(libpath) {
	.Call("RXMPP__shutdown")
}

loadModule("agent_module", TRUE)

#'@export
XMPP_LEVEL_DEBUG <- 0L

#'@export
XMPP_LEVEL_INFO <- 1L

#'@export
XMPP_LEVEL_WARN <- 2L

#'@export
XMPP_LEVEL_ERROR <- 3L