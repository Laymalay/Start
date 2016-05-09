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

    static constexpr float  BUTTON_SHOWER_X = 0;
    float const BUTTON_SHOWER_Y = 0;
    float const BUTTON_FOOD_X = 0;
    float const BUTTON_FOOD_Y = 0;
    float const BUTTON_WC_X = 0;
    float const BUTTON_WC_Y = 0;
    float const BUTTON_GAME_X = 0;
    float const BUTTON_GAME_Y = 0;
    float const BUTTON_SPORT_X = 0;
    float const BUTTON_SPORT_Y = 0;
    float const BUTTON_WORK_X = 0;
    float const BUTTON_WORK_Y = 0;
    float const BUTTON_CURE_X = 0;
    float const BUTTON_CURE_Y = 0;
    float const BUTTON_PLACEBO_X = 0;
    float const BUTTON_PLACEBO_Y = 0;

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
