#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Digit
{
private:
    int digit;
public:

    Digit(){
        digit=0;
    }
    Digit(int a){
        if(a>=0&&a<=9)digit=a;
        else digit=0;
    }

    void setDigit(int a){
        if(a>=0&&a<=9)digit=a;
        else digit=0;
    }

    int getDigit(){
        return digit;
    }
};


class IntNumber
{
private:
  	vector<Digit>Losdigitos;
    bool isnegative;

public:
    IntNumber()
    {
        Losdigitos.push_back(Digit());
        isnegative=false;
    }
    IntNumber(char *letras)
    {
       int i=0;
       if(letras[0]=='+')++i;
       if(letras[0]=='-'){isnegative=true;++i;}
       while(letras[i]=='0')++i;
       if(letras[i]>57||letras[i]<48){isnegative=false;Losdigitos.push_back(Digit());return;}
       while(letras[i]>=48&&letras[i]<=57){Losdigitos.push_back(Digit((int)letras[i]-48));++i;}
    }
    void display()
    {
        if(isnegative)cout<<"-";
        if(Losdigitos[0].getDigit()==0){
            cout<<0;
            return;
        }
        for(Digit x : Losdigitos)cout<<x.getDigit();
    }
};



int main(void)
{
    return 0;
}
