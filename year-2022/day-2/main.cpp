#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>
using namespace std;

int scoreFairPlay(const vector<string>& temp);
int scoreLoseDrawWin(const vector<string>& temp);

vector<string> fileToVector(const string& file);

int main(){
    vector<string> temp;
    temp = fileToVector("input.txt");
    cout<<"Total score according to the strategy guide: "<<scoreFairPlay(temp);
    cout<<"\nTotal score according to the changed strategy guide with WinDrawLose: "<<scoreLoseDrawWin(temp);
}

int scoreFairPlay(const vector<string>& temp){
    int countPlayer = 0;
    int countMatch = 0;
    for(auto t:temp){
        if(t[2] == 88) countPlayer+=1;
        if(t[2] == 89) countPlayer+=2;
        if(t[2] == 90) countPlayer+=3;

        if(t[2] - t[0] == 23) countMatch+=3;
        if(t[2] - t[0] == 24) countMatch+=6;
        if(t[2] - t[0] == 21) countMatch+=6;
    }
    return countPlayer+countMatch;
}
int scoreLoseDrawWin(const vector<string>& temp){
    int countPlayer = 0;
    int countMatch = 0;
    char letr;
    for(auto t:temp){
        if(t[2] == 89) countMatch+=3;
        if(t[2] == 90) countMatch+=6;
        if(t[2] == 88 )letr = t[0]+22;
        if(t[2] == 89) letr = t[0]+23;
        if(t[2] == 90) letr = t[0]+24;

        if(t[2] == 90 && t[0] == 67) letr = t[0]+21;
        if(t[2] == 88 && t[0] == 65) letr = t[0]+25;
        if(letr == 88) countPlayer+=1;
        if(letr == 89) countPlayer+=2;
        if(letr == 90) countPlayer+=3;
    }
    return countPlayer+countMatch;
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


//Total score according to the strategy guide: 17189
//Total score according to the changed strategy guide with WinDrawLose: 13490
//https://adventofcode.com/2022/day/2

//  X - 88,   Y - 89,    Z - 90
//  X - rock, Y - paper, Z - scissors;
//  X - 1,    Y - 2,     Z - 3;
//  X - lose, Y - draw,  Z - win

// A - rock, B - paper, C - scissors;
// A - 65,   B - 66,    C - 67


//win paper: 90-66=24, win scissors: 88-67=21, win rock: 89-65=24
//lose paper: 88-66=22, lose scissors: 89-67=22, lose rock: 90-65=25
//draw paper: 89-66=23, draw scissors: 80-67=23, draw rock: 88-65=23

//A Y -- rock and I need to draw
//B X -- papper and I need to lose
//C Z -- scissors and I need to win

//p -win 3+6 = 9
//s - win 1+6 = 7
//r - draw 1+3 = 4
//s - draw 3+3 = 6
//r - win 2+6 = 8
//s - lose 2+0 = 2
// 36