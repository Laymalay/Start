#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <unistd.h>
using namespace std;

Game::Game(float widht,float hight, string name): mycat_(name){

   window = new sf::RenderWindow(sf::VideoMode(widht,hight),
    "tamagotchi");
};

void Game::start(){
  while(1){
    Game::render();
    Game::update();
    Game::control();
    sleep(40);

  }
}

void Game::control() {

  sf::Event event;
  while (window->pollEvent(event))
  {
      if (event.type == sf::Event::Closed)
          window->close();
      if (event.type == sf::Event::MouseButtonPressed){
          float x,y;
          float const widht=10;
          float const hight=10;
          x=event.mouseButton.x;
          y=event.mouseButton.y;
          //смотрит входит ли нажатие в область кнопки
          if (BUTTON_SHOWER_X<x&&BUTTON_SHOWER_X+widht>x
          &&BUTTON_SHOWER_Y<y&&BUTTON_SHOWER_Y+hight>y)
          {
            mycat_.Action("shower");//действие
          }

          if (BUTTON_FOOD_X<x&&BUTTON_FOOD_X+widht>x
          &&BUTTON_FOOD_Y<y&&BUTTON_FOOD_Y+hight>y)
          {
            mycat_.Action("food");//действие
          }
          if (BUTTON_WC_X<x&&BUTTON_WC_X+widht>x
          &&BUTTON_WC_Y<y&&BUTTON_WC_Y+hight>y)
          {
            mycat_.Action("wc");//действие
          }
          if (BUTTON_GAME_X<x&&BUTTON_GAME_X+widht>x
          &&BUTTON_GAME_Y<y&&BUTTON_GAME_Y+hight>y)
          {
            mycat_.Action("game");    //действие
          }
          if (BUTTON_SPORT_X<x&&BUTTON_SPORT_X+widht>x
          &&BUTTON_SPORT_Y<y&&BUTTON_SPORT_Y+hight>y)
          {
            mycat_.Action("sport");//действие
          }
          if (BUTTON_WORK_X<x&&BUTTON_WORK_X+widht>x
          &&BUTTON_WORK_Y<y&&BUTTON_WORK_Y+hight>y)
          {
            mycat_.Action("work");//действие
          }
          if (BUTTON_CURE_X<x&&BUTTON_CURE_X+widht>x
          &&BUTTON_CURE_Y<y&&BUTTON_CURE_Y+hight>y)
          {
            mycat_.Action("cure");//действие
          }
          if (BUTTON_PLACEBO_X<x&&BUTTON_PLACEBO_X+widht>x
          &&BUTTON_PLACEBO_Y<y&&BUTTON_PLACEBO_Y+hight>y)
          {
            mycat_.Action("placebo");
          }

         }


  }
}
void Game::update() {
    mycat_.change_over(5);
}

//////////////////////////////////////////
//     ОТОБРАЖЕНИЕ ВСЕГО НА ЭКРАНЕ      //
//////////////////////////////////////////
void Game::render() {
  window->clear(sf::Color::White);
  window->display();
}


//////////////////////////////////////////
//              Condition               //
//////////////////////////////////////////
//happy,good,so_so,sad,verysad,died
void Game::show_condition (string condition_){
  if (condition_ == "ill") Game::ill();
  if (condition_ == "happy") Game::happy();
  if (condition_ == "good") Game::good();
  if (condition_ == "soso") Game::so_so();
  if (condition_ == "sad") Game::sad();
  if (condition_ == "verysad") Game::verysad();
  if (condition_ == "died") Game::died();
  if (condition_ =="eat") Game::eat();
  if (condition_ =="wc") Game::wc();
  if (condition_ =="sport") Game::sport();
  if (condition_ =="shower") Game::shower();
  if (condition_ =="work") Game::work();
  if (condition_ =="play") Game::play();
  if (condition_ =="cure") Game::cure();
}
void Game::happy(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("happy.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::good(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("good.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::so_so(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("soso.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::sad(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("sad.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::verysad(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("sad.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::ill(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("ill.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::died(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("died.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              ACTION                  //
//////////////////////////////////////////
void Game::eat(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("eat.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::wc(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("wc.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::sport(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("sport.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::shower(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("shower_.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::work(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("work.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::play(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("play.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::cure(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("cure.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              CLOUD                   //
//////////////////////////////////////////
void Game::Cloud(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("sad.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::hungry(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("hungry.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::need_wc(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("need_wc.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::need_cure(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("need_cure.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              BUTTON                  //
//////////////////////////////////////////
void Game::draw_button_shower(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("shower.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_food(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("food.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_WC(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("WC.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Game(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("Game.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Sport(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("Sport.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Work(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("Work.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Cure(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("Cure.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_placebo(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("placebo.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
