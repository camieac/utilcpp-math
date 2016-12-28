#Compile the example executable
add_executable(utilc-template-example utilc-template-example.c)
include_directories(../include/)
target_link_libraries(utilc-template-example utilc-template)
