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
            mycat_.Action("shower");mycat_.condition_="shower";//действие
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
    sleep(1);

}

//////////////////////////////////////////
//     ОТОБРАЖЕНИЕ ВСЕГО НА ЭКРАНЕ      //
//////////////////////////////////////////
void Game::render() {
  window->clear(sf::Color::White);
  Game::draw_button_WC();
  Game::draw_button_food();
  Game::draw_button_Sport();
  Game::draw_button_shower();
  Game::draw_button_Work();
  Game::draw_button_placebo();
  Game::draw_button_Cure();
  Game::draw_button_Game();
  Game::show_condition(mycat_.condition_);
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
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/happy_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::good(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/good_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::so_so(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/soso_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::sad(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/sad_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::verysad(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/verysad_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::ill(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/ill_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::died(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/died_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              ACTION                  //
//////////////////////////////////////////
void Game::eat(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/eat_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::wc(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/wc__resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::sport(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/sport__resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::shower(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/shower__resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::work(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/Workresize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::play(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/play_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::cure(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/cure__resize.jpg");

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
  texture.loadFromFile("res/sad_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::hungry(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/hungry_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::need_wc(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/need_wc_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::need_cure(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/need_cure_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              BUTTON                  //
//////////////////////////////////////////
void Game::draw_button_shower(){
  float const X=550;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/shower_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_food(){
  float const X=150;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/food_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_WC(){
  float const X=350;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/wc_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Game(){
  float const X=550;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/game_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Sport(){
  float const X=750;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/sport_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Work(){
  float const X=150;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/work_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Cure(){
  float const X=750;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/cure_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_placebo(){
  float const X=350;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/placebo_resize.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
