//business.cpp
#ifndef BUSINESS
#define BUSINESS

#include <iostream>
#include <string>
#include "structure_define.h"
#include "little_target.h"
using namespace std;

void business(int cash, bool isBankrupt[5], bool *isSetUpCompany[5], company *company_list[5], string *company_charlist[5]){
    char input;
    cout << "" << endl;     //游戏界面

    bool hasSetCompany = false;
    int temp;

    for (int i = 0; i < 5; i++){
        if (isSetUpCompany[i]){
            hasSetCompany = true;
            temp = i;
        }
    }

    while (true){
        //游戏界面, to be completed








        bool quit = false;
        cin >> input;

        switch (input){
            case 'q':
                quit = true;
                break;

            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
                if (!isBankrupt[input]){
                    //已设立一家公司，可进行买/卖两种操作
                    if (hasSetCompany && input == temp){

                        cout << "..." << endl; // 游戏界面

                        cin >> input;
                        
                        //buy
                        if (input == 'b'){
                            int max_share_to_buy;
                            max_share_to_buy = cash / (*company_list)[temp].cost_per_share;

                            cout << temp << "." << company_charlist[temp] << ":" << endl;
                            cout << "you could buy at most" << max_share_to_buy << "shares" << endl;
                            cout << "enter the number of shares you want to buy: " << endl;
                            int num;
                            cin >> num;

                            if (num >= 0 && num <= max_share_to_buy){
                                cash -= (num * (*company_list)[temp].cost_per_share);
                                (*company_list)[temp].average_cost = (((*company_list)[temp].average_cost * (*company_list)[temp].share_number) + (*company_list)[temp].cost_per_share * num) / ((*company_list)[temp].share_number + num);
                                (*company_list)[temp].share_number += num;   
                            }

                            else if (num > max_share_to_buy){
                                cout << "you don't have enough cash" << endl;
                            }

                            else{
                                cout << "invalid input" << endl;
                            }
                        }
                        
                        //sell
                        else if (input == 's'){
                            cout << "you could sell at most" << (*company_list)[temp].share_number << endl;
                            cout << "enter the number of shares you want to sell: " << endl;
                            int num;
                            cin >> num;
                            
                            //部分卖出
                            if (num >= 0 && num < (*company_list)[temp].share_number){
                                int profit, price;
                                price = num * (*company_list)[temp].cost_per_share;
                                cash += price;
                                cout << "you sold these shares for " << price << " dollar" << endl;

                                (*company_list)[temp].share_number -= num;

                                profit = round(((*company_list)[temp].cost_per_share - (*company_list)[temp].average_cost) * num);
                                
                                if (profit >= 0){
                                    cout << "you earned " << profit << endl;
                                }
                                else{
                                    cout << "you lost " << (-profit) << endl; 
                                }
                            }

                            //全部卖出
                            else if (num == (*company_list)[temp].share_number){
                                int profit, price;
                                price = num * (*company_list)[temp].cost_per_share;
                                cash += price;

                                (*company_list)[temp].share_number = 0;
                                *isSetUpCompany[temp] = false;
                                hasSetCompany = false;

                                profit = round(((*company_list)[temp].cost_per_share - (*company_list)[temp].average_cost) * num);

                                if (profit >= 0){
                                    cout << "you earned " << profit << " dollar" << endl;
                                }
                                else{
                                    cout << "you lost " << (-profit) << " dollar" << endl; 
                                }
                            }

                            else if (num > (*company_list)[temp].share_number){
                                cout << "you don't have enough shares" << endl;
                            }

                            else{
                                cout << "invalid input" << endl;
                            }
                        }
                    }

                    //已设立一家公司，对另一家公司不能再进行操作                        
                    else if (hasSetCompany && input != temp){
                        cout << "you can only set up one company at a time";
                    }

                    //还未设立公司, 可以选择是否设立一家公司
                    else{
                        cout << "Do you want to set up" << company_charlist[input] << endl;
                        
                        
                        // to be complete   

                    }

                }else{
                    cout << "This company has gone bankrupt due to the recession" << endl;
                    cout << "You could not operate on this company" << endl;
                }
                break;

            default:
                continue;
                break;
        }

        if (quit){
            break;
        }
        
    }
}

#endif
