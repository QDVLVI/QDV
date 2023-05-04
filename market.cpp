#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "structure_define.h"
using namespace std;

/*商品属性
struct goods{
    int high_price;
    int normal_price;
    int low_price;
    double high_price_possiblity;
    double normal_price_possibility;
    double low_price_possibility;
};

//角色属性
struct role{
    int cash;
    int total_assets;
    int health;
    int fame;
    int age;
    int retire_age;
    int storehouse_capacity; //仓库容量
    bool isSick;
};
 //仓库物品 (linked list)
 struct product{
     string name;
     int number;
     product *next;
 };
 //商品，to be completed
 goods liquor;        //白酒
 goods imported_car;  //进口汽车
 goods jade;          //玉石
 goods melon_seed;    //瓜子
 goods domian_name;   //域名
 goods gold;          //黄金
 goods copycat_phone; //山寨手机
 goods bit_coin;      //比特币
 goods goods_list[8] = {liquor, imported_car, jade, melon_seed, domian_name, gold, copycat_phone, bit_coin};
*/

goods liquor;        //白酒
goods imported_car;  //进口汽车
goods jade;          //玉石
goods melon_seed;    //瓜子
goods domian_name;   //域名
goods gold;          //黄金
goods copycat_phone; //山寨手机
goods bit_coin;      //比特币
goods goods_list[8] = {liquor, imported_car, jade, melon_seed, domian_name, gold, copycat_phone, bit_coin};
goods market[5];
bool check(int cash,int total_price){
    bool judge=true;
    if (cash<total_price){
        judge=false;
    }
    return judge;
}
void set_price(){
    srand(time(nullptr));
    //liquor price
    liquor.name = "liquor";
    liquor.normal_price = rand()%1001+500;
    liquor.high_price = liquor.normal_price*((rand()%434)/100.0+5.67);
    liquor.low_price = liquor.normal_price%((rand()%41+40)/100);
    
    //imported_car price
    imported_car.name = "imported car";
    imported_car.normal_price = rand()%25000+35000;
    imported_car.high_price = imported_car.normal_price*((rand()%1227)/1000+1.357);
    imported_car.low_price = imported_car.normal_price*((rand()%3977)/10000+0.2857);
    
    //jade price
    jade.name = "jade";
    jade.normal_price = rand()%2001+2000;
    jade.high_price = jade.normal_price*((rand()%5501)/1000+2.5);
    jade.low_price = jade.normal_price*((rand()%101)/1000+0.4);
    
    //melon_seed price
    melon_seed.name = "melon seed";
    melon_seed.normal_price = rand()%171+80;
    melon_seed.high_price = melon_seed.normal_price*((rand()%12501)/2500+3.6);
    melon_seed.low_price = melon_seed.normal_price*((rand()%158+21)/1000+0.22);
    
    //domian_name price
    domian_name.name = "domian name";
    domian_name.normal_price = rand()%13001+19000;
    domian_name.high_price = domian_name.normal_price*((rand()%51)/100+2);
    domian_name.low_price = domian_name.normal_price*((rand()%501)/10000+0.45);
    
    //gold price
    gold.name = "gold";
    gold.normal_price = rand()%2001+4000;
    gold.high_price = gold.normal_price*((rand()%251)/1000+3);
    gold.low_price = gold.normal_price*((rand()%501)/10000+0.45);
    
    //copycat_phone price
    copycat_phone.name = "copycat phone";
    copycat_phone.normal_price = rand()%351+450;
    copycat_phone.high_price = copycat_phone.normal_price*((rand()%751)/1000+5.5);
    copycat_phone.low_price = copycat_phone.normal_price*((rand()%51)/1000+0.45);
    
    //bit_coin price
    bit_coin.name = "bit coin";
    bit_coin.normal_price = rand()%4101+3900;
    bit_coin.high_price = bit_coin.normal_price*((rand()%1501)/1000+5.5);
    bit_coin.low_price = bit_coin.normal_price*((rand()%71)/1000+0.43);
    
    
    
}

//随机产品
int select_goods(){
    srand(time(0));
    bool dis[8]={true,false,true,true,false,true,true,false};
    for (int i=0;i<8;i++){
        int index=rand()%8;
        
        bool temp=dis[i];
        dis[i]=dis[index];
        dis[index]=temp;
    }
    for (int j=0;j<8;j++){
        goods_list[j].appear=dis[j];
    }
    
    return 0;
}
void add_list(){
    int j=0;
    for (int i=0;i<8;i++){
        if (goods_list[i].appear == true){
            market[j]=goods_list[i];
            j++;
        }
    }
}
int main(){
    product *storehouse;
    storehouse = new product;
    int No,num,price,total_price; //No 编号12345 /num 购买商品数目
    int cash=100000,health=100;//初始十万元,健康值100
    bool tf=true,canno=true;
    string decision;
    while (tf){
        set_price();
        select_goods();
        add_list();
        
        cout<<"1:Purchase"<<endl;
        cout<<"2:Sale"<<endl;
        cout<<"3:Quit"<<endl;
        cout<<"Your decision: ";
        cin>>decision;
        if (decision=="1"){
            cout<<"|"<<setw(15)<<"Goods"<<setw(12)<<"|"<<setw(18)<<"Storehouse"<<setw(9)<<"|"<<endl;
            cout<<"|"<<"1: "<<left<<setw(23)<<market[0].name<<"|"<<"1: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            cout<<"|"<<"2: "<<left<<setw(23)<<market[1].name<<"|"<<"2: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            cout<<"|"<<"3: "<<left<<setw(23)<<market[2].name<<"|"<<"3: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            cout<<"|"<<"4: "<<left<<setw(23)<<market[3].name<<"|"<<"4: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            cout<<"|"<<"5: "<<left<<setw(23)<<market[4].name<<"|"<<"5: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            
            
            //打印商品
            cout<<"Which good do you want: ";
            cin>>No;
            cout<<"How many do you want: ";
            cin>>num;
            //price 初始化
            total_price=num*price;
            check(cash,total_price);
            {if (canno){
                cash=cash-total_price;
                health-=1;
                //存入storehouse
                cout<<"Purchase successful!"<<endl;
                cout<<"Remained Cash: "<<cash<<endl;
                
            }
            else{
                cout<<"Purchase failed, you need more Cash"<<endl;
            }
                
            }
        }
        if (decision=="2"){
            cout<<"Which good do you want to sell: ";
            cin>>No;
            cout<<"How many do you want to sell: ";
            cin>>num;
            total_price=num*price;
            cash+=total_price;
            health-=1;
            }
        if (decision=="3"){
            break;
        }
    }
    
    
    
    
    
    
    
}

