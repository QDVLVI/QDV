#include <iostream>
#include <string>
#include <cmath>
#include "target.h"

using namespace std;

void spend_money(int &lottery_num, int &cash, bool &hasHouse, bool &hasCar, int &health, int &retire_age){

    cout << "1--lotteries" << endl;
    cout << "2--houses(extend your life)" << endl;
    cout << "3--cars(extend your life)" << endl;
    cout << "4--medical treatment" << endl;
    cout << "5--back" << endl;
    int option;
    cin >> option;
    while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5) {
        cout << "Option does not exist. Please enter again."<<endl;
        cout << "1--lotteries" << endl;
        cout << "2--houses(extend your life)" << endl;
        cout << "3--cars(extend your life)" << endl;
        cout << "4--medical treatment" << endl;
        cout << "5--back" << endl;
        cin >> option;
    }
    while (option != 5) {

        if (option == 1) {
            int lottery_cost = pow(3,lottery_num) * 1500;
            int prize = 5 * lottery_cost;

            cout << "Buying lotteries " << endl;
            cout << "Lottery costs " << lottery_cost << endl;
            cout << "The prize is " << prize << ". Enter Y to confirm, enter N to go back."<<endl;
            string lottery_confirm;
            cin >> lottery_confirm;
            while (lottery_confirm != "Y" && lottery_confirm != "N") {
                cout << "Option does not exist. Please enter again." << endl;
                cout << "Enter Y to confirm, enter N to go back."<<endl;
                cin >> lottery_confirm;
            }
            if (cash < pow(3, lottery_num) * 1500) {
                cout << "cash: " << cash << " cost: " << lottery_cost << endl;
                cout << "You don't have enough cash." << endl;
            }
            else {
                if (lottery_confirm == "N") {//exit lottery
                }
                if (lottery_confirm == "Y") {
                    cash -= lottery_cost;
                    lottery_num ++;
                    //win
                    if (rand() % 5 == 1) {
                        cash += prize;
                        cout << "You win! The prize is " << prize << endl;

                    }
                    else {
                        cout << "Bad luck!" << endl;
                    }
                }
            }
        }



        else if (option == 2){
            cout << "Buying house" << endl;
            cout << "Price of house: 1,000,000" << endl;
            cout << "Enter Y to confirm, enter N to go back." << endl;
            string house_confirm;
            cin >> house_confirm;
            while (house_confirm != "Y" && house_confirm != "N") {
                cout << "Option does not exist. Please enter again." << endl;
                cout << "Enter Y to confirm, enter N to go back."<<endl;
                cin >> house_confirm;
            }
            if (house_confirm == "Y") {
                if (hasHouse == true) {
                    cout << "You have already bought a house." << endl;
                }
                else if (cash < 1000000) {
                    cout << "Your cash is not enough." << endl;
                }
                else {
                    cash -= 1000000;
                    hasHouse = true;
                    retire_age += 5;
                    cout << "You have bought the house successfully." << endl;
                    cout << "your retirement has been extended." << endl;
                }
            }
            else if (house_confirm == "N"){//exit house
            }            
        }


        else if (option == 3) {
            cout << "Buying car" << endl;
            cout << "Price of car: 200,000" << endl;
            cout << "Enter Y to confirm, enter N to go back." << endl;
            string car_confirm;
            cin >> car_confirm;
            while (car_confirm != "Y" && car_confirm != "N") {
                cout << "Option does not exist. Please enter again." << endl;
                cout << "Enter Y to confirm, enter N to go back." << endl;
                cin >> car_confirm;
            }
            if (car_confirm == "Y") {
                if (hasHouse == true) {
                    cout << "You have already bought a car." << endl;
                }
                else if (cash < 200000) {
                    cout << "Your cash is not enough." << endl;
                }
                else {
                    cash -= 200000;
                    hasCar = true;
                    retire_age +=2;
                    cout << "You have bought the car successfully." << endl;
                    cout << "your retirement has been extended." << endl;
                }
            }
            else {
                if (car_confirm == "N"){//exit car
                }
            }
        }

        else if (option == 4) {
            cout << "Your current health is " << health << endl;
            cout << "Cost of healing is " << 50 * (100 - health) * (100 - health) << endl;
            cout << "Enter Y to confirm, enter N to go back" << endl;
            string healing_confirm;
            cin >> healing_confirm;
            while (healing_confirm != "Y" || healing_confirm != "N") {
                cout << "Option does not exist. Please enter again." << endl;
                cout << "Enter Y to confirm, enter N to go back." << endl;
                cin >> healing_confirm;
            }
            if (healing_confirm == "Y") {
                cash -= 50 * (100 - health) * (100 - health);
                health = 100;
            }
            else {
                if (healing_confirm == "N"){//exit treatment
                }
            }
        }
    }
}

