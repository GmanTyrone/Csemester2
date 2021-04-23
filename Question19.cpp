#include <iostream>

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
    void display(){
        cout<<digit;
    }
};

class IntNumber
{
private:
    Digit Losdigitos[1000];
    bool isnegative=false;
    int counter=0;
    char *p;
public:
    IntNumber()
    {
        return;
    }
    IntNumber(char *letras)
    {
       p=letras;
       int i=0;
       if(letras[0]=='+')++i;
       if(letras[0]=='-'){isnegative=true;++i;}
       while(letras[i]=='0')++i;
       if(!isdigit(letras[i])){
          return;
          }
       while(isdigit(letras[i])){
            Losdigitos[counter]=Digit((int)letras[i]-'0');
            ++i;
            ++counter;
            }
    }
    void display()
    {
        if(counter==0){
            cout<<0;
            return;
        }
        if(isnegative)cout<<"-";
        for(int i=0;i<counter;++i)Losdigitos[i].display();
    }


    IntNumber *add(IntNumber *num2) const{
        long long int sum = stoll(num2->p) + stoll(p);
        string sumstr = to_string(sum);
        return new IntNumber(&sumstr[0]);
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
