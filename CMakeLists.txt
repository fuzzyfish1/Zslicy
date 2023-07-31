cmake_minimum_required(VERSION 3.22)

project(slicer) # a 3d printing slicer

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_SKIP_INSTALL_RULES True)

#set(CMAKE_BINARY_DIR "./bin")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)
include_directories(include)

set(SOURCES
		src/lib/common.cpp
		src/lib/fileParser.cpp
		src/lib/superImposer.cpp

		src/objs/facet.cpp
		src/objs/coord.cpp
		src/objs/slice.cpp
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#add_executable(test test.cpp)
add_executable(Zslicy src/main.cpp ${SOURCES})

set(TEST_SOURCES

		test/lib/testCommon.cpp
		test/lib/testFileParser.cpp
		test/lib/testSuperImposer.cpp

		test/obj/testSlice.cpp
		test/obj/testFacet.cpp
		test/obj/testCoord.cpp
)

add_executable(test test/testMain.cpp ${TEST_SOURCES} ${SOURCES})

target_link_libraries(test ${GTEST_LIBRARIES} pthread)