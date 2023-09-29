#include "Solenoid.hpp"
namespace model
{
    Solenoid::Solenoid(char port, bool initstate): solenoid(port,initstate)
    {
        state = initstate;
        solenoid.set_value(state);
    }
    void Solenoid::toggle()
    {
        state = !state;
        solenoid.set_value(state);
    }
    void Solenoid::setState(bool istate)
    {
        state = istate;
        solenoid.set_value(state);
    }
    bool Solenoid::getState()
    {
        return state;
    }
}