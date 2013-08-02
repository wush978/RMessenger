\name{sendXMPPMessage}
\alias{sendXMPPMessage}
\title{Send Message}
\usage{
  sendXMPPMessage(jid, password, to, message,
    log_level = XMPP_LEVEL_ERROR, timeout = 15)
}
\arguments{
  \item{jid}{single length character such as
  "xxxxxx@chat.facebook.com" or "xxxxx@gmail.com"}

  \item{password}{single length character which is the
  password for \code{jid}}

  \item{to}{single length character which is the jid of
  receiver such as "-<fbid>@chat.facebook.com" or
  "xxxx@gmail.com"}

  \item{message}{multiple length character, the messages to
  \code{to}.}

  \item{log_level}{level of displayed message to R console.
  One of \code{\link{XMPP_LEVEL_DEBUG}},
  \code{\link{XMPP_LEVEL_INFO}},
  \code{\link{XMPP_LEVEL_WARN}}, and
  \code{\link{XMPP_LEVEL_ERROR}}}

  \item{timeout}{time(seconds) to wait for sending message.
  The longest time for blocking is \code{2*timeout}}
}
\description{
  This function sends a message via XMPP protocol.
}
\examples{
\dontrun{
sendXMPPMessage("xxx@chat.facebook.com", "xxx", "-12345xxx1324@chat.facebook.com",
 "test message via R")
}
}
\seealso{
  \code{\link{facebookMessage}} for sending message via
  facebook
}

