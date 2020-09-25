#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

vector<int> generateLotteryWheel(int& wheel_size){

    vector<int> wheel;

    for(int i = 1; i < wheel_size+1; i++){
        wheel.push_back(i);
    }

    return wheel;
}

int main(){

    int random_keno;
    int lucky_number;

    srand (time(NULL));

    int random_numbers = 20;
    int wheel_size = 80;

    vector<int> lottery_wheel = generateLotteryWheel(wheel_size);

    vector<int> winning_numbers;

    ofstream winning_numbers_txt;

    for (int i = 1; i < random_numbers+1; ++i){
        random_keno = rand() % lottery_wheel.size() + 1;

        lucky_number = lottery_wheel.at(random_keno - 1);
        lottery_wheel.erase(lottery_wheel.begin() + (random_keno - 1)); // removes number to avoid repetition

        cout << "Võidunumber " << i << ": " << lucky_number << endl;

        winning_numbers.push_back(lucky_number);

    }

    winning_numbers_txt.open("WinningNumbers.txt");
    sort(winning_numbers.begin(), winning_numbers.end());

    for (int i : winning_numbers){
        winning_numbers_txt << i << endl;
    }

    winning_numbers_txt.close();

}