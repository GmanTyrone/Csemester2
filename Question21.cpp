#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Decode
{
public:
    string decodigo;
    int len;


    Decode()
    {
        decodigo="";
        len=decodigo.size();
    }
    Decode(string word)
    {
        decodigo="";
        int longitude=word.size();
        for(int i=longitude-1;i>=0;i-=3)
        {
            int a=0;
            for(int j=0;j<3;++j)
            {
                a+=((int)word[i-j]-48)*pow(10,j);
            }
            decodigo.insert(0,1,(char)a);
        }
        len=decodigo.size();
    }

    string decode()
    {
        return decodigo;
    }
};



//072101108108111

int main() {
  string str;
  cin>>str;
  Decode *code = new Decode(str);
  cout<<code->decode();
  return 0;
}
