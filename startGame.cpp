
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include "target.h"
#include "structure_define.h"

using namespace std;

void readPlayerData(role player){
    ofstream fout;
    fout.open("player.txt", ios::out);
    if (fout.fail()){
        cout << "fail to player data" << endl;
    }else{
        fout << player.cash << endl;
        fout << player.total_assets << endl;
        fout << player.health << endl;
        fout << player.fame << endl;
        fout << player.age << endl;
        fout << player.retire_age << endl;
        fout << player.storehouse_capacity << endl;
        fout << player.isSick << endl;
        fout.close();
    }
}

void readCompanyData(company *company_list){
    ofstream fout;
    fout.open("company.txt", ios::out);
    if (fout.fail()){
        cout << "fail to save company data" << endl;
    }else{
        for (int i = 0; i < 5; i++){
            fout << company_list[i].name << " ";
            fout << company_list[i].cost_per_share << " ";
            fout << company_list[i].average_cost << " ";
            fout << company_list[i].ups_possibility << " ";
            fout << company_list[i].amplitude << " ";
            fout << company_list[i].dividend_rate << " ";
            fout << company_list[i].profit_year << " ";
            fout << company_list[i].share_number << " ";
            fout << company_list[i].bankrupt_threshold << " ";
            fout << company_list[i].set_up_years << " ";
            fout << company_list[i].isSetup << " ";
            fout << company_list[i].isBankrupt << endl;
        }
        fout.close();
    }
}

void readStorehouseData(){
    
}

