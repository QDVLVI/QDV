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
	ifstream fin ("leaderboard.txt");
	ofstream fout("leaderboard.txt");
	vector<int> record;
	vector<string> list;
	string lines;

    do {
		std::cout << "===========================" << std::endl;
        std::cout << "   100 Million Small Target💰   " << std::endl;
        std::cout << "===========================" << std::endl;
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
				
				record.push_back(result);

				int rank, data;
				string line;
				istringstream line_in(line);

				while (getline(fin,line)){
					line_in >> rank >> data;
					record.push_back(data);
				}

				sort(record.begin(), record.end(), greater<int>());

				vector<int>::iterator itr = record.begin();
				int rank = 1;
				for (itr; itr != record.end(); itr++){
					if (rank > 10){
						break;
					}
					fout << rank << ": " << *itr << endl;
					rank ++;
				}
			}
		}
			
		else if (choice == 2){
			std::cout << "Leaderboard" <<  std::endl;
			std::cout << setw(10) << "rank" << "record" << endl;
			
			while(getline(fin, lines)){
				list.push_back(lines);
			}

			vector<string>::iterator stringItr = list.begin();
			for (stringItr; stringItr != list.end(); stringItr++){
				cout << *stringItr << endl;
			}
			//显示排行榜
		}
		
		else if (choice == 3){
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
		}
			
		else if (choice == 4){
			std::cout << "Goodbye!" << std::endl;
			std::cout <<"Thank you for playing our game and wish you the best of luck in completing every goal in real life as well!😄"<<endl;
			exit(0);
			//结束语待完善
		}
		
		else{
			std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }
    } while (choice != 5);
    return 0;
}
