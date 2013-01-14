library(XMPPNotifier)

file.remove("test.log")

fb_agent <- new("Rcpp_FacebookAgent", readline("facebook account:"), readline("password:"), "test.log")

fb_agent$sendMsg(readline("target fbid:"), readline("content:"))

readLines("test.log")