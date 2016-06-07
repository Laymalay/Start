#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pet.hpp"
#include <string>
#include <ctime>
#ifndef GAME_HPP_
#define GAME_HPP_
using namespace std;




class Game {
  public:


    Game(float widht,float hight,string name);
    void menu();
    void start();
    void control();
    void render();
    void update();
    void over();


  private:
    Pet mycat_;
    sf::RenderWindow* window;
    sf::SoundBuffer buttonSoundBuffer;
    sf::Sound buttonSound;
    sf::Music music;

    sf::SoundBuffer ShowerBuffer;
    sf::Sound ShowerSound;

    sf::SoundBuffer CureBuffer;
    sf::Sound CureSound;

    sf::SoundBuffer WorkBuffer;
    sf::Sound WorkSound;

    sf::SoundBuffer GameBuffer;
    sf::Sound GameSound;

    int sshower=0,scure=0,swork=0,sgame=0;
    int speedLife=1;
    int speedHealht=1;

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

    float const BUTTON_SPEED1_X = 50;
    float const BUTTON_SPEED1_Y = 500;

    float const BUTTON_SPEED2_X = 750;
    float const BUTTON_SPEED2_Y = 500;

    void drawButtonSpeed1();
    void drawButtonSpeed2();

    void drawButtonPlacebo();
    void drawButtonShower();
    void drawButtonFood();
    void drawButtonWC();
    void drawButtonGame();
    void drawButtonSport();
    void drawButtonWork();
    void drawButtonCure();
    void drawBackground();
    void drawBackgroundMenu();
    void drawBackgroundInfo();
    void drawBackgroundOver();
    void drawButtonStart();
    void drawButtonExit();
    void drawButtonInfo();
    void drawButtonBack();
    void drawButton();
    //////////////////////////////////////////
    //              Condition               //
    //////////////////////////////////////////
    void showCondition(string condition);
    void showThoughts(string thoughts);
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
    void needShower();
    void hungry();
    void needWc();
    void needCure();
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
#endif
