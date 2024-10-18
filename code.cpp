#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAX_LENGTH=9;

void input_file_to_array(char (&read_answer_keys) [10][10][MAX_LENGTH],char file[1000]){
    ifstream inputFile1(file);
    // Check if the file is open
    if (!inputFile1.is_open()) {
        throw runtime_error("Unable to open file: student_answers_keys.txt");
    }
    char buffer[9]; // Buffer to read each answer including spaces and null terminator
    
    for(int i = 0; i < 10; i++) {
        //cout<<buffer2<<endl;
        for(int j = 0; j < 10; j++) {
            if(j==9){
                inputFile1.read(buffer, 8); // Because of new line at the end of the line
                buffer[8] = '\0';
                inputFile1.ignore(2);
                sort(buffer,buffer+MAX_LENGTH-1);
                strncpy(read_answer_keys[i][j], buffer, MAX_LENGTH);
                continue;
            }
            inputFile1.read(buffer, 8); // Read 8 characters (the answer with spaces)
            buffer[8] = '\0'; // Null-terminate the string
            sort(buffer,buffer+MAX_LENGTH-1); // Sort the buffer by ASCII value
            strncpy(read_answer_keys[i][j], buffer, MAX_LENGTH); // Copy to the array
            inputFile1.ignore(1); // Ignore the space separating answers
        }
    }

    inputFile1.close(); // Close the file after reading

}

void input_file_to_array(char (&read_answer_keys) [10][10][MAX_LENGTH],char file[1000],char groups[],int size=10){
    ifstream inputFile1(file);
    // Check if the file is open
    if (!inputFile1.is_open()) {
        throw runtime_error("Unable to open file: student_answers_keys.txt");
    }
    char buffer2[4];
    int counter=0;
    char buffer[9]; // Buffer to read each answer including spaces and null terminator
    
    for(int i = 0; i < 10; i++) {
        inputFile1.read(buffer2, 4);
        buffer2[1]='\0';
        //cout<<"2: "<<buffer2<<endl;
        groups[counter]=*buffer2;
        counter++;
        for(int j = 0; j < 10; j++) {
            if(j==9){
                inputFile1.read(buffer, 8); // Because of new line at the end of the line
                buffer[8] = '\0';
                inputFile1.ignore(2);
                sort(buffer,buffer+MAX_LENGTH-1);
                strncpy(read_answer_keys[i][j], buffer, MAX_LENGTH);
                continue;
            }
            inputFile1.read(buffer, 8); // Read 8 characters (the answer with spaces)
            buffer[8] = '\0'; // Null-terminate the string
            //cout<<"1: "<<buffer<<endl;
            sort(buffer,buffer+MAX_LENGTH-1); // Sort the buffer by ASCII value
            strncpy(read_answer_keys[i][j], buffer, MAX_LENGTH); // Copy to the array
            inputFile1.ignore(1); // Ignore the space separating answers
        }
    }

    inputFile1.close(); // Close the file after reading

}

int num_of_answers(char answer[1000]){
    int counter=0;
    for(int i=0;answer[i]!='\0';i++){
        if(isalpha(answer[i])) counter++;
    }
    return counter;
}



double grading(char stud_answer[1000],char test_answer[1000]){
    double plus_points;
    double minus_points;
    double pm_points=0;
    // Check if the test answer has any answers
    if(num_of_answers(test_answer)!=0){
        plus_points=0;
        minus_points=0;
        // Going through all the chars in the string
        for(int i=7;i>-1;i--){
            // Checking if the char is a letter, if not break it to be more optimised
            if(isalpha(stud_answer[i])){
                bool wrong_answer=true;  
                for(int j=0;test_answer[j]!='\0';j++){
                    if(stud_answer[i]==test_answer[j]){
                        //cout<<"curr+ "<<stud_answer[i]<<endl;
                        plus_points=plus_points+4./num_of_answers(test_answer);
                        wrong_answer=false;
                        break;
                    }
                }
                if(wrong_answer){
                    //cout<<"curr- "<<stud_answer[i]<<endl;
                    minus_points++;
                }
            }else{
                break;
            }
        }
        pm_points=plus_points-minus_points;
        if(pm_points<0) {
            pm_points=0;
        }
        return pm_points;
    }else{
        plus_points=4;
        minus_points=0;
        for(int i=7;i>-1;i--){
            if(isalpha(stud_answer[i])){
                minus_points++;                     // if the question doesn't have correct answers
            }else{
                break;
            }
        }
        pm_points=plus_points-minus_points;
        if(pm_points<0) pm_points=0;
        return pm_points;
    }
    

}



int main() {
    srand(time(0));

   char read_answer_keys[10][10][MAX_LENGTH]; // Matrix to store the answers for 10 different exams, each with 10 questions
    char read_answer_keys_file[]="student_answers_keys.txt";
    char read_answers[10][10][MAX_LENGTH];     // Matrix to store the answers of 10 students, each with 10 question 
    char read_answers_file[]="student_answers.txt";
    char groups[10];
    int size=10;
    input_file_to_array(read_answer_keys,read_answer_keys_file);  // Inputing from file to array all the answers
    input_file_to_array(read_answers,read_answers_file,groups,size);
    double sum=0;
    
    for(int i = 0; i < 10; i++) {
        int random_test=groups[i]-'0'; //  Randomly picking exam for every student
        cout<<random_test<<endl;
        for(int j = 0; j < 10; j++) {
            char student_answer[MAX_LENGTH]="";
            char test_answer[MAX_LENGTH]="";     // variables to store only 1 answer
            strncpy(student_answer, read_answers[i][j], MAX_LENGTH);
            strncpy(test_answer, read_answer_keys[random_test][j], MAX_LENGTH);   //    Copying answer to variables from matrixes
            cout<<student_answer<<"|"<<test_answer<<endl;
            cout<<grading(student_answer,test_answer)<<endl;
            sum+=grading(student_answer,test_answer);

        }
        cout<<"Student"<<i<<": "<<sum<<endl;
        cout<<"________"<<endl;
        sum=0;
    }
    
    

    return 0;
}
