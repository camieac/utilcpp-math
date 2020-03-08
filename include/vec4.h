/**
* @file vec4.h
* @author Cameron A. Craig
* @date 20 Jan 2017
* @version 0.2.0
* @copyright 2017 Cameron A. Craig
* @brief 4-axis vector maths.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/

#ifndef UTILC_VEC_4_H
#define UTILC_VEC_4_H

#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

namespace ucm {
	class vec4 {
		public:
		//Constructors
		vec4();
		vec4(float xyzw);
		vec4(float x, float y, float z, float w);

		//Fields (Member variables)
		union {
			//For coordinates
			struct {
				float x;
				float y;
				float z;
				float w;
			};
	        //For colours
			struct {
				float r;
				float g;
				float b;
				float a;
			};
		};

		/* Overloading vector operators */
		float& operator[](int idx);
		bool operator==(vec4 rhs);
		vec4 operator+(vec4 rhs);
		vec4 operator-(vec4 rhs);
		vec4 operator*(vec4 rhs);
		vec4 operator/(vec4 rhs);

		/* Overloading scalar operators */
		vec4 operator+(float scalar);
		vec4 operator-(float scalar);
		vec4 operator*(float scalar);
		vec4 operator/(float scalar);

		/* Overloading scalar shorthand operators */
		vec4 operator+=(float scalar);
		vec4 operator-=(float scalar);
		vec4 operator*=(float scalar);
		vec4 operator/=(float scalar);

		/* Overloading vector shorthand operators */
		vec4 operator+=(vec4 rhs);
		vec4 operator-=(vec4 rhs);

		vec4 cross(vec4 rhs);
		float dot(vec4 rhs);

		//Miscellaneous methods
		float length(void);

		string toString(void);
	};
	ostream& operator<<(ostream& os, const vec4& v);
	vec4 abs(vec4 v);
};

#endif //UTILC_VEC_3_H
