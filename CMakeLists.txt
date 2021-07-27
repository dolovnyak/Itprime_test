cmake_minimum_required(VERSION 3.19)
project(itprime_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
        main.cpp
        HappyTicketsCalculator/HappyTicketsCalculator.cpp
        )
target_include_directories(${PROJECT_NAME} PUBLIC HappyTicketsCalculator)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        )