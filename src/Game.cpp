#include "../include/Game.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#define true 1
#define false 0

Game::Game(float widht, float hight) {

  window = new sf::RenderWindow(sf::VideoMode(widht, hight), "tamagotchi");
  if (!window) {
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

void Game::menu() {

  sf::Music music;
  if (!music.openFromFile("res/music_menu.ogg")) {
    window->close();
  } // error

  music.setVolume(50); // reduce the volume
  music.setLoop(true);
  music.play();

  while (1) {
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
    if (speedLife == 1) {
      text.setString("speed : slow ");
      text.setPosition(350, 100);
      text.setColor(sf::Color::White);
      text.setStyle(sf::Text::Bold | sf::Text::Italic);
      window->draw(text);
    } else {
      text.setString("speed : faste ");
      text.setPosition(350, 100);
      text.setColor(sf::Color::White);
      text.setStyle(sf::Text::Bold | sf::Text::Italic);
      window->draw(text);
    }

    text.setString("slow");
    text.setPosition(80, 530);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);
    text.setString("fast");
    text.setPosition(780, 530);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);

    text.setString("START");
    text.setPosition(400, 202);
    text.setColor(sf::Color::Yellow);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);
    text.setString("EXIT");
    text.setPosition(400, 402);
    text.setColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);
    text.setString("INFO");
    text.setPosition(400, 602);
    text.setColor(sf::Color::Magenta);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);
    window->display();
    sf::Event event;

    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {

        music.stop();
        window->close();
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        float x, y;
        x = event.mouseButton.x;
        y = event.mouseButton.y;
        //смотрит входит ли нажатие в область кнопки
        if (getButton(Button::STR).X < x &&
            getButton(Button::STR).X + getButton(Button::STR).W > x &&
            getButton(Button::STR).Y < y &&
            getButton(Button::STR).Y + getButton(Button::STR).H > y) {
          buttonSound.play();
          music.stop();
          start();
        }
        if (getButton(Button::INF).X < x &&
            getButton(Button::INF).X + getButton(Button::INF).W > x &&
            getButton(Button::INF).Y < y &&
            getButton(Button::INF).Y + getButton(Button::INF).H > y) {
          buttonSound.play();
          while (1) {
            window->clear(sf::Color::White);
            Game::drawBackgroundInfo();
            Game::drawButtonBack();
            sf::Font font;
            sf::Text text;

            font.loadFromFile("res/GoodDog.otf");
            text.setFont(font);
            text.setCharacterSize(70);

            text.setString("BACK");
            text.setPosition(400, 602);
            text.setColor(sf::Color::Yellow);
            text.setStyle(sf::Text::Bold | sf::Text::Italic);
            window->draw(text);

            text.setCharacterSize(100);
            text.setString("Hi");
            text.setPosition(250, 50);
            text.setColor(sf::Color::Blue);
            text.setStyle(sf::Text::Bold | sf::Text::Italic);
            window->draw(text);

            text.setCharacterSize(100);
            text.setString("Love me,\n   feed me,\n   never leave me.");
            text.setPosition(250, 150);
            text.setColor(sf::Color::Magenta);
            text.setStyle(sf::Text::Bold | sf::Text::Italic);
            window->draw(text);

            window->display();
            sf::Event event;
            while (window->pollEvent(event)) {
              if (event.type == sf::Event::Closed) {
                music.stop();
                window->close();
              }
              if (event.type == sf::Event::MouseButtonPressed) {
                float x, y;

                x = event.mouseButton.x;
                y = event.mouseButton.y;
                if (getButton(Button::BC).X < x &&
                    getButton(Button::BC).X + getButton(Button::BC).W > x &&
                    getButton(Button::BC).Y < y &&
                    getButton(Button::BC).Y + getButton(Button::BC).H > y) {
                  buttonSound.play();
                  music.stop();
                  menu();
                }
              }
            }
          }
        }
        if (getButton(Button::EX).X < x &&
            getButton(Button::EX).X + getButton(Button::EX).W > x &&
            getButton(Button::EX).Y < y &&
            getButton(Button::EX).Y + getButton(Button::EX).H > y) {
          buttonSound.play();
          music.stop();
          window->close();
        }
        if (getButton(Button::SP1).X < x &&
            getButton(Button::SP1).X + getButton(Button::SP1).W > x &&
            getButton(Button::SP1).Y < y &&
            getButton(Button::SP1).Y + getButton(Button::SP1).H > y) {
          buttonSound.play();
          speedLife = 1;
          speedHealht = 1;
        }
        if (getButton(Button::SP2).X < x &&
            getButton(Button::SP2).X + getButton(Button::SP2).W > x &&
            getButton(Button::SP2).Y < y &&
            getButton(Button::SP2).Y + getButton(Button::SP2).H > y) {
          buttonSound.play();
          speedLife = 10;
          speedHealht = 10;
        }
      }
    }
  }
}

