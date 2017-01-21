/**
* @file vec3.h
* @author Cameron A. Craig
* @date 17 Jan 2017
* @version 0.1.0
* @copyright 2017 Cameron A. Craig
* @brief 3-axis vector maths.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
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

          string toString(void);
  };
};

#endif //UTILC_VEC_3_H
