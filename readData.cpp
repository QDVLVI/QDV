#include <fstream>
#include <map>
#include <sstream>
#include "structure_define.h"
#include "target.h"


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
        fout << player.hasHouse << endl;
        fout << player.hasCar << endl;
        fout << player.lottery_num << endl;
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

void readStorehouseData(map<string, store> storehouse){
    ofstream fout;
    map<string, store>::iterator itr = storehouse.begin();
    fout.open("storehouse.txt", ios::out);
    for (itr; itr != storehouse.end(); itr++){
        fout << itr->first << " " ;
        fout << (itr->second).buyInPrice << " " << (itr->second).number <<  (*itr->second).actual_price << endl;
    }
}
