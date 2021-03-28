#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Digit
{
public:
    int digit;
    Digit(){
        digit=0;
    }
    Digit(int a){
        if(a>=0&&a<=9)digit=a;
        else digit=0;
    }
    void setDigit(int b){
        if(b>=0&&b<=9)digit=b;
        else digit=0;
    }
    int getDigit(){
        return digit;
    }
};

int main(void)
{
    return 0;
}
