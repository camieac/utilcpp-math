/**
* @file mat4x4.cpp
* @author Cameron A. Craig
* @copyright 2017 - 2020 Cameron A. Craig
* @brief 4-axis vector maths.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/

#include <stdlib.h>
#include <cmath>
#include <iostream>
#include "vec4.h"
#include "mat4x4.h"

/* Constructors */
ucm::mat4x4::mat4x4(){
	this->mat[0] *= 0.0f;
	this->mat[1] *= 0.0f;
	this->mat[2] *= 0.0f;
	this->mat[3] *= 0.0f;
}

ucm::mat4x4::mat4x4(float all){
	this->mat[0] = ucm::vec4(all);
	this->mat[1] = ucm::vec4(all);
	this->mat[2] = ucm::vec4(all);
	this->mat[3] = ucm::vec4(all);
}

ucm::mat4x4::mat4x4(ucm::vec4 col1, ucm::vec4 col2, ucm::vec4 col3, ucm::vec4 col4){
	this->mat[0] = col1;
	this->mat[1] = col2;
	this->mat[2] = col3;
	this->mat[3] = col4;
}

bool ucm::mat4x4::operator==(ucm::mat4x4 rhs) {
	return(
		this->mat[0] == rhs.mat[0] &&
		this->mat[1] == rhs.mat[1] &&
		this->mat[2] == rhs.mat[2] &&
		this->mat[3] == rhs.mat[3]
	);
}

/* Vector Arithmetic */
ucm::mat4x4 ucm::mat4x4::operator+(ucm::mat4x4 rhs) {
	return ucm::mat4x4(
		this->mat[0] + rhs.mat[0],
		this->mat[1] + rhs.mat[1],
		this->mat[2] + rhs.mat[2],
		this->mat[3] + rhs.mat[3]
	);
}

ucm::mat4x4 ucm::mat4x4::operator-(ucm::mat4x4 rhs) {
	return ucm::mat4x4(
		this->mat[0] - rhs.mat[0],
		this->mat[1] - rhs.mat[1],
		this->mat[2] - rhs.mat[2],
		this->mat[3] - rhs.mat[3]
	);
}

/* Scalar Arithmetic */

ucm::mat4x4 ucm::mat4x4::operator+(float scalar) {
	return ucm::mat4x4(
		this->mat[0] + scalar,
		this->mat[1] + scalar,
		this->mat[2] + scalar,
		this->mat[3] + scalar
	);
}

ucm::mat4x4 ucm::mat4x4::operator-(float scalar) {
	return ucm::mat4x4(
		this->mat[0] - scalar,
		this->mat[1] - scalar,
		this->mat[2] - scalar,
		this->mat[3] - scalar
	);
}

ucm::mat4x4 ucm::mat4x4::operator*(float scalar) {
	return ucm::mat4x4(
		this->mat[0] * scalar,
		this->mat[1] * scalar,
		this->mat[2] * scalar,
		this->mat[3] * scalar
	);
}

ucm::mat4x4 ucm::mat4x4::operator/(float scalar) {
	return ucm::mat4x4(
		this->mat[0] / scalar,
		this->mat[1] / scalar,
		this->mat[2] / scalar,
		this->mat[3] / scalar
	);
}

/* Shorthand vector operators */
ucm::mat4x4 ucm::mat4x4::operator+=(ucm::mat4x4 rhs){
	this->mat[0] = this->mat[0] + rhs.mat[0];
	this->mat[1] = this->mat[1] + rhs.mat[1];
	this->mat[2] = this->mat[2] + rhs.mat[2];
	this->mat[3] = this->mat[3] + rhs.mat[3];
	return (*this);
}

ucm::mat4x4 ucm::mat4x4::operator-=(ucm::mat4x4 rhs){
	this->mat[0] = this->mat[0] - rhs.mat[0];
	this->mat[1] = this->mat[1] - rhs.mat[1];
	this->mat[2] = this->mat[2] - rhs.mat[2];
	this->mat[3] = this->mat[3] - rhs.mat[3];
	return (*this);
}

/* Shorthand scalar operators */
ucm::mat4x4 ucm::mat4x4::operator+=(float scalar){
	this->mat[0] = this->mat[0] + scalar;
	this->mat[1] = this->mat[1] + scalar;
	this->mat[2] = this->mat[2] + scalar;
	this->mat[3] = this->mat[3] + scalar;
	return (*this);
}

ucm::mat4x4 ucm::mat4x4::operator-=(float scalar){
	this->mat[0] = this->mat[0] - scalar;
	this->mat[1] = this->mat[1] - scalar;
	this->mat[2] = this->mat[2] - scalar;
	this->mat[3] = this->mat[3] - scalar;
	return (*this);
}

ucm::mat4x4 ucm::mat4x4::operator*=(float scalar){
	this->mat[0] = this->mat[0] * scalar;
	this->mat[1] = this->mat[1] * scalar;
	this->mat[2] = this->mat[2] * scalar;
	this->mat[3] = this->mat[3] * scalar;
	return (*this);
}

ucm::mat4x4 ucm::mat4x4::operator/=(float scalar){
	this->mat[0] = this->mat[0] / scalar;
	this->mat[1] = this->mat[1] / scalar;
	this->mat[2] = this->mat[2] / scalar;
	this->mat[3] = this->mat[3] / scalar;
	return (*this);
}

/* Miscellaneous methods */

ucm::vec4& ucm::mat4x4::operator[](int idx) {
	return this->mat[idx];
}

std::ostream& ucm::operator<<(std::ostream& os, mat4x4& m) {
	os << m[0][0] << " " << m[1][0] << " " << m[2][0] << " " << m[3][0] << std::endl;
	os << m[0][1] << " " << m[1][1] << " " << m[2][1] << " " << m[3][1] << std::endl;
	os << m[0][2] << " " << m[1][2] << " " << m[2][2] << " " << m[3][2] << std::endl;
	os << m[0][3] << " " << m[1][3] << " " << m[2][3] << " " << m[3][3] << std::endl;

	return os;
}
