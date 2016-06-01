#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.hpp"
#include <unistd.h>
using namespace std;

Game::Game(float widht,float hight, string name): mycat_(name){

   window = new sf::RenderWindow(sf::VideoMode(widht,hight),
    "tamagotchi");


};



void Game::menu(){

  sf::Music music;
  if (!music.openFromFile("res/music_menu.ogg")){
     window->close();} // error

     music.setVolume(50);         // reduce the volume
     music.setLoop(true);
  music.play();

  while(1){
  window->clear(sf::Color::White);


  Game::draw_background_menu();
  Game::draw_button_start();
  Game::draw_button_info();
  Game::draw_button_exit();

  sf::Font font;
  sf::Text text;

  font.loadFromFile("res/GoodDog.otf");
  text.setFont(font);
  text.setCharacterSize(70);

  text.setString("START");
  text.setPosition (400,202);
  text.setColor(sf::Color::Yellow);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("EXIT");
  text.setPosition (400,402);
  text.setColor(sf::Color::Black);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("INFO");
  text.setPosition (400,602);
  text.setColor(sf::Color::Magenta);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  window->display();
  sf::Event event;

  while (window->pollEvent(event))
  {
    if (event.type == sf::Event::Closed){
          button_sound();
          music.stop();
        window->close();
      }
    if (event.type == sf::Event::MouseButtonPressed){
        float x,y;
        float const widht=400;
        float const hight=100;
        x=event.mouseButton.x;
        y=event.mouseButton.y;
        //смотрит входит ли нажатие в область кнопки
        if (BUTTON_START_X<x&&BUTTON_START_X+widht>x
        &&BUTTON_START_Y<y&&BUTTON_START_Y+hight>y)
        {
          button_sound();
          music.stop();
          start();
        }
        if (BUTTON_INFO_X<x&&BUTTON_INFO_X+widht>x
        &&BUTTON_INFO_Y<y&&BUTTON_INFO_Y+hight>y)
        {

          while(1){
            window->clear(sf::Color::White);
            Game::draw_background_info();
            Game::draw_button_back();
            sf::Font font;
            sf::Text text;

            font.loadFromFile("res/GoodDog.otf");
            text.setFont(font);
            text.setCharacterSize(70);

            text.setString("BACK");
            text.setPosition (400,602);
            text.setColor(sf::Color::Yellow);
            text.setStyle(sf::Text::Bold | sf::Text::Italic);
            window->draw(text);
            window->display();
            sf::Event event;
            while (window->pollEvent(event)){
              if (event.type == sf::Event::Closed){
                music.stop();
                window->close();
              }
                if (event.type == sf::Event::MouseButtonPressed){
                    float x,y;
                    float const widht=400;
                    float const hight=100;
                    x=event.mouseButton.x;
                    y=event.mouseButton.y;
                    if (BUTTON_BACK_X<x&&BUTTON_BACK_X+widht>x
                    &&BUTTON_BACK_Y<y&&BUTTON_BACK_Y+hight>y)
                    {
                      button_sound();
                      music.stop();
                      menu();
                    }
                  }
             }
        }
        }
        if (BUTTON_EXIT_X<x&&BUTTON_EXIT_X+widht>x
        &&BUTTON_EXIT_Y<y&&BUTTON_EXIT_Y+hight>y)
        {
            button_sound();
          music.stop();
          window->close();
        }

  }
}
}
}
void Game::start(){
  sf::Music music;
  if (!music.openFromFile("res/bcg.ogg")){
     window->close();
   } // error

  music.setVolume(50);         // reduce the volume
  music.setLoop(true);
  music.play();

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
      if (event.type == sf::Event::Closed){

          window->close();
        }
      if (event.type == sf::Event::MouseButtonPressed){
          float x,y;
          float const widht=100;
          float const hight=100;
          x=event.mouseButton.x;
          y=event.mouseButton.y;
          //смотрит входит ли нажатие в область кнопки
          if (BUTTON_SHOWER_X<x&&BUTTON_SHOWER_X+widht>x
          &&BUTTON_SHOWER_Y<y&&BUTTON_SHOWER_Y+hight>y)
          {
            /*sf::SoundBuffer Buffer;
            Buffer.loadFromFile("bathroom-sink.wav");
            sf::Sound Sound;
            Sound.setBuffer(Buffer);
            Sound.play();
            Sound.stop();*/
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
            mycat_.Action("play");    //действие
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
          if (BUTTON_X<x&&BUTTON_X+400>x
          &&BUTTON_Y<y&&BUTTON_Y+100>y)
          {

            window->close();
          }

         }


  }
}
void Game::update() {
    mycat_.change_over(1);
    sleep(1);

}

