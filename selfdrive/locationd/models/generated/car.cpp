#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1615733273851856782) {
   out_1615733273851856782[0] = delta_x[0] + nom_x[0];
   out_1615733273851856782[1] = delta_x[1] + nom_x[1];
   out_1615733273851856782[2] = delta_x[2] + nom_x[2];
   out_1615733273851856782[3] = delta_x[3] + nom_x[3];
   out_1615733273851856782[4] = delta_x[4] + nom_x[4];
   out_1615733273851856782[5] = delta_x[5] + nom_x[5];
   out_1615733273851856782[6] = delta_x[6] + nom_x[6];
   out_1615733273851856782[7] = delta_x[7] + nom_x[7];
   out_1615733273851856782[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_588534079108109212) {
   out_588534079108109212[0] = -nom_x[0] + true_x[0];
   out_588534079108109212[1] = -nom_x[1] + true_x[1];
   out_588534079108109212[2] = -nom_x[2] + true_x[2];
   out_588534079108109212[3] = -nom_x[3] + true_x[3];
   out_588534079108109212[4] = -nom_x[4] + true_x[4];
   out_588534079108109212[5] = -nom_x[5] + true_x[5];
   out_588534079108109212[6] = -nom_x[6] + true_x[6];
   out_588534079108109212[7] = -nom_x[7] + true_x[7];
   out_588534079108109212[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5222983493844414120) {
   out_5222983493844414120[0] = 1.0;
   out_5222983493844414120[1] = 0;
   out_5222983493844414120[2] = 0;
   out_5222983493844414120[3] = 0;
   out_5222983493844414120[4] = 0;
   out_5222983493844414120[5] = 0;
   out_5222983493844414120[6] = 0;
   out_5222983493844414120[7] = 0;
   out_5222983493844414120[8] = 0;
   out_5222983493844414120[9] = 0;
   out_5222983493844414120[10] = 1.0;
   out_5222983493844414120[11] = 0;
   out_5222983493844414120[12] = 0;
   out_5222983493844414120[13] = 0;
   out_5222983493844414120[14] = 0;
   out_5222983493844414120[15] = 0;
   out_5222983493844414120[16] = 0;
   out_5222983493844414120[17] = 0;
   out_5222983493844414120[18] = 0;
   out_5222983493844414120[19] = 0;
   out_5222983493844414120[20] = 1.0;
   out_5222983493844414120[21] = 0;
   out_5222983493844414120[22] = 0;
   out_5222983493844414120[23] = 0;
   out_5222983493844414120[24] = 0;
   out_5222983493844414120[25] = 0;
   out_5222983493844414120[26] = 0;
   out_5222983493844414120[27] = 0;
   out_5222983493844414120[28] = 0;
   out_5222983493844414120[29] = 0;
   out_5222983493844414120[30] = 1.0;
   out_5222983493844414120[31] = 0;
   out_5222983493844414120[32] = 0;
   out_5222983493844414120[33] = 0;
   out_5222983493844414120[34] = 0;
   out_5222983493844414120[35] = 0;
   out_5222983493844414120[36] = 0;
   out_5222983493844414120[37] = 0;
   out_5222983493844414120[38] = 0;
   out_5222983493844414120[39] = 0;
   out_5222983493844414120[40] = 1.0;
   out_5222983493844414120[41] = 0;
   out_5222983493844414120[42] = 0;
   out_5222983493844414120[43] = 0;
   out_5222983493844414120[44] = 0;
   out_5222983493844414120[45] = 0;
   out_5222983493844414120[46] = 0;
   out_5222983493844414120[47] = 0;
   out_5222983493844414120[48] = 0;
   out_5222983493844414120[49] = 0;
   out_5222983493844414120[50] = 1.0;
   out_5222983493844414120[51] = 0;
   out_5222983493844414120[52] = 0;
   out_5222983493844414120[53] = 0;
   out_5222983493844414120[54] = 0;
   out_5222983493844414120[55] = 0;
   out_5222983493844414120[56] = 0;
   out_5222983493844414120[57] = 0;
   out_5222983493844414120[58] = 0;
   out_5222983493844414120[59] = 0;
   out_5222983493844414120[60] = 1.0;
   out_5222983493844414120[61] = 0;
   out_5222983493844414120[62] = 0;
   out_5222983493844414120[63] = 0;
   out_5222983493844414120[64] = 0;
   out_5222983493844414120[65] = 0;
   out_5222983493844414120[66] = 0;
   out_5222983493844414120[67] = 0;
   out_5222983493844414120[68] = 0;
   out_5222983493844414120[69] = 0;
   out_5222983493844414120[70] = 1.0;
   out_5222983493844414120[71] = 0;
   out_5222983493844414120[72] = 0;
   out_5222983493844414120[73] = 0;
   out_5222983493844414120[74] = 0;
   out_5222983493844414120[75] = 0;
   out_5222983493844414120[76] = 0;
   out_5222983493844414120[77] = 0;
   out_5222983493844414120[78] = 0;
   out_5222983493844414120[79] = 0;
   out_5222983493844414120[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2424869017441490344) {
   out_2424869017441490344[0] = state[0];
   out_2424869017441490344[1] = state[1];
   out_2424869017441490344[2] = state[2];
   out_2424869017441490344[3] = state[3];
   out_2424869017441490344[4] = state[4];
   out_2424869017441490344[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2424869017441490344[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2424869017441490344[7] = state[7];
   out_2424869017441490344[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2623601853171030751) {
   out_2623601853171030751[0] = 1;
   out_2623601853171030751[1] = 0;
   out_2623601853171030751[2] = 0;
   out_2623601853171030751[3] = 0;
   out_2623601853171030751[4] = 0;
   out_2623601853171030751[5] = 0;
   out_2623601853171030751[6] = 0;
   out_2623601853171030751[7] = 0;
   out_2623601853171030751[8] = 0;
   out_2623601853171030751[9] = 0;
   out_2623601853171030751[10] = 1;
   out_2623601853171030751[11] = 0;
   out_2623601853171030751[12] = 0;
   out_2623601853171030751[13] = 0;
   out_2623601853171030751[14] = 0;
   out_2623601853171030751[15] = 0;
   out_2623601853171030751[16] = 0;
   out_2623601853171030751[17] = 0;
   out_2623601853171030751[18] = 0;
   out_2623601853171030751[19] = 0;
   out_2623601853171030751[20] = 1;
   out_2623601853171030751[21] = 0;
   out_2623601853171030751[22] = 0;
   out_2623601853171030751[23] = 0;
   out_2623601853171030751[24] = 0;
   out_2623601853171030751[25] = 0;
   out_2623601853171030751[26] = 0;
   out_2623601853171030751[27] = 0;
   out_2623601853171030751[28] = 0;
   out_2623601853171030751[29] = 0;
   out_2623601853171030751[30] = 1;
   out_2623601853171030751[31] = 0;
   out_2623601853171030751[32] = 0;
   out_2623601853171030751[33] = 0;
   out_2623601853171030751[34] = 0;
   out_2623601853171030751[35] = 0;
   out_2623601853171030751[36] = 0;
   out_2623601853171030751[37] = 0;
   out_2623601853171030751[38] = 0;
   out_2623601853171030751[39] = 0;
   out_2623601853171030751[40] = 1;
   out_2623601853171030751[41] = 0;
   out_2623601853171030751[42] = 0;
   out_2623601853171030751[43] = 0;
   out_2623601853171030751[44] = 0;
   out_2623601853171030751[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2623601853171030751[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2623601853171030751[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2623601853171030751[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2623601853171030751[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2623601853171030751[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2623601853171030751[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2623601853171030751[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2623601853171030751[53] = -9.8000000000000007*dt;
   out_2623601853171030751[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2623601853171030751[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2623601853171030751[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2623601853171030751[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2623601853171030751[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2623601853171030751[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2623601853171030751[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2623601853171030751[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2623601853171030751[62] = 0;
   out_2623601853171030751[63] = 0;
   out_2623601853171030751[64] = 0;
   out_2623601853171030751[65] = 0;
   out_2623601853171030751[66] = 0;
   out_2623601853171030751[67] = 0;
   out_2623601853171030751[68] = 0;
   out_2623601853171030751[69] = 0;
   out_2623601853171030751[70] = 1;
   out_2623601853171030751[71] = 0;
   out_2623601853171030751[72] = 0;
   out_2623601853171030751[73] = 0;
   out_2623601853171030751[74] = 0;
   out_2623601853171030751[75] = 0;
   out_2623601853171030751[76] = 0;
   out_2623601853171030751[77] = 0;
   out_2623601853171030751[78] = 0;
   out_2623601853171030751[79] = 0;
   out_2623601853171030751[80] = 1;
}
void h_25(double *state, double *unused, double *out_7108329555975014541) {
   out_7108329555975014541[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7957787671269649036) {
   out_7957787671269649036[0] = 0;
   out_7957787671269649036[1] = 0;
   out_7957787671269649036[2] = 0;
   out_7957787671269649036[3] = 0;
   out_7957787671269649036[4] = 0;
   out_7957787671269649036[5] = 0;
   out_7957787671269649036[6] = 1;
   out_7957787671269649036[7] = 0;
   out_7957787671269649036[8] = 0;
}
void h_24(double *state, double *unused, double *out_6296605103778358590) {
   out_6296605103778358590[0] = state[4];
   out_6296605103778358590[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4399862072467325900) {
   out_4399862072467325900[0] = 0;
   out_4399862072467325900[1] = 0;
   out_4399862072467325900[2] = 0;
   out_4399862072467325900[3] = 0;
   out_4399862072467325900[4] = 1;
   out_4399862072467325900[5] = 0;
   out_4399862072467325900[6] = 0;
   out_4399862072467325900[7] = 0;
   out_4399862072467325900[8] = 0;
   out_4399862072467325900[9] = 0;
   out_4399862072467325900[10] = 0;
   out_4399862072467325900[11] = 0;
   out_4399862072467325900[12] = 0;
   out_4399862072467325900[13] = 0;
   out_4399862072467325900[14] = 1;
   out_4399862072467325900[15] = 0;
   out_4399862072467325900[16] = 0;
   out_4399862072467325900[17] = 0;
}
void h_30(double *state, double *unused, double *out_7476731041306035423) {
   out_7476731041306035423[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5961260072312294382) {
   out_5961260072312294382[0] = 0;
   out_5961260072312294382[1] = 0;
   out_5961260072312294382[2] = 0;
   out_5961260072312294382[3] = 0;
   out_5961260072312294382[4] = 1;
   out_5961260072312294382[5] = 0;
   out_5961260072312294382[6] = 0;
   out_5961260072312294382[7] = 0;
   out_5961260072312294382[8] = 0;
}
void h_26(double *state, double *unused, double *out_1505238130700805342) {
   out_1505238130700805342[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6747453083565846356) {
   out_6747453083565846356[0] = 0;
   out_6747453083565846356[1] = 0;
   out_6747453083565846356[2] = 0;
   out_6747453083565846356[3] = 0;
   out_6747453083565846356[4] = 0;
   out_6747453083565846356[5] = 0;
   out_6747453083565846356[6] = 0;
   out_6747453083565846356[7] = 1;
   out_6747453083565846356[8] = 0;
}
void h_27(double *state, double *unused, double *out_2317871105294060633) {
   out_2317871105294060633[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8184854143496237599) {
   out_8184854143496237599[0] = 0;
   out_8184854143496237599[1] = 0;
   out_8184854143496237599[2] = 0;
   out_8184854143496237599[3] = 1;
   out_8184854143496237599[4] = 0;
   out_8184854143496237599[5] = 0;
   out_8184854143496237599[6] = 0;
   out_8184854143496237599[7] = 0;
   out_8184854143496237599[8] = 0;
}
void h_29(double *state, double *unused, double *out_2475057773645189778) {
   out_2475057773645189778[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6471491416626686566) {
   out_6471491416626686566[0] = 0;
   out_6471491416626686566[1] = 1;
   out_6471491416626686566[2] = 0;
   out_6471491416626686566[3] = 0;
   out_6471491416626686566[4] = 0;
   out_6471491416626686566[5] = 0;
   out_6471491416626686566[6] = 0;
   out_6471491416626686566[7] = 0;
   out_6471491416626686566[8] = 0;
}
void h_28(double *state, double *unused, double *out_8693729533986790170) {
   out_8693729533986790170[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1389092399557155992) {
   out_1389092399557155992[0] = 1;
   out_1389092399557155992[1] = 0;
   out_1389092399557155992[2] = 0;
   out_1389092399557155992[3] = 0;
   out_1389092399557155992[4] = 0;
   out_1389092399557155992[5] = 0;
   out_1389092399557155992[6] = 0;
   out_1389092399557155992[7] = 0;
   out_1389092399557155992[8] = 0;
}
void h_31(double *state, double *unused, double *out_7265516224326143686) {
   out_7265516224326143686[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6121244981332494880) {
   out_6121244981332494880[0] = 0;
   out_6121244981332494880[1] = 0;
   out_6121244981332494880[2] = 0;
   out_6121244981332494880[3] = 0;
   out_6121244981332494880[4] = 0;
   out_6121244981332494880[5] = 0;
   out_6121244981332494880[6] = 0;
   out_6121244981332494880[7] = 0;
   out_6121244981332494880[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1615733273851856782) {
  err_fun(nom_x, delta_x, out_1615733273851856782);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_588534079108109212) {
  inv_err_fun(nom_x, true_x, out_588534079108109212);
}
void car_H_mod_fun(double *state, double *out_5222983493844414120) {
  H_mod_fun(state, out_5222983493844414120);
}
void car_f_fun(double *state, double dt, double *out_2424869017441490344) {
  f_fun(state,  dt, out_2424869017441490344);
}
void car_F_fun(double *state, double dt, double *out_2623601853171030751) {
  F_fun(state,  dt, out_2623601853171030751);
}
void car_h_25(double *state, double *unused, double *out_7108329555975014541) {
  h_25(state, unused, out_7108329555975014541);
}
void car_H_25(double *state, double *unused, double *out_7957787671269649036) {
  H_25(state, unused, out_7957787671269649036);
}
void car_h_24(double *state, double *unused, double *out_6296605103778358590) {
  h_24(state, unused, out_6296605103778358590);
}
void car_H_24(double *state, double *unused, double *out_4399862072467325900) {
  H_24(state, unused, out_4399862072467325900);
}
void car_h_30(double *state, double *unused, double *out_7476731041306035423) {
  h_30(state, unused, out_7476731041306035423);
}
void car_H_30(double *state, double *unused, double *out_5961260072312294382) {
  H_30(state, unused, out_5961260072312294382);
}
void car_h_26(double *state, double *unused, double *out_1505238130700805342) {
  h_26(state, unused, out_1505238130700805342);
}
void car_H_26(double *state, double *unused, double *out_6747453083565846356) {
  H_26(state, unused, out_6747453083565846356);
}
void car_h_27(double *state, double *unused, double *out_2317871105294060633) {
  h_27(state, unused, out_2317871105294060633);
}
void car_H_27(double *state, double *unused, double *out_8184854143496237599) {
  H_27(state, unused, out_8184854143496237599);
}
void car_h_29(double *state, double *unused, double *out_2475057773645189778) {
  h_29(state, unused, out_2475057773645189778);
}
void car_H_29(double *state, double *unused, double *out_6471491416626686566) {
  H_29(state, unused, out_6471491416626686566);
}
void car_h_28(double *state, double *unused, double *out_8693729533986790170) {
  h_28(state, unused, out_8693729533986790170);
}
void car_H_28(double *state, double *unused, double *out_1389092399557155992) {
  H_28(state, unused, out_1389092399557155992);
}
void car_h_31(double *state, double *unused, double *out_7265516224326143686) {
  h_31(state, unused, out_7265516224326143686);
}
void car_H_31(double *state, double *unused, double *out_6121244981332494880) {
  H_31(state, unused, out_6121244981332494880);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
