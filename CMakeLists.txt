cmake_minimum_required(VERSION 3.23)

project(csv_median_calculator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(csv_median_calculator
    src/main.cpp
    src/config.cpp
    src/median_calculator.cpp
    src/csv_reader.cpp
    src/file_scanner.cpp
    src/record_loader.cpp
    src/result_writer.cpp
)

target_include_directories(csv_median_calculator
    PRIVATE
        include
)