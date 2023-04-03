#pragma once
#include "MotionLimits.hpp"
namespace lib50810
{
    class MotionProfile{
        protected:

        MotionLimits limits;
        bool ifReversed {false};
        
        //Vector for storing amount of time during each phase.
        std::vector<okapi::QTime> t_phase;
        //Vector for storing the velocity during each phase.
        std::vector<okapi::QSpeed> v_phase;
        //Vector for storing the acceleration during each phase.
        std::vector<okapi::QAcceleration> a_phase;
        //Vector for storing the jerk during each phase.
        std::vector<okapi::QJerk> j_phase;
        public:
        
        /**
         * @brief Function for setting the limits for the motion profile
         * @param limits The limits for the motion profile
        */
        virtual void setLimits(MotionLimits limits);
        /**
         * @brief Function for generating the motion profile.
         * @param distance The distance for the motion profile
        */
        virtual void setDistance(QLength distance);
        /**
         * @brief Gets the position at a certian point or time.
         * @param time Param for time
        */
        virtual void getPosition(QTime time);
        /**
         * @brief Gets the velocity at a certian point or time.
         * @param time Param for time
        */
        virtual void getVelocity(QTime time);
        /**
         * @brief Gets the acceleration at a certian point or time.
         * @param time Param for time
        */
        virtual void getAcceleration(QTime time);
    };
};