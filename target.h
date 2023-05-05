//little_target.h
#ifndef LITTLE_TARGET
#define LITTLE_TARGET
#include "structure_define.h"
#include <map>
//在这里declare其他函数
bool check(int cash,int price, int number, int capacity);
bool select_goods(goods* good_list);
void market(int &cash, int &health, int &storehouse_capacity, goods* good_list, map<string, store> &storehouse);

void business(int &cash, int &health, company* company_list);

void readPlayerData(role player);
void readCompanyData(company* company_list);
void readStorehouseData(map<string, store> storehouse);

#endif
