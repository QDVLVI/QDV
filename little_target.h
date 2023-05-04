#ifndef LITTLE_TARGET
#define LITTLE_TARGET
#include "structure_define.h"

//在这里declare其他函数

//market
bool check(int cash,int price, int number, int capacity);
bool select_goods(goods* good_list);
void market(int &cash, int &health, int &storehouse_capacity, goods* good_list, map<string, store> &storehouse);

//business
void business(int &cash, bool* isBankrupt, bool* isSetUpCompany, company* company_list, string* company_charlist);

#endif
