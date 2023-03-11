#include <iostream>
#include <stdio.h>
#include "StudentManager.h"
#include "MaterialManager.h"
#include <fstream>
#include <string>
using namespace std;

StudentManager students;
MaterialManager books;
ifstream infileStudentInfo;
ifstream infileBookInfo;
ofstream outFileStudentInfo;
ofstream outFileBookInfo;
string studentFIle;
string bookFile;


template <typename T>
void swap(T* a, T* b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

template <typename T>
int partition(T * arrList,int start,int end)
{
	   T pivot = arrList[end]; // pivot
	    int i = (start - 1); // Index of smaller element

	    for (int j = start; j <= end - 1; j++)
	    {
	        // If current element is smaller than the pivot
	        if (arrList[j] < pivot)
	        {
	            i++; // increment index of smaller element
	            swap(&arrList[i], &arrList[j]);
	        }
	    }
	    swap(&arrList[i + 1], &arrList[end]);
	    return (i + 1);
 }
/**
 * Generic recursive function to sort list of items
 *  based on the QUICK SORT method
 */
template <typename T>
 void Quicksort(T * arrList, int start, int end)
 {
    if(start<end)
    {
         int index=partition(arrList, start, end);
             Quicksort(arrList, start, index - 1);
             Quicksort(arrList, index + 1, end);
    }
}
/**
 * function to read students' list at the beginning from the students's file
 * @param studentFIle: name of student's file
 */
void printStudentInfo(){
	if(studentFIle!=""){
		infileStudentInfo.open(studentFIle);
		if(infileStudentInfo.fail()){
			cout<<"\n FILE NOT FOUND\n\n";
//			endfunction();
//			return 0;
		}
		else{
			while(!infileStudentInfo.eof())
			{
				string tStr;
				student * stdnt = new student();
				getline(infileStudentInfo, tStr);
				if(tStr.size()>1 && tStr.at(0)!='#'){
	//				cout << tStr ;
					stdnt->parseLine(tStr, books);
					students.addStudent(stdnt);
				}

			}
		}
		infileStudentInfo.close();
	}
}
/**
 * function to read books' list at the beginning from  the book's file
 * @param bookFile: name of book's file
 */
void printBookInfo(){
	if(bookFile!=""){
		infileBookInfo.open(bookFile);
		if(infileBookInfo.fail()){
			cout<<"\nFILE NOT FOUND\n\n";
//			endfunction();
//			return 0;
		}
		else{
			while(!infileBookInfo.eof())
			{
				string tStr;
				book * bk = new book();
				getline(infileBookInfo, tStr);
				if(tStr.size()>1 && tStr.at(0)!='#'){
	//				cout << tStr ;
					bk->addBOOK_COUNT();
					bk->parseLine(tStr);
					books.addBook(bk);
				}

			}
		}
		infileBookInfo.close();
	}
}
/**
 * function to write students' list to the student's file
 * @param fileName: name of the student's file
 */
void updateStudentInfo(){

	remove( studentFIle.c_str() );
	outFileStudentInfo.open(studentFIle, fstream::in | fstream::out | fstream::app);
	students.printFile( outFileStudentInfo);
	outFileStudentInfo.close();
}
/**
 * function to write books' list to the book's file
 * @param fileName: name of the book's file
 */
void updateBookInfo(){

	remove( bookFile.c_str() );
	outFileBookInfo.open(bookFile, fstream::in | fstream::out | fstream::app);
	books.printFile( outFileBookInfo);
	outFileBookInfo.close();
}

/**
 * function to print intro message
 */
void intro(){
	//system("clear");
	cout<<"*** BURJ KHALIFA LIBRARY MANAGEMENT SYSTEM ***";
    cout<<"\n\n******* BURJ GROUP ******* \n";
}
/**
 * function to print endfunction message
 */
void endfunction(){
	//system("clear");
	cout<<"*** THANKS FOR USING THE BURJ LIBRARY SYSTEM ***";
    cout<<"\n\n*** BURJ KHALIFA THANKS YOU *** \n";
}
/**
 * function to print initial menu
 */
void menuView(){
	cout<<"\n1. ADMINISTRATOR";
	cout<<"\n2. STUDENT";
	cout<<"\n0. EXIT";
	cout<<"\n\nOPTION: ";
}
/**
 * function to handle and show administrator's menu
 */
void adminView(){
	int option = 0;
	int id=0;
	string name;
	string authName;

	do{
		cout<<"\n1. ADD STUDENT";
		cout<<"\n2. VIEW STUDENTS LIST";
		cout<<"\n3. ADD BOOK";
		cout<<"\n4. VIEW BOOKS LIST";
		cout<<"\n5. VIEW BORROWED BOOKS";
		cout<<"\n0. PREVIOUS MENU";
		cout<<"\n\nOPTION: ";
		cin >> option;
		switch(option){
		case 1:
		{
			cout<<"ENTER STUDENT ID:";
			cin>>id;
			while(cin.fail()) {
				cout << "INVALID ID\n";
				cin.clear();
				cin.ignore(256,'\n');
				cout<<"RE-ENTER STUDENT ID:";
				cin>>id;
			}
			while ( students.findStudentId(id) ){
				cout << "ID EXISTS, \n";
				cout<<"RE-ENTER STUDENT ID:";
				cin>>id;
			}
			cout<<"ENTER STUDENT NAME:";
			cin>>name;
			student * stdnt = new student(id, name);
			students.addStudent(stdnt);
//			string temp;
//			stdnt->createLine(temp);
//			outFileStudentInfo<<temp;
			break;
		}
		case 2:
		{
			students.print();
			break;
		}
		case 3:
		{
			cout<<"BOOK NAME:";
			cin>>name;
			cout<<"AUTHOR NAME:";
			cin>>authName;
			books.addBook( name, authName);
			break;
		}
		case 4:
		{
			books.print();
			break;
		}
		case 5:
		{
			//string  borrowedBooks[books.getSize()];
			string  borrowedBooks[80000];
			int borrowedBooksSize = 0;
			books.borrowedBooksStrList(borrowedBooks,borrowedBooksSize);
			if(borrowedBooksSize==0){
				cout<<"NO BOOK IS BORROWED\n";
			}
			else{
				Quicksort(borrowedBooks, 0, borrowedBooksSize-1);
				for(int j = 0;j<borrowedBooksSize;j++){
					cout<<borrowedBooks[j].substr(11);
				}
			}
			break;
		}
		case 0:
			break;
		default:
			cout<<"INPUT ERROR";
			break;
		}
	}while(option!=0);
	updateBookInfo();
	updateStudentInfo();
}
/**
 * function to handle and show student's meni
 */
void studentView(){
	int option = 0;
	student * currentStudent = NULL;
	int id=0;
	string name;
	string authName;
	book * fBook =NULL;

	do{
		cout<<"ENTER YOUR ID:";
		cin >>id;
		while(cin.fail()) {
			cout << "INVALID ID\n";
			cin.clear();
			cin.ignore(256,'\n');
			cout<<"RE-ENTER STUDENT ID:";
			cin>>id;
		}
		currentStudent = students.findStudentId(id);
		if(currentStudent== NULL){
			cout<<"STUDENT ID NOT FOUND!\n";
		}
	}while(currentStudent== NULL);

	do{
		cout<<"\n1. BORROW A BOOK";
		cout<<"\n2. RETURN A BOOK";
		cout<<"\n3. VIEW BORROWED BOOKS";
		cout<<"\n5. VIEW BOOKS LIST";
		cout<<"\n0. RETURN TO PREVIOUS MENU";
		cout<<"\n\nENTER YOUR OPTION: ";
		cin >> option;
		switch(option){
		case 1:
		{
			fBook =NULL;
			do{
				cout<<"ENTER BOOK ID TO BORROW:";
				cin>>id;
				while(cin.fail()) {
					cout << "INVALID ID\n";
					cin.clear();
					cin.ignore(256,'\n');
					cout<<"RE-ENTER BOOK ID:";
					cin>>id;
				}
				fBook = books.findBookId(id);
				if(fBook== NULL){
					cout<<"BOOK ID NOT FOUND!\n";
				}
			}while(fBook== NULL);
			int *stdId = new int(currentStudent->getId());
			if(fBook->borrowBook(stdId)){
				currentStudent->addBorrowedBook(fBook);
				cout<<"STUDENT "<<currentStudent->getId()<<" BORROWS BOOK "<<id<<"\n";
			}
			break;
		}
		case 2:
		{
			fBook =NULL;
			do{
				cout<<"ENTER BOOK ID TO RETURN:";
				cin>>id;
				while(cin.fail()) {
					cout << "ID IS NOT VALID\n";
					cin.clear();
					cin.ignore(256,'\n');
					cout<<"RE-ENTER BOOK ID:";
					cin>>id;
				}
				fBook = books.findBookId(id);
				if(fBook== NULL){
					cout<<"BOOK ID NOT FOUND IN BOOK LIST!";
				}
			}while(fBook== NULL);
			int xBookId = currentStudent->getBorrowedBooks()->find(*fBook);
			if(xBookId!=-1){
				int sid = fBook->returnBook();
				if(sid > -1){
					currentStudent->removeBorrowedBookAtindex(xBookId);
				}
				if(sid > 0 ){
					student * tempStudent = students.findStudentId(sid);

					tempStudent->addBorrowedBook(fBook);
					cout<<"STUDENT "<<tempStudent->getId()<<" BORROWS BOOK "<<id<<"\n";
				}
			}
			break;
		}
		case 3:
		{
			cout<<*(currentStudent->getBorrowedBooks());
			break;
		}
		case 5:
		{
			books.print();
			break;
		}
		case 0:
			break;
		default:
			cout<<"Unknown input";
			break;
		}

	}while(option!=0);
	updateBookInfo();
	updateStudentInfo();
}
/**
 * main function that handles whole program
 * @return
 */
int main(int argc, char* argv[]) {
	intro();

	int option = 0;
//	string studentFIle;
//	string bookFile;

	if(argc == 3){
		studentFIle = argv[1];
		bookFile = argv[2];
	}
	else{
		studentFIle = "student.txt";
		bookFile = "book.txt";
	}

	printBookInfo();
	printStudentInfo();

	do{
		menuView();
		cin >> option;
		while(cin.fail()) {
			cout << "YOUR OPTION IS NOT VALID\n";
			cin.clear();
			cin.ignore(256,'\n');
			cout<<"RE-ENTER YOUR OPTION:";
			cin>>option;
		}
		switch(option){
		case 1:
			adminView();
			break;
		case 2:
			studentView();
			break;
		case 0 :
			 endfunction();
			 break;

		}
	}while(option!=0);
	updateBookInfo();
	updateStudentInfo();
	return 0;
}
