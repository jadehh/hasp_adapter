cmake_minimum_required(VERSION 3.19)
project(hasp_adapter_x86_64)
set(CMAKE_CXX_FLAGS)
add_library(${PROJECT_NAME} SHARED   hasp_adapter.cpp)
add_executable(${PROJECT_NAME} main.cpp hasp_adapter.cpp)
target_link_libraries(${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/lib/Linux/libhasp_linux_x86_64_34033.a
        pthread)

