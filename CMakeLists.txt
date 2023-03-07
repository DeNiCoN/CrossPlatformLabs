cmake_minimum_required(VERSION 3.25)
project(mymodule CXX)

find_package (Python3 COMPONENTS Development)
find_package(Boost COMPONENTS python REQUIRED)

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")

# Add a shared module - modules are intended to be imported at runtime.
add_library(mymodule MODULE src/mymodule.cpp)

target_link_libraries(mymodule ${Boost_LIBRARIES} Python3::Module)
