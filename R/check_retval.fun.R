check_retval <- function(con, stage, is.return=FALSE) {
	Sys.sleep(0.5)
	str <- read.socket(socket=con, maxlen=4096L)
	switch(stage, 
				 "digest-md5" = .check_retval_digest_md5(str),
				 oauth2.0 = .check_retval_oauth2.0(str),
				 challenge = .check_retval_challenge(str),
				 success = .check_retval_success(str),
				 facebook_stream = .check_retval_facebook_stream(str),
				 facebook_resource = .check_retval_facebook_resource(str), 
				 facebook_session = .check_retval_facebook_session(str)
	)
	if (is.return) {
		return(str)
	}
}

.grep_check_pattern <- function(pattern, str, error_str) {
	if (!length(grep(pattern=pattern, x=str, fixed=TRUE))) {
		stop(error_str)
	}
}

.check_retval_digest_md5 <- function(str) {
	.grep_check_pattern("DIGEST-MD5", str, paste("authentication mechanism is not supported", str))
}

.check_retval_oauth2.0 <- function(str) {
	.grep_check_pattern("X-OAUTH2", str, paste("authentication mechanism is not supported", str))
}

.check_retval_challenge <- function(str) {
	.grep_check_pattern("challenge", str, paste("failed to challenge:", str))
}

.check_retval_success <- function(str) {
	.grep_check_pattern("success", str, paste("failed to recive successful message:", str))
}

.check_retval_facebook_stream <- function(str) {
	.grep_check_pattern("stream:stream", str, paste("failed to start stream:", str))
}

.check_retval_facebook_resource <- function(str) {
	.grep_check_pattern("chat.facebook.com", str, paste("failed to start resource:", str))
}

.check_retval_facebook_session <- function(str) {
	.grep_check_pattern("session", str, paste("failed to start session:", str))
}