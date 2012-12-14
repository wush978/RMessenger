\name{facebook_message}
\alias{facebook_message}
\title{Login facebook}
\usage{
  facebook_message(username = "", password = "", fbid = "",
    message = "")
}
\arguments{
  \item{username}{}

  \item{password}{}
}
\value{
  error message or TRUE
}
\description{
  Login and send message to a facebook user with his/her
  fbid via XMPP The authentication is based on DIGEST-MD5
  authentication mechanism
}

