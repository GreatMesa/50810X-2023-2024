#include "buttons.hpp"
//Page Creation
lv_obj_t * AutonPage = lv_page_create(lv_scr_act(), NULL); //Page for Auotn Selector
lv_obj_t * MotorsPage = lv_page_create(lv_scr_act(), NULL); // Page for Motors Menu
lv_obj_t * SensorPage = lv_page_create(lv_scr_act(), NULL);
lv_obj_t * OdomPage = lv_page_create(lv_scr_act(), NULL);

lv_obj_t * ddlists = lv_ddlist_create(lv_scr_act(), NULL);

lv_style_t redREL; //relesed style
lv_style_t redPR; //pressed style
lv_style_t redtREL; //relesed style
lv_style_t redtPR; //pressed style

lv_style_t ButtonStyleREL; //relesed style
lv_style_t ButtonStylePR; //pressed style

lv_style_t pageStyle;
lv_style_t descStyle;
//AutonSelector
lv_obj_t * but1= lv_btn_create(AutonPage, NULL);
lv_obj_t * but1_label= lv_label_create(but1, NULL);
lv_obj_t * but2= lv_btn_create(AutonPage, NULL);
lv_obj_t * but2_label= lv_label_create(but2, NULL);
lv_obj_t * but3= lv_btn_create(AutonPage, NULL);
lv_obj_t * but3_label= lv_label_create(but3, NULL);
lv_obj_t * but4= lv_btn_create(AutonPage, NULL);
lv_obj_t * but4_label= lv_label_create(but4, NULL);

lv_obj_t * description = lv_page_create(AutonPage, NULL);

lv_obj_t * desc_label= lv_label_create(description, NULL);

int Auton_Selected = 0;

std::string str1= "  Left Side";
std::string str2= "  Right Side";
std::string str3= "  Solo AWP";
std::string str4= "  Skills";
//Motor Menu

