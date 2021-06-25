#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(void)
{
    int n;
    /*string flush;
    bool flag=false;*/
    while(cin>>n)
        {
            //if(flag==true)getline(cin,flush);
            //cin>>n;
            //if(n<1||n>100000)return 0;
            long long int mapa[n];
            long long int x,y,maxtH=0,minH=106,localmax=0;

            //Fills the H values
            for(int i=0;i<n;++i){
                cin>>mapa[i];
            }

            //Computes the Happiness
            for(int i=1;i<=n;++i){//number of days in the subgroups
                for(int j=0;j<n-i;++j){//subgroups
                    localmax=0;
                    minH=106;
                    for(int k=0;k<=i;++k){//
                        localmax+=mapa[j+k];
                        //cout<<mapa[j+k]<<" ";
                        if(mapa[j+k]<minH)minH=mapa[j+k];
                        if(k==i){
                            localmax*=minH;
                            /*cout<<endl<<"local max: "<<localmax<<endl;
                            cout<<"local min: "<<minH<<endl;
                            cout<<"tama;o grupo: "<<i-1<<endl;*/
                            if(localmax>maxtH){
                                maxtH=localmax;
                                /*cout<<"MAX: "<<localmax<<endl;*/
                                x=j+1;
                                y=j+i+1;
                            }
                            //cout<<endl;
                        }
                    }
                }
            }

            //Prints
            cout<<maxtH<<endl<<x<<" "<<y<<endl;
            //flag=true;
        }
    return 0;
}
