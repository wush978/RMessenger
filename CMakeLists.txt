cmake_minimum_required(VERSION 2.8)
project(RMessenger)
find_package(LibR)
if(${LIBR_FOUND})
else()
	message(FATAL_ERROR "No R...")
endif()
message(STATUS ${CMAKE_SOURCE_DIR})
add_custom_target(RMessenger ALL
	COMMAND find ${CMAKE_SOURCE_DIR} -name "*.o" -exec rm "{}" "\;"
	COMMAND find ${CMAKE_SOURCE_DIR} -name "*.so" -exec rm "{}" "\;"
	COMMAND ${LIBR_EXECUTABLE} --slave -e "\"stopifnot(require(roxygen2));roxygenize('${CMAKE_SOURCE_DIR}',roclets=c('rd','collate','namespace'))\""
	COMMAND ${LIBR_EXECUTABLE} CMD INSTALL "${CMAKE_SOURCE_DIR}")

