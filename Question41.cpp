#include <iostream>
#include <bits/stdc++.h>
/*
class minefield
{
public:
    minefield(int l, int c)
    {
      lines = l;
      columns = c;
      map = new char *[lines];
      int j;
      for(j = 0;j < lines;j ++)
        map[j] = new char[columns];
    }
private:
    int lines,columns;
    char **map;
};*/

using namespace std;

int main(void)
{
    int n,m,counter=1;
    while(1)
        {
            cin>>n>>m;
            if(n==0&&m==0)return 0;
            char mapa[n+2][m+2];

            //Creates the map nxm with borders
            for(int i=0;i<n+2;++i){
                for(int j=0;j<m+2;++j){
                    mapa[i][j]='.';
                }
            }

            //Fills the mines
            for(int i=1;i<n+1;++i){
                for(int j=1;j<m+1;++j){
                    cin>>mapa[i][j];//=getchar();
                }
                //getchar();
            }

            //Changes to numbers
            for(int i=1;i<n+1;++i){
                for(int j=1;j<m+1;++j){
                    int numero=0;
                    if(mapa[i-1][j-1]=='*')++numero;
                    if(mapa[i-1][j]=='*')++numero;
                    if(mapa[i-1][j+1]=='*')++numero;
                    if(mapa[i][j-1]=='*')++numero;
                    if(mapa[i][j+1]=='*')++numero;
                    if(mapa[i+1][j-1]=='*')++numero;
                    if(mapa[i+1][j]=='*')++numero;
                    if(mapa[i+1][j+1]=='*')++numero;
                    if(mapa[i][j]=='*');
                    else mapa[i][j]=(char)(numero+48);
                }
            }

            //Prints
            cout<<"Field #"<<counter<<":"<<endl;
            for(int i=1;i<n+1;++i){
                for(int j=1;j<m+1;++j){
                    cout<<mapa[i][j];
                    if(j==m)cout<<endl;
                }
            }
            counter++;
            cout<<endl;
        }
    return 0;
}
