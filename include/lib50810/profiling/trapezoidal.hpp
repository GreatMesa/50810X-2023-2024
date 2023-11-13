#pragma once
#include "lib50810/profiling/constraint.hpp"
#include "lib50810/profiling/profilepoint.hpp"
#include <vector>
namespace lib50810
{
    class trapezoidalProfile
    {
        private:
        ChassisConstraint constraint; //Chassis constraint for profile.
        int direction; //Int for foward or negative direction.
        okapi::QLength mincruise; //Minimum distance for cruise period.
        okapi::QLength distance; // Distance for the profiel to follow.
        okapi::QTime at, ct, dt; // Times phases for the profile.
        okapi::QTime totaltime;
        okapi::QLength d1, d2, d3;
        okapi::QSpeed v1, v2, v3;
        okapi::QAcceleration a1, a2, a3;
        public:
        double divs, iterations;
        trapezoidalProfile() = default;
        /**
         * @brief Creates a trapezoidal profile object.
         * @param constraint Constraints used in generating profile.
         * @param divs Time to iterate by.
        */
        trapezoidalProfile(ChassisConstraint constraint, double divs);

        /**
         * @brief Sets the phases for the profile.
         * @param distance Distance for the profile.
        */
        void setPhases(okapi::QLength distance);
        /**
         * @brief Sets a 2 stage motion profile.
        */
        void TriangularProfile();
        /**
         * @brief Sets a 3 stage motion profile.
        */
        void TrapezoidalProfile();
        /**
         * @brief Returns the total time of the profile.
         * @return Total profile time.
        */
        okapi::QTime maxTime();
        /**
         * @brief Returns position at a certian time.
         * @param time Time to check profile.
         * @return Position at given time.
        */
        okapi::QLength getPosition(okapi::QTime time);
        /**
         * @brief Returns velocity at a certian time.
         * @param time Time to check profile.
         * @return Velocity at given time.
        */
        okapi::QSpeed getVelocity(okapi::QTime time);
        /**
         * @brief Returns acceleration at a certian time.
         * @param time Time to check profile.
         * @return Acceleration at given time.
        */
        okapi::QAcceleration getAcceleration(okapi::QTime time);
        /**
         * @brief Returns profile point at a certian time.
         * @param time Time to check profile.
         * @return Profile Point at given time.
        */
        profilePoint getPoint(okapi::QTime time);
        /**
         * @brief Returns a profile.
         * @return Generated Profile.
        */
        std::vector<profilePoint> generateProfile(okapi::QLength distance);
    };
}