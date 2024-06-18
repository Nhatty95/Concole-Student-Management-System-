#include <iostream>
#include <string>
#include <stdlib.h> //Inorder to use system("clear") for linux
#include <vector> //Inorder to use vectors(Students data in this case)

using namespace std;

const int MAX_POINT = 100;
const int MIN_POINT = 0;
const int NUMBER_OF_GRADES = 5;

struct Stud{
  string name, ID;
  int grade[5];
  float average;
};

vector<Stud> students; //Vector of structs

void clearConsole() { //clean console

  int i = system("clear"); // change 'clear' to 'cls' for windows
  if(i == 0){}
} 

void gradeCalculate(Stud stud){ //calculates average grade
  float sum = 0.0;

  for(int i = 0; i < NUMBER_OF_GRADES; i++){
    sum += stud.grade[i];
  }
  stud.average = sum / NUMBER_OF_GRADES;
  cout << "Average grade: " << stud.average << endl;

  if(stud.average >= 90){
    cout << "Alphabetical grade: A  (Pass)" << endl;
  }
  else if (stud.average >= 75){
    cout << "Alphabetical grade: B  (Pass)" << endl;
  }
  else if (stud.average >= 65){
    cout << "Alphabetical grade: C  (Pass)" << endl;
  }
  else if (stud.average >= 50){
    cout << "Alphabetical grade: D  (Pass)" << endl;
  }
  else{
    cout << "Alphabetical grade: F  (Fail)" << endl;
  }
  cout << "-----------------------" << endl;
 
} 

void displayStudent(){ // purpose is to display all students data

  for(Stud student : students){
     cout << "#######################" << endl; 
    cout << "-----------------------" << endl;
    cout << "Name: " << student.name << endl;
    cout << "ID: " << student.ID << endl;
    cout << "Grades: ";
    for(int i = 0; i < NUMBER_OF_GRADES; i++) {
        cout << student.grade[i] << " ";
    }
    cout << endl;
    cout << "....................... " << endl;

    
    gradeCalculate(student);
    
  }
} 

void clearInput(){ //clears an input buffer
  cin.clear();
  cin.ignore(1024, '\n');
}

void addStudent(){ //add new students to the list 
  clearInput();

  Stud newStudent;
  
  cout << "Enter student name: " ;
  getline(cin, newStudent.name); 
  cout << "Enter student ID: ";
  getline(cin, newStudent.ID);
  for(int i = 0; i < NUMBER_OF_GRADES; i++){
    cout << "Enter grade " << i+1 << ": ";

    cin >> newStudent.grade[i];

    if(cin.fail()){
      clearInput();
      
      cout << "Invalid input. Please enter a number." << endl;
      i--;
    }
    
    if (newStudent.grade[i] > MAX_POINT || newStudent.grade[i] < MIN_POINT ){
      cout << "Invalid grade. Please enter a grade between 0 and 100." << endl;
      i--;
      
    }
    
  }

  students.push_back(newStudent); //add student to students vectorte

  clearConsole(); 
}

void resultForSpecificStudent(){ //shows the result of a specific student
  clearConsole();

  int index = 0;
  int input;

  if(students.size() != 0){
    for(Stud student: students){
      cout << index << ". " << student.name << endl;
      index++;
    }

    cout << "-----------------------" << endl;
    cout << "Choose a student to view the result." << endl;
    cout << "-----------------------" << endl;

    do{
      clearInput();
      cin >> input;

      if(cin.fail() || input >= students.size()){
        cout << "Invalid input. Please enter a valid index." << endl;

      }
    } while (cin.fail() || input >= students.size());

    cout << "-----------------------" << endl;
    cout << "Name: " << students[input].name << endl; //purpose of this line ??
    gradeCalculate(students[input]);
  } 
  else {
    cout << "No students found." << endl;
  }
}
  
int main() {
  int choice;

  do{
    cout << "Grade Managment System\n" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Result for specific student" << endl; 
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "" << endl;
    clearConsole();
    
    switch (choice){
      case 1:
        cout << "-----------------------" << endl;
        addStudent();
        cout << "-----------------------" << endl;
        break;
      case 2:
        cout << "-----------------------" << endl;
        displayStudent();
        break;
      case 3: 
        cout << "-----------------------" << endl;
        resultForSpecificStudent();
        break;
      case 4:
        cout << endl;
        cout << "Exiting Operation.....";
        break;
      default:
        cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        clearInput();
      
    } 
  }while(choice != 4);
  
  return 0;
}