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


#'@title Level for displaying logs
#'
#'@usage parameters for \code{\link{sendXMPPMessage}} and \code{\link{facebookMessage}}
#'@aliases XMPP_LEVEL_DEBUG XMPP_LEVEL_INFO XMPP_LEVEL_WARN XMPP_LEVEL_ERROR
#'@format integer
#'@export
#'@seealso \code{\link{sendXMPPMessage}} \code{\link{facebookMessage}}
#'@useDynLib RMessenger
#'@import Rcpp
#'@import methods
XMPP_LEVEL_DEBUG <- 0L

#'@export
XMPP_LEVEL_INFO <- 1L

#'@export
XMPP_LEVEL_WARN <- 2L

#'@export
XMPP_LEVEL_ERROR <- 3L
