#pragma once
#include <lvgl.h>
#include <functional>
#include <string>
#include "pros/adi.hpp"
#include <vector>
struct AutonPage
{
    private:
    std::function<void()> auton;
    std::string name;
    std::string description;
    public:
    AutonPage(std::function<void()> a, std::string n, std::string d);
    
};

class AutonSelector
{
    private:
    std::vector<AutonPage> autons;
    lv_color_t bg;
};