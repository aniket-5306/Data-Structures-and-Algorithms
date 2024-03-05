#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;

    //insertion using pair
    pair<string,int> p = make_pair("ek",1);
    m.insert(p);

    //insertion
    m["billi"] = 1;
    m["meao"] = 1;
    m["doo"] = 1;
    m["billi"] = 2;
    m["meao"]++;

    //searching
    cout << m["billi"] << endl;
    cout << m.at("billi") << endl;
    cout << m["teen"] << endl;
    cout << m.at("teen") << endl;

    //size of hashmap
    cout << m.size() << endl;

    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it -> first << ":" << it -> second << endl;
        it++;
    }

    //deleting a key value pair
    m.erase("doo");
    cout << m.size() << endl;

    for(auto i:m){
        cout << i.first << ":" << i.second << endl;
    }

}