//////////////////////////////////////////
//     ОТОБРАЖЕНИЕ ВСЕГО НА ЭКРАНЕ      //
//////////////////////////////////////////
void Game::render() {
  window->clear(sf::Color::White);
  Game::draw_background();
  Game::draw_button_WC();
  Game::draw_button_food();
  Game::draw_button_Sport();
  Game::draw_button_shower();
  Game::draw_button_Work();
  Game::draw_button_placebo();
  Game::draw_button_Cure();
  Game::draw_button_Game();
  Game::draw_button();
  Game::Cloud();
  Game::show_condition(mycat_.condition_);
  Game::show_thoughts(mycat_.thoughts_);


  mycat_.ControlProp();
  std::string eating_str = std::to_string(mycat_.eating);
  std::string leisure_str = std::to_string(mycat_.leisure);
  std::string need_str = std::to_string(mycat_.need);
  std::string happiness_str = std::to_string(mycat_.happiness);
  std::string hygiene_str = std::to_string(mycat_.hygiene);
  std::string health_str = std::to_string(mycat_.health);


  sf::Font font;
  sf::Text text;
  font.loadFromFile("res/GoodDog.otf");
  text.setFont(font);
  text.setCharacterSize(50);

  text.setString("eating-->"+eating_str);
  text.setPosition (10,0);
  text.setColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("leisure-->"+leisure_str);
  text.setPosition (10,50);
  text.setColor(sf::Color::Yellow);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("need-->"+need_str);
  text.setPosition (10,100);
  text.setColor(sf::Color::Blue);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("happiness-->"+happiness_str);
  text.setPosition (10,150);
  text.setColor(sf::Color::Cyan);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("hygiene-->"+hygiene_str);
  text.setPosition (10,200);
  text.setColor(sf::Color::Green);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("health-->"+health_str);
  text.setPosition (10,250);
  text.setColor(sf::Color::Magenta);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("condition-->"+mycat_.condition_);
  text.setPosition (670,300);
  text.setColor(sf::Color::Magenta);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("thoughts_-->"+mycat_.thoughts_);
  text.setPosition (670,350);
  text.setColor(sf::Color::White);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setCharacterSize(70);
  text.setString("EXIT");
  text.setPosition (400,902);
  text.setColor(sf::Color::Black);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
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
  if (condition_ == "eat") Game::eat();
  if (condition_ == "wc") Game::wc();
  if (condition_ == "sport") Game::sport();
  if (condition_ == "shower") Game::shower();
  if (condition_ == "work") Game::work();
  if (condition_ == "play") Game::play();
  if (condition_ == "cure") Game::cure();
}
void Game::show_thoughts(string thoughts){
  if (thoughts == "need_wc") Game::need_wc();
  if (thoughts == "hungry") Game::hungry();
  if (thoughts == "need_cure") Game::need_cure();
  if (thoughts == "need_shower") Game::need_shower();
  if (thoughts == "ok") Game::ok();
}
void Game::happy(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/happy.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::good(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/thank.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::so_so(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/soso.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::sad(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/sad.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::verysad(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/verysad.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::ill(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/ill.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::died(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/died.png");

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
  texture.loadFromFile("res/eat1.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::wc(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/wc.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::sport(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/sport.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::shower(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/shower.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::work(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/work.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::play(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/play_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::cure(){
  float const X=300;
  float const Y=150;

  sf::Texture texture;
  texture.loadFromFile("res/love.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              CLOUD                   //
//////////////////////////////////////////
void Game::Cloud(){
  float const X=520;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/cloud.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::ok(){
  float const X=700;
  float const Y=50;

  sf::Texture texture;
  texture.loadFromFile("res/yea.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::hungry(){
  float const X=700;
  float const Y=50;

  sf::Texture texture;
  texture.loadFromFile("res/hungry_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::need_wc(){
  float const X=730;
  float const Y=50;

  sf::Texture texture;
  texture.loadFromFile("res/wc_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::need_cure(){
  float const X=700;
  float const Y=50;

  sf::Texture texture;
  texture.loadFromFile("res/need_cure.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::need_shower(){
  float const X=700;
  float const Y=50;

  sf::Texture texture;
  texture.loadFromFile("res/need_shower.png");

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
  texture.loadFromFile("res/shower_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_food(){
  float const X=150;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/food_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_WC(){
  float const X=350;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/wc_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Game(){
  float const X=550;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/game_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Sport(){
  float const X=750;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/sport_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Work(){
  float const X=150;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/work_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_Cure(){
  float const X=750;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/cure_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_button_placebo(){
  float const X=350;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/placebo_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_background(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/bcg.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::draw_background_menu(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/menu.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::draw_background_info(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/info_bcg.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::draw_button_start(){
  float const X=300;
  float const Y=200;

  sf::Texture texture;
  texture.loadFromFile("res/button.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);

};
void Game::draw_button_exit(){
  float const X=300;
  float const Y=400;

  sf::Texture texture;
  texture.loadFromFile("res/button.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::draw_button_info(){
  float const X=300;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/button.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::draw_button_back(){
  float const X=300;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/button.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);}
  void Game::draw_button(){
    float const X=300;
    float const Y=900;

    sf::Texture texture;
    texture.loadFromFile("res/button.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(X,Y);
    window->draw(sprite);}
void Game::button_sound(){
  sf::SoundBuffer Buffer;
  if (!Buffer.loadFromFile("1405.wav"))
  {
    window->close();
  }
  sf::Sound Sound;
Sound.setBuffer(Buffer);
Sound.play();
Sound.stop();

};
