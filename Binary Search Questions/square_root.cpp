#include<iostream>
using namespace std;

double preciseValue(int n, double result, double addon){
        result += addon;
        while(true){
            if((result*result) == n){
                return result;
            }
            else if((result*result) < n){
                result += addon;
            }
            else{
                result -= addon;
                break;
            }
        }
        return result;
}

float squareRoot(int n){

    int s = 0;
    int e = n;
    double ans = 0;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if((mid*mid) == n){
            ans = mid;
            return ans;
        }
        else if(n < (mid*mid)){
            e = mid - 1;
        }
        else{
            ans = mid;
            s = mid + 1;
        }
    }

    double result1 = preciseValue(n,ans,0.1);
    double result2 = preciseValue(n,result1,0.01);
    double result3 = preciseValue(n,result2,0.001);
    double result4 = preciseValue(n,result3,0.0001);
    double result5 = preciseValue(n,result4,0.00001);           

    return result5;

}

int main(){
    int num;
    cout << "Enter a number:";
    cin >> num;
    cout << squareRoot(num);
}