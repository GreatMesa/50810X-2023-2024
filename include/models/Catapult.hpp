#pragma once
#include <functional>
#include <memory>
#include "okapi/api.hpp"
#include "lib50810/utility/taskwrapper.hpp"
namespace model
{
    /**
     * @brief Created on 11/11/2023, useful for creating catapult systems.
    */
    class Catapult : public ryan::TaskWrapper
    {
        private:
        std::shared_ptr<okapi::Motor> motor;
        std::shared_ptr<okapi::RotationSensor> sensor;
        double degrees;
        double toggle_degrees;
        public:
        /**
         * @brief Creates a Catapult object.
         * @param motor Catapult Motor.
         * @param sensor Rotation Sensor.
         * @param degrees Degrees needed for a full rotation.
        */
        Catapult(std::shared_ptr<okapi::Motor> Motor,std::shared_ptr<okapi::RotationSensor> Sensor, double Degrees);
        /**
         * @brief Function for shooting the catapult.
        */
        void shoot();

        void loop() override;
    };
}