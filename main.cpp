#include <iostream>
#include<vector>
#include<string>

using namespace std;


class Enemy{
protected:  //da je ostalo na private, izvedbena klasa ne bi mogla pristupati clanovima bazne klase enemy jer se privatnima moze pristupati samo unutar te klase ili preko getter metode
    string name;
    int health;
    int damage;
public:
    Enemy (const string& ime,int zdravlje, int steta):name(ime),health(zdravlje),damage(steta){
        if(zdravlje<0 || steta<0)
            throw invalid_argument("Health i damage moraju biti pozitivni bojevi.");
    };
    virtual void attack()=0;
    virtual void displayInfo()=0; //sve virtual void funkcije su =0 i moraju se overrideat
    virtual ~Enemy(){};
};



class Boss:public Enemy{
    string oruzije;
public:
    Boss(const string& ime,int z,int s, const string& o):Enemy(ime,z,s),oruzije(o){  //stringovi moraju biti const kako bi se rvalue iz main-a mogla vezati na njih, rvalue se veze na konstante reference
        if(o.empty()){
            throw invalid_argument("Dodajte oruzije."); //prekida ozvršenje programa i isduce sto se odradi u programu je catch naredba.
        }
    }
    void attack() override {  //sve cisto virtualne funkcije moraju biti override-ane
        cout << name << " napada oruzijem: '" << oruzije << "' i uzrokuje " << damage << " bodova stete." << endl;
    }

    void displayInfo() override {
        cout << "Ime neprijatelja: " << name
             << ", Zdravlje: " << health
             << ", Steta: " << damage
             << ", Oruzje: " << oruzije << endl;
    }


};

class Monster:public Enemy{
    string sposobnosti;
public:
    Monster(const string& ime,int z,int s, const string& spos):Enemy(ime,z,s),sposobnosti(spos){
        if(spos.empty()){
            throw invalid_argument("Dodajte oruzije.");
        }
    }
    void attack() override {
        cout << name << " ima sposobnost: '" << sposobnosti << "' i uzrokuje " << damage << " bodova stete." << endl;
    }

    void displayInfo() override {
        cout << "Ime neprijatelja: " << name
             << ", Zdravlje: " << health
             << ", Steta: " << damage
             << ", Sposobnost: " << sposobnosti << endl;
    }


};

int main()
{
    try{
        vector<Enemy*> neprijatelji;
        neprijatelji.push_back(new Boss("Lord",200,50,"puska"));  //new koristimo kod dinamièke alokacije memorije objekata prilikom korištenje pokazivaèa na vektor bazne klase
        neprijatelji.push_back(new Monster("Zmaj",150,40,"vatrene kugle"));
        neprijatelji.push_back(new Monster("troll",100,20,"regeneracija"));

        for (auto& neprijatelj : neprijatelji) {
            neprijatelj->displayInfo();
            neprijatelj->attack();
        }

        // Oslobaðanje memorije
        for (auto& neprijatelj : neprijatelji) {
            delete neprijatelj;
        }
    }
    // kod koristenja catch potrebno je catch naredbu odvojiti cijelim blokom try jer catch ne moze biti u istom bloku kao i petlja za oslobadanje memorije
    catch (const invalid_argument& e) {
    cerr << "Greška: " << e.what() << endl;}


    return 0;
}
