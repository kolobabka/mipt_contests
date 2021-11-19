cmake_minimum_required(VERSION 3.8)

project("Signals" VERSION 1.0.0)

set(SEND_EXEC_FILE "send")
set(RECIEVE_EXEC_FILE "recieve")

set(HEADERS

    signals.h
)

set(SEND_SOURCES

    send.c
    errors.c
)

set (RECIEVE_SOURCES
	
    recieve.c
    errors.c	
)   



#executable files
add_executable(${SEND_EXEC_FILE} ${SEND_SOURCES})
add_executable(${RECIEVE_EXEC_FILE} ${RECIEVE_SOURCES})

target_include_directories(${SEND_EXEC_FILE} PRIVATE)
target_include_directories(${RECIEVE_EXEC_FILE} PRIVATE)

# target_include_directories(${EXEC_FILE} PRIVATE headers)
#compiler settings

set (COMPILER_SETTINGS -Wall  -O2)

target_compile_options( ${SEND_EXEC_FILE} PRIVATE ${COMPILER_SETTINGS} )
target_compile_options( ${RECIEVE_EXEC_FILE} PRIVATE ${COMPILER_SETTINGS} )