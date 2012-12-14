parse_str <- function(str) {
	retval1 <- strsplit(str, split=",", fixed=TRUE)[[1]]
	retval <- list()
	for(retval1_element in retval1) {
		temp <- strsplit(retval1_element, split="=", fixed=TRUE)[[1]]
		temp[2] <- gsub('"', '', temp[2], fixed=TRUE)
		retval[[temp[1]]] <- temp[2]
	}
	retval
}