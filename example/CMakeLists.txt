#Compile the example executable
add_executable(utilcpp-math-example utilcpp-math-example.cpp)
include_directories(../include/)
target_link_libraries(utilcpp-math-example utilcpp-math)
