project(GraphPainter)

cmake_minimum_required(VERSION 3.0.0)

# Add include directories
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Mask serach all files in project
file(GLOB GraphPainter_SOURCE
	"*.cpp"
)

# Project definitions
if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Output program
add_executable(GraphPainter ${GraphPainter_SOURCE})