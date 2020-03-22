/**
* @file min_max.cpp
* @author Cameron A. Craig
* @copyright 2020 Cameron A. Craig
* @brief Min and max functions
* -- RULE_3_2_CD_do_not_use_special_characters_in_filename
* -- RULE_8_1_A_provide_file_info_comment
*/

#include "min_max.h"

int ucm::min(int x, int y) {
	if (x > y) {
		return y;
	}
	return x;
}

int ucm::max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
};
