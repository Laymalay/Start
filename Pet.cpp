  #include "Pet.hpp"


 
		Pet::Pet( string name) {}
	void Pet::shower() {
			hygiene = 100;

		}
	void Pet::food() {
		eating += 40;
		need += 10;
		happiness += 20;
		hygiene -= 5;

	}
	void Pet::WC() {
		need = 0;
  }
	void Pet::Game() {
		leisure += 30;
		eating -= 10;
		need += 5;
		happiness += 20;
		hygiene -= 20;


	}
	//add level (such as sport master )
	void Pet::Sport() {
		leisure += 5;
		eating -= 30;
		need += 20;
		happiness += 10;
		hygiene -= 30;

	}
	//add level (such as good proprogrammer )
	void Pet::Work() {
		leisure -= 20;
		eating -= 30;
		need += 10;
		happiness -= 10;
		hygiene -= 5;

	}
	void Pet::Cure() {
		health = 100;

	}
	void Pet::get_name() {

	}
	void Pet::show_condition() {

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

		}

	void Pet::Action(string tmp)
	{
		if (tmp == "feed") food();
		if (tmp == "wc") WC();
		if (tmp == "sport") Sport();
		if (tmp == "work") Work();
		if (tmp == "play") Game();
		if (tmp == "check") CheckAll();
		if (tmp == "cure")  Cure();

		if (tmp == "shower") shower();
	}
