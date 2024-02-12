/*
 * File Name: p3.c
 * 
 * Author: Jake Esperson
 * 
 * Date: 01-11-2023
 * 
 * Description: Given a txt file, after removing all non-alphabetical characters, uppercase and print all
 * words with length() >= 10. Your program should be able to read the filename from terminal. If
 * the number of arguments from terminal is incorrect, print an error message and exit the
 * program
 * Input: txt file
 * Output: Uppercased words with length() >= 10
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    string filename;
    string word;
    ifstream file;

    if(argc != 2){
        cout << "Incorrect number of arguments." << endl;
        return 0;
    }

    filename = argv[1];

    file.open(filename);

    if(!file.is_open()){
        cout << "File not found." << endl;
        return 0;
    }

    while(file >> word){
        string newWord = "";
        for(int i = 0; i < word.length(); i++){
            if(isalpha(word[i])){
                newWord += toupper(word[i]);
            }
        }
        if(newWord.length() >= 10){
            cout << newWord << endl;
        }
    }

    file.close();

    return 0;
}