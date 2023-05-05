#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include "structure_define.h"
using namespace std;


struct Talevel{
    string name;
    int level;
    int conpoint;//consumepoints
    string function;
};

void talent(  ){
    int quotient,talentpoint,talentsum,extra;
    Talevel t[3];
    
    
    ifstream fin;
    fin.open("talent_memory.txt");
    if(fin.fail()){
        cout<<"open failed."<<endl;
    }
    else{
        for (int i=0; i<3; i++){
            fin>>t[i].name>>t[i].level>>t[i].conpoint;
        }
        fin>>talentsum;
        fin.ignore();
        fin>>extra;
        fin.ignore();
        for ( int j=0; j<3; j++){
            getline(fin,t[j].function);
        }
    }
    fin.close();
    
    
    quotient= player.total_assets/1000000;
    if(quotient==0)
        talentpoint=5+extra;
    else if (quotient<5)
        talentpoint=10+extra;
    else if(quotient<10)
        talentpoint=50+extra;
    else if(quotient<50)
        talentpoint=100+extra;
    else if(quotient<100)
        talentpoint=250+extra;
    else if(quotient>=100)
        talentpoint=500+extra;
    cout<<"Talentpoints get: "<<talentpoint<<endl;//talentpoint
    talentsum+=talentpoint;
    cout<<"Total talentpoints: "<<talentsum<<endl;
    
    
    //玩家选择
    int input;
    cout<<"1.Upgrade talents"<<endl;
    cout<<"2.Quit"<<endl;
    cout<<"Your choice? ";
    cin>>input;
    
    while (input != 2){
        int n,m;
        
        cout<<"Enter No. of talent: ";
        cin>>n;
        m=n-1;
        if (talentsum >= t[m].conpoint){
            talentsum-=t[m].conpoint;
            t[m].level+=1;
            if(m==0){
                switch (t[m].level)
                {
                case 1:
                  t[m].conpoint = 120;
                  cout<<"increase in initial storehouse capacity"<<": +10"<<endl;
                  player.storehouse_capacity+=10;
                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint=190;
                  break;
                case 2:
                  t[m].conpoint = 200;
                  cout<<"increase in initial storehouse capacity"<<": +10-->20"<<endl;
                  player.storehouse_capacity+=10;
                  break;
                case 3:
                  cout<<"increase in initial storehouse capacity"<<": +20-->30"<<endl;
                  player.storehouse_capacity+=10;
                  break;
                }
            }
            if( m==2 ){
                switch (t[m].level)
                {
                case 1:
                  t[m].conpoint = 120;
                  cout<<t[m].function<<": +100000"<<endl;
                  player.cash+=100000;
                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint=190;
                  break;
                case 2:
                  t[m].conpoint = 200;
                  cout<<t[m].function<<": +100000-->200000"<<endl;
                  player.cash+=100000;
                  break;
                case 3:
                  cout<<t[m].function<<": +200000-->3000000"<<endl;
                  player.cash+=100000;
                  break;
                }
            }
            else if(m==7){
                switch (t[m].level)
                {
                case 0:
                  t[m].conpoint = 190;
                  break;
                case 1:
                  t[m].conpoint = 250;
                  cout<<t[m].function<<": 70-->80"<<endl;
                  player.retire_age+=10;
                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint=320;
                  break;
                case 2:
                  t[m].conpoint = 320;
                  cout<<t[m].function<<": 80-->90"<<endl;
                  player.retire_age+=10;
                  break;
                case 3:
                  cout<<t[m].function<<": 90-->100"<<endl;
                  player.retire_age+=10;
                  break;
                }
            }
           
        else{
            cout<<"you don't have enough talentpoints."<<endl;
        }
        cout<<"Remaining talentpoints: "<<talentsum<<endl;
        cout<<"1.Continue upgrading"<<endl;
        cout<<"2.Quit"<<endl;
        cout<<"Your choice? ";
        cin>>input;
    }
        
        
    ofstream fout;
    fout.open("talent_memory.txt");
    if(fout.fail()){
        cout<<"open failed."<<endl;
    }
    else{
        for ( int n=0; n<3; n++){
            fout<<t[n].name<<" "<<t[n].level<<" "<<t[n].conpoint<<endl;
        }
        fout<<talentsum<<endl;
        fout<<extra<<endl;
        fout<<"increase in initial storehouse"<<endl;
       
        fout<<"increase in initial money"<<endl;
       
        fout<<"longer career life"<<endl;
        
    }
    fout.close();
}
