parse_challenge <- function(str) {
	xml <- xmlParse(file=str, asText=TRUE)
	xml_root <- xmlRoot(xml)
	retval <- parse_str(base64Decode(getChildrenStrings(xml_root)))
}