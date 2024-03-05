#include<iostream>
#include "smartphone.cpp"
using namespace std;

class Car{
    //properties
    private:
    string name;
    int speed;
    int milege;

    public:
    static int mfg;
    //default constructor
    Car(){
        cout << "Constructor called" << endl;
    }
    //parameterized constructor
    Car(string name, int speed, int milege){
        this->name = name;
        this->speed = speed;
        this->milege = milege;
    }
    //copy constructor
    Car(Car& c){
        this->name = c.name;
        this->speed = c.speed;
        this->milege = c.milege;
    }

    //destructor
    ~Car(){
        cout << "Destructor called" << endl;
    }

    //methods
    void carInfo(){
        cout << "Name: " << name << endl;
        cout << "speed: " << speed << endl;
        cout << "Milege: " << milege << endl;
    }
    void applyBrake(){
        cout << "Apply brake to stop the car." << endl;
    }

    void increaseSpeed(){
        speed += 10;
        cout << "New speed :" << speed << endl;
    }

    //static function
    static void random(){
        cout << "Manufacture date -> " << mfg << endl;
    }
};

int Car::mfg = 2002;

int main(){

    // Car c1;
    // c1.speed = 70;
    // c1.name = "Wagon R";
    // c1.milege = 40;
    
    Car c1("Mahindra Thar",107,30);

    c1.carInfo();
    // c1.applyBrake();
    // c1.increaseSpeed();

    Smartphone sm;
    // sm.model = "Samsung galaxy S29";
    // sm.price = 49999;
    // sm.color = "Space Grey";
    sm.setData("Apple Iphone 14 pro max",159999,"Magenta Black");
    cout << endl;
    sm.phoneInfo();
    cout << sm.getPrice() << endl;


    //Dynamic creation of an object
    Smartphone *sm2 = new Smartphone();
    (*sm2).setData("Oneplus",19999,"oceanic blue");
    cout << endl;
    (*sm2).phoneInfo();
    sm2->phoneInfo();


    //Copy constructor
    Car c3("Mercedez Benz",190,27);
    cout << endl;
    c3.carInfo();
    cout << endl;
    Car c4(c3);
    c4.carInfo();

    //copy assignment operator
    Car c5 = c1;
    cout << endl;
    c5.carInfo();

    // Car *c6 = new Car();
    // delete c6;

    //static member call(static data member belongs to class)
    cout << Car::mfg << endl;
    // Car c7;
    // cout << c7.mfg << endl;

    //static function call
    Car::random();

}