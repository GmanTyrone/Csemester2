#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(void)
{
    long long int n;
    while(cin >> n)
        {
            if(n<1||n>100000)return 0;
            long long int mapa[n];
            long long int x,y,maxtH=0,minH=106,localmax=0;


            //fills with 0
            for(long long int i=0;i<n;++i){
                mapa[i]=0;
            }

            //Fills the H values
            for(long long int i=0;i<n;++i){
                scanf("%d",mapa[i]);
                //cin>>mapa[i];
            }



            //Computes the Happiness
            for (int i = 0; i < n; i++)
            {
                for(int j=i;j<n;j++){
                    localmax=0;
                    minH=mapa[i];
                    for(int k=i;k<=j;k++){
                        localmax=localmax+mapa[k];
                        if(mapa[k]<minH){
                            minH=mapa[k];
                        }
                    }
                    if(localmax*minH>maxtH){
                        maxtH=localmax*minH;
                        x=i+1;
                        y=j+1;
                    }
                }

            }

            //Prints
            cout<<maxtH<<endl<<x<<" "<<y<<endl;
        }
    return 0;
}
