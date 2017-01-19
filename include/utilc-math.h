/**
* @file utilc-math.h
* @author Cameron A. Craig
* @date 17 Jan 2017
* @version 0.1.0
* @copyright 2017 Cameron A. Craig
* @brief Defines uc_timing_h handle and function prototypes.
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/
#ifndef UTILC_MATH_H
#define UTILC_MATH_H

#include <string>
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

int ucm_version(void);

#endif
