#include <iostream>
#include <fstream>
#include "structure_define.h"
using namespace std;

//商品，to be completed
goods good_list[8];
goods liquor;        //白酒
goods imported_car;  //进口汽车
goods jade;          //玉石
goods melon_seed;    //瓜子
goods domian_name;   //域名
goods gold;          //黄金
goods copycat_phone; //山寨手机
goods bit_coin;      //比特币

int startGame(){
    role player;

    //选择读取存档（Load game) 或开始新游戏 (New game)
    cout << "..." << endl; //游戏界面，选择存档或新游戏, to be completed
    int temp;
    if (temp == 2){
        //读取存档，to be complete,从file中获取角色信息
        //to be completed
    }

    if (temp == 1){
        //初始化角色
        cout << "Please enter your character name: " << endl;
        char name;
        cin >> name;
        player = {100000, 100000, 100, 0, 20, 70, 100};

        //建立一个文档储存数据,to be completed
        ifstream fin;

    }

    //仓库 (使用linked list)
    product *storehouse;
    storehouse = new product;

    //游戏主循环
    int last_year_money = 100000;
    while (player.age <= player.retire_age){
        player.age += 1;
        cout << "..." << endl; // 游戏界面,从8个商品选5个出来展示，可以用file或直接cout,to be completed

        //随机事件
        if (player.total_assets > last_year_money){
            //随机奖励（年度最佳新人奖，x%触发，奖励10000-100000
            //to be completed
        }

        last_year_money = player.total_assets;

        //买卖（market），创业（business）会损失健康值，
        if (player.health <= 50){
            //有几率住院
            bool isSick; //设置一个random判断是否要住院一年, to be completed
            if (isSick){
                player.health = 100;
                cout << "..." << endl; //you are sick, and u r not able to do anything this year
                continue; //有几率认识伴侣：护士姐姐,to be completed
            }
        }
        
        else{
            char input;
            bool GoToNextYear = false;
            while (cin >> input){
                 switch (input){

                    //market, 市场
                    case 'm':
                        cout << '...' << endl; //游戏界面
                        //function, to be completed
                        break;
                    
                    //business, 创业
                    case 'b':
                        cout << '...' << endl; 
                        //function，to be completed
                        break;

                    //spend money，花钱
                    case 's':
                        cout << '...' << endl;
                        //function, to be completed
                        break;

                    //dating, 约会
                    case 'd':
                        cout << '...' << endl;
                        //function, to be completed
                        break;

                    //next year
                    case 'n':
                        GoToNextYear = true;
                        break;

                    default:
                        break;
                    
                    //将更新后的数据储存到文档，to be completed

                    if (GoToNextYear){
                        break;
                    }
                    
                }
            }
        }
    }
    
    //游戏结束，结算界面（x岁资产超百万，y岁资产超千万，z岁资产过亿，a岁资产最多为m，退休时资产为n，etc.）
    cout << '...' << endl;
}
