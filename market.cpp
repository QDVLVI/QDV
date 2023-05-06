#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <algorithm>
#include "target.h"
#include "structure_define.h"
using namespace std;

bool check(int cash, int price, int number, int capacity){
    bool judge=false;
    if (cash <= (price*number)){
        cout << "cash: " << cash << " total cost: " << price * number << endl;
        cout << "you don't have enough cash." << endl;
    }else if (number > capacity){
        cout << "number: " << number << " storehouse capacity: " << capacity << endl;
        cout << "purchased goods exceed your storehouse capacity." << endl; 
    }else{
        judge = true;
    }
    return judge;
}

void market(int &cash, int &health, int &storehouse_capacity, goods* good_list, map<string, store> &storehouse){

        //游戏界面
        cout<<"|"<<setw(15)<<"Goods"<<setw(12)<<"|"<<setw(18)<<"price(dollar)"<<setw(9)<<"|"<<endl;
        cout<<"|"<<"1: "<<left<<setw(23)<<good_list[0].name<<"|"<<"1: "<<left<<setw(23)<<good_list[0].actual_price<<"|"<<endl;
        cout<<"|"<<"2: "<<left<<setw(23)<<good_list[1].name<<"|"<<"2: "<<left<<setw(23)<<good_list[1].actual_price<<"|"<<endl;
        cout<<"|"<<"3: "<<left<<setw(23)<<good_list[2].name<<"|"<<"3: "<<left<<setw(23)<<good_list[2].actual_price<<"|"<<endl;
        cout<<"|"<<"4: "<<left<<setw(23)<<good_list[3].name<<"|"<<"4: "<<left<<setw(23)<<good_list[3].actual_price<<"|"<<endl;
        cout<<"|"<<"5: "<<left<<setw(23)<<good_list[4].name<<"|"<<"5: "<<left<<setw(23)<<good_list[4].actual_price<<"|"<<endl;

    //market loop
    while (true){
        char decision;
        bool quit = false;

        cout<<"1:Purchase"<<endl;
        cout<<"2:Sell"<<endl;
        cout<<"3:Quit"<<endl;
        cout<<"Your decision (1-3): ";

        cin >> decision;
        if (decision == '1'){
            //buying
            int No, num, maxNum;
            cout<<"Which good do you want: (0-quit)" << endl;
            cin >> No;
            if (No==0){
                continue;
            }
            if (No>5){
                cout<<"Invalid input."<<endl;
                continue;
            }
            maxNum = round(cash / good_list[No-1].actual_price );
            if (storehouse_capacity < maxNum){
                maxNum = storehouse_capacity;
            }
            cout<<"How many do you want (you could buy at most " << maxNum <<" ): " << endl;
            cin>>num;

            if (check(cash, good_list[No-1].actual_price, num, storehouse_capacity)){
                //将该物品加入仓库
                storehouse_capacity -= num;
                cash -= num * good_list[No-1].actual_price;
                health -= 1;

                //之前没买过这个物品
                if (storehouse.count(good_list[No-1].name) == 0){
                    store temp = {good_list[No-1].name, good_list[No-1].actual_price, num, good_list[No-1].actual_price};
                    storehouse[good_list[No-1].name] = temp; 
                }
                
                //之前买过这个商品
                else{
                    int updated_price;
                    updated_price = (storehouse[good_list[No-1].name].buyInPrice * storehouse[good_list[No-1].name].number + good_list[No-1].actual_price * num) / (num + storehouse[good_list[No-1].name].number);
                    storehouse[good_list[No-1].name].buyInPrice = updated_price;
                    storehouse[good_list[No-1].name].number += num;
                }
            }else{
                cout << "you don't have enough cash or your storehouse don't have enough space." << endl;
            }

        }else if (decision == '2'){
            map<string, store>::iterator itr = storehouse.begin();

            if (itr == storehouse.end()){
                cout << "you have not buy anything!" << endl;
            }else{
                int i = 1;
                //打印仓库
                for (itr; itr != storehouse.end(); itr++){
                    cout << i << ": " << itr->first << " " << (itr->second).number << endl;
                    i++;
                }

                //selling
                int No, num;
                cout << "select the good you want to sell: (0-quit)" << endl;
                cin >> No;
                if (No==0){
                    continue;
                }
                if (No > i || No < 1){
                    cout << "Invalid input" << endl;
                }

                else{
                    itr = storehouse.begin();
                    advance(itr, No-1);
                    string product = itr->first;

                    //检查该物品是否在market中
                    bool inMarket = false;
                    int temp;

                    for (int i = 0; i < 5; i++){
                        if (product == good_list[i].name){
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
                            profit = (good_list[temp].actual_price - storehouse[product].buyInPrice) * num;
                            storehouse[product].number -= num;
                            cash += good_list[temp].actual_price * num;
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
                            profit = (good_list[temp].actual_price - storehouse[product].buyInPrice) * num;
                            storehouse.erase(product);
                            cash += good_list[temp].actual_price * num;
                            health -= 1;

                            if (profit >= 0){
                                cout << "you earn " << profit << " dollars in this trade." << endl;
                            }else{
                                cout << "you lost " << (-profit) << " dollars in this trade." << endl;
                            }
                        }
                        else{
                            cout << "Invalid input" << endl;
                        }
                    }else{
                        cout << "No demand for this product now! You can only sell products in market." << endl;
                    }
                }
            }
        }else if (decision == '3'){
            quit = true;
        }
        else{}

        if (quit == true){
            break;
        }
        
        //游戏界面
        cout<<"|"<<setw(15)<<"Goods"<<setw(12)<<"|"<<setw(18)<<"price(dollar)"<<setw(9)<<"|"<<endl;
        cout<<"|"<<"1: "<<left<<setw(23)<<good_list[0].name<<"|"<<"1: "<<left<<setw(23)<<good_list[0].actual_price<<"|"<<endl;
        cout<<"|"<<"2: "<<left<<setw(23)<<good_list[1].name<<"|"<<"2: "<<left<<setw(23)<<good_list[1].actual_price<<"|"<<endl;
        cout<<"|"<<"3: "<<left<<setw(23)<<good_list[2].name<<"|"<<"3: "<<left<<setw(23)<<good_list[2].actual_price<<"|"<<endl;
        cout<<"|"<<"4: "<<left<<setw(23)<<good_list[3].name<<"|"<<"4: "<<left<<setw(23)<<good_list[3].actual_price<<"|"<<endl;
        cout<<"|"<<"5: "<<left<<setw(23)<<good_list[4].name<<"|"<<"5: "<<left<<setw(23)<<good_list[4].actual_price<<"|"<<endl;

        

    }

}
