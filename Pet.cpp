 #include "Pet.hpp"

 using namespace std;

		Pet::Pet( string name) {condition_="happy";}

	void Pet::shower() {
			hygiene = 100;
      condition_="shower";

		}
	void Pet::food() {
		eating += 40;
		need += 10;
		happiness += 20;
		hygiene -= 5;
    condition_="eat";

	}
	void Pet::WC() {
		need = 0;
    condition_="wc";
  }
	void Pet::Game() {
		leisure += 30;
		eating -= 10;
		need += 5;
		happiness += 20;
		hygiene -= 20;
    condition_="play";
	}

	void Pet::Sport() {
		leisure += 5;
		eating -= 30;
		need += 20;
		happiness += 10;
		hygiene -= 30;
   condition_="sport";

	}

	void Pet::Work() {
		leisure -= 20;
		eating -= 30;
		need += 10;
		happiness -= 10;
		hygiene -= 5;
    condition_="work";

	}
	void Pet::Cure() {
		happiness= 100;
    condition_="cure";
	}
  void Pet::placebo(){
    health=100;
    condition_="happy";
  }
	void Pet::get_name() {
	}

	string Pet::condition() {
    if (health <50) return condition_="ill";
    if (happiness>90) return condition_="happy";
    if (happiness>70&&happiness<90) return condition_="good";
    if (happiness>50&&happiness<70) return condition_="soso";
    if (happiness>30&&happiness<50) return condition_="sad";
    if (happiness>15&&happiness<30) return condition_="verysad";
    if (eating==0&&health==0&&happiness==0) return condition_="died";
    else return "error";
	}


	int Pet::property_of_condition(int &condition) {
		if (condition > 100) return condition = 100;
		if (condition < 0) return condition = 0;
		else  return condition;
	}
	void Pet::ControlProp() {
		property_of_condition(eating);
		property_of_condition(leisure);
		property_of_condition(need);
		property_of_condition(happiness);
		property_of_condition(hygiene);
		property_of_condition(health);
	}



	void 	Pet::change_over(int value) {
			eating -= value;
			leisure -= value;
			need += value;
			happiness -= value;
		    hygiene -= value;
			health -= 5;
			ControlProp();
      condition();

		}

	void Pet::Action(string tmp)
	{
		if (tmp == "feed") food();
		if (tmp == "wc") WC();
		if (tmp == "sport") Sport();
		if (tmp == "work") Work();
		if (tmp == "play") Game();
		if (tmp == "cure")  Cure();
		if (tmp == "shower") shower();
    if (tmp == "placebo") placebo();
	}
