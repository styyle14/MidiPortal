cmake_minimum_required (VERSION 3.10)
project (MidiPortal)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(PkgConfig REQUIRED)

add_executable(MidiPortal 
	main.cpp 
	helloworld.cpp
)

if(TARGET cabl-static)
	add_dependencies(MidiPortal
		cabl-static
	)
	message(STATUS "cabl-static target found.")
	target_link_libraries(MidiPortal
		cabl-static
	)
	target_include_directories(MidiPortal PRIVATE
		cabl-static
	)
elseif(TARGET cabl)
	message(FATAL_ERROR "cabl target found. Needed target cabl-static.")
else()
	find_package(RtMidi REQUIRED)
	link_directories(
		${RTMIDI_LIBRARY_DIRS}
	)
	include_directories(
		${RTMIDI_INCLUDE_DIRS}
	)
	find_package(Cabl REQUIRED)
	link_directories(
		${CABL_LIBRARY_DIRS}
	)
	include_directories(
		${CABL_INCLUDE_DIRS}
	)
endif()

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
link_directories(
	${GTKMM_LIBRARY_DIRS}
)
include_directories(
	${GTKMM_INCLUDE_DIRS}
)

include_directories(
	${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(MidiPortal
	${GTKMM_LIBRARIES}
)

install(
	TARGETS 
		MidiPortal
	DESTINATION 
		bin
)
