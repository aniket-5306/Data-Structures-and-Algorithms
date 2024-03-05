#include<iostream>
#include<string>
using namespace std;

class Mammals{

    public:
    int legs;
    string survival_area;
    string survial_food;

    public:
    void setData(int legs, string sa, string sf){
        this->legs = legs;
        this->survival_area = sa;
        this->survial_food = sf;
    }

    string getSurvivalFood(){
        return survial_food;
    }
    
};

class Human : protected Mammals{
    int max_iq;
    public:
    void setIQ(int iq){
        this->max_iq = iq;
    }
    int getIQ(){
        return max_iq;
    }
    void dailyRoutine(){
        cout << "Humans are considered as the most wisest mammals on the earth because of their decision making skills." << endl;
    }
    void callingFn(string food){
        this -> survial_food = food;
        cout << getSurvivalFood() << endl;
    }
};

class SuckedHuman : public Human{
    public:
    void anotherFnCalling(){
        this -> survial_food = "junk foods like chowmin and burgers";
        cout << getSurvivalFood() << endl;
    }
};

class Dolphin : public Mammals{
    public:
    int a;
    void dolphinActivity(){
        cout << "Dolphins are the wisest and cutest mammals live under water. Their iq are comparatibly simmilar to humans as they can sense any upcoming threats using their ultra sound sensing capabilities." << endl;
    }

    //operator overloading
    void operator-(Dolphin& obj){
        cout << this->a * obj.a << endl;
    }
};



int main(){

    Human h1;
    // h1.setData(2,"""land","fruits and vegetables");
    h1.setIQ(125);
    cout << h1.getIQ() << endl;
    h1.dailyRoutine();
    // cout << h1.getSurvivalFood() << endl;
    h1.callingFn("wheat and rice");
    cout << endl;

    Dolphin dlp;
    dlp.setData(2,"water","seafood");
    cout << dlp.getSurvivalFood() << endl;
    dlp.dolphinActivity();
    cout << endl;

    SuckedHuman sh;
    sh.anotherFnCalling();

    //operator overloading
    Dolphin dlp2;
    dlp2.a = 9;
    dlp.a = 7;
    dlp - dlp2;

}