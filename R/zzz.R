#'@useDynLib XMPPNotifier
loadModule("agent_module", TRUE)


#'Level for displaying message
#'
#'@export
XMPP_LEVEL_DEBUG <- 0L

#'Level for displaying message
#'
#'@export
XMPP_LEVEL_INFO <- 1L

#'Level for displaying message
#'
#'@export
XMPP_LEVEL_WARN <- 2L

#'Level for displaying message
#'
#'@export
XMPP_LEVEL_ERROR <- 3L