/**
* @file vec4.cpp
* @author Cameron A. Craig
* @date 20 Jan 2017
* @version 0.1.0
* @copyright 2017 Cameron A. Craig
* @brief 4-axis vector maths.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/

#include <stdlib.h>
#include <cmath>

#include "vec4.h"

/* Constructors */
ucm::vec4::vec4(){
  this->x = 0.0f;
  this->y = 0.0f;
  this->z = 0.0f;
  this->w = 0.0f;
}

ucm::vec4::vec4(float x, float y, float z, float w){
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = w;
}

bool ucm::vec4::operator==(vec4 rhs) {
    return(
      this->x == rhs.x &&
      this->y == rhs.y &&
      this->z == rhs.z &&
      this->w == rhs.w
    );
}

/* Vector Arithmetic */
ucm::vec4 ucm::vec4::operator+(ucm::vec4 rhs) {
	return ucm::vec4(
		this->x + rhs.x,
		this->y + rhs.y,
    this->z + rhs.z,
		this->w + rhs.w
	);
}

ucm::vec4 ucm::vec4::operator-(vec4 rhs) {
	return ucm::vec4(
		this->x - rhs.x,
		this->y - rhs.y,
    this->z - rhs.z,
		this->w - rhs.w

	);
}

float ucm::vec4::dot(vec4 rhs) {
    return (
			this->x * rhs.x +
			this->y * rhs.y +
      this->z * rhs.z +
			this->w * rhs.w
		);
}

/* Scalar Arithmetic */

ucm::vec4 ucm::vec4::operator+(float scalar) {
	return ucm::vec4(
		this->x + scalar,
		this->y + scalar,
    this->z + scalar,
		this->w + scalar
	);
}

ucm::vec4 ucm::vec4::operator-(float scalar) {
	return ucm::vec4(
		this->x - scalar,
		this->y - scalar,
    this->z - scalar,
		this->w - scalar
	);
}

ucm::vec4 ucm::vec4::operator*(float scalar) {
	return ucm::vec4(
		this->x * scalar,
		this->y * scalar,
    this->z * scalar,
		this->w * scalar
	);
}

ucm::vec4 ucm::vec4::operator/(float scalar) {
	return ucm::vec4(
		this->x / scalar,
		this->y / scalar,
    this->z / scalar,
		this->w / scalar
	);
}

/* Shorthand vector operators */
ucm::vec4 ucm::vec4::operator+=(vec4 rhs){
	this->x = this->x + rhs.x;
	this->y = this->y + rhs.y;
  this->z = this->z + rhs.z;
	this->w = this->w + rhs.w;
	return (*this);
}

ucm::vec4 ucm::vec4::operator-=(vec4 rhs){
	this->x = this->x - rhs.x;
	this->y = this->y - rhs.y;
  this->z = this->z - rhs.z;
	this->w = this->w - rhs.w;
	return (*this);
}

/* Shorthand scalar operators */
ucm::vec4 ucm::vec4::operator+=(float scalar){
	this->x = this->x + scalar;
	this->y = this->y + scalar;
  this->z = this->z + scalar;
	this->w = this->w + scalar;
	return (*this);
}

ucm::vec4 ucm::vec4::operator-=(float scalar){
	this->x = this->x - scalar;
	this->y = this->y - scalar;
  this->z = this->z - scalar;
	this->w = this->w - scalar;
	return (*this);
}

ucm::vec4 ucm::vec4::operator*=(float scalar){
	this->x = this->x * scalar;
	this->y = this->y * scalar;
  this->z = this->z * scalar;
	this->w = this->w * scalar;
	return (*this);
}

ucm::vec4 ucm::vec4::operator/=(float scalar){
	this->x = this->x / scalar;
	this->y = this->y / scalar;
  this->z = this->z / scalar;
	this->w = this->w / scalar;
	return (*this);
}

/* Miscellaneous methods */
float ucm::vec4::length() {
    return float(sqrt(
      this->x*this->x +
      this->y*this->y +
      this->z*this->z +
      this->w*this->w
    ));
}

float ucm::vec4::operator[](int idx) {
    switch(idx){
			case 0: return this->x;
			case 1: return this->y;
			case 2: return this->z;
			case 3: return this->w;
			default: return NAN;
		}
}

string ucm::vec4::toString(void) {
    char c_string[55];
    char float_buffer[9];

    strcpy(c_string,"(x: ");
    sprintf(float_buffer, "%f", this->x);
    strcat(c_string,float_buffer);

    strcat(c_string,", y: ");
    sprintf(float_buffer, "%f", this->y);
    strcat(c_string,float_buffer);

    strcat(c_string,", z: ");
    sprintf(float_buffer, "%f", this->z);
    strcat(c_string, float_buffer);

    strcat(c_string,", w: ");
    sprintf(float_buffer, "%f", this->w);
    strcat(c_string, float_buffer);

    strcat(c_string,")");

    return std::string(c_string);
}
