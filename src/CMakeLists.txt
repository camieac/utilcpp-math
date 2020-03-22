# Bring in the headers and sources
include_directories(../include)
file(GLOB SOURCES "*.cpp")
file(GLOB PUBLIC_HEADERS "../include/utilcpp-math/*.h")

# Generate the shared library from the sources
add_library(utilcpp-math SHARED ${SOURCES})

# Compile with math library
target_link_libraries(utilcpp-math m)

if(UNIX)
	install(TARGETS utilcpp-math
		LIBRARY DESTINATION /usr/lib COMPONENT devel
	)
	install(FILES "../include/utilcpp-math.h" DESTINATION "/usr/include")
	install(DIRECTORY "../include/utilcpp-math"
		DESTINATION "/usr/include"
		FILES_MATCHING
		PATTERN "*.h"
	)
endif(UNIX)

if(WIN32)
	install(TARGETS utilcpp-math
		RUNTIME DESTINATION bin COMPONENT runtime
		ARCHIVE DESTINATION lib COMPONENT devel
		PUBLIC_HEADER DESTINATION include COMPONENT devel
	)
endif(WIN32)
