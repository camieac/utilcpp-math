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

int main (int argc, char *argv[]){
	ucm_vec3 v1(0.1f, 0.1f, 0.1f);
	cout << "v1 = " << v1.toString() << endl;
	ucm_vec3 v2;
	cout << "v2 = " << v2.toString() << endl;
	cout << "v1.x = " << v1.get_x() << endl;
	cout << "v2.x = " << v2.get_x() << endl;

	 if (v1 == v2){
		 cout << "v1 == v2";
	 }else {
		 cout << "v1 != v2";
	 }
	 //v1.length();
	// ucm_vec3 v2();
	//
	// ucm_vec3 v3;// = v1 + v2;

	//cout << v3.length();

	// cout << ucm_version();
	cout << "\n";


	return EXIT_SUCCESS;
}
