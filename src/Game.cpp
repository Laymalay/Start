#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/Game.hpp"
#include <unistd.h>

#define true 1
#define false 0





Game::Game(float widht,float hight, std::string name): mycat_(name){

   window = new sf::RenderWindow(sf::VideoMode(widht,hight),
    "tamagotchi");
    if (!window){
      exit(1);
    }
   buttonSoundBuffer.loadFromFile("res/1405.wav");
   buttonSound.setBuffer(buttonSoundBuffer);
   music.openFromFile("res/bcg.ogg");
   ShowerBuffer.loadFromFile("res/bathroom-sink.wav");
   ShowerSound.setBuffer(ShowerBuffer);
   CureBuffer.loadFromFile("res/rrr.wav");
   CureSound.setBuffer(CureBuffer);
   WorkBuffer.loadFromFile("res/miau02.wav");
   WorkSound.setBuffer(WorkBuffer);
   GameBuffer.loadFromFile("res/miau01.wav");
   GameSound.setBuffer(GameBuffer);

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


  Game::drawBackgroundMenu();
  Game::drawButtonStart();
  Game::drawButtonInfo();
  Game::drawButtonExit();
  Game::drawButtonSpeed1();
  Game::drawButtonSpeed2();

  sf::Font font;
  sf::Text text;



  font.loadFromFile("res/GoodDog.otf");
  text.setFont(font);
  text.setCharacterSize(70);
  if (speedLife==1){
  text.setString("speed : slow " );
  text.setPosition (350,100);
  text.setColor(sf::Color::White);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);}
  else{
  text.setString("speed : faste ");
  text.setPosition (350,100);
  text.setColor(sf::Color::White);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);}


  text.setString("slow");
  text.setPosition (80,530);
  text.setColor(sf::Color::White);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("fast");
  text.setPosition (780,530);
  text.setColor(sf::Color::White);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);

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
          buttonSound.play();
          music.stop();
          start();
        }
        if (BUTTON_INFO_X<x&&BUTTON_INFO_X+widht>x
        &&BUTTON_INFO_Y<y&&BUTTON_INFO_Y+hight>y)
        {
          buttonSound.play();
          while(1){
            window->clear(sf::Color::White);
            Game::drawBackgroundInfo();
            Game::drawButtonBack();
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

            text.setCharacterSize(100);
            text.setString("Hi");
            text.setPosition (250,50);
            text.setColor(sf::Color::Blue);
            text.setStyle(sf::Text::Bold | sf::Text::Italic);
            window->draw(text);

            text.setCharacterSize(100);
            text.setString("Love me,\n   feed me,\n   never leave me.");
            text.setPosition (250,150);
            text.setColor(sf::Color::Magenta);
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
                      buttonSound.play();
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
           buttonSound.play();
          music.stop();
          window->close();
        }
        if (BUTTON_SPEED1_X<x&&BUTTON_SPEED1_X+200>x
        &&BUTTON_SPEED1_Y<y&&BUTTON_SPEED1_Y+200>y)
        {
          buttonSound.play();
          speedLife=1;
          speedHealht=1;
        }
        if (BUTTON_SPEED2_X<x&&BUTTON_SPEED2_X+200>x
        &&BUTTON_SPEED2_Y<y&&BUTTON_SPEED2_Y+200>y)
        {
          buttonSound.play();
          speedLife=10;
          speedHealht=10;
        }

  }
}
}
}
void Game::start(){
 buttonSound.setVolume(50);
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
           music.stop();
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
            buttonSound.play();
            sshower=true;
            mycat_.Action("shower");//действие
          }

          if (BUTTON_FOOD_X<x&&BUTTON_FOOD_X+widht>x
          &&BUTTON_FOOD_Y<y&&BUTTON_FOOD_Y+hight>y)
          {buttonSound.play();
            mycat_.Action("food");//действие
          }
          if (BUTTON_WC_X<x&&BUTTON_WC_X+widht>x
          &&BUTTON_WC_Y<y&&BUTTON_WC_Y+hight>y)
          {buttonSound.play();
            mycat_.Action("wc");//действие
          }
          if (BUTTON_GAME_X<x&&BUTTON_GAME_X+widht>x
          &&BUTTON_GAME_Y<y&&BUTTON_GAME_Y+hight>y)
          {buttonSound.play();
            sgame=true;
            mycat_.Action("play");    //действие
          }
          if (BUTTON_SPORT_X<x&&BUTTON_SPORT_X+widht>x
          &&BUTTON_SPORT_Y<y&&BUTTON_SPORT_Y+hight>y)
          {buttonSound.play();
            mycat_.Action("sport");//действие
          }
          if (BUTTON_WORK_X<x&&BUTTON_WORK_X+widht>x
          &&BUTTON_WORK_Y<y&&BUTTON_WORK_Y+hight>y)
          {buttonSound.play();
            swork=true;
            mycat_.Action("work");//действие
          }
          if (BUTTON_CURE_X<x&&BUTTON_CURE_X+widht>x
          &&BUTTON_CURE_Y<y&&BUTTON_CURE_Y+hight>y)
          {buttonSound.play();
            mycat_.Action("cure");//действие
            scure=true;
          }
          if (BUTTON_PLACEBO_X<x&&BUTTON_PLACEBO_X+widht>x
          &&BUTTON_PLACEBO_Y<y&&BUTTON_PLACEBO_Y+hight>y)
          {buttonSound.play();
            mycat_.Action("placebo");
          }
          if (BUTTON_X<x&&BUTTON_X+400>x
          &&BUTTON_Y<y&&BUTTON_Y+100>y)
          {buttonSound.play();
            music.stop();
            window->close();
          }

         }


  }
}
void Game::update()
 {
     /*static int deltaTime = 0, prev = 0;
      int now = clock();
      deltaTime += now - prev;
      prev = now;
      if (deltaTime > 1000000) {
      mycat_.change_over(1);
      deltaTime = 0;
    }*/
    if (mycat_.condition_=="died"){
      music.stop();
      over();
    }
    if (sshower) {
      ShowerSound.setPitch (1);
      ShowerSound.play();
      sleep(2);
      ShowerSound.stop();
      sshower=false;
    }
    if (scure){
      CureSound.setPitch (1);
      CureSound.play();
      sleep(2);
      CureSound.stop();
      scure=false;
    }
    if (swork){
      WorkSound.setPitch (1);
      WorkSound.play();
      sleep(2);
      WorkSound.stop();
      swork=false;
    }
    if (sgame){
      GameSound.setPitch (1);
      GameSound.play();
      sleep(2);
      GameSound.stop();
      sgame=false;
    }

      mycat_.changeOver(speedLife,speedHealht);
      sleep(1);

}
void Game::over(){
  sf::Music music;
  if (!music.openFromFile("res/over.ogg")){
     window->close();} // error
     music.setVolume(50);// reduce the volume
     music.setLoop(true);
     music.play();
  while(1){
   window->clear(sf::Color::Black);
   Game::drawBackgroundOver();
    Game::drawButton();
      sf::Font font;
      sf::Text text;
      font.loadFromFile("res/GoodDog.otf");
      text.setFont(font);
    text.setCharacterSize(70);
    text.setString("EXIT");
    text.setPosition (420,902);
    text.setColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);
    text.setCharacterSize(150);
    text.setString("GAME OVER");
    text.setPosition (240,20);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);
    died();
    window->display();

  sf::Event event;

  while (window->pollEvent(event))
  {
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

        if (BUTTON_X<x&&BUTTON_X+widht>x
        &&BUTTON_Y<y&&BUTTON_Y+hight>y)
        {
           buttonSound.play();
          music.stop();
          window->close();
        }

    }
}
}
}


