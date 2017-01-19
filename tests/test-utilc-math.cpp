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

#define BOOST_TEST_MODULE UCM_VEC3_TESTS

#include <boost/test/unit_test.hpp>
#include <utilc-math.h>

static ucm_vec3 unit_x(1.0f, 0.0f, 0.0f);
static ucm_vec3 unit_y(0.0f, 1.0f, 0.0f);
static ucm_vec3 unit_z(0.0f, 0.0f, 1.0f);

static ucm_vec3 ones(1.0f, 1.0f, 1.0f);
static ucm_vec3 zeros(0.0f, 0.0f, 0.0f);

/* Scalar Arithmetic */

BOOST_AUTO_TEST_CASE(test_scalar_add) {
    BOOST_CHECK(unit_x + unit_y + unit_z == ones);        // #1 continues on error
}

BOOST_AUTO_TEST_CASE(test_scalar_subtract) {
    BOOST_CHECK(ones - unit_x - unit_y - unit_z == zeros);        // #1 continues on error
}

BOOST_AUTO_TEST_CASE(test_scalar_multiply) {
    BOOST_CHECK(ones * 10 == ucm_vec3(10.0f, 10.0f, 10.0f));        // #1 continues on error
}

BOOST_AUTO_TEST_CASE(test_scalar_divide) {
    BOOST_CHECK(ucm_vec3(10.0f, 10.0f, 10.0f) / 10 == ones);        // #1 continues on error
}

/* Vector Arithmetic */
