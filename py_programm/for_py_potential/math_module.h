#ifndef MATH_MODULE_H__
#define MATH_MODULE_H__

#include "definitions_math.h"

#ifdef __cplusplus
extern "C" {
#endif

double calculate_single_point_potential(int x, int y, point_charge *charges, int num_of_charges);

// Вспомогательные функции (трогать только если очень надо)
int is_position_allowed(int x, int y, point_charge charge);

double calc_potential(int x, int y, point_charge charge);
vect calc_elecrtic_strenght(int x, int y, point_charge charge);

#ifdef __cplusplus
}
#endif

#endif // MATH_MODULE_H__
