#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    while(cin>>n && n != EOF)
        {
            if(n<1||n>100000)return 0;
            int mapa[n];
            int x,y,maxtH=0,minH=106,localmax=0;
            //fills with 0
            for(int i=0;i<n;++i){
                mapa[i]=0;
            }

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
                            if(localmax>maxtH){
                                maxtH=localmax;
                                x=j+1;
                                y=j+i+1;
                            }
                        }
                    }
                }
            }

            //Prints
            cout<<maxtH<<endl<<x<<" "<<y<<endl;
        }
    return 0;
}
