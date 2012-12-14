gen_string <- function(size) {
	paste(sample(c(LETTERS, letters, 0:9), size, replace=TRUE), collapse="")
}