library(XMPPNotifier)

if (!exists("argv")) {
	argv <- commandargv(TRUE)
}
stopifnot(length(argv) == 4)


fb_agent <- new("Rcpp_FacebookAgent", argv[1], argv[2])

fb_agent$sendMsg(argv[4], argv[3])