cmake_minimum_required (VERSION 3.10)
project (MidiPortal)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)

link_directories(
	${GTKMM_LIBRARY_DIRS}
)

include_directories(
	${CMAKE_CURRENT_LIST_DIR}
	${GTKMM_INCLUDE_DIRS}
)

add_executable(MidiPortal 
	main.cpp 
	helloworld.cpp
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
