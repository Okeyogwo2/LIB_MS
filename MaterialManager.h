
#ifndef MATERIALMANAGER_H_
#define MATERIALMANAGER_H_

#include "Materials.h"
#include "CircularLinkedList.h"
#include <fstream>

/**
 * Class handles the list of the books
 */
class MaterialManager {
public:
	/**
	 * constructor function
	 */
	MaterialManager();
	/**
	 * destructor function
	 */
	virtual ~MaterialManager();
	/**
	 * function to add a book to the list of the books
	 * @param name: book name
	 * @param authName: author name of the book
	 */
	void addBook(std::string name, std::string authName);
	/**
	 * function to add a book to the list of the books
	 * @param temp: book object
	 */
	void addBook(book * temp);
	/**
	 * function to print the list of the books
	 */
	void print();
	/**
	 * function to find id of the book at location index of the books list
	 * @param index
	 * @return: pointer to the found book
	 */
	book * findBookId(int index) ;
	/**
	 * function to find book object among the books list
	 * @param temp book object
	 * @return: pointer to the found book
	 */
	book * findBook(book & temp) ;

	void borrowedBooksStrList(std::string * result, int & borrowedBooksSize);
	/**
	 * function to return size of the books list
	 * @return
	 */
	int getSize();
	/**
	 * function to print the list of the books to the file
	 */
	void printFile(std::ofstream& ouFile);


private:
	/**
	 * list of the books is kept in a queue
	 */
	circularLL<book> * booksList;

};

#endif /* MATERIALMANAGER_H_ */
