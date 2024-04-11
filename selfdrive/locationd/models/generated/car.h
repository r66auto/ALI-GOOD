#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1615733273851856782);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_588534079108109212);
void car_H_mod_fun(double *state, double *out_5222983493844414120);
void car_f_fun(double *state, double dt, double *out_2424869017441490344);
void car_F_fun(double *state, double dt, double *out_2623601853171030751);
void car_h_25(double *state, double *unused, double *out_7108329555975014541);
void car_H_25(double *state, double *unused, double *out_7957787671269649036);
void car_h_24(double *state, double *unused, double *out_6296605103778358590);
void car_H_24(double *state, double *unused, double *out_4399862072467325900);
void car_h_30(double *state, double *unused, double *out_7476731041306035423);
void car_H_30(double *state, double *unused, double *out_5961260072312294382);
void car_h_26(double *state, double *unused, double *out_1505238130700805342);
void car_H_26(double *state, double *unused, double *out_6747453083565846356);
void car_h_27(double *state, double *unused, double *out_2317871105294060633);
void car_H_27(double *state, double *unused, double *out_8184854143496237599);
void car_h_29(double *state, double *unused, double *out_2475057773645189778);
void car_H_29(double *state, double *unused, double *out_6471491416626686566);
void car_h_28(double *state, double *unused, double *out_8693729533986790170);
void car_H_28(double *state, double *unused, double *out_1389092399557155992);
void car_h_31(double *state, double *unused, double *out_7265516224326143686);
void car_H_31(double *state, double *unused, double *out_6121244981332494880);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}