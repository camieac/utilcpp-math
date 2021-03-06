/**
* @file vec3.h
* @author Cameron A. Craig
* @copyright 2017 - 2020 Cameron A. Craig
* @brief 3-axis vector maths.
*/

#ifndef UTILC_VEC_3_H
#define UTILC_VEC_3_H

#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

namespace ucm {
	class vec3 {
	public:
		//Constructors
		vec3();
		vec3(float xyz);
		vec3(float x, float y, float z);

		//Fields (Member variables)
		union {
			//For coordinates
			struct {
				float x;
				float y;
				float z;
			};
			//For colours
			struct {
				float r;
				float g;
				float b;
			};
		};

		/* Overloading operators */
		float operator[](int idx);
		bool operator==(vec3 rhs);

		/* Overloading vector operators */
		vec3 operator+(vec3 rhs);
		vec3 operator-(vec3 rhs);
		vec3 operator*(vec3 rhs);
		vec3 operator/(vec3 rhs);

		/* Overloading scalar operators */
		vec3 operator+(float scalar);
		vec3 operator-(float scalar);
		vec3 operator*(float scalar);
		vec3 operator/(float scalar);

		/* Overloading vector shorthand operators */
		vec3 operator*=(vec3 rhs);
		vec3 operator/=(vec3 rhs);

		/* Overloading scalar shorthand operators */
		vec3 operator+=(float scalar);
		vec3 operator-=(float scalar);
		vec3 operator*=(float scalar);
		vec3 operator/=(float scalar);

		/* Overloading vector shorthand operators */
		vec3 operator+=(vec3 rhs);
		vec3 operator-=(vec3 rhs);

		vec3 cross(vec3 rhs);
		float dot(vec3 rhs);

		//Miscellaneous methods
		float length(void);
		vec3 normalize();

		string toString(void);
	};
	ostream& operator<<(ostream& os, const vec3& v);
	vec3 abs(vec3 v);
};

#endif //UTILC_VEC_3_H
