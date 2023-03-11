#ifndef STUDENTMANAGER_H_
#define STUDENTMANAGER_H_
#include "BinarySearch.h"
#include "Students.h"
#include <fstream>

using namespace std;
/**
 * Class handles the list of the students
 */
class StudentManager {
public:
	/**
	 * constructor function
	 */
	StudentManager();
	/**
	 * destructor function
	 */
	virtual ~StudentManager();
	/**
	 * function to add a student to the list of the students
	 * @param id: student id
	 * @param name: student name
	 */
	void addStudent(int id, std::string name);
	/**
	 * function to add a student to the list of the students
	 * @param temp: student object
	 */
	void addStudent(student * temp);

	/**
	 * function to find id of the student at location index of the books list
	 * @param index
	 * @return: pointer to the found student
	 */
	student* findStudentId(int index);
	/**
	 * function to print the list of the students
	 */
	void print();
	/**
	 * function to print the list of the students to the file
	 */
	void printFile(std::ofstream& ouFileStudent);

private:
	/**
	 * list of the students is kept in a queue
	 */
	BinaryTree<student> *studentTree;
	/**
	 * function to find node
	 * @param node
	 * @param id
	 * @return
	 */
	student* find(const Node<student> * node,int id);
	/**
	 * function to traverse binary tree of the list of the students inorder
	 * @param tmp
	 */
	void inorder(const Node<student> * tmp);
	/**
	 * function to traverse binary tree of the list of the students inorder
	 * and write in file
	 * @param tmp
	 */
	void inorderFile(const Node<student> * tmp, std::ofstream& ouFileStudent);


};

#endif /* STUDENTMANAGER_H_ */
