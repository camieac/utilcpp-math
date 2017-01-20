/**
* @file test-utilc-math.c
* @author Cameron A. Craig
* @date 17 Jan 2017
* @version 0.1.0
* @copyright 2017 Cameron A. Craig
* @brief Unit tests for utilc-math.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment

* @note Check unit test documentation can be cound here:
* https://libcheck.github.io/check/doc/check_html/index.html#Top
*/

#include <boost/test/unit_test.hpp>
#include <utilc-math.h>
using namespace ucm;

BOOST_AUTO_TEST_SUITE(VEC3_TEST_SUITE)

static vec3 unit_x(1.0f, 0.0f, 0.0f);
static vec3 unit_y(0.0f, 1.0f, 0.0f);
static vec3 unit_z(0.0f, 0.0f, 1.0f);

static vec3 ones(1.0f, 1.0f, 1.0f);
static vec3 zeros(0.0f, 0.0f, 0.0f);

/* Accessing fields */

BOOST_AUTO_TEST_CASE(test_x) {
	vec3 v(62.92f,38.82f,52.70f);
	BOOST_CHECK(v.x == 62.92f);
}

BOOST_AUTO_TEST_CASE(test_y) {
	vec3 v(62.92f,38.82f,52.70f);
	BOOST_CHECK(v.y == 38.82f);
}

BOOST_AUTO_TEST_CASE(test_z) {
	vec3 v(62.92f,38.82f,52.70f);
	BOOST_CHECK(v.z == 52.70f);
}

BOOST_AUTO_TEST_CASE(test_r) {
	vec3 v(62.92f,38.82f,52.70f);
	BOOST_CHECK(v.r == 62.92f);
}

BOOST_AUTO_TEST_CASE(test_g) {
	vec3 v(62.92f,38.82f,52.70f);
	BOOST_CHECK(v.g == 38.82f);
}

BOOST_AUTO_TEST_CASE(test_b) {
	vec3 v(62.92f,38.82f,52.70f);
	BOOST_CHECK(v.b == 52.70f);
}

/* Scalar Arithmetic */

BOOST_AUTO_TEST_CASE(test_scalar_add) {
	BOOST_CHECK(unit_x + unit_y + unit_z  == ones);
}

BOOST_AUTO_TEST_CASE(test_scalar_subtract) {
	BOOST_CHECK(ones - unit_x - unit_y - unit_z == zeros);
}

BOOST_AUTO_TEST_CASE(test_scalar_multiply) {
	BOOST_CHECK(ones * 10 == vec3(10.0f, 10.0f, 10.0f));
}

BOOST_AUTO_TEST_CASE(test_scalar_divide) {
	BOOST_CHECK(vec3(10.0f, 10.0f, 10.0f) / 10 == ones);
}

BOOST_AUTO_TEST_SUITE_END()

/* Vector Arithmetic */
