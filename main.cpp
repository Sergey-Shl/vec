#include <iostream>
#include "vec.cpp"
#include <fstream>
#include <string>
using namespace std;

class reader
{
private:
	unsigned int quantity = 0;
	unsigned int id;
	string Name;
public:
	reader()
	{
		quantity++;
		id = quantity;
		Name = "None";
	}

	reader(string s)
	{
		id = quantity;
		quantity++;
		Name = s;
	}

	unsigned int getId()
	{
		return id;
	}

	string getName()
	{
		return Name;
	}
};

class book
{
private:
	unsigned int quantity = 0;
	unsigned int id;
	string name;
	string author;
	unsigned int year;
	m_vector<reader> readers;
public:
	book()
	{
		id = quantity;
		quantity++;
		name = "None";
		author = "None";
		year = 0;
	}
	book(string n, string a, int y)
	{
		id = quantity;
		quantity++;
		name = n;
		author = a;
		year = y;
	}

	string getBookName()
	{
		return name;
	}

	string getBookAuthor()
	{
		return author;
	}

	unsigned int getBookYear()
	{
		return year;
	}

	unsigned int getBookId()
	{
		return id;
	}

	void addReader(reader r)
	{
		readers.push_back(r);
	}

	void setName(string n)
	{
		name = n;
	}

	void setAuthor(string a)
	{
		author = a;
	}

	void setYear(int y)
	{
		year = y;
	}

	void setId(int i)
	{
		id = i;
	}
};

class library
{
private:
	m_vector<book> books;

	void addBook(book b)
	{
		books.push_back(b);
	}

public:
	void addBook()
	{
		string s;
		book b;
		int a;

		cout << "Name:";
		getline(std::cin, s);
		b.setName(s);

		cout << "Author:";
		getline(std::cin, s);
		b.setAuthor(s);

		cout << "Year:";
		cin >> a;
		b.setYear(a);
		getchar();
		addBook(b);
	}

	int getBooskQuantity()
	{
		return books.size();
	}

	string getBookInfo(int index, int type)
	{
		//type 1 - Name, 2 - Author
		if (type == 1)
			return books[index].getBookName();
		if (type == 2)
			return books[index].getBookAuthor();
	}

	int getBookYear(int index)
	{
		return books[index].getBookYear();
	}

	int getBookId(int index)
	{
		return books[index].getBookId();
	}

	void addReaderToBook(unsigned int index, reader r)
	{
		books[index].addReader(r);
	}

	void saveLib()
	{

		ofstream of;

		of.open("library.inf");
		of << getBooskQuantity() << "\n";

		for (int i = 0; i < getBooskQuantity(); i++)
		{
			of << getBookId(i) << "\n";
			of << getBookInfo(i, 1).size() << " ";
			of << getBookInfo(i, 1) << "\n";
			of << getBookInfo(i, 2).size() << " ";
			of << getBookInfo(i, 2) << "\n";
			of << getBookYear(i) << "\n";
		}

		of.close();

		cout << getBooskQuantity() << " books was succeseful saved" << endl;

	}

	void loadLib()
	{
		int num;
		string s;
		ifstream ifs;

		ifs.open("library.inf");
		ifs >> num;
		cout << "Books was loaded: " << num << endl;

		book b;
		int n;
		for (int i = 0; i < num; i++)
		{
			ifs >> n;
			b.setId(n);
			for (int j = 0; j < 3; j++)
			{

				getline(ifs, s);
				if (j == 1)
					b.setName(s);
				if (j == 2)
					b.setAuthor(s);
				s = "";
			}

			ifs >> n;
			b.setYear(n);

 			books.push_back(b);
		}

		ifs.close();

	}

	void printLib()
	{
		for (int i = 0; i < getBooskQuantity(); i++)
		{
			cout << "Name: " << getBookInfo(i, 1) << endl;
			cout << "Author: " << getBookInfo(i, 2) << endl;
			cout << "Year: " << getBookYear(i) << endl;
		}
	}
};

int main()
{
	char c = '0';
	library l;
	//l.loadLib();

	do
	{
		cout << "Tyepe: e - exit, a - add new book, s - save, l - load, d - delete item" << endl;
		c = getchar();
		getchar();

		switch (c)
		{
			case 'a':
				l.addBook();
				break;
			case 's':
				l.saveLib();
				break;
			case 'l':
				l.loadLib();
				break;

		default:
			break;
		}

	} while (c != 'e');
	
	//system("pause");
	return 0;
}
