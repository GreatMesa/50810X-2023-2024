#pragma once
#include "lib50810/utility/Units.hpp"
#include <iostream>
namespace lib50810
{
    struct profilePoint
    {
        public:
        /**
         * @brief Constructs a profile point at a given time.
         * @param leftpos Left-side position.
         * @param rightpos Right-side position.
         * @param leftvel Left-side velocity.
         * @param rightvel Right-side velocity.
         * @param leftaccel Left-side acceleration.
         * @param rightaccel Right-side acceleration.
        */
        profilePoint(double leftpos, double rightpos, double leftvel, double rightvel, double leftaccel, double rightaccel);
        /**
         * @brief Constructs a linear profile point at a given time.
         * @param pos Position.
         * @param vel Velocity.
         * @param accel Acceleration.
        */
        profilePoint(double pos, double vel, double accel);

        profilePoint() = default;
        double leftpos, rightpos, leftvel, rightvel, leftaccel, rightaccel;
        friend std::ostream& operator<<(std::ostream& os, profilePoint const& pt)
        {
            return std::cout << pt.leftpos<< ","<< pt.rightpos<< "," << pt.leftvel
            << ","<<pt.rightvel<<","<<pt.leftaccel<< ","<<pt.rightaccel<< ","<<std::endl;
        }
    };
}