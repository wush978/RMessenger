library(XMPPNotifier)

args <- commandArgs(TRUE)
stopifnot(length(args) == 4)


fb_agent <- new("Rcpp_FacebookAgent", args[1], args[2])

fb_agent$sendMsg(args[4], args[3])