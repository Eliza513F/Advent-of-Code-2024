#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

//function to get how many times a number occurs in an array
int getCount(int* arr, int n, int val){
    int count = 0;

    for (int i = 0; i < n; i++){ //go through the whole list, add to count if matches val
        if (arr[i] == val){
            count++;
        }
    }

    return count;
}

int main(){

    ifstream inputFile("d1Input.txt");
    string thisLine;
    int length = 1000; //number of lines in the file

    //must be dynamic in order to be assigned with variable length
    int* list1 = new int[length];
    int* list2 = new int[length];

    bool firstList = 1; //bool for which list the current number read belongs in
    int i = 0; //counts number of numbers read

    //read all the "words" (numbers) in the input file
    while (inputFile >> thisLine){
        if (firstList){
            list1[i/2] = stoi(thisLine); //convert string to int, add to list
        }
        else {
            list2[i/2] = stoi(thisLine);
        }
        i++; //add 1 to the count
        firstList = !firstList; //invert the boolean to flip which array is added to
    }

    //sort the lists to get the lowest pair, 2nd lowest pair, etc
    sort(list1, list1+length-1);
    sort(list2, list2+length-1);

    int sum = 0; //counts the sum of the distances
    for (int j = 0; j < length; j++){
        sum += abs(list2[j] - list1[j]);
    }

    int similarity = 0; //counts the similarity
    for (int j = 0; j < 1000; j++){
        similarity += list1[j] * getCount(&list2[0], 1000, list1[j]);
    }

    cout << "\nSum = " << sum;
    cout << "\nSimilarity = " << similarity;

    //free up the dynamic arrays
    delete list1;
    delete list2; 

    return 0;
}