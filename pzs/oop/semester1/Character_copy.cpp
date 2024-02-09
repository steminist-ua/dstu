#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std; 

class Character{
    protected: 
        string name; 
        int health; 
        int power; 
    public: 
        Character(string _name, int _health, int _power) : name(_name), health(_health), power(_power) {}
       
        string getName(){
            return name;
        }
        int getHealth(){
            return health; 
        }
        bool isAlive(){
            return health>0; 
        }

        void takeDamage(int damage){
            health -= damage; 
            if (health<0){
                health = 0;
            }
        }

        void attack(Character& target){
            int damage = rand() % power + 1; 
            target.takeDamage(damage); 
            cout << name << " attacks " << target.getName() << " for " << damage << " damage " << endl; 
        }

};

class Hero : public Character{
    public: 
        Hero(string _name, int _health, int _power) : Character(_name, _health, _power){}

        void heroAttack(Character& target){
            attack(target); 
            cout << name << " shouts a heroic battle cry!" << endl; 
        }
};

class Monster : public Character{
    public: 
        Monster(string _name, int _health, int _power) : Character(_name, _health, _power){}

        void monsterAttack(Character& target){
            attack(target); 
            cout << name << " growls menacingly!" << endl; 
        }
}; 

int main(){

    srand(static_cast<unsigned>(time(nullptr)));

    vector<Hero> heroes; 
    heroes.push_back(Hero("Hero 1", 100, 20));
    heroes.push_back(Hero("Hero 2", 120, 18));
    heroes.push_back(Hero("Hero 3", 80, 25));
    
    vector<Monster> monsters; 
    monsters.push_back(Monster("Monster 1", 80, 15));
    monsters.push_back(Monster("Monster 2", 100, 50));
    monsters.push_back(Monster("Monster 3", 120, 10));

    while(!heroes.empty() && !monsters.empty()){

        for(int i = 0; i < heroes.size(); i++){
            if(!monsters.empty()){
                int indexMonster = rand() % monsters.size(); 
                heroes[i].heroAttack(monsters[indexMonster]); 

                if(!monsters[indexMonster].isAlive()){
                    cout << monsters[indexMonster].getName() << " is defeated!" << endl;
                    monsters.erase(monsters.begin() + indexMonster);
                }
            }
        }


        for (int i = 0; i < monsters.size(); i++) {
            if (!heroes.empty() && heroes[i].isAlive()) {
                int heroIndex = rand() % heroes.size();
                monsters[i].monsterAttack(heroes[heroIndex]);

                if (!heroes[heroIndex].isAlive()) {
                    cout << heroes[heroIndex].getName() << " is defeated!" << endl;
                    heroes.erase(heroes.begin() + heroIndex);
                }
            }
        }

    }

    if (heroes.empty()) {
        cout << "Monsters win!" << endl;
    } else {
        cout << "Heroes win!" << endl;
    }

    return 0;


}



// vector<vector<Character>> characters;

// vector<Hero> heroes;
// heroes.push_back(Hero("Hero 1", 100, 20));
// heroes.push_back(Hero("Hero 2", 120, 18));
// heroes.push_back(Hero("Hero 3", 80, 25));

// vector<Monster> monsters;
// monsters.push_back(Monster("Monster 1", 80, 15));
// monsters.push_back(Monster("Monster 2", 100, 12));
// monsters.push_back(Monster("Monster 3", 120, 10));

// characters.push_back(heroes);
// characters.push_back(monsters);