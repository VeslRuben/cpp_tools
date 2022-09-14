#pragma once

namespace control {

    class Pid {
    public:
        Pid(double kp, double ti, double td, double dt, double setpoint, double min, double max);

        /**
         * Calculates the output of the PID controller
         * @param input The current input
         * @return The output of the PID controller
         */
        double calculate(double input);

        void setSetpoint(double setpoint){
            this->setpoint = setpoint;
        }

        void setLimits(double min, double max){
            this->min = min;
            this->max = max;
        }

        void setDeadband(double deadband){
            this->deadband = deadband;
        }

    private:
        double kp;
        double ti;
        double td;
        double dt;
        double setpoint;
        double min;
        double max;
        double error;
        double errorSum;
        double errorDiff;
        double lastError;
        double deadband = 0.01;
        double hysteresis = 0.01;
        double lastOutput = 0;
    };

}