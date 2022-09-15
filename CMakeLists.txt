cmake_minimum_required(VERSION 3.22)
project(cplusplus)

set(CMAKE_CXX_STANDARD 14)
#aux_source_directory()

#add_library()


FILE(GLOB_RECURSE FILES *.cpp)
FOREACH(FILE ${FILES})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" EXE ${FILE})
    ADD_EXECUTABLE(${EXE} ${FILE})
    MESSAGE(\ \ \ \ --\ SRC/${EXE}.CPP\ WILL\ BE\ COMPILED\ TO\ BIN/${EXE})
ENDFOREACH()

#target_link_libraries()

