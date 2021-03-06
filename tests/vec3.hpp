/**
* @file vec3.c
* @author Cameron A. Craig
* @copyright 2017 - 2020 Cameron A. Craig
* @brief Unit tests for utilcpp-math.

* @note Check unit test documentation can be found here:
* https://libcheck.github.io/check/doc/check_html/index.html#Top
*/

#include <boost/test/unit_test.hpp>
#include <utilcpp-math.h>
using namespace ucm;

BOOST_AUTO_TEST_SUITE(VEC3_TEST_SUITE)

static vec3 unit_x(1.0f, 0.0f, 0.0f);
static vec3 unit_y(0.0f, 1.0f, 0.0f);
static vec3 unit_z(0.0f, 0.0f, 1.0f);

static vec3 ones(1.0f, 1.0f, 1.0f);
static vec3 zeros(0.0f, 0.0f, 0.0f);

/* Constructors */
BOOST_AUTO_TEST_CASE(test_empty_constructor) {
	vec3 v;
	BOOST_CHECK(v.x == 0.0f);
	BOOST_CHECK(v.y == 0.0f);
	BOOST_CHECK(v.z == 0.0f);
}

BOOST_AUTO_TEST_CASE(test_single_constructor) {
	vec3 v(62.92f);
	BOOST_CHECK(v.x == 62.92f);
	BOOST_CHECK(v.y == 62.92f);
	BOOST_CHECK(v.z == 62.92f);
}

BOOST_AUTO_TEST_CASE(test_populated_constructor) {
	vec3 v(62.92f,38.82f,52.70f);
	BOOST_CHECK(v.x == 62.92f);
	BOOST_CHECK(v.y == 38.82f);
	BOOST_CHECK(v.z == 52.70f);
}

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

BOOST_AUTO_TEST_CASE(test_array_access) {
	vec3 v = vec3(1.0f, 2.0f, 3.0f);
	BOOST_CHECK(v[0] == v.x);
	BOOST_CHECK(v[1] == v.y);
	BOOST_CHECK(v[2] == v.z);
	BOOST_CHECK(v[3] != v[3]); //Checking for NAN
}

/* Scalar Arithmetic */
BOOST_AUTO_TEST_CASE(test_scalar_add) {
	BOOST_CHECK(zeros + 1.0f == ones);
}

BOOST_AUTO_TEST_CASE(test_scalar_subtract) {
	BOOST_CHECK(ones - 1.0f == zeros);
}

BOOST_AUTO_TEST_CASE(test_scalar_multiply) {
	BOOST_CHECK(ones * 10 == vec3(10.0f, 10.0f, 10.0f));
}

BOOST_AUTO_TEST_CASE(test_scalar_divide) {
	BOOST_CHECK(vec3(10.0f, 10.0f, 10.0f) / 10 == ones);
}

/* Vector Arithmetic */
BOOST_AUTO_TEST_CASE(test_vector_add) {
	BOOST_CHECK(zeros + ones == ones);
}

BOOST_AUTO_TEST_CASE(test_vector_subtract) {
	BOOST_CHECK(ones - ones == zeros);
}

BOOST_AUTO_TEST_CASE(test_vector_dot_product) {
	BOOST_CHECK(ones.dot(ones) == 3.0f);
	BOOST_CHECK(ones.dot(zeros) == 0.0f);
	BOOST_CHECK(
		vec3(82.54f, 93.25f, 162.34f).dot(
			vec3(91.34f, 792.23f, 85.83f)
		) == 95348.2890625f
	);
}

BOOST_AUTO_TEST_CASE(test_vector_cross_product) {
	BOOST_CHECK(ones.cross(ones) == zeros);
	BOOST_CHECK(ones.cross(zeros) == zeros);
	BOOST_CHECK(
		vec3(82.54f, 93.25f, 162.34f).cross(
			vec3(91.34f, 792.23f, 85.83f)
		) == vec3(-120606.960938f, 7743.726562f, 56873.210938f)
	);
}

/* Scalar Shorthand Operators */
BOOST_AUTO_TEST_CASE(test_shorthand_scalar_add) {
	vec3 v = zeros;
	v += 1.0f;
	BOOST_CHECK(v == ones);
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_subtract) {
	vec3 v = ones;
	v -= 1.0f;
	BOOST_CHECK(v == zeros);
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_multiply) {
	vec3 v = ones;
	v *= 2.0f;
	BOOST_CHECK(v == vec3(2.0f, 2.0f, 2.0f));
}

BOOST_AUTO_TEST_CASE(test_shorthand_scalar_divide) {
	vec3 v = ones;
	v /= 2.0f;
	BOOST_CHECK(v == vec3(0.5f, 0.5f, 0.5f));
}

/* Vector Shorthand Operators */
BOOST_AUTO_TEST_CASE(test_shorthand_vector_add) {
	vec3 v = zeros;
	v += ones;
	BOOST_CHECK(v == ones);
}

BOOST_AUTO_TEST_CASE(test_shorthand_vector_subtract) {
	vec3 v = ones;
	v -= ones;
	BOOST_CHECK(v == zeros);
}

/* Miscellaneous */
BOOST_AUTO_TEST_CASE(test_length) {
	vec3 v = vec3(6.0f, 6.0f, 7.0f);
	BOOST_CHECK(v.length() == 11.0f);
}

BOOST_AUTO_TEST_CASE(test_normalize) {
	vec3 v = vec3(4.0f, 4.0f, 4.0f);
	v.normalize();
	//Never seems to be exactly one
	BOOST_CHECK(v.length() > 0.9999f);
	BOOST_CHECK(v.length() < 1.0001f);
	BOOST_CHECK(v.x == v.y);
	BOOST_CHECK(v.y == v.z);
}

BOOST_AUTO_TEST_CASE(test_abs) {
	vec3 v = vec3(-6.0f, -6.0f, -7.0f);
	vec3 v_abs = vec3(6.0f, 6.0f, 7.0f);
	BOOST_CHECK(v_abs == abs(v));
}

BOOST_AUTO_TEST_CASE(test_tostring) {
	vec3 v = vec3(6.0f, 6.0f, 10.0f/3);
	BOOST_CHECK(v.toString() == "(x: 6, y: 6, z: 3.33333)");
}


BOOST_AUTO_TEST_SUITE_END()
