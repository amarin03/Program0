//Name: Andres Marin
//Student #: 2240386
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main (){

     int points, quarters, age; //Variable type int to hold users inputs and keep track of points.
     string grade, internship, academicStatus, probation;//Variables type string to hold user inputs.
       
     cout << "Welcome to housing selection using a point system." << endl; //Introductory statement.
     cout << "What class are you in? "; //Initial qustion to ask users class.
     cin >> grade; //Adds users input into variable grade.
   
     //Nested if statements to calculate inital points based on users class.
     if (grade == "Freshman" || grade == "freshman"){
          points = 1;
     }else if (grade == "Sophomore" || grade == "sophomore"){
          points = 2;
     }else if (grade == "Junior" || grade == "junior"){
          points = 3;
     }else if (grade == "Senior" || grade == "senior"){
          points = 4;
     
          //Statement to ask the senior how many quarters left before they graduate.
          cout << "How many quarters do you have left until you graduate? "; 
          cin >> quarters;

          if (quarters <= 2){ //If statement to calculate points based on user input.
              points += 2; //Awards 2 points if they have 2 or less quarters left before they graduate.
          }else{
              points += 1; //Awards 1 point if they have more than 2 quarters left before they graduate.
          }
     }else{
          throw invalid_argument(grade + " is an invalid input."); //Invalid argument statement.
     }

     cout << "How old are you? "; //Asking users age.
     cin >> age; //adds users input to age variable.

     if (age >= 18 && age <= 50){//Statement to calculate point value based on age.
          points += sqrt(age - 18); //points awarded based on the square root of their age subtracted by 18.
     }else{
          throw invalid_argument(age + " is an invalid input."); //Invalid argument statement.
     }

     cout << "Are you currently in an internship? "; //Ask users if they are in an internship.
     cin >> internship; 

     if (internship == "Yes" || internship == "yes"){
          points += 1; //Awards 1 point for having an internship.
     }else if (internship == "No" || internship == "no"){
          points += 0; //Does not award any points.
     }else{
          throw invalid_argument(internship + " is an invalid input."); //Invalid argument statement.   
     }
     
     //Ask user if they are currently in academic probation or possible suspension.
     cout << "Are you currently in Academic Probation or possible Academic Supension? \n";
     cout << "If you are in Academic Probation enter \"ap\". \n" //Tells user what they need to enter.
          << "If you are in Academic Suspension enter \"as\". \n"
          << "If you are in neither enter \"neither\". ";
     cin >> academicStatus;
     
     if (academicStatus == "ap"){ //Subtracts points if user is in probation or suspension.
          points -= 1;
     }else if (academicStatus == "as"){
          points -=2;
     }else if (academicStatus == "neither"){ //Awards 2 points for not being in either.
          points += 2;
     }else{
          throw invalid_argument(academicStatus + " is an invalid input."); //Invalid argument statement.
     }
     
     //Asks students if they have been in disciplinary probation during the year.
     cout << "Have you been on Disciplinary Probation at any point in the year? y/n: ";
     cin >> probation;

     if (probation == "y"){ //Subtracts points if they have.
          points -= 3;
     }else if (probation == "n"){ //Awards points if they havent.
          points += 3;
     }else{
          throw invalid_argument(probation + " is an invalid input."); //Invalid argument statement
     }

     cout << "your total point value is: " << points << ".\n"; //Statement outputting users total point value.
     return 0;
}