#######################
## SOURCE MAIN CMAKE ##
#######################

################################
## LIBRARYS AND CLASS SESSION ##
################################

find_package(OpenCV REQUIRED)
set(SOURCE_LIBS_LOCAL ${OpenCV_LIBS})

#########################
## HISTOGRAM MAIN PATH ##
#########################

include_directories(histogram)
add_subdirectory(histogram)

set(SOURCE_LIBS_LOCAL ${SOURCE_LIBS} ${SOURCE_LIBS_LOCAL})
set(SOURCE_LIBS ${SOURCE_LIBS_LOCAL} PARENT_SCOPE)

#########################
## EXECUTABLES SESSION ##
#########################
add_executable(hazeRemovalMain main.cpp)
target_link_libraries(hazeRemovalMain ${SOURCE_LIBS_LOCAL})
