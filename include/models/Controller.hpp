#pragma once
#include <functional>
#include "okapi/api.hpp"

namespace bt
{
    bool hold = 0;
    bool toggle = 1;
}
namespace model
{
    struct button
    {
    private:
        std::function<void()> function;
        bool button_type;

    public:
        button() = default;
        button(std::function<void()> func, bool bt);
    };
    class Controller
    {
    private:
        okapi::Controller master;
        button X;
        button Y;
        button A;
        button B;
        button Up;
        button Left;
        button Right;
        button Down;
        button L1;
        button R1;
        button L2;
        button R2;

    public:
        /**
         * @brief Class to set up the Controller;
         * @param x Function for the x button.
         * @param x_type Button type for x button.
         * @param y Function for the y button.
         * @param y_type Button type for y button.
         * @param a Function for the a button.
         * @param a_type Button type for a button.
         * @param b Function for the b button.
         * @param b_type Button type for b button.
         * @param up Function for the up button.
         * @param up_type Button type for up button.
         * @param left Function for the left button.
         * @param left_type Button type for left button.
         * @param right Function for the right button.
         * @param right_type Button type for right button.
         * @param down Function for the down button.
         * @param down_type Button type for down button.
         * @param l1 Function for the L1 button.
         * @param l1_type Button type for L1 button.
         * @param r1 Function for the R1 button.
         * @param r1_type Button type for R1 button.
         * @param l2 Function for the L2 button.
         * @param l2_type Button type for L2 button.
         * @param r2 Function for the R2 button.
         * @param r2_type Button type for R2 button.
         */
        Controller(std::function<void()> x,bool x_type,
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
        std::function<void()> r2,bool r2_type);
    };
}