/**
* @file mat4x4.h
* @author Cameron A. Craig
* @date 29 Jan 2017
* @version 0.1.0
* @copyright 2017 Cameron A. Craig
* @brief 4x4 matrix maths.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/

#ifndef UTILC_MAT_4X4_H
#define UTILC_MAT_4X4_H

#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

#include "vec4.h"

namespace ucm {
	class mat4x4 {
		public:
			//Constructors
			mat4x4();
			mat4x4(float all);
			mat4x4(ucm::vec4 col1, ucm::vec4 col2, ucm::vec4 col3, ucm::vec4 col4);

			//Fields (Member variables)
			ucm::vec4 mat[4];

			/* Overloading matrix operators */
			ucm::vec4& operator[](int idx);
			bool operator==(mat4x4 rhs);
			mat4x4 operator+(mat4x4 rhs);
			mat4x4 operator-(mat4x4 rhs);
			mat4x4 operator*(mat4x4 rhs);
			mat4x4 operator/(mat4x4 rhs);

			/* Overloading scalar operators */
			mat4x4 operator+(float scalar);
			mat4x4 operator-(float scalar);
			mat4x4 operator*(float scalar);
			mat4x4 operator/(float scalar);

			/* Overloading scalar shorthand operators */
			mat4x4 operator+=(float scalar);
			mat4x4 operator-=(float scalar);
			mat4x4 operator*=(float scalar);
			mat4x4 operator/=(float scalar);

			/* Overloading matrix shorthand operators */
			mat4x4 operator+=(mat4x4 rhs);
			mat4x4 operator-=(mat4x4 rhs);
	};
	ostream& operator<<(ostream& os, mat4x4& m);
};

#endif //UTILC_MAT_4X4_H
