#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Encode
{
public:
    string codigo;
    int len;


    Encode()
    {
        codigo="000";
        len=codigo.size();
    }
    Encode(string word)
    {
        codigo="";
        int longitude=word.size();
        for(int i=longitude-1;i>=0;--i)
        {
            int a=(int)word[i];
            string b=to_string(a);
            while(b.size()<3)b.insert(0,"0");
            codigo.insert(0,b);
        }
        len=codigo.size();
    }

    string encode()
    {
        return codigo;
    }
};





int main() {
  string str;
  getline(cin, str);
  Encode *code = new Encode(str);
  cout<<code->encode();
  return 0;
}
