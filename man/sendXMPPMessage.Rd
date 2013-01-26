\name{sendXMPPMessage}
\alias{sendXMPPMessage}
\title{Send XMPP Message}
\usage{
  sendXMPPMessage(jid, password, to, message,
    log_level = XMPP_LEVEL_ERROR, timeout = 15)
}
\arguments{
  \item{jid}{string such as "xxxxxx@chat.facebook.com"}

  \item{password}{password for login}

  \item{to}{"-<fbid>@chat.facebook.com"}

  \item{message}{message to send}

  \item{log_level}{level of displayed message. One of
  XMPP_LEVEL_DEBUG, XMPP_LEVEL_INFO, XMPP_LEVEL_WARN, and
  XMPP_LEVEL_ERROR}

  \item{timeout}{time to wait for sending message. The
  longest time for hanging is 2*timeout}
}
\description{
  Send XMPP Message
}
\examples{
sendXMPPMessage("xxx@chat.facebook.com", "xxx", "-12345xxx1324@chat.facebook.com", "test message via R")
}

