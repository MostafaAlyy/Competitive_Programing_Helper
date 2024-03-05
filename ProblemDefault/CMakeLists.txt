
#add this in the end of the CMakeLists.txt file 
#Extra flags to avoid errors on submitting to any online judge
set(EXTRA_FLAG "")


set(EXTRA_FLAG "-D_GLIBCXX_DEBUG")
set(GCC_COVERAGE_COMPILE_FLAGS "-Werror=return-type -DCLION ${EXTRA_FLAG}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

MATH(EXPR stack_size "1024 * 1024*1024 ")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")


