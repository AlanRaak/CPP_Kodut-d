#include <iostream>
#include <fstream>
#include <string>
#include <list> 
#include <iterator> 
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

ofstream ratings_data;

bool checkValidity(int& number){
    return true;
}

void takeRatings(vector<int>& ratings){

    int rating;
    for (int i = 1; i < 8;){
        cout << "Sisesta hinne kohtunik " << i << ". : " << endl;
        cin >> rating;
        if (checkValidity(rating)){
            ratings.push_back(rating);
            ratings_data << "Kohtunik " << i << ". hinne: " << rating << endl;
            i++;
        }
    }
}

float averageRating(vector<int>& ratings ){

    int total = 0;
    int sum = 0;
    for(int rating : ratings){
        sum += rating;
        total++;
    }

    ratings_data << "Average: " << (float)sum / (float)total << endl;

    return (float)sum / (float)total; // AVERAGE
}

void judgeRatingData(float& average, vector<int>& ratings){
    float difference;
    float highest_diff = 0;
    int highest_diff_number;
    vector<int> max_diff_judges;

    for(int i = 1; i < ratings.size()+1; i++){
        cout << "Kohtunik " << i << ". hinne: " << ratings.at(i-1);
        difference = ratings.at(i-1) - average;
        ratings_data << i << ". kohtuniku erinevus keskmisest: " << difference << endl;
        if (difference > 0){
            cout << ", suurem keskmisest " << difference << " võrra." << endl;
        }else if(difference < 0){
            cout << ", väiksem keskmisest " << -difference << " võrra." << endl;
        }else{
            cout << ", võrdne keskmisega" << endl;
        }
        if (difference > highest_diff){
            highest_diff = difference;
            highest_diff_number = i;

            max_diff_judges.clear();
            max_diff_judges.push_back(i);
        }else if(difference == highest_diff){
            max_diff_judges.push_back(i);
        }
    }
    cout << "Tegusteerija " << highest_diff_number << ". hinne erines kõige rohkem keskmisest." << endl;

    cout << "Kohtunikud, kes hindasid sama nagu oli maksimaalne hinde hälve:";

    ratings_data << "Suurim erinevus: " << highest_diff << " Kohtunikud: "; 
    for(int judge : max_diff_judges){
        cout << " " << judge << ". ";
        ratings_data << " " << judge;
    }
    cout << endl;

}

int main(){

    vector<int> ratings;
    float average_rating;

    ratings_data.open("tulemus.txt");

    takeRatings(ratings);
    average_rating = averageRating(ratings);
    judgeRatingData(average_rating, ratings);



}