# Bring in the headers and sources
include_directories(../include)
file(GLOB SOURCES "*.c")

# Generate the shared library from the sources
add_library(utilc-template SHARED ${SOURCES})

# Compile with math library
target_link_libraries(utilc-template m)

# Install system-wide
install(TARGETS utilc-template DESTINATION /usr/lib)
