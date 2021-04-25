#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int NX,NR;
    while(1){
    cin>>NX>>NR;

    //Makes arrays for Requests and Done
    if(NX==0&&NR==0)break;
    int Done[NX][2],Requests[NR][2];

    //Fill Requests and Done arrays
    for(int i=0;i<NX;++i){
        cin>>Done[i][0]>>Done[i][1];
    }

    for(int i=0;i<NR;++i){
        cin>>Requests[i][0]>>Requests[i][1];
    }

    //Generate array of Numbers
    long int count=0;
    long int date[137549][2];
    for(long int i=17000101;i<=21001231;++i){
        long int anio=i/10000;
        long int mes=(i%10000)/100;
        long int dia=i%100;
        if((anio!=0&&mes!=0&&dia!=0)&&mes<=12){
            if(mes%2!=0){
                if(dia<=31){
                    date[count][0]=i;
                    ++count;
                }
            }
            else if(mes==2){
                if((anio%4==0&&anio%100!=0)||anio%400==0){
                    if(dia<=29){
                        date[count][0]=i;
                        ++count;
                    }
                }
            }
            else{
                if(dia<=30){
                    date[count][0]=i;
                    ++count;
                }
            }
        }
    }

    //Fill with ones and 0s
    for(int i=0;i<NR;++i){
        for(int j=NR[i][0];j<=NR[i][1];++j){
            date[j]
        }
    }


    }
    return 0;
}
