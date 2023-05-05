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

void talent(role &player,  ){
    int quotient,talentpoint,talentsum,extra;
    Talevel t[11];
    
    
    ifstream fin;
    fin.open("talent_memory.txt");
    if(fin.fail()){
        cout<<"open failed."<<endl;
    }
    else{
        for (int i=0; i<11; i++){
            fin>>t[i].name>>t[i].level>>t[i].conpoint;
        }
        fin>>talentsum;
        fin.ignore();
        fin>>extra;
        fin.ignore();
        for ( int j=0; j<11; j++){
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
    int n;
    cout<<"Upgrade talents: enter 'No.'"<<endl;
    cout<<"Quit: enter '0'"<<endl;
    cout<<"Your choice? ";
    cin>>n;
    while (n != 0){
        int m=n-1;
        
        cout<<"You can upgrade unlocked talents."<<endl;
        cout<<"#:"<<left<<setw(18)<<"Name"<<left<<setw(9)<<"Level"<<endl;
        cout<<"1 :"<<left<<setw(18)<<t[0].name<<left<<setw(2)<<t[0].level<<" ----> "<<"2 :"<<left<<setw(18)<<t[1].name;
        (t[1].level>=0)? cout<<left<<setw(9)<<t[1].level<<endl : cout<<left<<setw(7)<<"locked"<<endl;
        cout<<"3 :"<<left<<setw(18)<<t[2].name<<left<<setw(2)<<t[2].level<<" ----> "<<"4 :"<<left<<setw(18)<<t[3].name;
        (t[3].level>=0)? cout<<left<<setw(9)<<t[3].level : cout<<left<<setw(7)<<"locked";
        cout<<" ----> "<<"5 :"<<left<<setw(18)<<t[4].name;
        (t[4].level>=0)? cout<<left<<setw(9)<<t[4].level : cout<<left<<setw(7)<<"locked";
        cout<<" ----> "<<"6 :"<<left<<setw(18)<<t[5].name;
        (t[5].level>=0)? cout<<left<<setw(9)<<t[5].level<<endl : cout<<left<<setw(7)<<"locked"<<endl;
        cout<<"7 :"<<left<<setw(18)<<t[6].name<<left<<setw(2)<<t[6].level<<" ----> "<<"8 :"<<left<<setw(18)<<t[7].name;
        (t[7].level>=0)? cout<<left<<setw(9)<<t[7].level<<endl : cout<<left<<setw(7)<<"locked"<<endl;
        cout<<"9 :"<<left<<setw(18)<<t[8].name<<left<<setw(2)<<t[8].level<<" ----> "<<"10:"<<left<<setw(18)<<t[9].name;
        (t[9].level>=0)? cout<<left<<setw(9)<<t[9].level : cout<<left<<setw(7)<<"locked";
        cout<<" ----> "<<"11:"<<left<<setw(18)<<t[10].name;
        (t[10].level>=0)? cout<<left<<setw(9)<<t[10].level<<endl : cout<<left<<setw(7)<<"locked"<<endl;
        
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
            if(m==6){
                switch (t[m].level)
                {
                case 1:
                  t[m].conpoint = 120;
                  cout<<t[m].function<<": +1%"<<endl;

                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint=190;
                  break;
                case 2:
                  t[m].conpoint = 200;
                  cout<<t[m].function<<": +1%-->2%"<<endl;

                  break;
                case 3:
                  cout<<t[m].function<<": +2%-->3%"<<endl;

                  break;
                }
            }
            if(m==8){
                switch (t[m].level)
                {
                case 1:
                  t[m].conpoint = 120;
                  cout<<t[m].function<<": 0-->10"<<endl;
                  player.frame+=10;
                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint=190;
                  break;
                case 2:
                  t[m].conpoint = 200;
                  cout<<t[m].function<<": 10-->20"<<endl;
                  player.frame+=10;
                  break;
                case 3:
                  cout<<t[m].function<<": 20-->30"<<endl;
                  player.frame+=10;
                  break;
                }
            }
            else if(m==1){
                switch (t[m].level)
                {
                case 0:
                  t[m].conpoint = 190;
                  break;
                case 1:
                  t[m].conpoint = 250;
                  cout<<t[m].function<<": +5%"<<endl;

                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint=320;
                  break;
                case 2:
                  t[m].conpoint = 320;
                  cout<<t[m].function<<": +5%-->10%"<<endl;

                  break;
                case 3:
                  cout<<t[m].function<<": +10%-->15%"<<endl;

                  break;
                }
            }
            else if(m==3){
                switch (t[m].level)
                {
                case 0:
                  t[m].conpoint = 190;
                  break;
                case 1:
                  t[m].conpoint = 250;
                  cout<<t[m].function<<": +0.1%"<<endl;

                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint=320;
                  break;
                case 2:
                  t[m].conpoint = 320;
                  cout<<t[m].function<<": +0.1%-->0.2%"<<endl;

                  break;
                case 3:
                  cout<<t[m].function<<": +0.2%-->0.3%"<<endl;

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
            else if(m==9){
                switch (t[m].level)
                {
                case 0:
                  t[m].conpoint = 190;
                  break;
                case 1:
                  t[m].conpoint = 250;
                  cout<<t[m].function<<": -10000"<<endl;

                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint=320;
                  break;
                case 2:
                  t[m].conpoint = 320;
                  cout<<t[m].function<<": -20000"<<endl;

                  break;
                case 3:
                  cout<<t[m].function<<": -30000"<<endl;

                  break;
                }
            }
            else if(m==4){
                switch (t[m].level)
                {
                case 0:
                  t[m].conpoint = 320;
                  break;
                case 1:
                  t[m].conpoint = 400;
                  cout<<t[m].function<<": +1%"<<endl;

                  t[m+1].level+=1;
                  cout<<t[m+1].name<<" is unlocked."<<endl;
                  t[m+1].conpoint= 480;
                  break;
                case 2:
                  t[m].conpoint = 500;
                  cout<<t[m].function<<": +1%-->2%"<<endl;
                  break;
                case 3:
                  cout<<t[m].function<<": +2%-->3%"<<endl;

                  break;
                }
            }
            else if( m==5 ){
                switch (t[m].level)
                {
                case 0:
                  t[m].conpoint = 480;
                  break;
                case 1:
                  t[m].conpoint = 670;
                  cout<<t[m].function<<": +10"<<endl;
                  extra=10;
                  t[m+1].level+=1;
                  break;
                case 2:
                  t[m].conpoint = 940;
                  cout<<t[m].function<<": +10-->50"<<endl;
                  extra=50;
                  break;
                case 3:
                cout<<t[m].function<<": +50-->100"<<endl;
                extra=100;
                break;
                }
            }
            else if( m==10 ){
                switch (t[m].level)
                {
                case 0:
                  t[m].conpoint = 320;
                  break;
                case 1:
                  t[m].conpoint = 400;
                  cout<<t[m].function<<": -5%"<<endl;

                  t[m+1].level+=1;
                  break;
                case 2:
                  t[m].conpoint = 500;
                  cout<<t[m].function<<": -10%"<<endl;

                  break;
                case 3:
                  cout<<t[m].function<<": -15%"<<endl;

                  break;
                }
            }
        else{
            cout<<"you don't have enough talentpoints."<<endl;
        }
        cout<<"Remaining talentpoints: "<<talentsum<<endl;
        cout<<"Continue upgrade: enter 'No.'"<<endl;
        cout<<"Quit: enter '0'"<<endl;
        cout<<"Your choice? ";
        cin>>n;
    }
        
        
    ofstream fout;
    fout.open("talent_memory.txt");
    if(fout.fail()){
        cout<<"open failed."<<endl;
    }
    else{
        for ( int n=0; n<11; n++){
            fout<<t[n].name<<" "<<t[n].level<<" "<<t[n].conpoint<<endl;
        }
        fout<<talentsum<<endl;
        fout<<extra<<endl;
        fout<<"increase in initial storehouse"<<endl;
        fout<<"increase in price of sales items"<<endl;
        fout<<"increase in initial money"<<endl;
        fout<<"increase in company profitability"<<endl;
        fout<<"increase in company selling price"<<endl;
        fout<<"increase in talent points per game"<<endl;
        fout<<"higher probability of winning lottery"<<endl;
        fout<<"longer career life"<<endl;
        fout<<"have a better initial reputation"<<endl;
        fout<<"lower car price"<<endl;
        fout<<"lower house price"<<endl;
    }
    fout.close();
}
