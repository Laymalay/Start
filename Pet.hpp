#include <string>

using namespace std;
class Pet{

public:
  Pet( string name);
  void shower();
  void food() ;
  void WC();
  void Game();
  void Sport();
  void Work() ;
  void Cure() ;
  void get_name() ;

  int property_of_condition(int &condition);
  void ControlProp();

  void change_over(int value) ;
  void show_condition() ;//полностью переписывать
  void Action(string tmp);
protected:
  static const int DEFAULT_VALUE=100;

  int eating = DEFAULT_VALUE;
  int leisure = DEFAULT_VALUE;
  int need = 0;
  int happiness = DEFAULT_VALUE;
  int hygiene = DEFAULT_VALUE;
  int health = DEFAULT_VALUE;
  string  name;
};
