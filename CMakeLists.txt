cmake_minimum_required(VERSION 3.5)
project(simple_api)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)
find_package(Threads REQUIRED)

add_executable(simple_api src/main.cpp)

target_include_directories(simple_api PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(simple_api PRIVATE
    ${Boost_LIBRARIES}
    Threads::Threads
)

# CROW_ENABLE_BOOST makrosunu tanımlayın
target_compile_definitions(simple_api PRIVATE CROW_ENABLE_BOOST)
