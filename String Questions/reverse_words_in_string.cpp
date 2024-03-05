#include <iostream>

using namespace std;

string reverseWordsInString(string s){
    string word = "";
    string result = "";
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            word += s[i];
        }
        if(s[i] == ' ' || i == s.length()-1){
            int start = 0;
            int end = word.length() - 1;
            while(start <= end){
                swap(word[start], word[end]);
                start++;
                end--;
            }
            result += word;
            result.push_back(' ');
            word = "";
        }    
            
    }
    
    return result;
}

int main()
{
    string s = "I am Chandrayan 3 Rover";
    
    int start = 0;
    int end = s.length() - 1;
    while(start <= end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
    
    cout << reverseWordsInString(s);
}