cmake_minimum_required(VERSION 3.15)
project(eproblem_ecc)

add_executable(problem_ec problem_ec.c)
target_link_libraries(problem_ec PRIVATE m)
