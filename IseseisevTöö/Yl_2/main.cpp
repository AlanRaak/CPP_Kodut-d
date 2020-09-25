#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void compare(float& last_throw, float& current_throw){
    float difference = last_throw - current_throw;

    if (difference < 0){
        cout << "See tulemus on eelmisest parem " << -difference << " meetrit" << endl;
    }else
    {
        cout << "See tulemus on eelmisest halvem " << difference << " meetrit" << endl;
    }
    
}

int main(){

    string name;
    float throw_distance;
    vector<float> attempts;

    float longest_throw;
    float second_longest_throw;

    cout << "Sisesta sportlase nimi: " << endl;
    cin >> name;

    name += ".txt";
    ofstream result_file;
    result_file.open(name);

    cout << "Sisesta 1. katse tulemus: " << endl;
    cin >> throw_distance;
    attempts.push_back(throw_distance);
    result_file << "1: " << throw_distance << endl;

    longest_throw = throw_distance;
    second_longest_throw = throw_distance;

    for(int i = 2; i < 7; i++){
        cout << "Sisesta " << i << ". katse tulemus: " << endl;
        cin >> throw_distance;
        result_file << i << ": " << throw_distance << endl;

        compare(attempts.back(), throw_distance);

        attempts.push_back(throw_distance);

        if (throw_distance > longest_throw){
            second_longest_throw = longest_throw;
            longest_throw = throw_distance;
        }
    }

    result_file << endl << "Best throw: " << longest_throw << endl << "Second best throw: " << second_longest_throw << endl;

    cout << "Parim tulemus: " << longest_throw << endl << "Paremuselt teine tulemus: " << second_longest_throw;

}