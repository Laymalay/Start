#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pet.hpp"
#include <string>
#include <ctime>
#ifndef GAME_HPP_
#define GAME_HPP_





class Game
{
public:


  Game (float widht, float hight);
  void menu ();
  void start ();
  void control ();
  void render ();
  void update ();
  void over ();

   ~Game ()
  {
    delete (window);
  }
private:
    Pet mycat_;
  sf::RenderWindow * window;
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

  int sshower = 0, scure = 0, swork = 0, sgame = 0;
  int speedLife = 1;
  int speedHealht = 1;

  void drawButtonSpeed1 ();
  void drawButtonSpeed2 ();

  void drawButtonPlacebo ();
  void drawButtonShower ();
  void drawButtonFood ();
  void drawButtonWC ();
  void drawButtonGame ();
  void drawButtonSport ();
  void drawButtonWork ();
  void drawButtonCure ();
  void drawButtonStart ();
  void drawButtonExit ();
  void drawButtonInfo ();
  void drawButtonBack ();
  void drawButton ();
  void drawBackground ();
  void drawBackgroundMenu ();
  void drawBackgroundInfo ();
  void drawBackgroundOver ();
  //////////////////////////////////////////
  //              Condition               //
  //////////////////////////////////////////
  void showCondition (std::string condition);
  void showThoughts (std::string thoughts);
  void happy ();
  void good ();
  void so_so ();
  void sad ();
  void verysad ();
  void died ();
  void ill ();
  //////////////////////////////////////////
  //                мысли                 //
  //////////////////////////////////////////
  void Cloud ();
  void needShower ();
  void hungry ();
  void needWc ();
  void needCure ();
  void ok ();

  //////////////////////////////////////////
  //              ACTION                  //
  //////////////////////////////////////////
  void eat ();
  void wc ();
  void sport ();
  void shower ();
  void work ();
  void play ();
  void cure ();


  enum Button
  {
    SP1,
    SP2,
    WRK,
    SPR,
    GM,
    FD,
    SH,
    CR,
    WC,
    PLC,
    STR,
    EX,
    BC,
    INF,
    BT
  };

  struct GameButton
  {
    int X, Y, W, H;
      std::string imagePath;
      GameButton (int X, int Y, int W, int H, std::string imagePath);
  };

  GameButton getButton (Button button);


};
#endif