//////////////////////////////////////////
//     ОТОБРАЖЕНИЕ ВСЕГО НА ЭКРАНЕ      //
//////////////////////////////////////////
void Game::render() {
  window->clear(sf::Color::White);
  Game::drawBackground();
  Game::drawButtonWC();
  Game::drawButtonFood();
  Game::drawButtonSport();
  Game::drawButtonShower();
  Game::drawButtonWork();
  Game::drawButtonPlacebo();
  Game::drawButtonCure();
  Game::drawButtonGame();
  Game::drawButton();
  Game::Cloud();
  Game::showCondition(mycat_.condition_);
  Game::showThoughts(mycat_.thoughts_);


  mycat_.ControlProp();
  std::string eatingStr = std::to_string(mycat_.eating);
  std::string leisureStr = std::to_string(mycat_.leisure);
  std::string needStr = std::to_string(mycat_.need);
  std::string happinessStr = std::to_string(mycat_.happiness);
  std::string hygieneStr = std::to_string(mycat_.hygiene);
  std::string healthStr = std::to_string(mycat_.health);


  sf::Font font;
  sf::Text text;
  font.loadFromFile("res/GoodDog.otf");
  text.setFont(font);
  text.setCharacterSize(50);

  text.setString("eating-->"+eatingStr);
  text.setPosition (10,0);
  text.setColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("leisure-->"+leisureStr);
  text.setPosition (10,50);
  text.setColor(sf::Color::Yellow);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("need-->"+needStr);
  text.setPosition (10,100);
  text.setColor(sf::Color::Blue);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("happiness-->"+happinessStr);
  text.setPosition (10,150);
  text.setColor(sf::Color::Cyan);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("hygiene-->"+hygieneStr);
  text.setPosition (10,200);
  text.setColor(sf::Color::Green);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("health-->"+healthStr);
  text.setPosition (10,250);
  text.setColor(sf::Color::Magenta);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
/*text.setString("condition-->"+mycat_.condition_);
  text.setPosition (670,300);
  text.setColor(sf::Color::Magenta);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("thoughts_-->"+mycat_.thoughts_);
  text.setPosition (670,350);
  text.setColor(sf::Color::White);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);*/
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
void Game::showCondition (std::string condition_){
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
void Game::showThoughts(std::string thoughts){
  if (thoughts == "need_wc") Game::needWc();
  if (thoughts == "hungry") Game::hungry();
  if (thoughts == "need_cure") Game::needCure();
  if (thoughts == "need_shower") Game::needShower();
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
  float const X=235;
  float const Y=200;

  sf::Texture texture;
  texture.loadFromFile("res/rip.png");

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
void Game::needWc(){
  float const X=730;
  float const Y=50;

  sf::Texture texture;
  texture.loadFromFile("res/wc_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::needCure(){
  float const X=700;
  float const Y=50;

  sf::Texture texture;
  texture.loadFromFile("res/need_cure.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::needShower(){
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
void Game::drawButtonShower(){
  float const X=550;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/shower_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawButtonFood(){
  float const X=150;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/food_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawButtonWC(){
  float const X=350;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/wc_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawButtonGame(){
  float const X=550;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/game_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawButtonSport(){
  float const X=750;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/sport_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawButtonWork(){
  float const X=150;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/work_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawButtonCure(){
  float const X=750;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/cure_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawButtonPlacebo(){
  float const X=350;
  float const Y=750;

  sf::Texture texture;
  texture.loadFromFile("res/placebo_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawBackground(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/bcg.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
}
void Game::drawBackgroundMenu(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/menu.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::drawBackgroundInfo(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/info_bcg.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::drawBackgroundOver(){
  float const X=0;
  float const Y=0;

  sf::Texture texture;
  texture.loadFromFile("res/over.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::drawButtonStart(){
  float const X=300;
  float const Y=200;

  sf::Texture texture;
  texture.loadFromFile("res/button.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);

};
void Game::drawButtonExit(){
  float const X=300;
  float const Y=400;

  sf::Texture texture;
  texture.loadFromFile("res/button.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::drawButtonInfo(){
  float const X=300;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/button.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);
};
void Game::drawButtonBack(){
  float const X=300;
  float const Y=600;

  sf::Texture texture;
  texture.loadFromFile("res/button.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X,Y);
  window->draw(sprite);}


void Game::drawButton(){
    float const X=300;
    float const Y=900;

    sf::Texture texture;
    texture.loadFromFile("res/button.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(X,Y);
    window->draw(sprite);}
void Game::drawButtonSpeed1(){
      float const X=50;
      float const Y=500;

      sf::Texture texture;
      texture.loadFromFile("res/speed1.png");

      sf::Sprite sprite;
      sprite.setTexture(texture);
      sprite.setPosition(X,Y);
      window->draw(sprite);
    };
void Game::drawButtonSpeed2(){
      float const X=750;
      float const Y=500;

      sf::Texture texture;
      texture.loadFromFile("res/speed2.png");

      sf::Sprite sprite;
      sprite.setTexture(texture);
      sprite.setPosition(X,Y);
      window->draw(sprite);
    };

Game::GameButton Game::getButton(Button button){
  switch(button) {
               case Game::Button::STR:
               {

                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }
               case Game::Button::WRK:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::SPR:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::GM:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::FD:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::SH:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::CR:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::WC:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::PLC:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::EX:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::BC:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }case Game::Button::INF:
               {
                 const float X = 100;
                 const float Y = 100;
                 const float W = 100;
                 const float H = 100;
                 const std::string PATH = "res/start.png";
                 return GameButton(X, Y,W,H, PATH);
                 break;
               }


             }
     return GameButton(1, 1,1,1, "res/start.png");

}
