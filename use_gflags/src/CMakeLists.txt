add_executable(sample sample.cc)
target_linK_libraries(sample libgflags.a)
add_dependencies(sample gflag)
#target_linK_libraries(sample pthread)