#include <iostream>
#include <bits/stdc++.h>
#include <vector>
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
    void setDigit(int b){
        if(b>=0&&b<=9)digit=b;
        else digit=0;
    }
    int getDigit(){
        return digit;
    }
    int sumdigit(Digit Digito2){
        return Digit.getDigit()+Digito2.getDigit();
    }
};

class IntNumber
{
public:
    //variables
    vector<Digit>Losdigitos;
    bool isnegative;

    //functions:
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
        if(Losdigitos[0].getDigit()==0){cout<<0;return;}
        for(Digit x : Losdigitos)cout<<x.getDigit();
    }
    IntNumber *add(const IntNumber *Numero2) const
    {
        int carry=0, cociente=0;
        IntNumber *sum = new IntNumber;
        int menor;
        int tamano=Losdigitos.size();
        int tamano2=Numero2->Losdigitos.size();
        int diferencia=abs(tamano-tamano2);
        if(tamano<tamano2)menor=tamano;
        else menor=tamano2;
        while(menor>=0){
            cociente=Losdigitos.at(menor)+Numero2->Losdigitos.at(menor);
            carry=cociente%10;
            cociente/=10;
            --menor;
        }
        return sum;
    }
};

int main()
{
  char num1[10000], num2[10000];
  cin>>num1>>num2;
  IntNumber *number1 = new IntNumber(num1);
  IntNumber *number2 = new IntNumber(num2);
  number1->display();
  cout<<endl;
  number2->display();
  cout<<endl;
  number1->add(number2)->display();
  cout<<endl;
  number2->add(number1)->display();
  return 0;
}
