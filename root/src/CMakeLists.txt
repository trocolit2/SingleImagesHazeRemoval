#######################
## SOURCE MAIN CMAKE ##
#######################

################################
## LIBRARYS AND CLASS SESSION ##
################################

find_package(OpenCV REQUIRED)
#find_package(Boost COMPONENTS regex REQUIRED)
#include_directories (${Boost_INCLUDE_DIRS})

set(SOURCE_LIBS_LOCAL ${OpenCV_LIBS})

add_library(SingleImageHazeRemoval SingleImageHazeRemoval.h)
set_target_properties(SingleImageHazeRemoval PROPERTIES PUBLIC_HEADER "SingleImageHazeRemoval.h")
set_target_properties(SingleImageHazeRemoval PROPERTIES LINKER_LANGUAGE CXX)

set(SOURCE_LIBS_LOCAL ${SOURCE_LIBS_LOCAL} SingleImageHazeRemoval)

## ADD SUBDIRECTORIES FROM HISTOGRAM
include_directories(histogram)
add_subdirectory(histogram)


set(SOURCE_LIBS ${SOURCE_LIBS} ${SOURCE_LIBS_LOCAL} PARENT_SCOPE)

#########################
## EXECUTABLES SESSION ##
#########################
#add_executable(AS2C main.cxx)
#target_link_libraries(AS2C ${SOURCE_LIBS})
