#include<iostream>
#include<fstream>
#include<cstdlib>
#include <ctime>
#include<string>
using namespace std;

bool check_if_in_string(string s , char c){
    for(int i=0;i<s.size();i++){
        if(s.at(i)==c){
            return true;
        }
    }
    return false;
}

int main(){
    srand(time(0));
    string pot_answers="ABCDEFGH";
    string answers="";
    int num_of_answers;
    int random_answer;
    ofstream outputFile("student_answers.txt");
    for(int i=1;i<11;i++){
        for(int j=1;j<11;j++){
            num_of_answers=rand()%8;
            for(int k=0;k<num_of_answers;k++){
                do{
                    random_answer=rand()%8;
                }while(check_if_in_string(answers, pot_answers.at(random_answer)));
                answers.push_back(pot_answers.at(random_answer));
            }
            while(answers.size()<8){
                answers.push_back(' ');
            }
            outputFile<<answers<<" ";
            answers="";
        }
        outputFile<<endl;
    }


    return 0;
}