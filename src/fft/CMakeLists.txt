add_library(
    FFT 
    arg_parser.cpp
)

target_include_directories(
    FFT PUBLIC "${CMAKE_CURRENT_LIST_DIR}"
)