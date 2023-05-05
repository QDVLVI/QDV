//business.cpp
#ifndef BUSINESS
#define BUSINESS

#include <iostream>
#include <string>
#include <iomanip>
#include "structure_define.h"
#include "target.h"

using namespace std;

void business(int &cash, int &health, company* company_list){
    char input;
    cout << "welcome to the market" << endl;
    cout << left ;
    cout << "  " << setw(27) <<  "name" << setw(10) << "股价" << setw(10) << "成本" << "持股数" << endl;
    cout << "1 " << setw(27) << setprecision(0) << fixed << company_list[0].name << setw(8) << company_list[0].cost_per_share << " " << setw(7) << company_list[0].average_cost << " " << company_list[0].share_number << endl;
    cout << "2 " << setw(27) << setprecision(0) << fixed << company_list[1].name << setw(8) << company_list[1].cost_per_share << " " << setw(7) << company_list[1].average_cost << " " << company_list[1].share_number << endl;
    cout << "3 " << setw(27) << setprecision(0) << fixed << company_list[2].name << setw(8) << company_list[2].cost_per_share << " " << setw(7) << company_list[2].average_cost << " " << company_list[2].share_number << endl;
    cout << "4 " << setw(27) << setprecision(0) << fixed << company_list[3].name << setw(8) << company_list[2].cost_per_share << " " << setw(7) << company_list[3].average_cost << " " << company_list[3].share_number << endl;
    cout << "5 " << setw(27) << setprecision(0) << fixed << company_list[4].name << setw(8) << company_list[4].cost_per_share << " " << setw(7) << company_list[4].average_cost << " " << company_list[4].share_number << endl;    //游戏界面

    while (true){
    /*
        游戏界面, to be completed
        按q退出“business”界面
        按1-5可以对对应公司进行操作
        若未设立公司：
            对于未成立公司可以选择set up
        若已设立公司
            对于已成立且超过profit_year的公司可以选择买(b)/卖(s)
            对于已成立但未超过profit_year的公司无法操作，无法获得分红
            对于其他未成立公司无法操作
    */

        bool hasSetCompany = false;
        int temp;

        //check if player has set up a company
        for (int i = 0; i < 5; i++){
            if (company_list[i].isSetup){
                hasSetCompany = true;
                temp = i;
                break;
            }
        }

        bool quit = false;
        cin >> input;

        cout << fixed << setprecision(0);

        switch (input){
            case 'q':
                quit = true;
                break;

            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
                if (company_list[input-'1'].isBankrupt == false){
                    //已设立一家公司，且过了profit year，可进行买/卖两种操作
                    if (hasSetCompany && (input -'1') == temp){
                        if (company_list[temp].startProfit())

                            cout << "b-buy\ns-sell\nother-quit" << endl; // 游戏界面

                            cin >> input;
                            
                            //buy
                            if (input == 'b'){
                                int max_share_to_buy;
                                max_share_to_buy = cash / company_list[temp].cost_per_share;

                                cout << temp+1 << "." << company_list[temp].name << ":" << endl;
                                cout << "you could buy at most " << fixed << max_share_to_buy << " shares" << endl;
                                cout << "enter the number of shares you want to buy: " << endl;
                                int num;
                                cin >> num;

                                if (num >= 0 && num <= max_share_to_buy){
                                    cash -= (num * company_list[temp].cost_per_share);
                                    company_list[temp].average_cost = ((company_list[temp].average_cost * company_list[temp].share_number) + company_list[temp].cost_per_share * num) / (company_list[temp].share_number + num);
                                    company_list[temp].share_number += num;   
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
                                
                                cout << "you could sell at most " << fixed << company_list[temp].share_number << endl;
                                cout << "enter the number of shares you want to sell: " << endl;
                                int num;
                                cin >> num;
                                
                                //部分卖出
                                if (num >= 0 && num < company_list[temp].share_number){
                                    int profit, price;
                                    price = num * company_list[temp].cost_per_share;
                                    cash += price;
                                    cout << "you sold these shares for " << fixed << price << " dollar" << endl;

                                    company_list[temp].share_number -= num;

                                    profit = round((company_list[temp].cost_per_share - company_list[temp].average_cost) * num);
                                    
                                    if (profit >= 0){
                                        cout << "you earned " << fixed << profit << endl;
                                    }
                                    else{
                                        cout << "you lost " << fixed << (-profit) << endl; 
                                    }
                                }

                                //全部卖出
                                else if (num == company_list[temp].share_number){
                                    int profit, price;
                                    price = num * company_list[temp].cost_per_share;
                                    cash += price;

                                    company_list[temp].share_number = 0;
                                    company_list[temp].set_up_years = 0;
                                    company_list[temp].isSetup = false;
                                    hasSetCompany = false;

                                    profit = round((company_list[temp].cost_per_share - company_list[temp].average_cost) * num);

                                    if (profit >= 0){
                                        cout << "you earned " << fixed << profit << " dollar " << "in your business" << endl;
                                    }
                                    else{
                                        cout << "you lost " << fixed << (-profit) << " dollar " << "in your business" << endl; 
                                    }
                                }

                                else if (num > company_list[temp].share_number){
                                    cout << "you don't have enough shares" << endl;
                                }

                                else{
                                    cout << "invalid input" << endl;
                                }
                        }
                        else{
                            cout << "your company is still need "<< company_list[temp].profit_year - company_list[temp].set_up_years <<" year for developing, you can not operate on it yet" << endl;
                        }
                    }

                    //已设立一家公司，对另一家公司不能再进行操作                        
                    else if (hasSetCompany && (input - '1') != temp){
                        cout << "you can only set up one company at a time";
                    }

                    //还未设立公司, 可以选择是否设立一家公司
                    else{
                        int temp = input - '1';
                        cout << "Do you want to set up " << company_list[temp].name << endl;
                        cout << "You need to buy 1000 shares of " << company_list[temp].name << " to set up this company" << endl;
                        cout << "which will cost you " << fixed << company_list[temp].cost_per_share * 1000 << " dollar" << endl;
                        if (cash >= 1000*company_list[temp].cost_per_share){
                            cout << "y-yes\nother-no" << endl;
                            cin >> input;
                            if(input == 'y'){
                                //个人变化
                                cash -= 1000 * company_list[temp].cost_per_share;
                                health -= 10;
                                hasSetCompany = true;
                                company_list[temp].isSetup = true;

                                //公司变化
                                company_list[temp].average_cost = company_list[temp].cost_per_share;
                                company_list[temp].share_number = 1000;
                                company_list[temp].set_up_years = 0;   

                                cout << "you have set up " << company_list[temp].name << endl; 
                                cout << "it would spend " << company_list[temp].profit_year << " year for developing" << endl;
                            }
                        }else{
                            cout << "you don't have enough cash to set up" << company_list[temp].name << endl;
                        }
                        
                        // to be complete   

                    }

                }else{
                    cout << "This company has gone bankrupt due to the recession" << endl;
                    cout << "You could not operate on this company" << endl;
                }

                break;

            default:
                break;
        }

        if (quit){
            break;
        }

    //游戏界面
    cout << endl;    
    cout << left;
    cout << "  " << setw(27) <<  "name" << setw(10) << "股价" << setw(10) << "成本" << "持股数" << endl;
    cout << "1 " << setw(27) << company_list[0].name << setw(7) << company_list[0].cost_per_share << " " << setw(7) << company_list[0].average_cost << " " << company_list[0].share_number << endl;
    cout << "2 " << setw(27) << company_list[1].name << setw(7) << company_list[1].cost_per_share << " " << setw(7) << company_list[1].average_cost << " " << company_list[1].share_number << endl;
    cout << "3 " << setw(27) << company_list[2].name << setw(7) << company_list[2].cost_per_share << " " << setw(7) << company_list[2].average_cost << " " << company_list[2].share_number << endl;
    cout << "4 " << setw(27) << company_list[3].name << setw(7) << company_list[2].cost_per_share << " " << setw(7) << company_list[3].average_cost << " " << company_list[3].share_number << endl;
    cout << "5 " << setw(27) << company_list[4].name << setw(7) << company_list[4].cost_per_share << " " << setw(7) << company_list[4].average_cost << " " << company_list[4].share_number << endl;
        
    }
}

#endif
