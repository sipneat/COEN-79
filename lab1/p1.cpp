/*
 * File Name: p1.c
 * 
 * Author: Jake Esperson
 * 
 * Date: 01-11-2023
 * 
 * Description: Given a string, output the number of alphanumeric characters 
 * and non-alphanumeric characters. Skip whitespaces
 * Input: Custom string
 * Output: "<input>" has __ alphanumeric characters and __ non-alphanumeric characters.
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    int alphaNum = 0;
    int nonAlphaNum = 0;

    cout << "Enter a sentence: ";
    getline(cin, input);

    for(int i = 0; i < input.length(); i++){
        if(isalnum(input[i])){
            alphaNum++;
        }else if(!isspace(input[i])){
            nonAlphaNum++;
        }
    }

    cout << "\"" << input << "\" has " << alphaNum << " alphanumeric characters and " << nonAlphaNum << " non-alphanumeric characters." << endl;

    return 0;
}