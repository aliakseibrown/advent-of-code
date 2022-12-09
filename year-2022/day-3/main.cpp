#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;
//--- Day 3: Rucksack Reorganization ---
//https://adventofcode.com/2022/day/3

int sumThreeGroups(const vector<string>& temp);
int sumItems(const vector<string>& temp);


vector<string> fileToVector(const string& file);

int main(){
    vector<string> temp;
    temp = fileToVector("input.txt");
    cout<<"\nThe sum of the priorities of each string devided by 2: "<<sumItems(temp);
    cout<<"\nThe sum of the priorities of those item types in group of 3: "<<sumThreeGroups(temp);
}
//The sum of the priorities of each string devided by 2: 7737
//The sum of the priorities of those item types in group of 3: 2697

int sumThreeGroups(const vector<string>& temp){
    int sum = 0;
    int sizeHalf = 0;
    string selected;
    set<char> set1;
    set<char>set2;
    set<char>set3;
    map<char, int>mapa;
    for(int k = 0; k < temp.size(); k=k+3){
        set1.clear();
        set2.clear();
        set3.clear();
        mapa.clear();
        for( auto t: temp[k]) set1.insert(t);
        for( auto t: temp[k+1]) set2.insert(t);
        for( auto t: temp[k+2]) set3.insert(t);

        for(auto s: set1) mapa[s]++;
        for(auto s: set2) mapa[s]++;
        for(auto s: set3) mapa[s]++;

        for(auto m:mapa) if(m.second == 3) selected.push_back(m.first);
    }
    for(int i = 0; i < selected.length(); i++){
        if(selected[i] > 96) sum += selected[i] - 96;
        else sum += selected[i] - 38;
    }
    return sum;
}
int sumItems(const vector<string>& temp){
    int sum = 0;
    int sizeHalf = 0;
    string selected;
    set<char> set1;
    set<char>set2;
    map<char, int>mapa;
    for(auto t:temp){
        mapa.clear();
        set1.clear();
        set2.clear();
        sizeHalf = t.length()/2;
        for(int i = 0; i < sizeHalf; i++){
            set1.insert(t[i]);
            set2.insert(t[sizeHalf+i]);
        }
        for(auto s:set1) mapa[s]++;
        for(auto s:set2) mapa[s]--;
        for(auto m:mapa) if(m.second == 0) selected.push_back(m.first);
    }
    for(int i = 0; i < selected.length(); i++){
        if(selected[i] > 96) sum += selected[i] - 96;
        else sum += selected[i] - 38;
    }
    return sum;
}

vector<string> fileToVector(const string& file){
    vector<string>vecLetters;
    ifstream inputFile(file);
    string buffer;
    if (inputFile.good()) {
        while (getline(inputFile, buffer)){
            if (!buffer.empty()) {
                vecLetters.push_back(buffer);
            }
        }
        inputFile.close();
        return vecLetters;

    }else {
        cout << "Error!";
        _exit(0);
    }
}
