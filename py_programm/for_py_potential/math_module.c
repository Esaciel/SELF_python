#include "math_module.h"

// Расчет потенциала единственной точки //////////////////////////////////////////////////////////
double calculate_single_point_potential(int x, int y, point_charge *charges, int num_of_charges)
{
    double potential = 0.0;
    for (int c = 0; c < num_of_charges; c++)
    {
        if (!is_position_allowed(x, y, charges[c]))
            return 0.0;
        potential += calc_potential(x, y, charges[c]);
    }
    return potential;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
// Проверка позиции ///////////////////////////////////////////////////////////
int is_position_allowed(int x, int y, point_charge charge)
{
    double r = sqrt(pow(abs(charge.x - x), 2) + pow(abs(charge.y - y), 2));
    return ((r < RADIUS_RESTRICTION) ? 0 : 1);
}
//////////////////////////////////////////////////////////////////////////////
// Расчет значений /////////////////////////////////////////////////////////////////////////////////////////
double calc_potential(int x, int y, point_charge charge)
{
    double r = PIXEL_TO_METER_CONVERSION * sqrt(pow(abs(charge.x - x), 2) + pow(abs(charge.y - y), 2));
    return (Q_TO_nQ * ELECTRIC_COEFFICIENT * charge.value / r);
}

vect calc_elecrtic_strenght(int x, int y, point_charge charge)
{
    double r = PIXEL_TO_METER_CONVERSION * sqrt(pow(abs(charge.x - x), 2) + pow(abs(charge.y - y), 2));
    double full_vect = Q_TO_nQ * ELECTRIC_COEFFICIENT * charge.value / pow(r, 2);
    vect result;
    result.x_component = cos(x - charge.x) * full_vect;
    result.y_component = sin(y - charge.y) * full_vect;
    return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
