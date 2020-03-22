/**
* @file utilcpp-math-example.c
* @author Cameron A. Craig
* @copyright 2017 - 2020 Cameron A. Craig
* @brief Example usage of utilcpp-math library.
*/

#include "utilcpp-math.h"
#include <stdlib.h>
#include <iostream>

static void vec3_examples() {
	cout << "vec3 examples" << std::endl;
	cout << "------------------------------------------------" << std::endl;
	// Define two vectors to be used throughout the examples.
	ucm::vec3 ones(1.0f, 1.0f, 1.0f);
	cout << "ones = " << ones.toString() << std::endl;

	// Default constructor initialises with zeros
	ucm::vec3 zeros;
	cout << "zeros = " << zeros.toString() << std::endl;

	// Example vector arithmetic
	cout << std::endl << "Vector Arithmetic:" << std::endl;

	ucm::vec3 sum = ones + ones;
	cout << "ones + ones = " << sum.toString() << std::endl;

	sum += 1.0f;
	sum -= 1.0f;
	sum *= 1.0f;
	sum /= 1.0f;

	ucm::vec3 diff = ones - ones;
	cout << "ones - ones = " << diff.toString() << std::endl;

	float dot_prod = ucm::vec3(12.0f, 8.0f, 5.0f)
		.dot(ucm::vec3(2.0f, 3.0f, 4.0f));
	cout << "(12,8,5).(2,3,4) == " << dot_prod << std::endl;

	ucm::vec3 cross_prod = ucm::vec3(12.0f, 8.0f, 5.0f)
		.cross(ucm::vec3(2.0f, 3.0f, 4.0f));
	cout << "(12,8,5)x(2,3,4) == " << cross_prod.toString() << std::endl;

	// Example scalar arithmetic
	cout << std::endl << "Scalar Arithmetic:" << std::endl;

	ucm::vec3 add = ones + 3.0f;
	cout << "ones + 3 = " << add.toString() << std::endl;

	ucm::vec3 sub = ones - 1.0f;
	cout << "ones - 1 = " << sub.toString() << std::endl;

	ucm::vec3 mul = ones * 2.0f;
	cout << "ones * 2 = " << mul.toString() << std::endl;

	ucm::vec3 div = ones / 2.0f;
	cout << "ones / 2 = " << div.toString() << std::endl;

	cout << std::endl << "Comparion:" << std::endl;
	if (ones == zeros) {
		cout << "ones == zeros";
	} else {
		cout << "ones != zeros" << std::endl;
	}

	cout << std::endl << "Length/Magnitude:" << std::endl;
	float length = ones.length();
	cout << "|ones| = " << length << std::endl;

	cout << std::endl << "Member access:" << std::endl;
	float x, y, z;
	x = ones.x;
	y = ones.y;
	z = ones.z;
	cout << "z:"<< x << ", y:" << y << ", z:" << z << std::endl;

	x = ones.r;
	y = ones.g;
	z = ones.b;
	cout << "r:"<< x << ", g:" << y << ", b:" << z << std::endl;

	x = ones[0];
	y = ones[1];
	z = ones[2];
	cout << "[0]:"<< x << ", [1]:" << y << ", [2]:" << z << std::endl;

	cout << "------------------------------------------------" << std::endl;
	cout << std::endl;
}

static void vec4_examples() {
	cout << "vec4 examples" << std::endl;
	cout << "------------------------------------------------" << std::endl;
	// Define two vectors to be used throughout the examples.
	ucm::vec4 ones(1.0f, 1.0f, 1.0f, 1.0f);
	cout << "ones = " << ones.toString() << std::endl;

	// Default constructor initialises with zeros
	ucm::vec4 zeros;
	cout << "zeros = " << zeros.toString() << std::endl;

	// Example vector arithmetic
	cout << std::endl << "Vector Arithmetic:" << std::endl;

	ucm::vec4 sum = ones + ones;
	cout << "ones + ones = " << sum.toString() << std::endl;

	sum += 1.0f;
	sum -= 1.0f;
	sum *= 1.0f;
	sum /= 1.0f;

	ucm::vec4 diff = ones - ones;
	cout << "ones - ones = " << diff.toString() << std::endl;

	float dot_prod = ucm::vec4(12.0f, 8.0f, 5.0f, 3.0f)
		.dot(ucm::vec4(2.0f, 3.0f, 4.0f, 5.0f));
	cout << "(12,8,5,3).(2,3,4,5) == " << dot_prod << std::endl;

	// Example scalar arithmetic
	cout << std::endl << "Scalar Arithmetic:" << std::endl;

	ucm::vec4 add = ones + 3.0f;
	cout << "ones + 3 = " << add.toString() << std::endl;

	ucm::vec4 sub = ones - 1.0f;
	cout << "ones - 1 = " << sub.toString() << std::endl;

	ucm::vec4 mul = ones * 2.0f;
	cout << "ones * 2 = " << mul.toString() << std::endl;

	ucm::vec4 div = ones / 2.0f;
	cout << "ones / 2 = " << div.toString() << std::endl;

	cout << endl << "Comparion:" << std::endl;
	if (ones == zeros) {
		cout << "ones == zeros";
	} else {
		cout << "ones != zeros" << std::endl;
	}

	cout << std::endl << "Length/Magnitude:" << std::endl;
	float length = ones.length();
	cout << "|ones| = " << length << std::endl;

	cout << std::endl << "Member access:" << std::endl;
	float x, y, z, w;
	x = ones.x;
	y = ones.y;
	z = ones.z;
	w = ones.w;
	cout << "z: "<< x << ", y: " << y
		<< ", z: " << z << ", w: " << w << std::endl;

	x = ones.r;
	y = ones.g;
	z = ones.b;
	w = ones.a;
	cout << "r: "<< x << ", g: " << y
		<< ", b: " << z << ", a: " << w << std::endl;

	x = ones[0];
	y = ones[1];
	z = ones[2];
	w = ones[3];
	cout << "[0]:"<< x << ", [1]:" << y
		<< ", [2]:" << z << ", [3]:" << w << std::endl;

	cout << "------------------------------------------------" << std::endl;
	cout << std::endl;
}

static void min_max_examples() {
	cout << endl << "Min/Max examples" << endl;
	cout << "------------------------------------------------" << std::endl;
	cout << "min(1, 0) = " << ucm::min(1, 0) << endl;
	cout << "max(1, 0) = " << ucm::max(1, 0) << endl;

	cout << "min(1.0, 0.0) = " << ucm::min(1.0f, 0.0f) << endl;
	cout << "max(1.0, 0.0) = " << ucm::max(1.0f, 0.0f) << endl;

	cout << "------------------------------------------------" << std::endl;
	cout << endl;
}

int main(int argc, char *argv[]) {
	vec3_examples();
	vec4_examples();
	min_max_examples();

	return EXIT_SUCCESS;
}
