/**
* @file vec4.c
* @author Cameron A. Craig
* @date 17 Jan 2017
* @version 0.2.0
* @copyright 2017 Cameron A. Craig
* @brief Unit tests for utilcpp-math.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment

* @note Check unit test documentation can be cound here:
* https://libcheck.github.io/check/doc/check_html/index.html#Top
*/

#include <boost/test/unit_test.hpp>
#include <utilcpp-math.h>
using namespace ucm;

BOOST_AUTO_TEST_SUITE(VEC4_TEST_SUITE)

static vec4 unit_x(1.0f, 0.0f, 0.0f, 0.0f);
static vec4 unit_y(0.0f, 1.0f, 0.0f, 0.0f);
static vec4 unit_z(0.0f, 0.0f, 1.0f, 0.0f);
static vec4 unit_w(0.0f, 0.0f, 0.0f, 1.0f);

static vec4 ones(1.0f, 1.0f, 1.0f, 1.0f);
static vec4 zeros(0.0f, 0.0f, 0.0f, 0.0f);

/* Constructors */
BOOST_AUTO_TEST_CASE(test_empty_constructor) {
	vec4 v;
	BOOST_CHECK(v.x == 0.0f);
	BOOST_CHECK(v.y == 0.0f);
	BOOST_CHECK(v.z == 0.0f);
	BOOST_CHECK(v.w == 0.0f);
}

BOOST_AUTO_TEST_CASE(test_single_constructor) {
	vec4 v(62.92f);
	BOOST_CHECK(v.x == 62.92f);
	BOOST_CHECK(v.y == 62.92f);
	BOOST_CHECK(v.z == 62.92f);
	BOOST_CHECK(v.w == 62.92f);
}

BOOST_AUTO_TEST_CASE(test_populated_constructor) {
	vec4 v(62.92f,38.82f,52.70f,82.72f);
	BOOST_CHECK(v.x == 62.92f);
	BOOST_CHECK(v.y == 38.82f);
	BOOST_CHECK(v.z == 52.70f);
	BOOST_CHECK(v.w == 82.72f);
}

/* Accessing fields */
BOOST_AUTO_TEST_CASE(test_x) {
	vec4 v(62.92f,38.82f,52.70f,37.97f);
	BOOST_CHECK(v.x == 62.92f);
}

BOOST_AUTO_TEST_CASE(test_y) {
	vec4 v(62.92f,38.82f,52.70f,37.97f);
	BOOST_CHECK(v.y == 38.82f);
}

BOOST_AUTO_TEST_CASE(test_z) {
	vec4 v(62.92f,38.82f,52.70f,37.97f);
	BOOST_CHECK(v.z == 52.70f);
}

BOOST_AUTO_TEST_CASE(test_w) {
	vec4 v(62.92f,38.82f,52.70f,37.97f);
	BOOST_CHECK(v.w == 37.97f);
}

BOOST_AUTO_TEST_CASE(test_array_access) {
	vec4 v = vec4(1.0f, 2.0f, 3.0f, 4.0f);
	BOOST_CHECK(v[0] == v.x);
	BOOST_CHECK(v[1] == v.y);
	BOOST_CHECK(v[2] == v.z);
	BOOST_CHECK(v[3] == v.w);
	//BOOST_CHECK(v[4] != v[4]);
}

/* Scalar Arithmetic */
BOOST_AUTO_TEST_CASE(test_scalar_add) {
	BOOST_CHECK(zeros + 1.0f == ones);
}

BOOST_AUTO_TEST_CASE(test_scalar_subtract) {
	BOOST_CHECK(ones - 1.0f == zeros);
}

BOOST_AUTO_TEST_CASE(test_scalar_multiply) {
	BOOST_CHECK(ones * 10 == vec4(10.0f, 10.0f, 10.0f, 10.0f));
}

BOOST_AUTO_TEST_CASE(test_scalar_divide) {
	BOOST_CHECK(vec4(10.0f, 10.0f, 10.0f, 10.0f) / 10 == ones);
}

/* Vector Arithmetic */
BOOST_AUTO_TEST_CASE(test_vector_add) {
	BOOST_CHECK(unit_x + unit_y + unit_z + unit_w == ones);
}

BOOST_AUTO_TEST_CASE(test_vector_subtract) {
	BOOST_CHECK(ones - unit_x - unit_y - unit_z - unit_w == zeros);
}

BOOST_AUTO_TEST_CASE(test_vector_dot_product) {
	BOOST_CHECK(ones.dot(ones) == 4.0f);
	BOOST_CHECK(ones.dot(zeros) == 0.0f);
	BOOST_CHECK(
		vec4(82.54f, 93.25f, 162.34f, 961.34f).dot(
			vec4(91.34f, 792.23f, 85.83f, 17.56f)
		) == 112229.4237f
	);
}

/* Scalar Shorthand Operators */
BOOST_AUTO_TEST_CASE(test_shorthand_scalar_add) {
	vec4 v = zeros;
	v += 1.0f;
	BOOST_CHECK(v == ones);
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_subtract) {
	vec4 v = ones;
	v -= 1.0f;
	BOOST_CHECK(v == zeros);
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_multiply) {
	vec4 v = ones;
	v *= 2.0f;
	BOOST_CHECK(v == vec4(2.0f, 2.0f, 2.0f, 2.0f));
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_divide) {
	vec4 v = ones;
	v /= 2.0f;
	BOOST_CHECK(v == vec4(0.5f, 0.5f, 0.5f , 0.5f));
}

/* Vector Shorthand Operators */
BOOST_AUTO_TEST_CASE(test_shorthand_vector_add) {
	vec4 v = zeros;
	v += ones;
	BOOST_CHECK(v == ones);
}

BOOST_AUTO_TEST_CASE(test_shorthand_vector_subtract) {
	vec4 v = ones;
	v -= ones;
	BOOST_CHECK(v == zeros);
}

/* Miscellaneous */
BOOST_AUTO_TEST_CASE(test_length) {
	vec4 v = vec4(6.0f, 6.0f, 7.0f, 0.0f);
	BOOST_CHECK(v.length() == 11.0f);
}

BOOST_AUTO_TEST_CASE(test_abs) {
	vec4 v = vec4(-6.0f, -6.0f, -7.0f, 0.0f);
	vec4 v_abs = vec4(6.0f, 6.0f, 7.0f, 0.0f);
	BOOST_CHECK(v_abs == abs(v));
}

BOOST_AUTO_TEST_CASE(test_tostring) {
	vec4 v = vec4(6.0f, 6.0f, 7.0f, 8.0f);
	BOOST_CHECK(
		v.toString() ==
			"(x: 6.000000, y: 6.000000, z: 7.000000, w: 8.000000)"
	);
}

BOOST_AUTO_TEST_SUITE_END()
