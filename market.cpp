#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <algorithm>
#include "structure_define.h"
using namespace std;

bool check(int cash,int price, int number, int capacity){
    bool judge=true;
    if (cash < (price*number) || number <= capacity){
        judge=false;
    }
    return judge;
}

//随机产品
bool select_goods(goods* good_list){
    //initialize good_list[].appear
    for (int i = 0; i < 8; i++){
        good_list[i].appear = false;
    }

    //randomly pick 5 good to appear
    int select_num = 0;
    while(select_num < 5){
        int random_seed = time(nullptr) + rand();
        srand(random_seed);
        int random_number = rand()%8;
        if (good_list[random_number].appear == false){
            good_list[random_number].appear = true;
            select_num++;
        }
    }

    return true;
}

void market(int &cash, int &health, int &storehouse_capacity, goods* good_list, map<string, store> &storehouse){
    //select good
    bool success = select_goods(good_list);
    goods *market = new goods[5];
    if (success){
        int j = 0;
        for (int i = 0; i < 8; i++){
            market[j] = good_list[i];
            j++;
        }

        //游戏界面
            cout<<"|"<<setw(15)<<"Goods"<<setw(12)<<"|"<<setw(18)<<"Storehouse"<<setw(9)<<"|"<<endl;
            cout<<"|"<<"1: "<<left<<setw(23)<<market[0].name<<"|"<<"1: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            cout<<"|"<<"2: "<<left<<setw(23)<<market[1].name<<"|"<<"2: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            cout<<"|"<<"3: "<<left<<setw(23)<<market[2].name<<"|"<<"3: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            cout<<"|"<<"4: "<<left<<setw(23)<<market[3].name<<"|"<<"4: "<<left<<setw(23)<<"vks"<<"|"<<endl;
            cout<<"|"<<"5: "<<left<<setw(23)<<market[4].name<<"|"<<"5: "<<left<<setw(23)<<"vks"<<"|"<<endl;
    }else{
        cout << "fail to select goods" << endl;
    }

    //market loop
    while (true){
        char decision;
        bool quit = false;

        cout<<"1:Purchase"<<endl;
        cout<<"2:Sale"<<endl;
        cout<<"3:Quit"<<endl;
        cout<<"Your decision: ";

        cin >> decision;
        if (decision == '1'){
            //buying
            int No, num, maxNum;
            cout<<"Which good do you want: " << endl;
            cin >> No;

            maxNum = min((market[No].actual_price / cash), storehouse_capacity);
            cout<<"How many do you want (you could buy at most " << maxNum <<" ): " << endl;
            cin>>num;

            if (check(cash, market[No].actual_price, num, storehouse_capacity)){
                //将该物品加入仓库
                storehouse_capacity -= num;
                cash -= num * market[No].actual_price;
                health -= 1;

                //之前没买过这个物品
                if (storehouse.count(market[No].name) == 0){
                    store temp = {market[No].name, market[No].actual_price, num};
                    storehouse[market[No].name] = temp; 
                }
                
                //之前买过这个商品
                else{
                    int updated_price;
                    updated_price = (storehouse[market[No].name].buyInPrice * storehouse[market[No].name].number + market[No].actual_price * num) / (num + storehouse[market[No].name].number);
                    storehouse[market[No].name].buyInPrice = updated_price;
                    storehouse[market[No].name].number += num;
                }
            }else{
                cout << "you don't have enough cash or your storehouse don't have enough space." << endl;
            }

        }else if (decision == '2'){
            map<string, store>::iterator itr = storehouse.begin();
            int i = 1;
            //打印仓库
            for (itr; itr != storehouse.end(); itr++){
                cout << i << ": " << itr->first << " " << (itr->second).number << endl;
                i++;
            }

            //selling
            int No, num;
            cout << "select the good you want to sell: " << endl;
            cin >> No;

            if (No > i || No < 1){
                cout << "invalid input" << endl;
            }

            else{
                itr = storehouse.begin();
                advance(itr, No-1);
                string product = itr->first;

                //检查该物品是否在market中
                bool inMarket = false;
                int temp;

                for (int i = 0; i < 5; i++){
                    if (product == market[i].name){
                        inMarket = true;
                        temp = i;
                        break;
                    }
                }

                if (inMarket){
                    cout << "How many products do you want to sell?" << endl;
                    cin >> num;
                    //1. 没卖完
                    if (num >= 0 && num < storehouse[product].number){
                        int profit;
                        profit = (market[temp].actual_price - storehouse[product].buyInPrice) * num;
                        storehouse[product].number -= num;
                        cash += market[temp].actual_price * num;
                        health -= 1;
                        
                        if (profit >= 0){
                            cout << "you earn " << profit << " dollars in this trade." << endl;
                        }else{
                            cout << "you lost " << (-profit) << " dollars in this trade." << endl;
                        }
                    }
                    //2. 卖完了
                    else if (num == storehouse[product].number){
                        int profit;
                        profit = (market[temp].actual_price - storehouse[product].buyInPrice) * num;
                        storehouse.erase(product);
                        cash += market[temp].actual_price * num;
                        health -= 1;

                        if (profit >= 0){
                            cout << "you earn " << profit << " dollars in this trade." << endl;
                        }else{
                            cout << "you lost " << (-profit) << " dollars in this trade." << endl;
                        }
                    }
                    else{
                        cout << "invalid input" << endl;
                    }
                }else{
                    cout << "No demand for this product now! You can only sell products in market." << endl;
                }
            }
        }else if (decision == 3){
            quit = true;
        }
        else{}

        if (quit){
            break;
        }
    }

}
