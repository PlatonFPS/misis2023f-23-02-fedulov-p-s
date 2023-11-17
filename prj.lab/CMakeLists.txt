add_library(complex complex.cpp complex.hpp)
add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex)