#ifndef QUEUE_BLOCKER_H
#define QUEUE_BLCCKER_H

#include <chrono>
#include "audioQueue.h"

class blocker
{
	private :
		double Kp;
		double Ki;
		double Kd;
		double prevErr;
		double integral;
		double derivative;
		double target;
		double delay;
		double inputSpeed;
		double outputSpeed;
	public :
					blocker			();
					blocker			(double Kp,
									 double Ki,
									 double Kd,
									 double target);
	inline	  void	setInputspeed   (double Ispeed)		{ inputSpeed  = Ispeed; }
			  void	setOutputspeed  (double Ospeed)		{ outputSpeed = Ospeed; }
			  void	setParameters	(double newKp,
									 double newKi,
									 double newKd)		{ Kp = newKp; Ki = newKi;Kd = newKd; }
			double	delayCalculate	(double value);
};

#endif // QUEUE_BLOCKER_H