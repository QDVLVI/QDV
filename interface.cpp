#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "target.h"

using namespace std;

int main() {
    int choice;
    ifstream file("README.md");
	ifstream fin ;
	ofstream fout;
	string lines;

    do {
		std::cout << "===============================" << std::endl;
        std::cout << "   100 Million Small Target💰   " << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << "1. Start Game" <<  std::endl;
        std::cout << "2. Leaderboard" <<  std::endl;
 		std::cout << "3. Help" <<  std::endl;
 		std::cout << "4. Exit" <<  std::endl;
        std::cout << "Enter your choice (1-4): ";

        cin >> choice;
		int result;

		if (choice == 1){
			std::cout << "Start Game" <<  std::endl;
			result = startGame();//开始游戏
			if (result != -1){
				//加入排行榜
				vector<int> record;
				
				record.push_back(result);

				int data;
				string code;
				string line;
				istringstream line_in(line);
				fin.open("leaderboard.txt");

				while (getline(fin,line)){
					line_in >> code >> data;
					record.push_back(data);
				}
				fin.close();

				sort(record.begin(), record.end(), greater<int>());

				vector<int>::iterator itr = record.begin();
				int rank = 1;
				fout.open("leaderboard.txt");
				for (itr; itr != record.end(); itr++){
					if (rank > 10){
						break;
					}
					fout << rank << ": " << *itr << endl;
					rank ++;
				}
				fout.close();
			}
		}
			
		else if (choice == 2){
			vector<string> list;
			std::cout << "Leaderboard" <<  std::endl;
			std::cout << setw(10) << "rank" << "record" << endl;
			
			fin.open("leaderboard.txt");
			while(getline(fin, lines)){
				list.push_back(lines);
			}

			vector<string>::iterator stringItr = list.begin();
			for (stringItr; stringItr != list.end(); stringItr++){
				cout << *stringItr << endl;
			}
			
			//显示排行榜
			fin.close();
		}
		
		else if (choice == 3){
			std::cout << "Help" <<  std::endl; 
			std::cout <<"100 Million Small Target is a business and life simulation game. Starting from the age of 20, all choices are up to you, whether to become rich or poor.

\nAuthor Information: Guan Haoning -- GuanHaoNing Huang Zixuan -- HHuangZZixuan Qiao Lechong -- QDVLVI Ding Jiayi -- daisyyding Zhu Jiaying -- jytiff

\nDescription: At the age of 20, you enter society and try to achieve the small target of earning one billion before retirement. Buy and sell bitcoins, domain names, liquor, counterfeit mobile phones... Found a gaming company, a real estate company, an electrical manufacturing factory... Spend money on luxury homes, cars... This is a lifetime of ups and downs in the business world, and also a reflection of the times. When each wave of wealth comes, some people soar to great heights, some people work hard, and some people lose everything. Randomly born, but equal opportunities. The choice is in your own hands.

\nRules Game objective: Get rich before retirement, for example, earn one billion first. \nMarket: Choose items to buy/sell, buy low and sell high, expand warehouse, and accumulate capital. \nEntrepreneurship: Found a company, enjoy the appreciation of assets, and receive dividend income. A large investment is required to start a business, which can be increased or decreased later. Spend money: Buy cars and houses, consume in different places, change attributes.

\nFeatures I. FIVE requirements: (1) Generation of random game sets or events: - Randomly generate prices for buying/selling items. - Randomly generated 5 items appearing each year. \n(2) Data structures for storing game status: - Linked lists are used to store elements that are dynamically added or removed from our game status. For example, the goods inforation in storehouse.cpp. - An array is also a simple data structure that are used to store our game status. \n(3) Dynamic memory management: - Goods and company information stored in linked list( pointers & dynamic variable allocation:new,delete) - Map(container) used in market.cpp \n(4) File input/output (e.g., for loading/saving game status): - ifstream used for getting information of player,company,storehouse - information of playere,company,storehouse is saved in separate files using ofstream defined in function. \n(5) Program codes in multiple files: - Different functions are in multiple files, i.e. business,market,spend_money. - Structs and classes are declared and stored in separate files.

\nII. Functionality and special features: Players can not only earn money, but also set up companies and spend money, for example, to buy a house, a car or a lottery ticket. At the same time, it is possible to extend the retirement age when making consumption.

\nIII. Coding style: - Define each part in different functions to make it easier to apply and read. - Name functions and variables according to the parts they are associated with to optimize readibility.

Compilation and execution instructions Run make target to compile the game. Do ./target to start the game. Run make clean to clean all the generated filles."
		}
			
		else if (choice == 4){
			std::cout << "Goodbye!" << std::endl;
			std::cout <<"Thank you for playing our game and wish you the best of luck in completing every goal in real life as well!😄"<<endl;
			exit(0);
			//结束语待完善
		}
		
		else{
			std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }cin >> choice;
    } while (choice != 5);
    return 0;
}

