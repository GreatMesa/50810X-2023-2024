#include "Controller.hpp"
namespace model
{
    using namespace okapi;
    button::button(std::function<void()> func, bool bt)
    {
        function = func;
        button_type = bt;
    }
    Controller::Controller(std::function<void()> x,bool x_type,
        std::function<void()> y,bool y_type,
        std::function<void()> a,bool a_type,
        std::function<void()> b,bool b_type,
        std::function<void()> up,bool up_type,
        std::function<void()> left,bool left_type,
        std::function<void()> right,bool right_type,
        std::function<void()> down,bool down_type,
        std::function<void()> l1,bool l1_type,
        std::function<void()> r1,bool r1_type,
        std::function<void()> l2,bool l2_type,
        std::function<void()> r2,bool r2_type)
        {
            X = button(x,x_type);
            Y = button(y,y_type);
            A = button(a,a_type);
            B = button(b,b_type);
            Up = button(up,up_type);
            Left = button(left,left_type);
            Right = button(right,right_type);
            Down = button(down,down_type);
            L1 = button(l1,l1_type);
            R1 = button(r1,r1_type);
            L2 = button(l2,l2_type);
            R2 = button(r2,r2_type);
        }
}