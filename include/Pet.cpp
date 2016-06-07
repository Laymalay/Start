 #include "../src/Pet.hpp"



		Pet::Pet( std::string name) {condition_="happy"; thoughts_="ok";}

	void Pet::shower() {
			hygiene = 100;
      happiness += 5;
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
    happiness += 5;
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
    happiness+=30;
    condition_="happy";
  }

	std::string Pet::condition() {
    if (eating<0.5&&health<0.5&&happiness<05) return condition_="died";
    if (health <20) return condition_="ill";
    if (happiness>90) return condition_="happy";
    if (happiness>70&&happiness<90) return condition_="good";
    if (happiness>50&&happiness<70) return condition_="soso";
    if (happiness>30&&happiness<50) return condition_="sad";
    if (happiness>15&&happiness<30) return condition_="verysad";
    else return "error";
	}
  std::string Pet::thoughts(){
    if (eating < 50) return thoughts_="hungry";
    if (need > 50) return thoughts_="need_wc";
    if (happiness < 60 ) return thoughts_="need_cure";
    if (hygiene < 50) return thoughts_="need_shower";
    else return thoughts_="ok";
  }


	int Pet::propertyOfCondition(int &condition) {
		if (condition > 100) return condition = 100;
		if (condition < 0) return condition = 0;
		else  return condition;
	}
	void Pet::ControlProp() {
		propertyOfCondition(eating);
		propertyOfCondition(leisure);
		propertyOfCondition(need);
		propertyOfCondition(happiness);
		propertyOfCondition(hygiene);
		propertyOfCondition(health);
	}



	void 	Pet::changeOver(int value, int a) {

      eating -= value;
			leisure -= value;
			need += value;
			happiness -= value;
		  hygiene -= value;
			health -= a;

			ControlProp();
      condition();
      thoughts();

		}

	void Pet::Action(std::string tmp)
	{
		if (tmp == "food") food();
		if (tmp == "wc") WC();
		if (tmp == "sport") Sport();
		if (tmp == "work") Work();
		if (tmp == "play") Game();
		if (tmp == "cure")  Cure();
		if (tmp == "shower") shower();
    if (tmp == "placebo") placebo();
	}
