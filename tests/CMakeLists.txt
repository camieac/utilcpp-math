set(MIN_BOOST_VERSION "1.57")
set(Boost_ADDITIONAL_VERSIONS ${MIN_BOOST_VERSION})
set(INCLUDES ${Boost_INCLUDE_DIRS} ../include)

# finds boost, triggers an error otherwise
find_package(Boost ${MIN_BOOST_VERSION} REQUIRED COMPONENTS unit_test_framework)

file(GLOB TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/test-util*.cpp)

if (NOT Boost_FOUND)
	message(FATAL_ERROR "Fatal error: Boost (version >= " ${MIN_BOOST_VERSION} ") required.")
else()
	message(STATUS "Setting up Boost")

	include_directories (${INCLUDES})
	link_directories(../lib)

	add_executable(test-utilcpp-math ${TEST_SRCS})

	# Overriding global config, test binary goes in tests folder
	set_target_properties(test-utilcpp-math
		PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
	)

	add_test(test-utilcpp-math ${CMAKE_CURRENT_BINARY_DIR}/test-utilcpp-math)
	message(STATUS "Test binary is located in " ${CMAKE_CURRENT_BINARY_DIR})

	set(LIBS utilcpp-math ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
	target_link_libraries(test-utilcpp-math ${LIBS})

	# Use boost shared library
	target_compile_definitions(test-utilcpp-math PRIVATE "BOOST_TEST_DYN_LINK=1")

	SETUP_TARGET_FOR_COVERAGE(
		coverage		# Name for coverage target.
		test-utilcpp-math	# Name of the test driver executable that runs the tests.
		coverage		# Name of output directory.
	)

endif (NOT Boost_FOUND)
