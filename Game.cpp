#include <SFML/Graphics.hpp>
#include "Game.hpp"
using namespace std;

Game::Game(float widht,float hight, string name): mycat_(name){

   window = new sf::RenderWindow(sf::VideoMode(widht,hight),
    "tamagotchi");
};


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
            //действие
          }
          if (BUTTON_GAME_X<x&&BUTTON_GAME_X+widht>x
          &&BUTTON_GAME_Y<y&&BUTTON_GAME_Y+hight>y)
          {
            //действие
          }
          if (BUTTON_SPORT_X<x&&BUTTON_SPORT_X+widht>x
          &&BUTTON_SPORT_Y<y&&BUTTON_SPORT_Y+hight>y)
          {
            //действие
          }
          if (BUTTON_WORK_X<x&&BUTTON_WORK_X+widht>x
          &&BUTTON_WORK_Y<y&&BUTTON_WORK_Y+hight>y)
          {
            //действие
          }
          if (BUTTON_CURE_X<x&&BUTTON_CURE_X+widht>x
          &&BUTTON_CURE_Y<y&&BUTTON_CURE_Y+hight>y)
          {
            //действие
          }

         }


  }
}
void Game::update() {
    mycat_.change_over(5);

}

//отображение всего на экране
void Game::render() {
  window->clear(sf::Color::White);
  window->display();
}
//рисует кнопки
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