int startGame(){
    //角色
    role player{100000, 100000, 100, 0, 20, 70, 100, false};

    //公司
    company *company_list = new company[5];
    company_list[0].name = "gaming_industry";
    company_list[1].name = "real_estate_company";
    company_list[2].name = "electric_manufacture";
    company_list[3].name = "energy_drink_factory";
    company_list[4].name = "internet_celebrity_anchor";

    //仓库
    map<string, store> storehouse;
    

    //选择读取存档（Load game) 或开始新游戏 (New game)

    cout << "1-start a new game\n2-continue" << endl; //游戏界面，选择存档或新游戏, to be completed
    int temp;
    cin >> temp;

    if (temp == 2){
        ifstream finPlayer, finCompany;
        finPlayer.open("player.txt");
        finCompany.open("company.txt");
        if (finPlayer.peek() == ifstream::traits_type::eof() || finCompany.peek() == ifstream::traits_type::eof()){
            cout << "no record found" << endl;
            return 0;
        }

    //读取存档，从file中获取角色信息
    finPlayer >> player.cash;
    finPlayer >> player.total_assets;
    finPlayer >> player.health;
    finPlayer >> player.fame;
    finPlayer >> player.age;
    finPlayer >> player.retire_age;
    finPlayer >> player.storehouse_capacity;
    finPlayer >> player.isSick;

    //从file中获取公司信息
    string line;
    int i = 0;
    
    while (getline(finCompany, line)){
        istringstream line_in(line);
        line_in >> company_list[i].name;
        line_in >> company_list[i].cost_per_share;
        line_in >> company_list[i].average_cost;
        line_in >> company_list[i].ups_possibility;
        line_in >> company_list[i].amplitude;
        line_in >> company_list[i].dividend_rate;
        line_in >> company_list[i].profit_year;
        line_in >> company_list[i].share_number;
        line_in >> company_list[i].bankrupt_threshold;
        line_in >> company_list[i].set_up_years;
        line_in >> company_list[i].isSetup;
        line_in >> company_list[i].isBankrupt;
        i++;
    }
        
        //to be completed
    }

    if (temp == 1){
        //初始化角色
        //建立一个文档储存数据,to be completed
        readPlayerData(player);

        company_list[0].initCompany(700,  0, 0.6, 0.1,  0.02, 2, 0, 1);                //氪金游戏公司
        company_list[1].initCompany(4000, 0, 0.8, 0.2,  0.01, 5, 0, 10);               //房地产公司
        company_list[2].initCompany(500,  0, 0.6, 0.1,  0.02, 3, 0, 1);                //电器制造厂
        company_list[3].initCompany(1000, 0, 0.6, 0.05, 0.03, 2, 0, 1);                //运动饮料厂
        company_list[4].initCompany(50,   0, 0.5, 0.1,  0.01, 1, 0, 0.1);              //网红主播
    }

    //仓库 (使用linked list)
    map<string, store> storehouse;

    //商品，to be completed
    goods *good_list = new goods[8];
    good_list[0].name = "liquor";        //白酒
    good_list[0].normal_price_possibility = 0.5;
    good_list[0].high_price_possiblity = 0.2;
    good_list[0].low_price_possibility = 0.3;
    
    good_list[1].name = "imported_car";  //进口汽车
    good_list[1].normal_price_possibility = 0.7;
    good_list[1].high_price_possiblity = 0.1;
    good_list[1].low_price_possibility = 0.2;
    
    good_list[2].name = "jade";          //玉石
    good_list[2].normal_price_possibility = 0.5;
    good_list[2].high_price_possiblity = 0.2;
    good_list[2].low_price_possibility = 0.3;
    
    good_list[3].name = "melon_seed";    //瓜子
    good_list[3].normal_price_possibility = 0.4;
    good_list[3].high_price_possiblity = 0.3;
    good_list[3].low_price_possibility = 0.3;
    
    good_list[4].name = "domain_name";   //域名
    good_list[4].normal_price_possibility = 0.5;
    good_list[4].high_price_possiblity = 0.15;
    good_list[4].low_price_possibility = 0.35;
    
    good_list[5].name = "gold";          //黄金
    good_list[5].normal_price_possibility = 0.6;
    good_list[5].high_price_possiblity = 0.2;
    good_list[5].low_price_possibility = 0.2;
    
    good_list[6].name = "copycat_phone"; //山寨手机
    good_list[6].normal_price_possibility = 0.4;
    good_list[6].high_price_possiblity = 0.3;
    good_list[6].low_price_possibility = 0.3;
    
    good_list[7].name = "bit_coin";      //比特币
    good_list[7].normal_price_possibility = 0.5;
    good_list[7].high_price_possiblity = 0.15;
    good_list[7].low_price_possibility = 0.35;

    int market_value = 0;
    
    //游戏主循环
    while (player.age <= player.retire_age){
        player.age += 1;

        //商品价格
        //initialize price
        srand(time(nullptr));
        //liquor price
        good_list[0].normal_price = rand()%1001+500;
        good_list[0].high_price = round(good_list[0].normal_price*((rand()%434)/100.0+5.67));
        good_list[0].low_price = round(good_list[0].normal_price*((rand()%41+40)/100));

        //imported_car price
        good_list[1].normal_price = rand()%25000+35000;
        good_list[1].high_price = round(good_list[1].normal_price*((rand()%1227)/1000+1.357));
        good_list[1].low_price = round(good_list[1].normal_price*((rand()%3977)/10000+0.2857));

        //jade price
        good_list[2].normal_price = rand()%2001+2000;
        good_list[2].high_price = round(good_list[2].normal_price*((rand()%5501)/1000+2.5));
        good_list[2].low_price = round(good_list[2].normal_price*((rand()%101)/1000+0.4));

        //melon_seed price
        good_list[3].normal_price = rand()%171+80;
        good_list[3].high_price = round(good_list[3].normal_price*((rand()%12501)/2500+3.6));
        good_list[3].low_price = round(good_list[3].normal_price*((rand()%158+21)/1000+0.22));
        
        //domain_name price
        good_list[4].normal_price = rand()%13001+19000;
        good_list[4].high_price = round(good_list[4].normal_price*((rand()%51)/100+2));
        good_list[4].low_price = round(good_list[4].normal_price*((rand()%501)/10000+0.45));

        //gold price
        good_list[5].normal_price = rand()%2001+4000;
        good_list[5].high_price = round(good_list[5].normal_price*((rand()%251)/1000+3));
        good_list[5].low_price = round(good_list[5].normal_price*((rand()%501)/10000+0.45));

        //copycat_phone price
        good_list[6].normal_price = rand()%351+450;
        good_list[6].high_price = round(good_list[6].normal_price*((rand()%751)/1000+5.5));
        good_list[6].low_price = round(good_list[6].normal_price*((rand()%51)/1000+0.45));
       
        //bitcoin price
        good_list[7].normal_price = rand()%4101+3900;
        good_list[7].high_price = round(good_list[7].normal_price*((rand()%1501)/1000+5.5));
        good_list[7].low_price = round(good_list[7].normal_price*((rand()%71)/1000+0.43));
        good_list[7].normal_price_possibility = 5.0;
        good_list[7].high_price_possiblity = 1.5;
        good_list[7].low_price_possiblity = 3.5;
        //公司投资
        for(int i = 0; i < 5; i++){
            //是否破产
            if (company_list[i].bankrupt()){
                company_list[i].isBankrupt = true;
                if (company_list[i].isSetup = true){
                    company_list[i].isSetup = false;
                    cout << "your company" << company_list[i].name << "has bankrupt due to the recession" << endl;
                }
                continue;
            }

            //股价浮动
            company_list[i].floating();

            //分红
            if (company_list[i].isSetup == true){
                if (company_list[i].startProfit()){
                    player.cash += company_list[i].dividend();
                    player.total_assets += company_list[i].market_value();
                    cout << company_list[i].name << " pays dividends of " << company_list[i].dividend() << " dollar" << endl;
                }
                company_list[i].set_up_years++;
            }
        }

        for (int i = 0; i < 5; i++){
            if (company_list[i].isSetup){
                market_value = round(company_list[i].cost_per_share * company_list[i].share_number);
            }
        }
           
        player.total_assets = player.cash + market_value;  //还要再加车的价值和房的价值
        cout << "player's total assets: " << player.total_assets << endl;

        readCompanyData(company_list);
        readPlayerData(player);

        cout << "..." << endl; // 游戏界面,从8个商品选5个出来展示，可以用file或直接cout,to be completed



        //买卖（market），创业（business）会损失健康值，
        if (player.health <= 50){
            //有几率住院
            srand(time(nullptr));
            int a = rand() % 4; //25%
            if (a != 1){
                player.isSick = true;
            }

        }
        
        //手动操作
        char input;
        bool GoToNextYear = false;

        if (!player.isSick){
            cout << "m-market\nb-business\ns-spend money\nn-go to next year" << endl;
            while (cin >> input){
                
                
                //market, 市场
                if (input == 'm'){
                    cout << "..." << endl; //游戏界面，写market的来设计一下按键
                    market(player.cash, player.health, player.storehouse_capacity, good_list, storehouse);




                }
                
                //business, 创业
                else if (input == 'b'){
                    cout << "..." << endl; //游戏界面，写business的来设计按键
                    int cash = player.cash;
                    int health = player.health;
                    business(cash, health, company_list);
                    player.cash = cash;
                    player.health = health;
                    readCompanyData(company_list);

                }

                //spend money，花钱
                else if (input == 's'){
                    cout << "..." << endl; //游戏界面，写spend money的来设计界面
                    //function, to be completed




                }

                //next year
                else if (input == 'n'){
                    GoToNextYear = true;
                }

                else if (input == 'q'){
                    readPlayerData(player);
                    return 0;
                }

                for (int i = 0; i < 5; i++){
                    if (company_list[i].isSetup){
                        market_value = company_list[i].market_value();
                    }
                }
                        
                player.total_assets = player.cash + market_value;  //还要再加车的价值和房的价值
                //将更新后的数据储存到文档，to be completed

                if (GoToNextYear){
                    readPlayerData(player);
                    break;
                }
                cout << "m-market\nb-business\ns-spend money\nn-go to next year" << endl;
            }
        }
        else{
            player.isSick = false;
            player.health = 100;
            cout << "you are sick this year and could not do anything this year" << endl;
            cout << "n-next year" << endl;     //游戏界面，按n进入下一年，按q提前退休




            string input;
            while(true){
                cin >> input;
                if (input == "n"){
                    readPlayerData(player);
                    break;
                }else{
                    cout << "you are sick this year and could not do anything this year" << endl;
                    continue;
                }
                
            }
        }
    }
        
    
    //游戏结束，结算界面（x岁资产超百万，y岁资产超千万，z岁资产过亿，a岁资产最多为m，退休时资产为n，etc.）
    cout << "..." << endl;
    delete[] company_list;
    delete[] good_list;

    //清空存档中的内容
    ofstream foutPlayer, foutCompany, foutStorehouse;
    foutPlayer.open("player.txt", ios::trunc);
    foutCompany.open("company.txt", ios::trunc);
    foutStorehouse.open("storehouse.txt", ios::trunc);
    foutPlayer.close();
    foutCompany.close();
    foutStorehouse.close();

    return 0;
}
