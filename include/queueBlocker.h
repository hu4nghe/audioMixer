#ifndef QUEUE_BLOCKER_H
#define QUEUE_BLCCKER_H

#include <chrono>

class queueBlocker
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
	public :
					 queueBlocker	();
					 queueBlocker	(double Kp,
									 double Ki,
									 double Kd,
									 double target);
			  void	setParameters	(double newKp,
									 double newKi,
									 double newKd)		{ Kp = newKp; Ki = newKi;Kd = newKd; }
			double	delayCalculate	(double value);
};

#endif // QUEUE_BLOCKER_H