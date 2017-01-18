/**
* @file utilc-timing.c
* @author Cameron A. Craig
* @date 17 Jan 2017
* @version 0.1.0
* @copyright 2017 Cameron A. Craig
* @brief Measure time without thinking about the arithmetic.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "utilc-math.h"

inline bool ucm_vec3::operator==(ucm_vec3 rhs) {
    return(x == rhs.x && y == rhs.y && z == rhs.z);
}

inline ucm_vec3 ucm_vec3::operator+(ucm_vec3 rhs) {
	return ucm_vec3(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z
	);
}

inline ucm_vec3 ucm_vec3::operator/(float scalar) {
	return ucm_vec3(
		x / scalar,
		y / scalar,
		z / scalar
	);
}

inline float ucm_vec3::dot(ucm_vec3 rhs) {
    return (
			x * rhs.x +
			y * rhs.y +
			z * rhs.z
		);
}

inline ucm_vec3 ucm_vec3::cross(ucm_vec3 rhs) {
	return ucm_vec3(
		y * rhs.z - z * rhs.y,
		z * rhs.x - x * rhs.z,
		x * rhs.y - y * rhs.x
	);
}

inline float ucm_vec3::length() {
    return float(sqrt( x*x + y*y + z*z ));
}

int ucm_version(void);
