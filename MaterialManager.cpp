#include "MaterialManager.h"

MaterialManager::MaterialManager() {
	booksList = new circularLL<book>();
}

MaterialManager::~MaterialManager() {
	delete(booksList);
}

void MaterialManager::addBook(std::string name, std::string authName) {
	book * temp = new book(name, authName);
	booksList->add(temp);
}
void MaterialManager::addBook(book * temp) {
	booksList->add(temp);
}

void MaterialManager::print() {
	if(booksList->getSize() == 0){
		std::cout<<"No student is added to the tree";
	}
	else {
		std::cout<<*booksList;
	}
}
void MaterialManager::printFile(std::ofstream& ouFile) {
	book ** list = booksList->nodeList();
	for(int i=0; i<booksList->getSize(); i++){
		std::string str;
		list[i]->createLine(str);
		ouFile<<str<<"\n";
	}
}
book * MaterialManager::findBookId(int index) {
	book ** list = booksList->nodeList();
	for(int i=0; i<booksList->getSize(); i++){
		if(list[i]->getId()==index){
			return list[i];
		}
	}
	return NULL;
}
book * MaterialManager::findBook(book & temp) {
	book ** list = booksList->nodeList();
	for(int i=0; i<booksList->getSize(); i++){
		if(!(*list[i]!=temp)){
			return list[i];
		}
	}
	return NULL;
}


void MaterialManager::borrowedBooksStrList(std::string * result, int & borrowedBooksSize) {
	book ** list = booksList->nodeList();
	int c=0;
	for(int i=0; i<booksList->getSize(); i++){
		if(list[i]->isBorrowed()){
			std::string temp ;
			list[i]->toString(temp);
			result[c++]=temp;
		}
	}
	borrowedBooksSize = c;
}

int MaterialManager::getSize() {
	return booksList->getSize();
}

