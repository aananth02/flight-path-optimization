# Path definitions.
set(lib_dir ${CMAKE_CURRENT_SOURCE_DIR})

# Add libdir1 library.
set(libdir1_dir ${lib_dir}/libdir1)
file(GLOB_RECURSE libdir1_sources CONFIGURE_DEPENDS ${libdir1_dir}/*.h ${libdir1_dir}/*.cpp)
add_library(libdir1 ${libdir1_sources})
set_target_properties(libdir1 PROPERTIES LINKER_LANGUAGE CXX)

# Need to add libraries in the above mentioned format

# Overall libraries format
# Add overall libs library.
add_library(libs INTERFACE)
target_include_directories(libs INTERFACE ${lib_dir})

#Below command is needed to add libraries like cs225
#target_link_libraries(libs INTERFACE cs225)