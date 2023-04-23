#ifndef NEW_STRUCT
#define NEW_STRUCT

//商品属性
struct goods{
        char name;
        int high_price;
        int normal_price;
        int low_price;
        int high_price_possiblity;
        int normal_price_possibility;
        int low_price_possibility;
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
};

//仓库物品
struct product{
    goods name;
    int number;
    product *next;
};

#endif
