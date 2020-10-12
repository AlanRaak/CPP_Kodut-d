#include <iostream>
#include <bits/stdc++.h> 
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

float average_temp(vector<int> &temps){
    int len = 0;
    int sum = 0;
    for (int num : temps){
        len++;
        sum += num;
    }
    return sum/(float)len;
}

float average_temp_wo_minmax(vector<int> &temps){
    int len = -2;
    int sum = -*max_element(temps.begin(), temps.end()) -*min_element(temps.begin(), temps.end());
    for (int num : temps){
        len++;
        sum += num;
    }
    return sum/(float)len;
}

void print_data(string &name, vector<int> &temps){
    cout << name << " -  data: ";

    cout << "Average temperature is: " << average_temp(temps) << endl;
    cout << "Warmest temperature is: " << *max_element(temps.begin(), temps.end()) << endl;
    cout << "Coldest temperature is: " << *min_element(temps.begin(), temps.end()) << endl;
    cout << "Average temperature without min/max is: " << average_temp_wo_minmax(temps) << endl << endl;

    temps.clear(); // clears vector for next data
}

void get_temperatures(string line, vector<int> &temps){
    int index = line.find_first_of("1234567890");
    line = line.substr(index, string::npos);
    string delimiter = " ";

    size_t pos = 0;
    string token;
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        temps.push_back(stoi(token));
        line.erase(0, pos + delimiter.length());
    }
    temps.push_back(stoi(line));
}

void get_name(string &line, string &name){
    int index = line.find_first_of("1234567890");
    name = line.substr(0, index-1);
}


int main(){
    string file_name;
    cout << "Sisesta faili nimi: " << endl;
    cin >> file_name;
    ifstream myfile (file_name);
    bool keep_going = true;

    vector<int> temperatures;
    string city_name;

    string line;
    if(myfile.is_open()){
        getline(myfile,line);
        get_temperatures(line, temperatures);
        get_name(line, city_name);
        print_data(city_name, temperatures);

        cout << "Tahad veel andmeid? (y/n): " << endl;

        char answer;
        cin >> answer;
        if (answer == 'y'){
            while(getline(myfile,line)){
                get_temperatures(line, temperatures);
                get_name(line, city_name);

                print_data(city_name, temperatures);
            }
        }
    }
}