void Game::start() {
  buttonSound.setVolume(50);
  music.setVolume(50); // reduce the volume
  music.setLoop(true);
  music.play();

  while (1) {
    Game::render();
    Game::update();
    Game::control();
  }
}

void Game::control() {

  sf::Event event;

  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      music.stop();
      window->close();
    }
    if (event.type == sf::Event::MouseButtonPressed) {
      float x, y;

      x = event.mouseButton.x;
      y = event.mouseButton.y;
      //смотрит входит ли нажатие в область кнопки
      if (getButton(Button::SH).X < x &&
          getButton(Button::SH).X + getButton(Button::SH).W > x &&
          getButton(Button::SH).Y < y &&
          getButton(Button::SH).Y + getButton(Button::SH).H > y) {
        buttonSound.play();
        sshower = true;
        mycat_.Action("shower"); //действие
      }

      if (getButton(Button::FD).X < x &&
          getButton(Button::FD).X + getButton(Button::FD).W > x &&
          getButton(Button::FD).Y < y &&
          getButton(Button::FD).Y + getButton(Button::FD).H > y) {
        buttonSound.play();
        mycat_.Action("food"); //действие
      }
      if (getButton(Button::WC).X < x &&
          getButton(Button::WC).X + getButton(Button::WC).W > x &&
          getButton(Button::WC).Y < y &&
          getButton(Button::WC).Y + getButton(Button::WC).H > y) {
        buttonSound.play();
        mycat_.Action("wc"); //действие
      }
      if (getButton(Button::GM).X < x &&
          getButton(Button::GM).X + getButton(Button::GM).W > x &&
          getButton(Button::GM).Y < y &&
          getButton(Button::GM).Y + getButton(Button::GM).H > y) {
        buttonSound.play();
        sgame = true;
        mycat_.Action("play"); //действие
      }
      if (getButton(Button::SPR).X < x &&
          getButton(Button::SPR).X + getButton(Button::SPR).W > x &&
          getButton(Button::SPR).Y < y &&
          getButton(Button::SPR).Y + getButton(Button::SPR).H > y) {
        buttonSound.play();
        mycat_.Action("sport"); //действие
      }
      if (getButton(Button::WRK).X < x &&
          getButton(Button::WRK).X + getButton(Button::WRK).W > x &&
          getButton(Button::WRK).Y < y &&
          getButton(Button::WRK).Y + getButton(Button::WRK).H > y) {
        buttonSound.play();
        swork = true;
        mycat_.Action("work"); //действие
      }
      if (getButton(Button::CR).X < x &&
          getButton(Button::CR).X + getButton(Button::CR).W > x &&
          getButton(Button::CR).Y < y &&
          getButton(Button::CR).Y + getButton(Button::CR).H > y) {
        buttonSound.play();
        mycat_.Action("cure"); //действие
        scure = true;
      }
      if (getButton(Button::PLC).X < x &&
          getButton(Button::PLC).X + getButton(Button::PLC).W > x &&
          getButton(Button::PLC).Y < y &&
          getButton(Button::PLC).Y + getButton(Button::PLC).H > y) {
        buttonSound.play();
        mycat_.Action("placebo");
      }
      if (getButton(Button::BT).X < x &&
          getButton(Button::BT).X + getButton(Button::BT).W > x &&
          getButton(Button::BT).Y < y &&
          getButton(Button::BT).Y + getButton(Button::BT).H > y) {
        buttonSound.play();
        music.stop();
        window->close();
      }
    }
  }
}

void Game::update() {
  /*static int deltaTime = 0, prev = 0;
     int now = clock();
     deltaTime += now - prev;
     prev = now;
     if (deltaTime > 1000000) {
     mycat_.change_over(1);
     deltaTime = 0;
     } */
  if (mycat_.condition_ == "died") {
    music.stop();
    over();
  }
  if (sshower) {
    ShowerSound.setPitch(1);
    ShowerSound.play();
    sleep(2);
    ShowerSound.stop();
    sshower = false;
  }
  if (scure) {
    CureSound.setPitch(1);
    CureSound.play();
    sleep(2);
    CureSound.stop();
    scure = false;
  }
  if (swork) {
    WorkSound.setPitch(1);
    WorkSound.play();
    sleep(2);
    WorkSound.stop();
    swork = false;
  }
  if (sgame) {
    GameSound.setPitch(1);
    GameSound.play();
    sleep(2);
    GameSound.stop();
    sgame = false;
  }

  mycat_.changeOver(speedLife, speedHealht);
  sleep(1);
}

