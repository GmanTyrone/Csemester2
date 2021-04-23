#include <iostream>
#include <string>

using namespace std;

class Encode
{
public:
    string codigo;

    Encode()
    {
        codigo="";
  	}
    Encode(string word)
    {
    for (int i = 0; i < word.length(); ++i){
        string numero=to_string((int)word[i]);
        while(numero.length()<3)numero.insert(0,"0");
        codigo += numero;
        }
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
