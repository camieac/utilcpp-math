/**
* @file utilc-math-example.c
* @author Cameron A. Craig
* @date 17 Jan 2017
* @version 0.1.0
* @copyright 2017 Cameron A. Craig
* @brief Example usage of utilc-math library.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/
#include <iostream>
using namespace std;

#include <stdlib.h>

#include <utilc-math.h>
using namespace ucm;

int main (int argc, char *argv[]){
	//Define two vectors to be used throughout the examples.
	vec3 v1(0.1f, 0.1f, 0.1f);
	cout << "v1 = " << v1.toString() << endl;

	vec3 v2;
	cout << "v2 = " << v2.toString() << endl;

	//Example vector arithmetic
	vec3 sum = v1 + v2;

	vec3 dif = v1 - v2;

	float dot_prod = v1.dot(v2);

	vec3 cross_prod = v1.cross(v2);

	//Example scalar arithmetic
	vec3 add = v1 + 3.0f;

	vec3 sub = v1 - 1.0f;

	vec3 mul = v1 * 2.0f;

	vec3 div = v1 / 2.0f;

	 if (v1 == v2){
		 cout << "v1 == v2";
	 }else {
		 cout << "v1 != v2";
	 }
	 //v1.length();
	// vec3 v2();
	//
	// vec3 v3;// = v1 + v2;

	//cout << v3.length();

	// cout << ucm_version();
	cout << "\n";


	return EXIT_SUCCESS;
}
