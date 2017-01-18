#Compile the example executable
add_executable(utilc-math-example utilc-math-example.cpp)
include_directories(../include/)
target_link_libraries(utilc-math-example utilc-math)
