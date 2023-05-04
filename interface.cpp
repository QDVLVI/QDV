#include <iostream>
#include <fstream>
#include <string>
#include "startGame.h"

using namespace std;

int main() {
    int choice;
    do {
	std::cout << "===========================" << std::endl;
        std::cout << "   100 Million Small Target   " << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "1. Start Game" <<  std::endl;
        std::cout << "2. Continue Game" <<  std::endl;
        std::cout << "3. Talent" <<  std::endl;
        std::cout << "4. List" <<  std::endl;
 	std::cout << "5. Help" <<  std::endl;
 	std::cout << "6. Exit" <<  std::endl;
        std::cout << "Enter your choice (1-6): ";
        cin >> choice;
        switch (choice) {
     		case 1:
                	std::cout << "Start Game" <<  std::endl;
  			int result = startGame();//开始游戏
                	break;
            	case 2:
                	std::cout << "Continue Game" <<  std::endl;
			//根据之前存档，继续游戏
                	break;
            	case 3:
                	std::cout << "Talent" <<  std::endl;
  			talent();//
                	break;
            	case 4:
                	std::cout << "List" <<  std::endl;
			//显示排行榜
                	break;
     		case 5:
  			std::cout << "Help" <<  std::endl;
			//读取readme
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
  			std::cout << "Goodbye!" << std::endl;
			//结束语待完善
                	break;
            	default:
                	std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
                	break;
        }
    } while (choice != 6);
    return 0;
}
