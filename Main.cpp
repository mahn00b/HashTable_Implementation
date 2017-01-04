 
#include "HashTable.h"
#include "Student.h"
#include "Node.h"
#include <iostream>





using namespace std;


void printMenu();


int main() {
  
  bool quit = false, isStudent = false; 
  HashTable<int> Int;
  HashTable<Student> student;
  int response;
  string name;
  
  cout<< "Would you like to use  with int(1) or Student(2)?";
  cin >> response;
  
  if(response == 2)
    isStudent = true;
  
  
  while(!quit) {
    
    
    printMenu();
    cin >> response;
    
    
    switch(response)
    {
      case 1:
	
	if(isStudent)
	{
	  
      
      cout <<"Enter Next Student ID:\n";
      cin >> response;
      
      Student y(response);
      
      cout<<"Enter Student First Name: \n";
      cin>> name;
      
      y.setFirstName(name);
      
      cout<<"Enter Student Last Name: \n";
      cin>> name;
      
      y.setLastName(name);
	  
      
      student.insert(y);
     
	
	  
	} else {
	cout << endl << "Enter The Integer You Would Like to Insert: " << endl;
	cin >> response;
	Int.insert(response);
	}
	break;
      case 2:
	if(isStudent) {
	cout << endl << "Enter The ID for the Student You Would Like to Delete: " << endl;
	cin >> response;
	Student sq(response);
	student.deleteNode(sq);
	} else {
	cout << endl << "Enter The Integer You Would Like to Delete: " << endl;
	cin >>response;
	Int.deleteNode(response);
	}
	break;
      case 3:
	if(isStudent)
	  student.printNodes();
	else
	  Int.printNodes();
	break;
      case 4:

	
	if(isStudent)
	{
	  
	 cout <<"Enter the ID of the student you want to search"<<endl;
	 cin >> response;
	 Student std(response);
	  
	    Node<Student>* ss = student.search(std);
	    
	    if(ss != NULL)
	      cout<<"\nValue Found: \n" << ss -> getValue();
	    else
	      cout<<"\nValue is not found\n";
	    
	    
	} else {
	  
	  	 cout <<"Enter the value of the integer you want to search"<<endl;
	 cin >> response;

	  
	    Node<int>* ss = Int.search(response);
	    
	    if(ss != NULL)
	      cout<<"\nValue Found: \n" << ss -> getValue();
	    else
	      cout<<"\nValue is not found\n";
	  
	  
	}
	break;
      case 5:
	quit = true;
	break;
      
    } 
    
  }
  
  
  
  
  
  return 0;
}



void printMenu() {
  
cout << endl << "What would you like to do?" << endl
      <<"----------------------------" << endl
      <<"1. Insert" << endl
      <<"2. Delete" << endl
      <<"3. Print" << endl
      <<"4. Search" << endl
      <<"5. Quit" <<endl;
  
  
}