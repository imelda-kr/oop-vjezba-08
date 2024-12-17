#include <iostream>
#include<vector>
#include<string>

using namespace std;


class Enemy{
    string name;
    int health;
    int damage;
public:
    Enemy (string& ime,int& zdravlje, int& steta):name(ime),health(zdravlje),damage(steta){
        if(zdravlje<0 || steta<0)
            return invalid_argument("Health i damage moraju biti pozitivni bojevi.");
    };
    virtual void attac()=0;
    virtual void displayinfo()=0;
};

void Enemy::attac(){damage+=1};
void Enemy::displayinfo(){cout<<"Ime neprijatelja: "<<name<<", zdravlje:"<<health<<", steta:"<<damage<<endl;};

class Boss:protected Enemy{
    string oruzije;
public:
    Boss(string& ime,int& z,int& s, string& o):(Enemy(ime,z,s),oruzije(o)){
        if(o.empty()){
            return invalid_argument("Dodajte oruzije.")
        }
    }


};

class Monster:protected Enemy{
    string sposobnosti;
public:
    Monster(string& ime,int& z,int& s, string& spos):(Enemy(ime,z,s),sposobnosti(spos)){
        if(spos.empty()){
            return invalid_argument("Dodajte oruzije.")
        }
    }


};

int main()
{
    <vector>Enemy* neprijatelji;


    return 0;
}