void Game::over() {
  sf::Music music;
  if (!music.openFromFile("res/over.ogg")) {
    window->close();
  }                    // error
  music.setVolume(50); // reduce the volume
  music.setLoop(true);
  music.play();
  while (1) {
    window->clear(sf::Color::Black);
    Game::drawBackgroundOver();
    Game::drawButton();
    sf::Font font;
    sf::Text text;
    font.loadFromFile("res/GoodDog.otf");
    text.setFont(font);
    text.setCharacterSize(70);
    text.setString("EXIT");
    text.setPosition(420, 902);
    text.setColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);
    text.setCharacterSize(150);
    text.setString("GAME OVER");
    text.setPosition(240, 20);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Italic);
    window->draw(text);
    died();
    window->display();

    sf::Event event;

    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        music.stop();
        window->close();
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        float x, y;

        x = event.mouseButton.x;
        y = event.mouseButton.y;

        if (getButton(Button::BT).X < x &&
            getButton(Button::BT).X + getButton(Button::BT).W > x &&
            getButton(Button::BT).Y < y &&
            getButton(Button::BT).Y + getButton(Button::BT).H > y) {
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

  text.setString("eating-->" + eatingStr);
  text.setPosition(10, 0);
  text.setColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("leisure-->" + leisureStr);
  text.setPosition(10, 50);
  text.setColor(sf::Color::Yellow);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("need-->" + needStr);
  text.setPosition(10, 100);
  text.setColor(sf::Color::Blue);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("happiness-->" + happinessStr);
  text.setPosition(10, 150);
  text.setColor(sf::Color::Cyan);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("hygiene-->" + hygieneStr);
  text.setPosition(10, 200);
  text.setColor(sf::Color::Green);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  text.setString("health-->" + healthStr);
  text.setPosition(10, 250);
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
  text.setPosition(400, 902);
  text.setColor(sf::Color::Black);
  text.setStyle(sf::Text::Bold | sf::Text::Italic);
  window->draw(text);
  window->display();
}

//////////////////////////////////////////
//              Condition               //
//////////////////////////////////////////
// happy,good,so_so,sad,verysad,died
void Game::showCondition(std::string condition_) {
  if (condition_ == "ill")
    Game::ill();
  if (condition_ == "happy")
    Game::happy();
  if (condition_ == "good")
    Game::good();
  if (condition_ == "soso")
    Game::so_so();
  if (condition_ == "sad")
    Game::sad();
  if (condition_ == "verysad")
    Game::verysad();
  if (condition_ == "died")
    Game::died();
  if (condition_ == "eat")
    Game::eat();
  if (condition_ == "wc")
    Game::wc();
  if (condition_ == "sport")
    Game::sport();
  if (condition_ == "shower")
    Game::shower();
  if (condition_ == "work")
    Game::work();
  if (condition_ == "play")
    Game::play();
  if (condition_ == "cure")
    Game::cure();
}

void Game::showThoughts(std::string thoughts) {
  if (thoughts == "need_wc")
    Game::needWc();
  if (thoughts == "hungry")
    Game::hungry();
  if (thoughts == "need_cure")
    Game::needCure();
  if (thoughts == "need_shower")
    Game::needShower();
  if (thoughts == "ok")
    Game::ok();
}

