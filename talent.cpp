//talent.cpp

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//待补充：talent_memory.txt

//待补充：function of talents

struct Talevel{
    string name;
    int level;
    int conpoint;//consumepoints
    string function;
};

void talent(int assets，int &initial_money, int &storehouse){
    int quotient,talentpoint,talentsum,extra;
    Talevel t[12];
    
    
    ifstream fin;
    fin.open("talent_memory.txt");
    if(fin.fail()){
        cout<<"open failed."<<endl;
    }
    else{
        for (int i=0; i<12; i++){
            fin>>t[i].name>>t[i].level>>t[i].conpoint;
        }
        fin>>talentsum;
        fin>>extra;
        for ( int j=0; j<12; j++){
            getline(fin,t[j].function);
        }
    }
    fin.close();
    
    
    quotient=assets/1000000;
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
    cout<<"The talentpoints gotten are "<<talentpoint<<endl;//talentpoint
    talentsum+=talentpoint;
    cout<<"the total talentpoints are "<<talentsum<<endl;
    
    
    //游戏界面
    cout<<"You can upgrade unlocked talents."<<endl;
    //待补充：所有talents（12） & level（0~3）
    //未解锁的talents，标注locked
    //前一个升到等级1后，后一个解锁（标注等级0)
    
    //倒爷 --销售达人 
    //大富之家 --经营理念 --资本运作 --基业长青 
    //赌神 --老当益壮 
    //名门望族 --懂车帝 --欧皇 --炒房团 
    
    
    
    //talent功能介绍，玩家可以选择是否查看
    //未完成
    for (int k=0; k<12; k++){
        if (t[k].level>=0){
            cout<<t[k].name<<"  "<<t[k].conpoint<<"  "<<t[k].function<<endl;
        }
    }
    
    
    
    //玩家选择
    string input;
    cout<<"Please enter the name of talents you want to upgrade, otherwisw enter 'e': ";
    cin>>input;
    while (input != "e"){
        for(int m=0; m<12; m++){
            if(input==t[m].name){
                    if (talentsum >= t[m].conpoint){
                        talentsum-=t[m].conpoint;
                        t[m].level+=1;
                        if(m==0){
                            switch (t[m].level)
                            {
                            case 0:
                              t[m].conpoint = 80;
                              break;
                            case 1:
                              t[m].conpoint = 120;
                              cout<<"increase in initial storehouse"<<": 0-->10"<<endl;
                              
                              t[m+1].level+=1;
                              cout<<t[m+1].name<<" is unlocked."<<endl;
                              t[m+1].conpoint=190;
                              break;
                            case 2:
                              t[m].conpoint = 200;
                              cout<<"increase in initial storehouse"<<": 10-->20"<<endl;
                              
                              break;
                            case 3:
                              cout<<"increase in initial storehouse"<<": 20-->30"<<endl;
                              
                              break;
                            }
                        }
                        if( m==2 ){
                            switch (t[m].level)
                            {
                            case 0:
                              t[m].conpoint = 80;
                              break;
                            case 1:
                              t[m].conpoint = 120;
                              cout<<t[m].function<<": +100000"<<endl;
                              initial_money+=100000;
                              t[m+1].level+=1;
                              cout<<t[m+1].name<<" is unlocked."<<endl;
                              t[m+1].conpoint=190;
                              break;
                            case 2:
                              t[m].conpoint = 200;
                              cout<<t[m].function<<": +100000-->200000"<<endl;
                              initial_money+=100000;
                              break;
                            case 3:
                              cout<<t[m].function<<": +200000-->3000000"<<endl;
                              initial_money+=100000;
                              break;
                            }
                        }
                        if(m==6){
                            switch (t[m].level)
                            {
                            case 0:
                              t[m].conpoint = 80;
                              break;
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
                            case 0:
                              t[m].conpoint = 80;
                              break;
                            case 1:
                              t[m].conpoint = 120;
                              cout<<t[m].function<<": 5-->10"<<endl;
                              
                              t[m+1].level+=1;
                              cout<<t[m+1].name<<" is unlocked."<<endl;
                              t[m+1].conpoint=190;
                              break;
                            case 2:
                              t[m].conpoint = 200;
                              cout<<t[m].function<<": 10-->20"<<endl;
                              
                              break;
                            case 3:
                              cout<<t[m].function<<": 20-->30"<<endl;
                              
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
                              
                              t[m+1].level+=1;
                              cout<<t[m+1].name<<" is unlocked."<<endl;
                              t[m+1].conpoint=320;
                              break;
                            case 2:
                              t[m].conpoint = 320;
                              cout<<t[m].function<<": 80-->90"<<endl;
                              
                              break;
                            case 3:
                              cout<<t[m].function<<": 90-->100"<<endl;
                              
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
                        else if(m==10){
                            switch (t[m].level)
                            {
                            case 0:
                              t[m].conpoint = 320;
                              break;
                            case 1:
                              t[m].conpoint = 400;
                              cout<<t[m].function<<": +5%"<<endl;
                              
                              t[m+1].level+=1;
                              cout<<t[m+1].name<<" is unlocked."<<endl;
                              t[m+1].conpoint= 480;
                              break;
                            case 2:
                              t[m].conpoint = 500;
                              cout<<t[m].function<<": +5%-->10%"<<endl;
                              break;
                            case 3:
                              cout<<t[m].function<<": +10%-->15%"<<endl;
                              
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
                        else if( m==11 ){
                            switch (t[m].level)
                            {
                            case 0:
                              t[m].conpoint = 480;
                              break;
                            case 1:
                              t[m].conpoint = 670;
                              cout<<t[m].function<<": -5%"<<endl;
                              
                              t[m+1].level+=1;
                              break;
                            case 2:
                              t[m].conpoint = 940;
                              cout<<t[m].function<<": -10%"<<endl;
                              
                              break;
                            case 3:
                              cout<<t[m].function<<": -15%"<<endl;
                              
                              break;
                        }
                    }
                }
                    else{
                        cout<<"you don't have enough talentpoints."<<endl;
                    }
            }
        }
        cout<<"the remaining talentpoints are "<<talentsum<<endl;
        cout<<"enter name of talent to continue upgrade, 'e' to exit. ";
        cin>>input;
    }
        
        
    ofstream fout;
    fout.open("talent_memory.txt");
    if(fout.fail()){
        cout<<"open failed."<<endl;
    }
    else{
        for ( int n=0; n<12; n++){
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
        fout<<"increased probability of frame event"<<endl;
        fout<<"lower house price"<<endl;
    }
    fout.close();
}
