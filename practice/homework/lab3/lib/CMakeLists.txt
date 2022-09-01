cmake_minimum_required(VERSION 3.0.0)
set(LIBPOINT_SRC CPoint.cc)
add_library(CPoint SHARED ${LIBPOINT_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_library(CPoint_static STATIC ${LIBPOINT_SRC})
set_target_properties(CPoint PROPERTIES CLEAN_DIRECT_OUPUT 1)
set_target_properties(CPoint_static PROPERTIES CLEAN_DIRECT_OUPUT 1)


install(TARGETS CPoint CPoint_static
    LIBRARY DESTINATION include/lib
    ARCHIVE DESTINATION include/lib
    )
install(FILES CPoint.h DESTINATION include/CPoint)
