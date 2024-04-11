#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_8830313127491550522);
void live_err_fun(double *nom_x, double *delta_x, double *out_7908678811988243858);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_941763017296711969);
void live_H_mod_fun(double *state, double *out_6823151941932317943);
void live_f_fun(double *state, double dt, double *out_2403288129910261610);
void live_F_fun(double *state, double dt, double *out_650572151652149189);
void live_h_4(double *state, double *unused, double *out_8118881495832247998);
void live_H_4(double *state, double *unused, double *out_4825432206016758516);
void live_h_9(double *state, double *unused, double *out_989251737294441862);
void live_H_9(double *state, double *unused, double *out_6334092932428345630);
void live_h_10(double *state, double *unused, double *out_2465302419882892756);
void live_H_10(double *state, double *unused, double *out_5621009454868272093);
void live_h_12(double *state, double *unused, double *out_3517055550585568807);
void live_H_12(double *state, double *unused, double *out_5446531231064352183);
void live_h_35(double *state, double *unused, double *out_8628897288838199418);
void live_H_35(double *state, double *unused, double *out_8192094263389365892);
void live_h_32(double *state, double *unused, double *out_7834541211346809503);
void live_H_32(double *state, double *unused, double *out_8323259048330106361);
void live_h_13(double *state, double *unused, double *out_7480146177107144916);
void live_H_13(double *state, double *unused, double *out_4085164215042953269);
void live_h_14(double *state, double *unused, double *out_989251737294441862);
void live_H_14(double *state, double *unused, double *out_6334092932428345630);
void live_h_33(double *state, double *unused, double *out_25273791197226189);
void live_H_33(double *state, double *unused, double *out_7104092805681328120);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}