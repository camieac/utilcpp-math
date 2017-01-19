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
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#include "utilc-math.h"

ucm_vec3::ucm_vec3(){
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
}

ucm_vec3::ucm_vec3(float x, float y, float z){
  this->x = x;
  this->y = y;
  this->z = z;
}

float ucm_vec3::get_x(void){
  return this->x;
}

float ucm_vec3::get_y(void){
  return this->y;
}

float ucm_vec3::get_z(void){
  return this->z;
}

void ucm_vec3::set_x(float x){
  this->x = x;
}

void ucm_vec3::set_y(float y){
  this->y = y;
}

void ucm_vec3::set_z(float z){
  this->z = z;
}

bool ucm_vec3::operator==(ucm_vec3 rhs) {
    return(this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
}

ucm_vec3 ucm_vec3::operator+(ucm_vec3 rhs) {
	return ucm_vec3(
		this->x + rhs.x,
		this->y + rhs.y,
		this->z + rhs.z
	);
}

ucm_vec3 ucm_vec3::operator/(float scalar) {
	return ucm_vec3(
		this->x / scalar,
		this->y / scalar,
		this->z / scalar
	);
}

float ucm_vec3::dot(ucm_vec3 rhs) {
    return (
			this->x * rhs.x +
			this->y * rhs.y +
			this->z * rhs.z
		);
}

ucm_vec3 ucm_vec3::cross(ucm_vec3 rhs) {
	return ucm_vec3(
		this->y * rhs.z - this->z * rhs.y,
		this->z * rhs.x - this->x * rhs.z,
		this->x * rhs.y - this->y * rhs.x
	);
}

float ucm_vec3::length() {
    return float(sqrt( this->x*this->x + this->y*this->y + this->z*this->z ));
}

string ucm_vec3::toString(void)
{
    char c_string[40];
    char float_buffer[9];

    strcpy(c_string,"(x: ");
    sprintf(float_buffer, "%f", x);
    strcat(c_string,float_buffer);
    cout < c_string;

    strcat(c_string,", y: ");
    sprintf(float_buffer, "%f", y);
    strcat(c_string,float_buffer);
    cout < c_string;

    strcat(c_string,", z: ");
    sprintf(float_buffer, "%f", z);
    strcat(c_string, float_buffer);
    cout < c_string;

    strcat(c_string,")");
    cout < c_string;

    return std::string(c_string);
}

int ucm_version(void);
