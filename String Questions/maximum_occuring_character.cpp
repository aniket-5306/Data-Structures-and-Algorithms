#include<iostream>
using namespace std;

char maxOccuringCharacter(string s){
    int characterCount[26] = {0};
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            characterCount[s[i] - 'A']++;
        else if(s[i] >= 'a' && s[i] <= 'z')
            characterCount[s[i] - 'a']++;
    }
    // for(int k = 0; k < 26; k++){
    //     cout << characterCount[k] << " ";
    // }
    int maxposition = 0;
    for(int j = 1; j < 26; j++){
        if(characterCount[j] > characterCount[maxposition]){
            maxposition = j;
        }
    }
    return char('a' + maxposition);
}

int main(){
    string s = "India";
    cout << "Maximum occuring character -> " << maxOccuringCharacter(s);
}