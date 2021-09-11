cmake_minimum_required (VERSION 3.12)
project (MyProject VERSION 1.0.0)

add_library(

  ARGV
  argv.c
  argv.h
  main.c
)

add_executable (argv argv.c main.c)

target_link_libraries (argv PRIVATE ARGV)
