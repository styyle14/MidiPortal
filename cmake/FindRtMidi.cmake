message (STATUS "Checking for RtMidi...")
find_path(RTMIDI_INCLUDE_DIRS
		RtMidi.h
	PATHS
		/usr/include
		/usr/include/rtmidi
		/usr/local/include
		/usr/local/include/rtmidi
)
find_library(RTMIDI_LIBRARIES
	NAMES
		rtmidi
	PATHS
		/usr/lib
		/usr/local/lib
)

if(RTMIDI_INCLUDE_DIRS AND RTMIDI_LIBRARIES)
	mark_as_advanced(
		RTMIDI_INCLUDE_DIRS
		RTMIDI_LIBRARIES
	)

	set(RTMIDI_FOUND true)
	message (STATUS "Found: RtMidi")
	message(STATUS " - Includes: ${RTMIDI_INCLUDE_DIRS}")
	message(STATUS " - Libraries: ${RTMIDI_LIBRARIES}")
else()
	set(RTMIDI_FOUND false)
	message (FATAL_ERROR "NOT Found: RtMidi")
endif()
