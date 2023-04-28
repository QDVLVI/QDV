//talent.cpp

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//待补充：12 talentpoints

//待补充：talent_memory.txt

//待补充：function of talents

struct Talevel{
    string name;
    int level;
    int conpoint;//consumepoints
};

void talent(int assets){
    int quotient,talentpoint,talentsum,familyrank;
    Talevel t[12];//name&level
    
    
    ifstream fin;
    fin.open("talent_memory.txt");
    if(fin.fail()){
        cout<<"open failed."<<endl;
    }
    else{
        for (int i=0; i<12; i++){
            fin>>t[i].name;
            fin>>t[i].level;
            fin>>t[i].conpoint;
        }
        fin>>talentsum;
    }
    fin.close();
    
    
    for ( int j=0; j<12; j++){
        if (t[j].level>=0){
            familyrank+=t[j].level;
        }
    }
    
    
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
    cout<<"The talentpoints gotten are "<<talentpoint<<endl;//talentpoint
    talentsum+=talentpoint;
    cout<<"the total talentpoints are "<<talentsum<<endl;
    
    
    //游戏界面
    cout<<"      Family rank: "<<familyrank<<endl;
    cout<<"You can upgrade unlocked talents."<<endl;
    //待补充：所有talents & level（0~3）
    //未解锁的talents，标注locked
    
    
    
    
    for (int k=0; k<12; k++){
        if (t[k].level>=0){
            cout<<t[k].name<<"  "<<t[k].conpoint<<"  "<<//function(待补充)<<endl;
        }
    }
    
    
    
    //玩家选择
    string input;
    cout<<"Please enter the name of talents you want to upgrade, otherwisw enter 'n': ";
    cin>>input;
    if (input=="n"){
        //直接退出界面，fstream
        
    }
    else{
        for(int m=0; m<12; m++){
            if(input==t[m].name){
                talentsum-=t[m].conpoint;
                t[m].level+=1;
                if(m==0 || m==2 || m==6 || m==8){
                    switch (t[m].level)
                    {
                        case 0:
                          t[m].conpoint = 80;
                          break;
                        case 1:
                          t[m].conpoint = 120;
                          t[m+1].level+=1;
                          cout<<t[m+1].name<<" is unlocked."<<endl;
                          t[m+1].conpoint=190;
                          break;
                        case 2:
                          t[m].conpoint = 200;
                          break;
                    }
                }
                else if(m==1 || m==3 || m==7 || m==9){
                    switch (t[m].level)
                    {
                        case 0:
                          t[m].conpoint = 190;
                          break;
                        case 1:
                          t[m].conpoint = 250;
                          t[m+1].level+=1;
                          cout<<t[m+1].name<<" is unlocked."<<endl;
                          t[m+1].conpoint=320;
                          break;
                        case 2:
                          t[m].conpoint = 320;
                          break;
                    }
                }
                else if(m==4 || m==10){
                    switch (t[m].level)
                    {
                        case 0:
                          t[m].conpoint = 320;
                          break;
                        case 1:
                          t[m].conpoint = 400;
                          t[m+1].level+=1;
                          cout<<t[m+1].name<<" is unlocked."<<endl;
                          t[m+1].conpoint= 480;
                          break;
                        case 2:
                          t[m].conpoint = 500;
                          break;
                    }
                }
                else if( m==5 || m==11 ){
                    switch (t[m].level)
                    {
                        case 0:
                          t[m].conpoint = 480;
                          break;
                        case 1:
                          t[m].conpoint = 670;
                          t[m+1].level+=1;
                          break;
                        case 2:
                          t[m].conpoint = 940;
                          break;
                    }
                }
            }
        }
    }
    cout<<"the total talentpoints are "<<talentsum<<endl;
    
    
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
    }
    fout.close();
    
    
    
    
    
    //consumption[4][3]={80,120,200, 190,250,320, 320,400,500, 480,670,940}
    //待补充：显示界面:名称(12)+等级（0~3)
             //倒爷 0--销售达人 1
             //大富之家 2--经营理念 3--资本运作 4--基业长青 5
             //赌神 6--老当益壮 7
             //名门望族 8--懂车帝 9--欧皇 10--炒房团 11
             
            // 若已解锁，显示level：0；未解锁，显示level：null
            
    //int profiteer[80，120，200]；
    //增加初始仓库Add initial warehouse 
    //1) 0-->10; 2) 10--> 20; 3) 20-->30                        
    //int sales_professional[190, 250, 320];
    //出售物品价格提升Increase in price of items for sale
    //1）5%; 2) 10%; 3) 15%
    
    //int great_wealth[80, 120, 200];
    //增加初始金钱Increase initial money
    //1）0-->10000; 2) 10000-->20000; 3) 20000-->30000
    //int management_Philosophy[190, 250, 320];
    //增加公司收益率Increase company profitability
    //1) 0-->0.1%; 2)0.1%-->0.2%; 3)0.2%-->0.3%
    //int capital_operation[320, 400, 500];
    //公司卖出价格增加Increase in company selling price
    //1）1%； 2）2%； 3）3%
    //int foundation_of_longevity[480, 670, 940];
    //家族天赋点结算提升Talent Point Settlement Boost
    //1）10； 2）50； 3）100
    
    //int gambling_God[80, 120, 200];
    //买彩票中奖几率提升Improve chances of winning the lottery 
    //1）2%； 2）5%； 3）10%
    //int longevity[190, 250, 320];
    //退休年限延长longer career life
    //1) 70-->80; 2) 80-->90; 3)90-->100
    
    //int aristocrats[80, 120, 200];
    //增加初始名声Increase in initial fame
    //1）5--10; 2)10-->20; 3)30--40
    //int car_guy[190, 250, 320];
    //购买汽车价格降低Lower price for purchasing a car
    //1）-10000； 2）-20000； 3）-30000
    //int lucky_man[320, 400, 500];
    //名声事件触发概率提升Increased probability of fame event triggering
    //1）5%； 2）10%； 3）15%
    //int house_speculation[480, 670, 940];
    //购买住宅价格降低Lower prices for purchasing a home
    //1）-5%; 2)-10%; 3)-15%
    
    //补充 name --> level --> price
    
    //如果前一个talent变成level1，下一个talent就解锁，可以进行consumption，txt中level+1
    
    //sum减去相应的，增加初始功能,增加level和family rank
    //fout txt file
    
}
