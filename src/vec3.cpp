/**
* @file vec3.cpp
* @author Cameron A. Craig
* @copyright 2017 - 2020 Cameron A. Craig
* @brief 3-axis vector maths.
*/

#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <sstream>

#include "utilcpp-math/vec3.h"

/* Constructors */
ucm::vec3::vec3() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

ucm::vec3::vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

ucm::vec3::vec3(float xyz) {
	this->x = xyz;
	this->y = xyz;
	this->z = xyz;
}

/* Vector Arithmetic */
ucm::vec3 ucm::vec3::operator+(ucm::vec3 rhs) {
	return ucm::vec3(
		this->x + rhs.x,
		this->y + rhs.y,
		this->z + rhs.z
	);
}

ucm::vec3 ucm::vec3::operator-(vec3 rhs) {
	return ucm::vec3(
		this->x - rhs.x,
		this->y - rhs.y,
		this->z - rhs.z
	);
}

float ucm::vec3::dot(vec3 rhs) {
	return (
		this->x * rhs.x +
		this->y * rhs.y +
		this->z * rhs.z
	);
}

ucm::vec3 ucm::vec3::cross(ucm::vec3 rhs) {
	return ucm::vec3(
		this->y * rhs.z - this->z * rhs.y,
		this->z * rhs.x - this->x * rhs.z,
		this->x * rhs.y - this->y * rhs.x
	);
}

/* Scalar Arithmetic */
ucm::vec3 ucm::vec3::operator+(float scalar) {
	return ucm::vec3(
		this->x + scalar,
		this->y + scalar,
		this->z + scalar
	);
}

ucm::vec3 ucm::vec3::operator-(float scalar) {
	return ucm::vec3(
		this->x - scalar,
		this->y - scalar,
		this->z - scalar
	);
}

ucm::vec3 ucm::vec3::operator*(float scalar) {
	return ucm::vec3(
		this->x * scalar,
		this->y * scalar,
		this->z * scalar
	);
}

ucm::vec3 ucm::vec3::operator/(float scalar) {
	return ucm::vec3(
		this->x / scalar,
		this->y / scalar,
		this->z / scalar
	);
}

/* Shorthand scalar operators */
ucm::vec3 ucm::vec3::operator+=(float scalar) {
	this->x = this->x + scalar;
	this->y = this->y + scalar;
	this->z = this->z + scalar;
	return (*this);
}

ucm::vec3 ucm::vec3::operator-=(float scalar) {
	this->x = this->x - scalar;
	this->y = this->y - scalar;
	this->z = this->z - scalar;
	return (*this);
}

ucm::vec3 ucm::vec3::operator*=(float scalar) {
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	this->z = this->z * scalar;
	return (*this);
}

ucm::vec3 ucm::vec3::operator/=(float scalar) {
	this->x = this->x / scalar;
	this->y = this->y / scalar;
	this->z = this->z / scalar;
	return (*this);
}

/* Shorthand vector operators */
ucm::vec3 ucm::vec3::operator+=(vec3 rhs) {
	this->x = this->x + rhs.x;
	this->y = this->y + rhs.y;
	this->z = this->z + rhs.z;
	return (*this);
}

ucm::vec3 ucm::vec3::operator-=(vec3 rhs) {
	this->x = this->x - rhs.x;
	this->y = this->y - rhs.y;
	this->z = this->z - rhs.z;
	return (*this);
}

/* Miscellaneous methods */
float ucm::vec3::length() {
	return static_cast<float>(sqrt(
		this->x * this->x +
		this->y * this->y +
		this->z * this->z
	));
}

ucm::vec3 ucm::vec3::normalize() {
	float l = this->length();
	this->x /= l;
	this->y /= l;
	this->z /= l;
	return (*this);
}

ucm::vec3 ucm::abs(ucm::vec3 v) {
	return ucm::vec3(
		std::abs(v.x),
		std::abs(v.y),
		std::abs(v.z)
	);
}

bool ucm::vec3::operator==(vec3 rhs) {
	return(this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
}

float ucm::vec3::operator[](int idx) {
	switch(idx) {
		case 0: return this->x;
		case 1: return this->y;
		case 2: return this->z;
		default: return NAN;
	}
}

string ucm::vec3::toString(void) {
	ostringstream ss;
	ss << "(x: " << x << ", y: " << y << ", z: " << z << ")";
	return ss.str();
}

ostream& ucm::operator<<(ostream& os, const ucm::vec3& v) {
	os << v.x << endl;
	os << v.y << endl;
	os << v.z << endl;
	return os;
}
