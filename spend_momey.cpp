#include <iostream>
#include <string>

using namespace std;

int spend_money(int &lottery_num){

    cout << "..." << endl; //游戏界面，写spend money的来设计界面
    cout << "1--lotteries" << endl;
    cout << "2--houses" << endl;
    cout << "3--cars" << endl;
    cout << "4--medical treatment" << endl;
    cout << "5--back" << endl;
    int option;
    cin >> option;
    while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5) {
        cout << "Option does not exist. Please enter again.";
        cout << "1--lotteries" << endl;
        cout << "2--houses" << endl;
        cout << "3--cars" << endl;
        cout << "4--medical treatment" << endl;
        cout << "5--back" << endl;
        cin >> option;
    }
    while (option != 5) {




        if (option == 1) {
            cout << "Buying lotteries " << endl;
            cout << "Lottery costs " << (5 + lottery_num) * (3 * lottery_num) * 4500;
            cout << "The prize is " << (5+lottery_num)*(2+lottery_num)*9000 << ". Enter Y to confirm, enter N to go back.";
            string   lottery_confirm;
            cin >> lottery_confirm;
            while (lottery_confirm != "Y" && lottery_confirm != "N") {
                cout << "Option does not exist. Please enter again.";
                cout << "Enter Y to confirm, enter N to go back.";
                cin >> lottery_confirm;
            }
            if (player.cash < (5 + lottery_num) * (3 * lottery_num) * 4500) {
                cout << "Your cash is not enough.";
                break;
            }
            else {
                if (lottery_confirm == "N") {//exit lottery
                    break;
                }
                if (lottery_confirm == "Y") {
                    player.cash -= (5 + lottery_num) * (3 * lottery_num) * 4500;
                    if (rand() % 2 == 1) {//win
                        player.cash += (5 + lottery_num) * (2 + lottery_num) * 9000
                        cout << "you won! The prize is " << (5 + lottery_num) * (2 + lottery_num) * 9000 << endl;

                    }
                    else {
                        cout << "you did not win.";
                    }
                }
            }
        }



        if (option == 2){
            cout << "Buying house" << endl;
            cout << "Price of house: 1,000,000" << endl;
            cout << "Enter Y to confirm, enter N to go back." << endl;
            string house_confirm;
            cin >> house_confirm;
            while (house_confirm != "Y" && house_confirm != "N") {
                cout << "Option does not exist. Please enter again.";
                cout << "Enter Y to confirm, enter N to go back.";
                cin >> house_confirm;
            }
            if (house_confirm == "Y") {
                if (player.house == true) {
                    cout << "You have already bought a house." << endl;
                }
                else if (player.cash < 1000000) {
                    cout << "Your cash is not enough."
                }
                else {
                    player.cash -= 1000000;
                    player.house = true;
                    //买房的其他加成
                    cout << "You have bought the house successfully."
                }

            }
        }


        if (option == 3) {
            cout << "Buying car" << endl;
            cout << "Price of car: 200,000" << endl;
            cout << "Enter Y to confirm, enter N to go back." << endl;
            string car_confirm;
            cin >> car_confirm;
            while (car_confirm != "Y" && car_confirm != "N") {
                cout << "Option does not exist. Please enter again.";
                cout << "Enter Y to confirm, enter N to go back.";
                cin >> car_confirm;
            }
            if (car_confirm == "Y") {
                if (player.house == true) {
                    cout << "You have already bought a car." << endl;
                }
                else if (player.cash < 200000) {
                    cout << "Your cash is not enough."
                }
                else {
                    player.cash -= 200000;
                    player.car = true;
                    //买车的其他加成
                    cout << "You have bought the car successfully."
                }

            }

        }


        if (option == 4) {
            cout << "Your current health is " << player.health << endl;
            cout << "Cost of healing is " << 50 * (100 - player.health) * (100 - player.health) << endl;
            cout << "Enter Y to confirm, enter N to go back";
            string healing_confirm;
            cin >> healing_confirm;
            while (healing_confirm != "Y" && healing_confirm != "N") {
                cout << "Option does not exist. Please enter again.";
                cout << "Enter Y to confirm, enter N to go back.";
                cin >> healing_confirm;
            }
            if (healing_confirm == "Y") {
                player.cash -= 50 * (100 - player.health) * (100 - player.health);
                player.health = 100
            }
        }





    }



}
