##########################
## HISTOGRAM MAIN CMAKE ##
##########################

add_library(CLAHE CLAHE.cpp CLAHE.h)
add_library(HistogramEqualization HistogramEqualization.cpp)

set(SOURCE_LIBS_LOCAL CLAHE HistogramEqualization)
set(SOURCE_LIBS ${SOURCE_LIBS} ${SOURCE_LIBS_LOCAL} PARENT_SCOPE)