#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

// void PID::Init(double Kp, double Ki, double Kd) {
// }
//
// void PID::UpdateError(double cte) {
// }
//
// double PID::TotalError() {
// }


void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Kd = Kd;
	PID::Ki = Ki;
}

void PID::UpdateError(double cte) {

	if (first_cte){
		//if this is the first cte signal received
		prev_cte = cte;
		sum_cte = 0;
	  first_cte= false;
	}
  p_error = cte;
  d_error = cte- prev_cte;
  i_error = sum_cte;
  prev_cte = cte;      //Set prev_cte as current CTE for next iteration
  sum_cte += cte;

}

double PID::TotalError()  {
	double steer = -1*(Kp*p_error + Kd*d_error + Ki*i_error);
	if(steer > 1){
		steer = 1;
	}
	if(steer< -1){
		steer= -1;
	}
	return steer;
}
