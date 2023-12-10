add_library(dynpon dynarr.cpp dynarr.hpp)
set_property(TARGET dynpon PROPERTY CXX_STANDARD 20)
target_include_directories(dynpon PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS dynpon)