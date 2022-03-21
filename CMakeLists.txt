cmake_minimum_required(VERSION 3.10)

# set the project name
project(chess)

# add the executable
add_executable(chess src/main.cpp)

# add libraries
add_library(utilities src/utilities.cpp)
add_library(ChessPiece src/ChessPiece.cpp)

# link libraries
target_link_libraries(chess PUBLIC utilities ChessPiece)

# add compiler options
add_compile_options(-Wall -Wextra -pedantic -Werror)