//Demonstrates static member variables and functions

#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    int HowHungry() const;
    int HowBored() const;

private:
    int m_Hunger;
    int m_Boredom;

    int GetMood() const;
    void PassTime(int time = 1);

};

int main()
{

    Critter crit;
	crit.Talk();

	int choice;
	do
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit " << endl;
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";

        cout << "Choice: ";
        cin >> choice;
    switch (choice)
        {
			case 0:
				cout << "Good-bye.\n";
				break;
			case 1:
				crit.Talk();
				break;
			case 2:
				crit.Eat();
				break;
			case 3:
				crit.Play();
				break;
			default:
				cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
	}  while (choice != 0);

    return 0;
}


Critter::Critter(int hunger, int boredom) {

m_Hunger =  hunger;
m_Boredom = boredom;
}

void Critter::Eat(int food) {
 cout << "Brruppp.\n";
m_Hunger = m_Hunger - food;
if(m_Hunger < 0) {
    m_Hunger = 0;
}

}

void Critter::Play(int fun) {
     cout << "Wheee!\n";

m_Boredom = m_Boredom - fun;
if(m_Boredom < 0) {
    m_Boredom = 0;
}

}


int Critter::GetMood() const {

int mood = 15 - (m_Hunger + m_Boredom);

if(mood > 0) {return mood;}
else {

    return 0;
}
}


void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Talk() {


    int mood = GetMood();
if(mood == 15) {
    cout << "I am super happy!" << endl;
}

else if(mood < 15 && mood > 9) {
    cout << "I am feeling good." << endl;
}


else if(mood < 10 && mood > 4) {
    cout << "I am getting frustrated." << endl;
}

else if(mood < 5 && mood > 0) {
    cout << "I am super mad!" << endl;
}

else if(mood == 0) {
        cout << "I will die, save me, please!" << endl;

}

int howhun = HowHungry();
int howbor = HowBored();

cout << "I am hungry at " << howhun << " level." << endl;
cout << "I am bored at " << howbor<< " level." << endl;

PassTime();

}


int Critter::HowHungry() const {

return m_Hunger;
}

int Critter::HowBored() const {
return m_Boredom;
}
