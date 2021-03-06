/**
* @file vec4.cpp
* @author Cameron A. Craig
* @copyright 2017 - 2020 Cameron A. Craig
* @brief 4-axis vector maths.
*/

#include <stdlib.h>
#include <cmath>
#include <string>
#include <iostream>
#include <sstream>

#include "utilcpp-math/vec4.h"

/* Constructors */
ucm::vec4::vec4() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
}

ucm::vec4::vec4(float xyzw) {
	this->x = xyzw;
	this->y = xyzw;
	this->z = xyzw;
	this->w = xyzw;
}

ucm::vec4::vec4(float x, float y, float z, float w) {
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
ucm::vec4 ucm::vec4::operator+=(vec4 rhs) {
	this->x = this->x + rhs.x;
	this->y = this->y + rhs.y;
	this->z = this->z + rhs.z;
	this->w = this->w + rhs.w;
	return (*this);
}

ucm::vec4 ucm::vec4::operator-=(vec4 rhs) {
	this->x = this->x - rhs.x;
	this->y = this->y - rhs.y;
	this->z = this->z - rhs.z;
	this->w = this->w - rhs.w;
	return (*this);
}

/* Shorthand scalar operators */
ucm::vec4 ucm::vec4::operator+=(float scalar) {
	this->x = this->x + scalar;
	this->y = this->y + scalar;
	this->z = this->z + scalar;
	this->w = this->w + scalar;
	return (*this);
}

ucm::vec4 ucm::vec4::operator-=(float scalar) {
	this->x = this->x - scalar;
	this->y = this->y - scalar;
	this->z = this->z - scalar;
	this->w = this->w - scalar;
	return (*this);
}

ucm::vec4 ucm::vec4::operator*=(float scalar) {
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	this->z = this->z * scalar;
	this->w = this->w * scalar;
	return (*this);
}

ucm::vec4 ucm::vec4::operator/=(float scalar) {
	this->x = this->x / scalar;
	this->y = this->y / scalar;
	this->z = this->z / scalar;
	this->w = this->w / scalar;
	return (*this);
}

/* Miscellaneous methods */
float ucm::vec4::length() {
	return static_cast<float>(sqrt(
		this->x*this->x +
		this->y*this->y +
		this->z*this->z +
		this->w*this->w
	));
}

ucm::vec4 ucm::abs(ucm::vec4 v) {
	return ucm::vec4(
		std::abs(v.x),
		std::abs(v.y),
		std::abs(v.z),
		std::abs(v.w)
	);
}

float& ucm::vec4::operator[](int idx) {
	switch(idx) {
		case 0: return this->x;
		case 1: return this->y;
		case 2: return this->z;
		case 3: return this->w;
	}
}

string ucm::vec4::toString(void) {
	ostringstream ss;
	ss << "(x: " << x << ", y: " << y << ", z: " << z << ", w: " << w << ")";
	return ss.str();
}

ostream& ucm::operator<<(ostream& os, const ucm::vec4& v) {
	os << v.x << endl;
	os << v.y << endl;
	os << v.z << endl;
	os << v.w << endl;
	return os;
}
