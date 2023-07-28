cmake_minimum_required(VERSION 3.22)

project(slicer) # a 3d printing slicer

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_SKIP_INSTALL_RULES True)

#set(CMAKE_BINARY_DIR "./bin")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

set(SOURCES
		src/lib/common.cpp
		src/lib/fileParser.cpp

		src/objs/facet.cpp
		src/objs/coord.cpp
		src/objs/slice.cpp

		src/main.cpp
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#add_executable(test test.cpp)
add_executable(Zslicy ${SOURCES})

set(TEST_SOURCES
		test/lib/testCommon.cpp
		test/lib/testFileParser.cpp

		test/obj/testSlice.cpp
		test/obj/testFacet.cpp
		test/obj/testCoord.cpp

		test/testMain.cpp
)

add_executable(test ${TEST_SOURCES})

target_link_libraries(test ${GTEST_LIBRARIES} pthread)


# --------------------------------------------------
## Set the output directory for the executable
#
## Add the include directory to the include path
#include_directories(include)
#
## Add the source files to the project
#set(SOURCES
#		src/main.cpp
#		src/MyClass.cpp
#		src/OtherClass.cpp
#		src/Subfolder/SomeUtility.cpp
#		src/Subfolder/AnotherSubfolder/Helper.cpp
#)
#
## Add an executable target for the main project
#add_executable(MyProject ${SOURCES})
#
## Optionally, you can add additional compile options if needed
## target_compile_options(MyProject PRIVATE -Wall -Wextra)
#
## Optionally, you can add additional link libraries if needed
## target_link_libraries(MyProject PRIVATE some_library)
#
## --- GTest Configuration ---
#
## Set the path to your GTest installation
#set(GTEST_DIR "/path/to/gtest")
#
## Add GTest library
#add_subdirectory(${GTEST_DIR} gtest_build)
#
## Include GTest headers
#include_directories(${GTEST_DIR}/include)
#
## List the test source files
#set(TEST_SOURCES
#		src/test/test_main.cpp
#		src/test/test_MyClass.cpp
#		src/test/test_OtherClass.cpp
#)
#
## Create the GTest test executable
#
#
## Link the test executable with GTest and the main project
#target_link_libraries(MyProjectTests PRIVATE gtest gtest_main)
#target_link_libraries(MyProjectTests PRIVATE MyProject)
#
## --- End of GTest Configuration ---
#
## Optionally, you can set the installation target to copy the main executable to 'bin' directory
## install(TARGETS MyProject DESTINATION bin)