void Game::happy() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/happy.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::good() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/thank.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::so_so() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/soso.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::sad() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/sad.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::verysad() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/verysad.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::ill() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/ill.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::died() {
  float const X = 235;
  float const Y = 200;

  sf::Texture texture;
  texture.loadFromFile("res/rip.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              ACTION                  //
//////////////////////////////////////////
void Game::eat() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/eat1.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::wc() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/wc.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::sport() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/sport.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::shower() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/shower.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::work() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/work.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::play() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/play_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::cure() {
  float const X = 300;
  float const Y = 150;

  sf::Texture texture;
  texture.loadFromFile("res/love.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              CLOUD                   //
//////////////////////////////////////////
void Game::Cloud() {
  float const X = 520;
  float const Y = 0;

  sf::Texture texture;
  texture.loadFromFile("res/cloud.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::ok() {
  float const X = 700;
  float const Y = 50;

  sf::Texture texture;
  texture.loadFromFile("res/yea.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::hungry() {
  float const X = 700;
  float const Y = 50;

  sf::Texture texture;
  texture.loadFromFile("res/hungry_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::needWc() {
  float const X = 730;
  float const Y = 50;

  sf::Texture texture;
  texture.loadFromFile("res/wc_.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::needCure() {
  float const X = 700;
  float const Y = 50;

  sf::Texture texture;
  texture.loadFromFile("res/need_cure.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::needShower() {
  float const X = 700;
  float const Y = 50;

  sf::Texture texture;
  texture.loadFromFile("res/need_shower.png");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

//////////////////////////////////////////
//              BUTTON                  //
//////////////////////////////////////////
void Game::drawButtonShower() {
  GameButton button = getButton(Button::SH);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButtonFood() {
  GameButton button = getButton(Button::FD);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButtonWC() {
  GameButton button = getButton(Button::WC);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButtonGame() {
  GameButton button = getButton(Button::GM);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButtonSport() {
  GameButton button = getButton(Button::SPR);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButtonWork() {
  GameButton button = getButton(Button::WRK);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButtonCure() {
  GameButton button = getButton(Button::CR);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButtonPlacebo() {
  GameButton button = getButton(Button::PLC);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawBackground() {
  float const X = 0;
  float const Y = 0;

  sf::Texture texture;
  texture.loadFromFile("res/bcg.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
}

void Game::drawBackgroundMenu() {
  float const X = 0;
  float const Y = 0;

  sf::Texture texture;
  texture.loadFromFile("res/menu.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
};

void Game::drawBackgroundInfo() {
  float const X = 0;
  float const Y = 0;

  sf::Texture texture;
  texture.loadFromFile("res/info_bcg.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
};

void Game::drawBackgroundOver() {
  float const X = 0;
  float const Y = 0;

  sf::Texture texture;
  texture.loadFromFile("res/over.jpg");

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(X, Y);
  window->draw(sprite);
};

void Game::drawButtonStart() {
  GameButton button = getButton(Button::STR);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
};

void Game::drawButtonExit() {
  GameButton button = getButton(Button::EX);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
};

void Game::drawButtonInfo() {
  GameButton button = getButton(Button::INF);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
};

void Game::drawButtonBack() {
  GameButton button = getButton(Button::BC);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButton() {
  GameButton button = getButton(Button::BT);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
}

void Game::drawButtonSpeed1() {
  GameButton button = getButton(Button::SP1);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
};

void Game::drawButtonSpeed2() {

  GameButton button = getButton(Button::SP2);

  sf::Texture texture;
  texture.loadFromFile(button.imagePath);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(button.X, button.Y);
  window->draw(sprite);
};

Game::GameButton::GameButton(int x, int y, int w, int h, std::string Path) {

  X = x;
  Y = y;
  W = w;
  H = h;
  imagePath = Path;
};

Game::GameButton Game::getButton(Button button) {
  switch (button) {
  case Game::Button::BT: {

    float X = 300;
    float Y = 900;
    float W = 400;
    float H = 100;
    std::string PATH = "res/button.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::SP1: {

    float X = 50;
    float Y = 500;
    float W = 200;
    float H = 200;
    std::string PATH = "res/speed1.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::SP2: {

    float X = 750;
    float Y = 500;
    float W = 200;
    float H = 200;
    std::string PATH = "res/speed2.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::STR: {

    float X = 300;
    float Y = 200;
    float W = 400;
    float H = 100;
    std::string PATH = "res/button.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::WRK: {
    float X = 150;
    float Y = 750;
    float W = 100;
    float H = 100;
    std::string PATH = "res/work_.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::SPR: {
    float X = 750;
    float Y = 600;
    float W = 100;
    float H = 100;
    std::string PATH = "res/sport_.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::GM: {
    float X = 550;
    float Y = 750;
    float W = 100;
    float H = 100;
    std::string PATH = "res/game_.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::FD: {
    float X = 150;
    float Y = 600;
    float W = 100;
    float H = 100;
    std::string PATH = "res/food_.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::SH: {
    float X = 550;
    float Y = 600;
    float W = 100;
    float H = 100;
    std::string PATH = "res/shower_.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::CR: {
    float X = 750;
    float Y = 750;
    float W = 100;
    float H = 100;
    std::string PATH = "res/cure_.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::WC: {
    float X = 350;
    float Y = 600;
    float W = 100;
    std::string PATH = "res/wc_.png";
    float H = 100;
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::PLC: {
    float X = 350;
    float Y = 750;
    float W = 100;
    float H = 100;
    std::string PATH = "res/placebo_.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::EX: {
    float X = 300;
    float Y = 400;
    float W = 400;
    float H = 100;
    std::string PATH = "res/button.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::BC: {
    float X = 300;
    float Y = 600;
    float W = 400;
    float H = 100;
    std::string PATH = "res/button.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  case Game::Button::INF: {
    float X = 300;
    float Y = 600;
    float W = 400;
    float H = 100;
    std::string PATH = "res/button.png";
    return Game::GameButton(X, Y, W, H, PATH);
    break;
  }
  default: { return GameButton(1, 1, 1, 1, "res/start.png"); }
  }
}
