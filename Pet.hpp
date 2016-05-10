#include <string>

using namespace std;

class Pet {

public:

  Pet(string name);
  string condition_;
  void shower();
  void food() ;
  void WC();
  void Game();
  void Sport();
  void Work() ;
  void Cure() ;
  void get_name() ;
  void placebo();

  int property_of_condition(int &condition);
  void ControlProp();

  void change_over(int value) ;
  string condition();
  void Action(string tmp);

  int eating = DEFAULT_VALUE;
  int leisure = DEFAULT_VALUE;
  int need = 0;
  int happiness = DEFAULT_VALUE;
  int hygiene = DEFAULT_VALUE;
  int health = DEFAULT_VALUE;

protected:
  static const int DEFAULT_VALUE=100;
  string  name;

};
