#include "lib50810/profiling/trapezoidal.hpp"
namespace lib50810
{
    using namespace okapi;
    trapezoidalProfile::trapezoidalProfile(ChassisConstraint constraint, double div)
    {
        divs = div;
        this->constraint = constraint;
        mincruise = constraint.maxVelocity * constraint.maxVelocity / constraint.maxAcceleration;
        a1 = constraint.maxAcceleration;
        a2 = 0*ftps2;
        a3 = -constraint.maxAcceleration;
    }
    void trapezoidalProfile::TriangularProfile()
    {
        //Time phases
        at = sqrt(distance / constraint.maxAcceleration);
        ct = 0*second;
        dt = at;
        //Distance phases
        d1 = (distance / 2);
        d2 = 0 * foot;
        d3 = d1;
        //Velocity phases.
        v1 = 0 * ftps;
        v2 = at * constraint.maxAcceleration;
        v3 = v2;

        totaltime = at + ct + dt;
    }
    void trapezoidalProfile::TrapezoidalProfile()
    {
        //Distance phases
        d1 = 0.5 * constraint.maxVelocity * constraint.maxVelocity / constraint.maxAcceleration;
        at = constraint.maxVelocity / constraint.maxAcceleration;

        ct = (distance - (d1 *2)) / constraint.maxVelocity;
        d2 =  constraint.maxVelocity * ct;

        d3 = d1;
        dt = at;
        //Velocity phases.
        v1 = 0*ftps;
        v2 = constraint.maxVelocity;
        v3 = constraint.maxVelocity;

        totaltime = at + ct + dt;
    }
    void trapezoidalProfile::setPhases(QLength idistance)
    {
        if(idistance > 0*foot){direction = 1;}
        else{direction = -1;}
        distance = abs(idistance);
        if(distance < mincruise)
        {
            TriangularProfile();
        }
        else
        {
            TrapezoidalProfile();
        }
    }
    QTime trapezoidalProfile::maxTime()
    {
        return at + ct + dt;
    }
    QLength trapezoidalProfile::getPosition(okapi::QTime time)
    {
        QLength pos;
        if(time < 0*second)
        {//Profile hasn't started.
            pos = 0*foot;
        }
        else if(time > totaltime)
        {//Profile finished.
            pos = distance;
        }
        else if(time < at)
        {//Profile in first stage.
            pos =  0.5 * constraint.maxAcceleration * time * time;
        }
        else if(time > (at + ct))
        {//Profile in third stage.
            QTime dtime = time - (at + ct);
            pos = (d1 + d2) + v3 * dtime + 0.5 * a3 * dtime * dtime;
        }
        else
        {//Profile in second stage.
            pos = d1 + constraint.maxVelocity * (time - at);
        }
        return pos * direction;
    }
    QSpeed trapezoidalProfile::getVelocity(QTime time)
    {
        QSpeed vel;
        if(time < 0*second || time > totaltime)
        {//Profile hasn't started / already finished.
            vel = 0*ftps;
        }
        else if(time < at)
        {//First stage.
            vel = constraint.maxAcceleration * time;
        }
        else if(time > (at + ct))
        {//Third stage.
            vel = constraint.maxAcceleration * (at+ct+dt - time);
        }
        else
        {//Second stage.
            vel = constraint.maxVelocity;
        }
        return vel * direction;
    }
    QAcceleration trapezoidalProfile::getAcceleration(QTime time)
    {
        QAcceleration accel;
        if(time < 0*second || time > totaltime)
        {
            accel = 0*ftps2;
        }
        else if(time < at)
        {
            accel = a1;
        }
        else if(time < at + ct)
        {
            accel = a2;
        }
        else
        {
            accel = a3;
        }
        return accel * direction;
    }
    profilePoint trapezoidalProfile::getPoint(okapi::QTime time)
    {
        double pos = getPosition(time).convert(foot);
        double vel = getVelocity(time).convert(ftps);
        double accel = getAcceleration(time).convert(ftps2);
        return {pos,vel,accel};
    }
    
    std::vector<profilePoint> trapezoidalProfile::generateProfile(QLength distance)
    {
        setPhases(distance);
        std::vector<profilePoint> path;
        
        iterations = ceil(maxTime().convert(second) / divs);
        for(int i = 0; i < iterations; i++)
        {
            profilePoint pt = getPoint(i*second*divs);
            path.push_back(pt);
        }
        return path;
    }
    
}
