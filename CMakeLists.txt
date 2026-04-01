cmake_minimum_required(VERSION 3.10)
project(SCHOOLFESTIVAL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the base path
set(RAYLIB_PATH "/home/ivan/raylib")

add_executable(SCHOOLFESTIVAL
    "ПейоЯворовПрограма/PeioQvorovPrograma.cpp"
    "ПейоЯворовПрограма/QvorovMainFrame.cpp"
)

# Use the same variable name here
target_include_directories(SCHOOLFESTIVAL PRIVATE 
    "${RAYLIB_PATH}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/ПейоЯворовПрограма/"
)

# Point directly to the .a file in the src folder
target_link_libraries(SCHOOLFESTIVAL PRIVATE 
    "${RAYLIB_PATH}/src/libraylib.a"
    GL m pthread dl rt X11
)