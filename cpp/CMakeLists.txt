cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT (HorizonCore CXX)

include(${HORIZON_BUILD_TOOL_ROOT}/cmake/UtilMacro.cmake)
include(${HORIZON_BUILD_TOOL_ROOT}/cmake/ProjectSetting.cmake)
include(${HORIZON_BUILD_TOOL_ROOT}/cmake/LibSetting.cmake)



file(GLOB PLATFORM_HEADER
 	"Platform/standard/*.h"
	"precompile/precompiled.h"
)
source_group_by_dir(PLATFORM_HEADER)
file(GLOB PLATFORM_SRCS
    "Platform/standard/*.cpp"
	"precompile/precompiled.cpp"
)

source_group_by_dir(PLATFORM_SRCS)

ADD_MSVC_PRECOMPILED_HEADER("precompile/precompiled.h" "precompile/precompiled.cpp" ${PLATFORM_SRCS})


add_executable(${PROJECT_NAME} ${PLATFORM_HEADER} ${PLATFORM_SRCS})


IF (WIN32)
	file(GLOB PLATFORM_WIN32_IMPLEMENT_HEADER
		"Platform/windows/implement/*.h"
	)
	file(GLOB PLATFORM_WIN32_IMPLEMENT_SRCS
		"Platform/windows/implement/*.cpp"
	)
	source_group_by_dir(PLATFORM_WIN32_IMPLEMENT_HEADER)
	source_group_by_dir(PLATFORM_WIN32_IMPLEMENT_SRCS)
	set(PLATFORM_IMPLEMENT_HEADER ${PLATFORM_WIN32_IMPLEMENT_HEADER})
	set(PLATFORM_IMPLEMENT_SRCS   ${PLATFORM_WIN32_IMPLEMENT_SRCS})
ELSE()
  # set stuff for other systems
ENDIF()




file(GLOB PROJ_HEADER
	"Public/*.hpp"
 	"Public/*.h"
   	"Private/*.hpp"
   	"Private/*.h"
	"precompile/precompiled.h"
)
source_group_by_dir(PROJ_HEADER)

file(GLOB PROJ_SRCS
    "Public/*.cpp"
    "Private/*.cpp"
	"precompile/precompiled.cpp"
)
source_group_by_dir(PROJ_SRCS)

#HorizonCoreStatic.dir/$(Configuration)/

ADD_MSVC_PRECOMPILED_HEADER("precompile/precompiled.h" "precompile/precompiled.cpp" ${PROJ_SRCS})
ADD_MSVC_PRECOMPILED_HEADER("precompile/precompiled.h" "precompile/precompiled.cpp" ${PLATFORM_IMPLEMENT_SRCS})

add_library(HorizonCoreStatic STATIC ${PROJ_HEADER} ${PLATFORM_IMPLEMENT_HEADER}  
									 ${PROJ_SRCS}   ${PLATFORM_IMPLEMENT_SRCS})




#add_library(HorizonCoreShared SHARED ${PROJ_SRCS})

include(${HORIZON_BUILD_TOOL_ROOT}/cmake/LibLink.cmake)
