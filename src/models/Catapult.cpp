#include "Catapult.hpp"
namespace model
{
    Catapult::Catapult(std::shared_ptr<okapi::Motor> Motor,
                       std::shared_ptr<okapi::RotationSensor> Sensor,
                       double Degrees,
                       )
    {
        motor = std::move(Motor);
        sensor = std::move(Sensor);
        degrees = Degrees;
    }
    void Catapult::loop()
    {

    }
}