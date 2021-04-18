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
        return getDigit()+Digito2.getDigit();
    }
};

void Complemento(vector<Digit> a, int tamano)
{
    for(int i=0;i<tamano;++i){
        a.at(i).setDigit(9-a.at(i).getDigit());
    }
    a.at(tamano).setDigit(10-a.at(tamano).getDigit());
}

void Trim(vector<Digit> a)
{
    while(a.at(0).getDigit()==0)a.erase(a.begin());
}


class IntNumber
{
public:
    //variables
    vector<Digit>Losdigitos;
    int tamano=Losdigitos.size();
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
       isnegative=false;
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
        int carry=0, cociente=0, addtama;
        vector<Digit> top;
        bool topsign;
        vector<Digit> bot;
        bool botsign;


        //Puts the larger in size on top and the smallest in size on the bottom
        if(tamano>Numero2->tamano){
            top=Losdigitos;
            topsign=isnegative;
            bot=Numero2->Losdigitos;
            botsign=Numero2->isnegative;
            addtama=tamano+1;
        }
        else{
            bot=Losdigitos;
            botsign=isnegative;
            top=Numero2->Losdigitos;
            topsign=Numero2->isnegative;
            addtama=Numero2->tamano+1;
        }

        //Adds a bit at the beginning for sign
        top.insert(top.begin(),Digit());

        //Creates the character array for making the sum Number
        char numeros[addtama];

        //Adds 0's to the bottom one until its the same size as the top one
        while(bot.size()<addtama)bot.insert(bot.begin(),Digit());


        //Makes the complement for the numbers if necessary
        if(topsign)Complemento(top,addtama);
        if(botsign)Complemento(bot,addtama);


        //Fill the character array
        for(int i=addtama-1;i>=0;--i){
            numeros[i]=(top[i].getDigit()+bot[i].getDigit()+carry)%10;
            carry=(top[i].getDigit()+bot[i].getDigit()+carry)/10;
        }
        IntNumber *sum = new IntNumber(numeros);
        if(sum->Losdigitos[0].getDigit()==9)
        {
            Complemento(sum->Losdigitos,sum->Losdigitos.size());
            sum->isnegative=true;
        }
        Trim(sum->Losdigitos);
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
