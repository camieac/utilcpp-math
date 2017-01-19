/**
* @file ucm_vec3.h
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

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

class ucm_vec3 {
    private:
      //Fields (Member variables)
      float x;
      float y;
      float z;

    public:
        //Constructors
        ucm_vec3();
        ucm_vec3(float x, float y, float z);

        float get_x(void);
        float get_y(void);
        float get_z(void);
        void set_x(float x);
        void set_y(float y);
        void set_z(float z);

        //Overrideing operators
        bool operator==(ucm_vec3 rhs);
        ucm_vec3 operator+(ucm_vec3 rhs);
        ucm_vec3 operator-(ucm_vec3 rhs);
        ucm_vec3 operator*(ucm_vec3 rhs);
        ucm_vec3 operator/(ucm_vec3 rhs);
        ucm_vec3 operator+(float scalar);
        ucm_vec3 operator-(float scalar);
        ucm_vec3 operator*(float scalar);
        ucm_vec3 operator/(float scalar);
        ucm_vec3 cross(ucm_vec3 rhs);
        float dot(ucm_vec3 rhs);
        float length(void);
        string toString(void);
};
typedef class ucm_vec3 ucm_vec3;

#endif //UTILC_VEC_3_H
