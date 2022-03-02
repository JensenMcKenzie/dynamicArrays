/* 
dynamicArrays.cpp - tests out dynamically allocating arrays
Author: Jensen McKenzie
Module: 3
Project: Homework 3
Problem Statement: Write a program that is able to hold a dynamic amount of students in an array,
 sort the array by score, and then print the result to the screen.

Algorithm/Plan:
  1. Create a student class, that has two variables, grade and name.
  2. Create a function that sorts and array of students in ascending order, based on grade.
   2a. For each element in the array, check if there is another element that is greater than it. If so, switch the two positions, so the smaller element comes first.
  3. Create an average score function, that calculates the average grade of an array of students.
   3a. Loop through the array, adding all grades to a total. Return this sum divided by the number of students.
  4. Ask the user how many students they would like to enter, then dynamically allocate an array of students to this value.
  5. For each student in the array, ask the user for a name and grade. Reject the grade if it is less than 0.
  6. Sort the array using the function above, and print the result.
  7. Calculate the average grade of the array using the function above.
*/
#include <iostream>\
#include <String>
using namespace std;

//Student class
class student {
    //Only has two variables, name and grade
    string name = "";
    int grade = 0;
public:
    //Empty constructor
    student(){}

    //Full constructor, setting name to n and grade to g
    student(string n, int g){
        name = n;
        grade = g;
    }

    //Destructor
    ~student() {}

    //Getter methods
    string getName(){
        return name;
    }

    int getGrade(){
        return grade;
    }

    //Setter methods
    void setName(string n){
        name = n;
    }

    void setGrade(int g){
        grade = g;
    }
};

//Sort ascending function, sorts the given array in ascending order by grade
void sortAscending(student* scores, int length){
    //Temp student variable for swapping positions later on
    student temp;
    //For each item in the array, check every other item to see if their grade is greater than the current one
    for (int i = 0; i < length; i++){
        for (int j = i+1; j < length; j++){
            if ((scores+i)->getGrade() > (scores+j)->getGrade()){
                //If the grade is greater, swap the two positions, placing the smaller grade closer to the front of the array
                temp = *(scores+i);
                *(scores+i) = *(scores+j);
                *(scores+j) = temp;
            }
        }
    }
}

//Calculates the average grade of an array of students
int avgScore(student* scores, int length){
    //Sum variable
    int avg = 0;
    //Loop through the array, adding each student's grade to the sum
    for (int i = 0; i < length; i++){
        avg += (scores+i)->getGrade();
    }
    //Return the sum, divided by the total number of students
    return avg/length;
}

int main() {
    //Create length variable, and the pointer to the array of students
    int length;
    student* list;
    //Ask the user to enter the length of the array
    cout << "How many students would you like to enter? ";
    cin >> length;
    //Set the array of students to the lenght specified by the user
    list = new student[length];
    //For each item in the array, prompt the user to enter a name and grade
    for (int i = 0; i < length; i++){
        int score = 0;
        string name = "";
        bool valid = false;
        //Prompt the user to enter a name
        cout << "Enter the students name for position " << i+1 << ": ";
        cin >> name;
        //Prompt the user to enter a grade, reject grade and display error message if this number is negative
        while (!valid){
            cout << "Enter score for position " << i+1 << ": ";
            cin >> score;
            if (score < 0){
                cout << "Invalid score, please try again." << endl;
            }else{
                *(list+i) = student(name, score);
                valid = true;
            }
        }
    }
    //Sort the list of students in ascending order
    sortAscending(list, length);
    //Print the sorted list
    cout << "Sorted list:" << endl;
    for (int i = 0; i < length; i++){
        cout << "Name: " << (list+i)->getName() << ", grade: " << (list+i)->getGrade() << endl;
    }
    //Calculate the average grade of the array, and print the result
    cout << "Average score: " << avgScore(list, length);
    //De-allocate the array of student objects
    delete [] list;
}