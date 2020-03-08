/**
* @file utilcpp-math-example.c
* @author Cameron A. Craig
* @date 17 Jan 2017
* @version 0.2.0
* @copyright 2017 Cameron A. Craig
* @brief Example usage of utilcpp-math library.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/
#include <iostream>
using namespace std;

#include <stdlib.h>

#include <utilcpp-math.h>
using namespace ucm;

int main (int argc, char *argv[]){
	//Define two vectors to be used throughout the examples.
	vec3 ones(1.0f, 1.0f, 1.0f);
	cout << "ones = " << ones.toString() << endl;
	vec3 zeros; //Default constructor initialises with zeros
	cout << "zeros = " << zeros.toString() << endl;

	//Example vector arithmetic
	cout << endl << "Vector Arithmetic:" << endl;

	vec3 sum = ones + ones;
	cout << "ones + ones = " << sum.toString() << endl;

	sum += 1.0f;
	sum -= 1.0f;
	sum *= 1.0f;
	sum /= 1.0f;

	vec3 diff = ones - ones;
	cout << "ones - ones = " << diff.toString() << endl;

	float dot_prod = vec3(12.0f, 8.0f, 5.0f).dot(vec3(2.0f, 3.0f, 4.0f));
	cout << "(12,8,5).(2,3,4) == " << dot_prod << endl;

	vec3 cross_prod = vec3(12.0f, 8.0f, 5.0f).cross(vec3(2.0f, 3.0f, 4.0f));
	cout << "(12,8,5)x(2,3,4) == " << cross_prod.toString() << endl;

	//Example scalar arithmetic
	cout << endl << "Scalar Arithmetic:" << endl;

	vec3 add = ones + 3.0f;
	cout << "ones + 3 = " << add.toString() << endl;

	vec3 sub = ones - 1.0f;
	cout << "ones - 1 = " << sub.toString() << endl;

	vec3 mul = ones * 2.0f;
	cout << "ones * 2 = " << mul.toString() << endl;

	vec3 div = ones / 2.0f;
	cout << "ones / 2 = " << div.toString() << endl;

	cout << endl << "Comparion:" << endl;
	if (ones == zeros){
		cout << "ones == zeros";
	}else {
		cout << "ones != zeros" << endl;
	}

	cout << endl << "Length/Magnitude:" << endl;
	float length = ones.length();
	cout << "|ones| = " << length << endl;

	cout << endl << "Member access:" << endl;
	float x,y,z;
	x = ones.x;
	y = ones.y;
	z = ones.z;
	cout << "z:"<< x << ", y:" << y << ", z:" << z << endl;

	x = ones.r;
	y = ones.g;
	z = ones.b;
	cout << "r:"<< x << ", g:" << y << ", b:" << z << endl;

	x = ones[0];
	y = ones[1];
	z = ones[2];
	cout << "[0]:"<< x << ", [1]:" << y << ", [2]:" << z << endl;

	return EXIT_SUCCESS;
}
