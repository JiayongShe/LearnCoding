# <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>.

#
# Project Properties
#
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (gflags_example)
SET (APPLICATION_NAME "gflags example")
SET (APPLICATION_VERSION_MAJOR 0)
SET (APPLICATION_VERSION_MINOR 0)
SET (APPLICATION_VERSION_PATCH 0)

#
# Debugging Options
#
SET (CMAKE_VERBOSE_MAKEFILE 1) # Use 1 for debugging, 0 for release

#
# Project Output Paths
#
SET (MAINFOLDER ${PROJECT_SOURCE_DIR})
SET (EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
SET (LIBRARY_OUTPUT_PATH "${MAINFOLDER}/lib")

#
# Project Search Paths
#
SET (CMAKE_MODULE_PATH "${MAINFOLDER}/_cmake_scripts")
INCLUDE_DIRECTORIES("${MAINFOLDER}/src")

#
# Thirdparty package install
#
add_custom_target(
   gflag
   COMMAND ./configure  --prefix=${MAINFOLDER}/thirdparty/install&&make&&make install
   WORKING_DIRECTORY ${MAINFOLDER}/thirdparty/gflags
   )

include_directories(${MAINFOLDER}/thirdparty/install/include)
link_directories("${MAINFOLDER}/thirdparty/install/lib")
#
# Configure Files
#
FILE (GLOB_RECURSE CONFIGINPUTS1 include/*.in.h)
FILE (GLOB_RECURSE CONFIGINPUTS2 include/*.h.in)
FILE (GLOB_RECURSE CONFIGINPUTS3 src/*.in.h)
FILE (GLOB_RECURSE CONFIGINPUTS4 src/*.h.in)
FILE (GLOB_RECURSE CONFIGINPUTS5 test/*.in.h)
FILE (GLOB_RECURSE CONFIGINPUTS6 test/*.h.in)
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS1}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS2}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS3}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS4}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS5}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS6}")
FOREACH (CONFIGINPUT ${CONFIGINPUTS})
    STRING (REPLACE ".in.h" ".h" CONFIGOUTPUT1 "${CONFIGINPUT}")
    STRING (REPLACE ".h.in" ".h" CONFIGOUTPUT2 "${CONFIGOUTPUT1}")
    CONFIGURE_FILE ("${CONFIGINPUT}" "${CONFIGOUTPUT2}")
ENDFOREACH (CONFIGINPUT ${CONFIGINPUTS})

#
# Add Build Targets
#
ADD_SUBDIRECTORY(src)


#
# Add Documentation Targets
#
#INCLUDE (DocumentationTargets)