lv_style_t motor_style;
lv_obj_t * d= lv_label_create(MotorsPage, NULL);
lv_obj_t * Motors= lv_page_create(MotorsPage, NULL);
lv_obj_t * Motors_Label = lv_label_create(Motors,NULL);
lv_obj_t * temp_button = lv_btn_create(MotorsPage,NULL);
lv_obj_t * volt_button = lv_btn_create(MotorsPage,NULL);
lv_obj_t * temp_l= lv_label_create(temp_button, NULL);
lv_obj_t * volt_l= lv_label_create(volt_button, NULL);
lv_style_t mot_btnstyleREL;
lv_style_t mot_btnstylePR;
void temp_display();
void volt_display();
std::string text;
//Function for DDlist
static lv_res_t dd_act(lv_obj_t*)
{ 
    int ind;
    ind = lv_ddlist_get_selected(ddlists);
        if(ind == 0)
        {
            lv_obj_set_hidden(AutonPage, false);
            lv_obj_set_hidden(MotorsPage, true);
            lv_obj_set_hidden(SensorPage,true);
            lv_obj_set_hidden(OdomPage,true);
        }
        else if(ind == 1)
        {
            lv_obj_set_hidden(AutonPage, true);
            lv_obj_set_hidden(MotorsPage, false);
            lv_obj_set_hidden(SensorPage,true);
            lv_obj_set_hidden(OdomPage,true);
        }
        else if(ind == 2)
        {
            lv_obj_set_hidden(AutonPage, true);
            lv_obj_set_hidden(MotorsPage, true);
            lv_obj_set_hidden(SensorPage,false);
            lv_obj_set_hidden(OdomPage,true);
        }
        else if(ind == 3)
        {
            lv_obj_set_hidden(AutonPage, true);
            lv_obj_set_hidden(MotorsPage, true);
            lv_obj_set_hidden(SensorPage,true);
            lv_obj_set_hidden(OdomPage,false);
        }
    return LV_RES_OK;
}
static lv_res_t but1_act(lv_obj_t*);
static lv_res_t but2_act(lv_obj_t*);
static lv_res_t but3_act(lv_obj_t*);
static lv_res_t but4_act(lv_obj_t*);
static lv_res_t temp(lv_obj_t*);
static lv_res_t volt(lv_obj_t*);
void makePage(lv_color_t color,lv_color_t textcolor)
{
    lv_obj_set_hidden(MotorsPage, true);
    lv_obj_set_hidden(SensorPage, true);
    lv_obj_set_hidden(OdomPage, true);

    lv_obj_set_width(AutonPage, 500);
    lv_obj_set_height(AutonPage,272);
    lv_obj_set_pos(AutonPage,-10,0);

    lv_obj_set_width(MotorsPage, 500);
    lv_obj_set_height(MotorsPage,272);
    lv_obj_set_pos(MotorsPage,-10,0);

    lv_obj_set_width(SensorPage, 490);
    lv_obj_set_height(SensorPage,272);

    lv_obj_set_width(OdomPage, 490);
    lv_obj_set_height(OdomPage,272);

    lv_style_copy(&pageStyle ,&lv_style_plain);
    pageStyle.body.main_color = color;
    pageStyle.body.grad_color = color;
    pageStyle.text.color = textcolor;
    pageStyle.body.radius = 0;

    lv_page_set_style(AutonPage,LV_PAGE_STYLE_BG,&pageStyle);
    lv_page_set_style(MotorsPage,LV_PAGE_STYLE_BG,&pageStyle);
    lv_page_set_style(SensorPage,LV_PAGE_STYLE_BG,&pageStyle);
    lv_page_set_style(OdomPage,LV_PAGE_STYLE_BG,&pageStyle);
    
}
void buttonstyle(lv_color_t redcolor,lv_color_t bluecolor){   
    lv_style_copy(&redREL, &lv_style_plain);
    redREL.body.main_color = LV_COLOR_HEX(0xAAAAAA);
    redREL.body.grad_color = LV_COLOR_HEX(0xAAAAAA);
    redREL.body.radius = 20;
    redREL.text.color = bluecolor;
    redREL.body.border.width = 2;
    redREL.body.border.color = bluecolor;

    lv_style_copy(&redPR, &lv_style_plain);
    redPR.body.main_color = bluecolor;
    redPR.body.grad_color = bluecolor;
    redPR.body.radius = 20;
    redPR.text.color = LV_COLOR_HEX(0xAAAAAA);
    redPR.body.border.width = 2;
    redPR.body.border.color = LV_COLOR_HEX(0xAAAAAA);

    lv_style_copy(&mot_btnstylePR, &lv_style_plain);
    mot_btnstylePR.body.main_color = LV_COLOR_HEX(0x00FF00);
    mot_btnstylePR.body.radius = 0;
    mot_btnstylePR.text.color = LV_COLOR_WHITE;
    redREL.body.border.width = 2;
    redREL.body.border.color = LV_COLOR_WHITE;

    lv_style_copy(&mot_btnstyleREL, &lv_style_plain);
    mot_btnstyleREL.body.main_color = bluecolor;
    mot_btnstyleREL.body.grad_color = bluecolor;
    mot_btnstyleREL.body.radius = 0;
    mot_btnstyleREL.text.color = LV_COLOR_WHITE;
    mot_btnstyleREL.body.border.width = 2;
    mot_btnstyleREL.body.border.color = LV_COLOR_WHITE;
    
}
void AutonSelector(lv_color_t textcolor){
    lv_label_set_text(desc_label," Do nothing");
    lv_label_set_text(but1_label, "Left Side");
    lv_label_set_text(but2_label, "Right Side");
    lv_label_set_text(but3_label, "Solo AWP");
    lv_label_set_text(but4_label, "Skills");
    
    lv_btn_set_style(but1, LV_BTN_STYLE_REL, &redREL); //set the relesed style
    lv_btn_set_style(but1, LV_BTN_STYLE_PR, &redPR); //set the pressed style

    lv_btn_set_style(but2, LV_BTN_STYLE_REL, &redREL); //set the relesed style
    lv_btn_set_style(but2, LV_BTN_STYLE_PR, &redPR); //set the pressed style
    
    lv_btn_set_style(but3, LV_BTN_STYLE_REL, &redREL); //set the relesed style
    lv_btn_set_style(but3, LV_BTN_STYLE_PR, &redPR); //set the pressed style

    lv_btn_set_style(but4, LV_BTN_STYLE_REL, &redREL); //set the relesed style6
    lv_btn_set_style(but4, LV_BTN_STYLE_PR, &redPR); //set the pressed style

    lv_obj_set_width(but1, 175);
    lv_obj_set_height(but1,35);

    lv_obj_set_width(but2, 175);
    lv_obj_set_height(but2,35);

    lv_obj_set_width(but3, 175);
    lv_obj_set_height(but3,35);

    lv_obj_set_width(but4, 175);
    lv_obj_set_height(but4,35);

    lv_obj_set_pos(but1,0,50);
    lv_obj_set_pos(but2,0,95);
    lv_obj_set_pos(but3,0,140);
    lv_obj_set_pos(but4,0,185);

    lv_obj_set_pos(description,187,0);
    lv_obj_set_size(description,280,220);

    lv_style_copy(&descStyle ,&lv_style_plain);
    descStyle.body.main_color = LV_COLOR_HEX(0x000000);
    descStyle.body.grad_color = LV_COLOR_HEX(0x000000);
    descStyle.text.color = textcolor;
    descStyle.body.radius = 20;
    descStyle.body.border.width = 2;
    descStyle.body.border.color = LV_COLOR_HEX(0xFFFFFF);

    lv_page_set_style(description,LV_PAGE_STYLE_BG,&descStyle);
    lv_btn_set_action(but1,LV_BTN_ACTION_CLICK,but1_act);
    lv_btn_set_action(but2,LV_BTN_ACTION_CLICK,but2_act);
    lv_btn_set_action(but3,LV_BTN_ACTION_CLICK,but3_act);
    lv_btn_set_action(but4,LV_BTN_ACTION_CLICK,but4_act);
}
void MotorsMenu(lv_color_t color){
    lv_label_set_text(temp_l,"temp");
    lv_label_set_text(volt_l,"volt");
    lv_style_copy(&motor_style ,&lv_style_plain);
    motor_style.body.main_color = LV_COLOR_HEX(0x0000DD);
    motor_style.body.grad_color = LV_COLOR_HEX(0x0000DD);
    motor_style.text.color = color;
    motor_style.body.radius = 2;
    motor_style.body.border.width = 2;
    motor_style.text.color = LV_COLOR_WHITE;
    motor_style.body.border.color = LV_COLOR_HEX(0x0000DD);

    lv_page_set_style(Motors,LV_PAGE_STYLE_BG,&motor_style);
    lv_obj_set_size(Motors,285,210);
    lv_obj_set_pos(Motors,185,5);
    lv_obj_set_size(temp_button,80,40);
    lv_obj_set_pos(temp_button,5,50);
    lv_obj_set_size(volt_button,80,40);
    lv_obj_set_pos(volt_button,95,50);

    lv_btn_set_style(volt_button, LV_BTN_STYLE_REL, &mot_btnstyleREL); //set the relesed style
    lv_btn_set_style(volt_button, LV_BTN_STYLE_PR, &mot_btnstylePR); //set the pressed style
    lv_btn_set_style(temp_button, LV_BTN_STYLE_REL, &mot_btnstyleREL); //set the relesed style
    lv_btn_set_style(temp_button, LV_BTN_STYLE_PR, &mot_btnstylePR); //set the pressed style


    lv_btn_set_action(temp_button,LV_BTN_ACTION_CLICK,temp);
    lv_btn_set_action(volt_button,LV_BTN_ACTION_CLICK,volt);
}

