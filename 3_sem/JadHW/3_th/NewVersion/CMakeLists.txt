cmake_minimum_required( VERSION 3.16 )

project( BizzBuzz VERSION 1.0.0 LANGUAGES C )

set( EXEC_NAME "BizzBuzz" )

add_executable( ${EXEC_NAME} )
target_include_directories( ${EXEC_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/headers" )
target_sources( BizzBuzz PRIVATE
    sources/bizzbuzz.c
    sources/errors.c
    sources/main.c
)

set( COMMON_COMPILER_OPTIONS
    -Wall -Wpedantic -Wunused -Wunreachable-code
)
set( DEBUG_COMPILER_OPTIONS
    -g -O0
)
set( RELEASE_COMPILER_OPTIONS
    -O3
)

target_compile_features( ${EXEC_NAME} PRIVATE c_std_11 )
target_compile_options( ${EXEC_NAME} PRIVATE ${COMMON_COMPILER_OPTIONS} )

option( DEBUG_BUILD "Build debug project version." ON )

if ( DEBUG_BUILD )
    target_compile_options( ${EXEC_NAME} PRIVATE ${DEBUG_COMPILER_OPTIONS} )
else()
    target_compile_options( ${EXEC_NAME} PRIVATE ${RELEASE_COMPILER_OPTIONS} )
endif( DEBUG_BUILD )
