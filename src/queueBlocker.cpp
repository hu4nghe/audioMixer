#include "queueBlocker.h"

queueBlocker::queueBlocker()
	:	Kp(0.1),
		Ki(0.01),
		Kd(0.05),
		prevErr(0),
		integral(0),
		derivative(0),
		target(50),
		delay(0){}

queueBlocker::queueBlocker(	double kp,
							double ki, 
							double kd, 
							double targetPoint)
	:	Kp(kp), 
		Ki(ki), 
		Kd(kd), 
		prevErr(0), 
		integral(0), 
		derivative(0),
		target(targetPoint),
		delay(0){}


double queueBlocker::delayCalculate(double value)
{
	auto err	=	target - value;
	integral	+=	target;
	derivative	=	err - prevErr;
	auto delay	=	Kp * err + Ki * integral + Kd * derivative;
	prevErr		=	err;
	return delay;
}