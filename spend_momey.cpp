int spend_money(){

    cout << "..." << endl; //游戏界面，写spend money的来设计界面
    cout << "1--lotteries" << endl;
    cout << "2--houses" << endl;
    cout << "3--cars" << endl;
    cout << "4--medical treatment" << endl;
    cout << "5--back" << endl;
    int option;
    cin >> option;
    while (option != 5) {
        if (option == 1) {
            cout << "Buying lotteries\nPlease enter the amount: " << endl;
            int lottery_amount;
            cin >> lottery_amount;
            cout << "The prize is " << lottery_amount * 5 << ". Enter Y to confirm, Enter N to go back.";
            string   lottery_confirm;
            cin >> lottery_confirm;
            if (player.cash < lottery_amount) {
                cout << "Your cash is not enough.";
                break;
            }
            else {
                if (lottery_confirm == "N") {//exit lottery
                    break;
                }
                if (lottery_confirm == "Y") {
                    player.cash -= lottery_amount;
                    if (rand() % 6 == 1) {//win
                        //money +lottery_amount*5
                        cout << "you win! the prize is" << lottery_amount * 5 << endl;
                    }
                    else {
                        cout << "you did not win.";
                    }
                }
            }
        }
        if (option == 2) {
            cout << "Purchasing houses\n1--island\n2--school district house\n3--sea view villa\n4--holiday resort\n5--apartment\n6--hut";
            int house_option;
            cin >> house_option;
            //cout information;

            if (house_option == 1) {

            }
            if (house_option == 2) {

            }
            if (house_option == 3) {

            }
            if (house_option == 4) {

            }
            if (house_option == 5) {

            }
        }

        
    }



}
