##########################
## TOOLS TEST MAIN CMAKE ##
##########################

add_library(toolsTest Tools.cpp)

set(SOURCE_LIBS_LOCAL toolsTest)
set(SOURCE_LIBS ${SOURCE_LIBS_LOCAL} ${SOURCE_LIBS}  PARENT_SCOPE)