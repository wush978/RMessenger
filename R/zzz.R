#'@title Level for displaying logs
#'
#'@usage parameters for \code{\link{sendXMPPMessage}} and \code{\link{facebookMessage}}
#'@aliases XMPP_LEVEL_DEBUG XMPP_LEVEL_INFO XMPP_LEVEL_WARN XMPP_LEVEL_ERROR
#'@format integer
#'@export
#'@seealso \code{\link{sendXMPPMessage}} \code{\link{facebookMessage}}
#'@useDynLib RMessenger
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
