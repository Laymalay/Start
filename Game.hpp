#include <SFML/Graphics.hpp>
#include "Pet.hpp"
#include <string>
using namespace std;


class Game {
  public:


    Game(float widht,float hight,string name);
    void start();
    void control();
    void render();
    void update();
  private:
    Pet mycat_;
    sf::RenderWindow* window;

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

    void draw_button_placebo();
    void draw_button_shower();
    void draw_button_food();
    void draw_button_WC();
    void draw_button_Game();
    void draw_button_Sport();
    void draw_button_Work();
    void draw_button_Cure();

    //////////////////////////////////////////
    //              Condition               //
    //////////////////////////////////////////
    void show_condition(string condition);
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

    void hungry();
    void need_wc();
    void need_cure();

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
