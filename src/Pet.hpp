#include <string>
#ifndef PET_HPP_
#define PET_HPP_

using namespace std;

class Pet {

public:

  Pet(string name);
  string condition_;
  string thoughts_;
  void shower();
  void food() ;
  void WC();
  void Game();
  void Sport();
  void Work() ;
  void Cure() ;
  void get_name() ;
  void placebo();

  int propertyOfCondition(int &condition);
  void ControlProp();

  void changeOver(int value,int a);
  string condition();
  string thoughts();
  void Action(string tmp);

  int eating = defaultValue;
  int leisure = defaultValue;
  int need = 0;
  int happiness = defaultValue;
  int hygiene = defaultValue;
  int health = defaultValue;

protected:
  static const int defaultValue=100;
  string  name;

};
#endif
