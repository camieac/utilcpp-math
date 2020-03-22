/**
* @file mat4x4.cpp
* @author Cameron A. Craig
* @copyright 2017 - 2020 Cameron A. Craig
* @brief Unit tests for utilcpp-math.

* @note Check unit test documentation can be found here:
* https://libcheck.github.io/check/doc/check_html/index.html#Top
*/
#include <sstream>
#include <boost/test/unit_test.hpp>
#include <utilcpp-math.h>
using namespace ucm;

BOOST_AUTO_TEST_SUITE(MAT4X4_TEST_SUITE)

static vec4 v_unit_x(1.0f, 0.0f, 0.0f, 0.0f);
static vec4 v_unit_y(0.0f, 1.0f, 0.0f, 0.0f);
static vec4 v_unit_z(0.0f, 0.0f, 1.0f, 0.0f);
static vec4 v_unit_w(0.0f, 0.0f, 0.0f, 1.0f);
static vec4 v_ones(1.0f, 1.0f, 1.0f, 1.0f);
static vec4 v_zeros(0.0f, 0.0f, 0.0f, 0.0f);

static mat4x4 identity(v_unit_w, v_unit_z, v_unit_y, v_unit_x);
static mat4x4 ones(v_ones, v_ones, v_ones, v_ones);
static mat4x4 zeros(v_zeros, v_zeros, v_zeros, v_zeros);

/* Constructors */
BOOST_AUTO_TEST_CASE(test_empty_constructor) {
	mat4x4 m;
	BOOST_CHECK(m[0] == v_zeros);
	BOOST_CHECK(m[1] == v_zeros);
	BOOST_CHECK(m[2] == v_zeros);
	BOOST_CHECK(m[3] == v_zeros);
}

BOOST_AUTO_TEST_CASE(test_single_constructor) {
	mat4x4 m(91.72f);
	BOOST_CHECK(m[0] == vec4(91.72f));
	BOOST_CHECK(m[1] == vec4(91.72f));
	BOOST_CHECK(m[2] == vec4(91.72f));
	BOOST_CHECK(m[3] == vec4(91.72f));
}

BOOST_AUTO_TEST_CASE(test_populated_constructor) {
	mat4x4 m(v_unit_x, v_unit_y, v_unit_z, v_unit_w);
	BOOST_CHECK(m[0] == v_unit_x);
	BOOST_CHECK(m[1] == v_unit_y);
	BOOST_CHECK(m[2] == v_unit_z);
	BOOST_CHECK(m[3] == v_unit_w);
}

/* Scalar Arithmetic */
BOOST_AUTO_TEST_CASE(test_scalar_add) {
	mat4x4 m;
	BOOST_CHECK(m + 1.0f == ones);
}

BOOST_AUTO_TEST_CASE(test_scalar_subtract) {
	BOOST_CHECK(ones - 1.0f == zeros);
}

BOOST_AUTO_TEST_CASE(test_scalar_multiply) {
	BOOST_CHECK(ones * 10 == mat4x4(
		vec4(10.0f, 10.0f, 10.0f, 10.0f),
		vec4(10.0f, 10.0f, 10.0f, 10.0f),
		vec4(10.0f, 10.0f, 10.0f, 10.0f),
		vec4(10.0f, 10.0f, 10.0f, 10.0f)
	));
}

BOOST_AUTO_TEST_CASE(test_scalar_divide) {
	BOOST_CHECK(mat4x4(
		vec4(10.0f, 10.0f, 10.0f, 10.0f),
		vec4(10.0f, 10.0f, 10.0f, 10.0f),
		vec4(10.0f, 10.0f, 10.0f, 10.0f),
		vec4(10.0f, 10.0f, 10.0f, 10.0f)
	) / 10 == ones);
}

/* Matrix Arithmetic */
BOOST_AUTO_TEST_CASE(test_matrix_add) {
	BOOST_CHECK(ones + ones == mat4x4(
		vec4(2.0f,2.0f,2.0f,2.0f),
		vec4(2.0f,2.0f,2.0f,2.0f),
		vec4(2.0f,2.0f,2.0f,2.0f),
		vec4(2.0f,2.0f,2.0f,2.0f)
	));
}

BOOST_AUTO_TEST_CASE(test_matrix_subtract) {
	BOOST_CHECK(ones - ones == zeros);
}



/* Scalar Shorthand Operators */
BOOST_AUTO_TEST_CASE(test_shorthand_scalar_add) {
	mat4x4 m;
	m += 1.0f;
	BOOST_CHECK(m == ones);
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_subtract) {
	mat4x4 m = ones;
	m -= 1.0f;
	BOOST_CHECK(m == zeros);
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_multiply) {
	mat4x4 m = ones;
	m *= 2.0f;
	BOOST_CHECK(m == mat4x4(
		vec4(2.0f,2.0f,2.0f,2.0f),
		vec4(2.0f,2.0f,2.0f,2.0f),
		vec4(2.0f,2.0f,2.0f,2.0f),
		vec4(2.0f,2.0f,2.0f,2.0f)
	));
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_divide) {
	mat4x4 m = ones;
	m /= 2.0f;
	BOOST_CHECK(m == mat4x4(
		vec4(0.5f,0.5f,0.5f,0.5f),
		vec4(0.5f,0.5f,0.5f,0.5f),
		vec4(0.5f,0.5f,0.5f,0.5f),
		vec4(0.5f,0.5f,0.5f,0.5f)
	));
}

/* Matrix Shorthand Operators */
BOOST_AUTO_TEST_CASE(test_shorthand_matrix_add) {
	mat4x4 m = zeros;
	m += ones;
	BOOST_CHECK(m == ones);
}

BOOST_AUTO_TEST_CASE(test_shorthand_matrix_subtract) {
	mat4x4 m = ones;
	m -= ones;
	BOOST_CHECK(m == zeros);
}

/* Stream insertion */
BOOST_AUTO_TEST_CASE(test_stream_insert_operator) {
	std::stringstream ss1;
	std::stringstream ss2;
	ss2 << "1 0 0 0" << endl
		<< "0 0 0 0" << endl
		<< "0 0 0 0" << endl
		<< "0 1 0 0" << endl;

	mat4x4 mat;
	mat[0][0] = 1.0f;
	mat[1][3] = 1.0f;

	ss1 << mat;
	BOOST_CHECK(ss1.str() == ss2.str());
}

BOOST_AUTO_TEST_SUITE_END()
