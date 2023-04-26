#ifndef NEW_STRUCT
#define NEW_STRUCT

//define your struct here

//商品属性
struct goods{
        int high_price;
        int normal_price;
        int low_price;
        double high_price_possiblity;
        double normal_price_possibility;
        double low_price_possibility;
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

//公司属性
class company{
        double ups_possibility;     //上浮概率 (x%)
        double amplitude;           //最高上浮/下跌幅度 (y%)
        double dividend_rate;       //分红比例 (z%)
        int profit_year;            //建立后多少年开始盈利
        double bankrupt_threshold;  //破产阈值

        public:
            double cost_per_share;      //每股价格
            double average_cost;        //平均成本价
            int share_number;           //持股数

            company(double a, double b, double c, double d, double e, int f, int g, double h){
                cost_per_share = a;       
                average_cost = b;             
                ups_possibility = c;        
                amplitude = d;              
                dividend_rate = e;          
                profit_year = f;            
                share_number = g;           
                bankrupt_threshold = h;     
            }

            company(){

            }
        

            int dividend(){
                int money;
                money = round(cost_per_share * (share_number * dividend_rate));
                return money;
            }

            void floating(){
                //to determine whether increase or decrease
                bool *increase = new bool[100];
                for (int i = 0; i < 100; i++){
                    if (i < ups_possibility*100){
                        increase[i] = true;
                    }else{
                        increase[i] = false;
                    }
                }

                srand(time(nullptr));

                int random_number1 = rand() % 100;

                bool isIncrease = false;
                if (increase[random_number1]){
                    isIncrease = true;
                }

                delete[] increase;

                //to determine the rate of increase or decrease
                int temp = amplitude * 100;
                int random_number2;
                random_number2 = rand() % temp;

                //update cost_per_share
                if (isIncrease){
                    cost_per_share = cost_per_share * (1+(random_number2/100));
                }else{
                    cost_per_share = cost_per_share * (1-(random_number2/100));
                }

            }

            bool bankrupt(){
                if (cost_per_share < bankrupt_threshold){
                    cost_per_share = 0;
                    return true;
                }else{
                    return false;
                }
            }

            int market_value(){
                int temp;
                temp = round(cost_per_share * share_number);
                return temp; 
            }
};


#endif
