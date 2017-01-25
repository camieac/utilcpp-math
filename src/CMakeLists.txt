# Bring in the headers and sources
include_directories(../include)
file(GLOB SOURCES "*.cpp")

# Generate the shared library from the sources
add_library(utilc-math SHARED ${SOURCES})

# Compile with math library
target_link_libraries(utilc-math m)

if(UNIX)
  install(TARGETS utilc-math DESTINATION /usr/lib)
endif(UNIX)

if(WIN32)
  install(TARGETS utilc-math
       RUNTIME DESTINATION bin COMPONENT runtime
       ARCHIVE DESTINATION lib COMPONENT devel
       PUBLIC_HEADER DESTINATION include COMPONENT devel
  )
endif(WIN32)
