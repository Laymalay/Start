#include <string>
#ifndef PET_HPP_
#define PET_HPP_



class Pet {

public:

  Pet(std::string name);
  std::string condition_;
  std::string thoughts_;
  void shower();
  void food() ;
  void WC();
  void Game();
  void Sport();
  void Work() ;
  void Cure() ;
  void placebo();

  int propertyOfCondition(int &condition);
  void ControlProp();

  void changeOver(int value,int a);
  std::string condition();
  std::string thoughts();
  void Action(std::string tmp);

  int eating = defaultValue;
  int leisure = defaultValue;
  int need = 0;
  int happiness = defaultValue;
  int hygiene = defaultValue;
  int health = defaultValue;

protected:
  static const int defaultValue=100;
  std::string  name;

};
#endif
