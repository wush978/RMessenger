\name{facebookMessage}
\alias{facebookMessage}
\title{Send Facebook Message}
\usage{
  facebookMessage(username, password, fbid, message,
    log_level = XMPP_LEVEL_ERROR, timeout = 15)
}
\arguments{
  \item{username}{facebook username}

  \item{password}{password for login}

  \item{fbid}{to a string of number of fbid}

  \item{message}{message to send}

  \item{log_level}{level of displayed message. One of
  XMPP_LEVEL_DEBUG, XMPP_LEVEL_INFO, XMPP_LEVEL_WARN, and
  XMPP_LEVEL_ERROR}

  \item{timeout}{time to wait for sending message. The
  longest time for hanging is 2*timeout}
}
\description{
  Send Facebook Message
}
\examples{
facebookMessage("wush", "shouldnotbehere", "12345678", "R XMPPNotifier testing message")
}

