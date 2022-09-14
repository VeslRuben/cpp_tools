#include "pid.h"


namespace control{


    Pid::Pid(double kp, double ti, double td, double dt, double setpoint, double min, double max) {
        this->kp = kp;
        this->ti = ti;
        this->td = td;
        this->dt = dt;
        this->setpoint = setpoint;
        this->min = min;
        this->max = max;
        this->error = 0;
        this->errorSum = 0;
        this->errorDiff = 0;
        this->lastError = 0;

    }

    double Pid::calculate(double input) {
        this->error = this->setpoint - input;
        // deadband
        if (this->error < this->deadband && this->error > -this->deadband) {
            this->error = 0;
        }
        this->errorSum += this->error * this->dt;
        if (this->errorSum > this->max) {
            this->errorSum = this->max;
        } else if (this->errorSum < this->min) {
            this->errorSum = this->min;
        }
        this->errorDiff = (this->error - this->lastError) / this->dt;
        this->lastError = this->error;

        double output = this->kp * this->error + this->kp / this->ti * this->errorSum + this->kp * this->td * this->errorDiff;

        //hysteresis
        if (output < this->lastOutput + this->hysteresis && output > this->lastOutput - this->hysteresis) {
            output = this->lastOutput;
        }

        if (output > this->max) {
            output = this->max;
        } else if (output < this->min) {
            output = this->min;
        }
        this->lastOutput = output;

        return output;
    }
}
