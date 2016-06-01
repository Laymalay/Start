#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pet.hpp"
#include <string>
using namespace std;


class Game {
  public:


    Game(float widht,float hight,string name);
    void menu();
    void start();
    void control();
    void render();
    void update();
  private:
    Pet mycat_;
    sf::RenderWindow* window;

    float const BUTTON_X = 300;
    float const BUTTON_Y = 900;

    float const BUTTON_START_X = 300;
    float const BUTTON_START_Y = 200;

    float const BUTTON_INFO_X = 300;
    float const BUTTON_INFO_Y = 600;

    float const BUTTON_EXIT_X = 300;
    float const BUTTON_EXIT_Y = 400;

    float const BUTTON_BACK_X = 300;
    float const BUTTON_BACK_Y = 600;


    float const BUTTON_SHOWER_X = 550;
    float const BUTTON_SHOWER_Y = 600;

    float const BUTTON_FOOD_X = 150;
    float const BUTTON_FOOD_Y = 600;

    float const BUTTON_WC_X = 350;
    float const BUTTON_WC_Y = 600;

    float const BUTTON_GAME_X = 550;
    float const BUTTON_GAME_Y = 750;

    float const BUTTON_SPORT_X = 750;
    float const BUTTON_SPORT_Y = 600;

    float const BUTTON_WORK_X = 150;
    float const BUTTON_WORK_Y = 750;

    float const BUTTON_CURE_X = 750;
    float const BUTTON_CURE_Y = 750;

    float const BUTTON_PLACEBO_X = 350;
    float const BUTTON_PLACEBO_Y = 750;
    void button_sound();
    void draw_button_placebo();
    void draw_button_shower();
    void draw_button_food();
    void draw_button_WC();
    void draw_button_Game();
    void draw_button_Sport();
    void draw_button_Work();
    void draw_button_Cure();
    void draw_background();
    void draw_background_menu();
    void draw_background_info();
    void draw_button_start();
    void draw_button_exit();
    void draw_button_info();
    void draw_button_back();
    void draw_button();
    //////////////////////////////////////////
    //              Condition               //
    //////////////////////////////////////////
    void show_condition(string condition);
    void show_thoughts(string thoughts);
    void happy();
    void good();
    void so_so();
    void sad();
    void verysad();
    void died();
    void ill();
    //////////////////////////////////////////
    //                мысли                 //
    //////////////////////////////////////////
    void Cloud();
    void need_shower();
    void hungry();
    void need_wc();
    void need_cure();
    void ok();

    //////////////////////////////////////////
    //              ACTION                  //
    //////////////////////////////////////////
    void eat();
    void wc();
    void sport();
    void shower();
    void work();
    void play();
    void cure();


};
