enable_testing()
set(MIN_BOOST_VERSION "1.57")
set(Boost_ADDITIONAL_VERSIONS ${MIN_BOOST_VERSION})
set(INCLUDES ${Boost_INCLUDE_DIRS} ../include)


# finds boost, triggers an error otherwise
find_package(Boost ${MIN_BOOST_VERSION} REQUIRED COMPONENTS unit_test_framework)

file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

if (NOT Boost_FOUND)
	message(FATAL_ERROR "Fatal error: Boost (version >= " ${MIN_BOOST_VERSION} ") required.")
else()
	message(STATUS "Setting up Boost")

	include_directories (${INCLUDES})

	add_executable(test-utilc-math ${TEST_SRCS})
	set(LIBS utilc-math ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
	target_link_libraries(test-utilc-math ${LIBS})

	# Use boost shared library
	target_compile_definitions(test-utilc-math PRIVATE "BOOST_TEST_DYN_LINK=1")#

	add_test(test-utilc-math ${CMAKE_CURRENT_BINARY_DIR}/test-utilc-math)


endif (NOT Boost_FOUND)
