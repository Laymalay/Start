#include <SFML/Graphics.hpp>
#include "Pet.hpp"
#include <string>
using namespace std;


class Game {
  public:


    Game(float widht,float hight,string name);
    void control();
    void render();
    void update();
  private:

    Pet mycat_;
    sf::RenderWindow* window;
    float const BUTTON_SHOWER_X = 0;
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


    void draw_button_shower();
    void draw_button_food();
    void draw_button_WC();
    void draw_button_Game();
    void draw_button_Sport();
    void draw_button_Work();
    void draw_button_Cure();



};
