#include <iostream>
#include <fstream>
#include <string>
#include "startGame.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "100 Million Small Target" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Continue Game" << endl;
        cout << "3. Talent" << endl;
        cout << "4. List" << endl;
	cout << "5. Help" << endl;
	cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        switch (choice) {
	    case 1:
                cout << "You chose option 1." << endl;//
		int result = startGame();
                break;
            case 2:
                cout << "You chose option 2." << endl;
		//待完善
                break;
            case 3:
                cout << "You chose option 3." << endl;
		talent();//这里role,player待完善
                break;
            case 4:
                cout << "You chose option 4." << endl;
		//
                break;
	    case 5:
		cout << "You chose option 5." << endl;
		ifstream file("README.md");
		if (file.is_open()) {
        		string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        		cout << text << endl;
        		file.close();
    		}
    		else {
       			cout << "Unable to open file." << endl;
    		}
                break;
	    case 6:
		cout << "Goodbye!" << endl;
		//详细文字信息，待完善
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
        }
    } while (choice != 6);
    return 0;
}