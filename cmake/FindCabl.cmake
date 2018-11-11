message (STATUS "Checking for Cabl...")
find_path(CABL_INCLUDE_DIRS
		cabl.h
	PATHS
		/usr/include
		/usr/local/include
	PATH_SUFFIXES
		cabl
)
find_library(CABL_LIBRARIES
	NAMES
		cabl
	PATHS
		/usr/lib
		/usr/local/lib
)

if(CABL_INCLUDE_DIRS AND CABL_LIBRARIES)
	mark_as_advanced(
		CABL_INCLUDE_DIRS
		CABL_LIBRARIES
	)

	set(CABL_FOUND true)
	message (STATUS "Found: Cabl")
	message(STATUS " - Includes: ${CABL_INCLUDE_DIRS}")
	message(STATUS " - Libraries: ${CABL_LIBRARIES}")
else()
	set(CABL_FOUND false)
	message (FATAL_ERROR "NOT Found: Cabl")
endif()
