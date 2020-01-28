cmake_minimum_required(VERSION 3.2)
project(tester)

add_executable(tester sources/tester.cpp)

set_target_properties(tester PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )

target_include_directories(tester
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(tester
        PRIVATE
        -lstdc++fs  # gcc < 9+ requirements for std::filesystem usage
        )

