#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>

//they need to know which Elf to ask: they'd like to know how many
// Calories are being carried by the Elf carrying the most Calories.
// In the example above, this is 24000 (carried by the fourth Elf).

using namespace std;

int maxOneElf(const vector<vector<int>>& temp);
int maxThreeElfs(const vector<vector<int>>& temp);
vector<vector<int>> fileToVector(const string& file);

int main(){
    vector<vector<int>> temp;
    temp = fileToVector("nums.txt");
    int maxOne = maxOneElf(temp);
    int maxThree = maxThreeElfs(temp);
    cout<<"The Elf carrying the most Calories: "<<maxOne<<"\n";
    cout<<"The top three Elves carrying the most Calories in total: "<<maxThree;
}

//The Elf carrying the most Calories: 67027
//The top three Elves carrying the most Calories in total: 197291

int maxThreeElfs(const vector<vector<int>>& temp){
    vector<int> topThree;
    int sum = 0;
    for(auto t:temp){
        for(auto s:t){
            sum+=s;
        }
        topThree.push_back(sum);
        sum = 0;
    }
    sort(topThree.begin(), topThree.end(), greater<>());
    sum = topThree[0]+topThree[1]+topThree[2];
    return sum;
}
int maxOneElf(const vector<vector<int>>& temp){
    int sum = 0;
    int max = 0;
    for(auto t:temp){
        for(auto s:t){
            sum+=s;
        }
        if(max < sum) max = sum;
        sum = 0;
    }
    return max;
}
vector<vector<int>> fileToVector(const string& file){
    vector<int> numbers;
    vector<vector<int>>vecNumbers;
    ifstream inputFile(file);
    string buffer;
    if (inputFile.good()) {
        while (getline(inputFile, buffer, '\n')){
            if (!buffer.empty()) {
                numbers.push_back((stoi(buffer)));
            }else {
                vecNumbers.push_back(numbers);
                numbers.clear();
            }
        }
        vecNumbers.push_back(numbers); // adding the last element
        inputFile.close();
        return vecNumbers;
    }else {
        cout << "Error!";
        _exit(0);
    }
}


//https://adventofcode.com/2022/day/1
