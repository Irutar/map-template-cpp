#include <iostream>
#include <string>
#include "Map.h"
#include "Book.h"

using namespace std;

int main(void) {
	typedef string Title;
	Map<Title, Book> database;

	database.add("Harry Potter", Book("Rowling", "Drama", 250, "borrowed"));
	database.add("Witcher", Book("Sapkowski", "Art", 300, "bookshelf"));
	database.add("Lord of the Rings", Book("Tolkien", "Fantasy", 600, "borrowed"));
	cout << database << endl;
	Map<Title, Book> newDatabase = database;
	
	Book* pB;
	pB = newDatabase.find("Witcher");
	pB->category = "Category_Change";
	pB = newDatabase.find("Harry Potter");
	pB->pages = 1337;

	database = newDatabase;
	
	cout << database << endl;
};
