
add_executable(FFT_CPU main.cpp)

add_subdirectory(fft)

target_link_libraries(FFT_CPU FFT)