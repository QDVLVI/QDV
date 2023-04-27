//talent.cpp

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//待补充：talentsum

//待补充：12 talentpoints

//待补充：talent_memory.txt

struct Talevel{
    string name;
    int level;
};

void talent(int assets){
    int quotient,talentpoint,talentsum,familyrank;
    Talevel talist[12];
    
    
    ifstream fin;
    fin.open("talent_memory.txt");
    for (int i=0; i<12; i++){
        fin>>talist[i].name;
        fin>>talist[i].level;
    }
    fin>>talentsum;
    
    
    for ( int j=0; j<12; j++){
        familyrank+=talist[j].level;
    }
    cout<<""<<endl;//current familyrank
    
    
    quotient=assets/1000000;
    if(quotient==0)
        talentpoint=5;
    else if (quotient<5)
        talentpoint=10;
    else if(quotient<10)
        talentpoint=50;
    else if(quotient<50)
        talentpoint=100;
    else if(quotient<100)
        talentpoint=250;
    else if(quotient==100)
        talentpoint=500;
    cout<<""<<endl;//talentpoint
    talentsum+=talentpoint;
    cout<<"the total talentpoints are "<<talentsum<<endl;
   
   //待补充：显示界面:名称(12)+等级（0~3)
             //倒爷 --销售达人
             //大富之家--经营理念--资本运作--基业长青
             //赌神--老当益壮
             //名门望族--懂车帝--欧皇--炒房团
    //int Profiteer[80，120，180]；
    //int Sales_professional[240, 310, 400];
    //int great_wealth[80, 120, 200];
    //int Management_Philosophy[160, 200, 270];
    //int Capital_operation[320, 400, 540];
    //int Foundation_of_longevity[480, 670, 940];
    //int Gambling_God[190, 240, 320];
    //int Longevity[320, 480, 720];
    //int Aristocrats[80, 110, 150];
    //int Car_guy[190, 250, 320];
    //int Lucky_man[320, 400, 500];
    //int House_speculation[300, 370, 500];
    
   
}
