#include<iostream>
using namespace std;

class Smartphone{
    private:
    string model;
    int price;
    string color;
    public:
    //setter
    void setData(string model,int price,string color){
        this->model = model;
        this->price = price;
        this->color = color;
    }
    //getter
    string getModel(){
        return model;
    }
    int getPrice(){
        return price;
    }
    string getColor(){
        return color;
    }

    void phoneInfo(){
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Color: " << color << endl;
    }
};