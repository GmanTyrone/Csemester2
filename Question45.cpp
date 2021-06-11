#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    while(1)
        {
            cin>>n;
            if(n==0)return 0;
            int mapa[n+1][n+1];
            int x,y,cols=0,rows=0;
            //fills with 0
            for(int i=0;i<n+1;++i){
                for(int j=0;j<n+1;++j){
                    mapa[i][j]=0;
                }
            }

            //Fills the bits
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    cin>>mapa[i][j];
                }
            }

            //Adds the columns and
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    mapa[i][n]+=mapa[i][j];
                    mapa[n][j]+=mapa[i][j];
                }
            }

            //Looks for the bit
            for(int i=0;i<n;++i){
                if(mapa[i][n]%2!=0){
                    rows++;
                    x=i+1;
                }
                if(mapa[n][i]%2!=0){
                    cols++;
                    y=i+1;
                }
            }

            //Prints
            if(cols==0&&rows==0) cout<<"OK"<<endl;
            else if(cols==1&&rows==1)cout<<"Change bit ("<<x<<","<<y<<")"<<endl;
            else cout<<"Corrupt"<<endl;
        }
    return 0;
}
