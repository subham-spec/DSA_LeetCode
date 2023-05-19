#include <iostream>
using namespace std;
    int value(char i){
        if(i=='I')
            return 1;
        if(i=='V')
            return 5;
        if(i=='X')
            return 10;
        if(i=='L')
            return 50;
        if(i=='C')
            return 100;
        if(i=='D')
            return 500;
        if(i=='M')
            return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0, i, l = s.length()-1;
        for(i=0; i<=l; i++){
            
            int a = value(s[i]);
            if(i==l){
                ans += a;
                break;
            }
            int b = value(s[i+1]);
            if(a<b){
                ans = ans - a + b;
                ++i;
            }
            else
                ans += a;
        }
        return ans;
    }
int main(){
    string roman = "MMCMIV";
    cout<<romanToInt(roman)<<endl;
}