void SensorsMenu(lv_color_t color,lv_color_t textcolor){
    
}
void OdomDisplay(){

}
void dropdown (){        
    lv_obj_set_pos(ddlists,2,5);
    lv_ddlist_set_hor_fit(ddlists,false);
    lv_obj_set_width(ddlists, 175);

    lv_ddlist_set_options(ddlists, 
        SYMBOL_HOME" Auton\n"
        SYMBOL_SETTINGS" Motors\n"
        SYMBOL_CHARGE" Sensors\n"
        SYMBOL_LOOP" Odom");
    lv_ddlist_set_draw_arrow(ddlists, true);
    lv_ddlist_set_action(ddlists, dd_act);
    
        
        
}
void gui(lv_color_t color,lv_color_t textcolor){
    makePage(color,textcolor);
    buttonstyle(LV_COLOR_HEX(0xFF0000),LV_COLOR_HEX(0xCCCCCC));
    AutonSelector(textcolor);
    MotorsMenu(textcolor);
    SensorsMenu(color,textcolor);
    OdomDisplay();
    dropdown();
}

void temp_display(){
    while(true){
        std::string text = 
        "Motor 1: " + std::to_string(Drive1.getTemperature()) + "\n"+
        "Motor 2: " + std::to_string(Drive2.getTemperature()) + "\n"+
        "Motor 3: " + std::to_string(Drive3.getTemperature()) + "\n"+
        "Motor 4: " + std::to_string(Drive4.getTemperature()) + "\n"+
        "Motor 5: " + std::to_string(Drive5.getTemperature()) + "\n"+
        "Motor 6: " + std::to_string(Drive6.getTemperature()) + "\n";
        lv_label_set_text(Motors_Label,text.c_str());
        pros::delay(20);
    }
}

