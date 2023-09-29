#pragma once
#include "pros/adi.hpp"
namespace model
{
    class Solenoid
    {
        pros::adi::Pneumatics solenoid;
        bool state;
        public:
        /**
         * @brief Creates a solenoid object.
         * @param port This is the port for the solenoid.
         * @param initstate This is the initial state for the solenoid.
        */
        Solenoid(char port, bool initstate = false);
        /**
         * @brief Toggles the piston to opposite state.
        */
        void toggle();
        /**
         * @brief Sets the state for the piston.
         * @param state State for the piston to go to.
        */
        void setState(bool istate);
        /**
         * @brief Get the state of the piston.
         * @return State of the piston.
        */
        bool getState();
    };
}