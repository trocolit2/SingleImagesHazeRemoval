##########################
## HISTOGRAM MAIN CMAKE ##
##########################

add_library(CLAHE CLAHE.cpp)
add_library(HistogramEqualization HistogramEqualization.cpp)

set(SOURCE_LIBS_LOCAL CLAHE  HistogramEqualization)
set(SOURCE_LIBS ${SOURCE_LIBS} ${SOURCE_LIBS_LOCAL})

set(SOURCE_LIBS ${SOURCE_LIBS} PARENT_SCOPE)