void volt_display(){
    while(true){
        std::string text = 
        "Motor 1: " + std::to_string(Drive1.getVoltage()) + "mV\n"+
        "Motor 2: " + std::to_string(Drive2.getVoltage()) + "mV\n"+
        "Motor 3: " + std::to_string(Drive3.getVoltage()) + "mV\n"+
        "Motor 4: " + std::to_string(Drive4.getVoltage()) + "mV\n"+
        "Motor 5: " + std::to_string(Drive5.getVoltage()) + "mV\n"+
        "Motor 6: " + std::to_string(Drive6.getVoltage()) + "mV\n";
        lv_label_set_text(Motors_Label,text.c_str());
        pros::delay(20);
    }
}
static lv_res_t but1_act(lv_obj_t*){
    lv_label_set_text(desc_label,str1.c_str());
    Auton_Selected = 1;
    printf("%d\n",Auton_Selected);
    return LV_RES_OK;
}
static lv_res_t but2_act(lv_obj_t*){
    lv_label_set_text(desc_label,str2.c_str());
    Auton_Selected = 2;
    printf("%d\n",Auton_Selected);
    return LV_RES_OK;
}
lv_res_t but3_act(lv_obj_t*){
    lv_label_set_text(desc_label,str3.c_str());
    Auton_Selected = 3;
    printf("%d\n",Auton_Selected);
    return LV_RES_OK;
}
static lv_res_t but4_act(lv_obj_t*){
    lv_label_set_text(desc_label,str4.c_str());
    Auton_Selected = 4;
    printf("%d\n",Auton_Selected);
    return LV_RES_OK;
}
static lv_res_t temp(lv_obj_t*){
    pros::Task temp(temp_display);
    return LV_RES_OK;
}
static lv_res_t volt(lv_obj_t*){
     pros::Task volt(volt_display);
     return LV_RES_OK;
}
/*
void imudisplay(){
    while(true){
    float degrees = imu.get();
    std::string text = "IMU Heading: " + std::to_string(degrees);
    lv_label_set_text(IMULabel, text.c_str());
    pros::delay(20);
    }
}
*/