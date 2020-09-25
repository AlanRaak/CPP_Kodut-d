#include <iostream>
#include <fstream>
#include <string>
#include <list> 
#include <iterator> 
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

bool checkValidity(float& number){

    if (number >= 0 && number <= 10 && (int)(number*10) % 5 == 0){
        return true;
    }else{
        return false;
    }
}

void takeGrades(vector<float>& output){

    float grade_in;

    for (size_t i = 1; i < 6;)
    {   
        cout << "Sisesta " << i << ". hinne: " << endl;
        cin >> grade_in;
        if (checkValidity(grade_in)){
            i++;
            output.push_back(grade_in);
        }
    }
}

void writeGradesToFile(vector<float>& grades){

    ofstream result_file;

    result_file.open ("grades.txt");

    if (result_file.is_open()){
        for(float grade : grades){
            result_file << grade << "\n";
        }
    }

    result_file.close();
}

void wrtieResultToFile(float& result){
    ofstream grades;

    grades.open("result.txt");

    if (grades.is_open()){
        grades << result;
    }

    grades.close();
}

void calculateResult(vector<float>& grades, float& result){
    float sum = 0;
    int total = 0;
    for (float grade : grades){
        sum += grade;
        total++;
    }
    sum = sum - (*max_element(grades.begin(), grades.end()) + *min_element(grades.begin(), grades.end()));

    result = sum / (total-2);
    
}

int main(){

    vector<float> grades;
    float result;

    takeGrades(grades);
    writeGradesToFile(grades);
    calculateResult(grades, result);
    wrtieResultToFile(result);

}