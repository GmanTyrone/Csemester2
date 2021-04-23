#include <iostream>
#include <string>
using namespace std;

class Decode
{
public:
    string decodigo;

    Decode()
    {
        decodigo="";
    }
    Decode(string word)
    {
        for(int i=0;i<word.length();i+=3)
        {
            char partei[3];
            word.copy(partei,3,i);
            decodigo+=(char)stoi(partei);
        }
    }

    string decode()
    {
        return decodigo;
    }
};

int main() {
  string str;
  cin>>str;
  Decode *code = new Decode(str);
  cout<<code->decode();
  return 0;
}
