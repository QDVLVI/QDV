#include <iostream>
#include <fstream>
#include <string>
#include "target.h"

using namespace std;

int main() {
    int choice;
    ifstream file("README.md");
    do {
	std::cout << "===========================" << std::endl;
        std::cout << "   100 Million Small Target   " << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "1. Start Game" <<  std::endl;
        
        std::cout << "2. Talent" <<  std::endl;
        std::cout << "3. List" <<  std::endl;
 	std::cout << "4. Help" <<  std::endl;
 	std::cout << "5. Exit" <<  std::endl;
        std::cout << "Enter your choice (1-5): ";
        cin >> choice;
        switch (choice) {
     		case 1:
                	std::cout << "Start Game" <<  std::endl;
			
			std::cout << "(a) New Game" <<  std::endl;
        		std::cout << "(b) Continue Game" <<  std::endl;
			std::cout << "Enter your choice (a/b): ";
			char gameType;
			cin >> gameType;
  			int result = startGame();//开始游戏
                	break;
            	
            	case 2:
                	std::cout << "Talent" <<  std::endl;
  			talent();//
                	break;
            	case 3:
                	std::cout << "List" <<  std::endl;
			//显示排行榜
                	break;
     		case 4:
  			std::cout << "Help" <<  std::endl;
			//读取readme
  			
  			if (file.is_open()) {
          			string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
          			cout << text << endl;
          			file.close();
      			}
      			else {
          			cout << "Unable to open file." << endl;
      			}
                	break;
     		case 5:
  			std::cout << "Goodbye!" << std::endl;
			//结束语待完善
                	break;
            	default:
                	std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
                	break;
        }
    } while (choice != 5);
    return 0;
}
