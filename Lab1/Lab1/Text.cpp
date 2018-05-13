/*Sayem Chowhury (fr9838)
Computer Science (II) Lab (1)
*/

/*Adding a comment to see it also change in resporitory */


#include<cctype>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

Text::Text ( const char* charSeq ) // defination of default constructor
{
	bufferSize = strlen(charSeq);
	buffer = new char[bufferSize+1]; 
	strcpy(buffer,charSeq);   

}

Text::Text ( const Text &other )// defination of copy constructor
{

	bufferSize = other.bufferSize;
	buffer = new char[bufferSize+1]; 
	strcpy(buffer, other.buffer);

}

void Text::operator =  (const Text &other)  // defination overloading assignment operator
{
	if (this!= &other)
	{
		delete[] buffer; 
		bufferSize = other.bufferSize;
		buffer = new char[bufferSize+1];
		strcpy(buffer, other.buffer);
		
	}
	
}

Text::~Text () //Destructor
{
	delete[] buffer; 
}

int Text::getLength () const
{
	return strlen(buffer); // return the length of the string 
						   // excluding the null character
} 

char Text::operator [] (int n) const
{
	{
		if (0 <= n && n < bufferSize)
			return buffer[n];
		else
		{
			cout << "Index out of bound" << endl;
			return -1;
		}
	}
}

void Text::clear ()
{

	buffer[0]='\0'; // copied a null string into the string buffer at the position 0 
	//
	bufferSize = 0;

}

void Text::showStructure() const

// Outputs the characters in a string. This operation is intended for
// testing/debugging purposes only.

{
	int j;   // Loop counter

	for (j = 0; j < bufferSize; j++)
		cout << j << "\t";
	cout << endl;
	for (j = 0; buffer[j] != '\0'; j++)

		cout << buffer[j] << "\t";
	cout << "\\0" << endl;
}

Text Text::toUpper( ) const
{
	Text temp; 
	temp =*this;   
	for (int i = 0; i < temp.bufferSize; i++)
	{
		temp.buffer[i]=static_cast<char>(toupper(temp.buffer[i]));
	}

	return temp;
}

Text Text::toLower( ) const
{
	Text temp;
	
	temp = *this;
	for (int i = 0; i < temp.bufferSize; i++)
	{
		temp.buffer[i]=static_cast<char>(tolower(temp.buffer[i]));
	}

	return temp;
}

bool Text::operator == ( const Text& other ) const
{
	char*p1;
	p1 = buffer;
	char *q1;
		q1= other.buffer;
		//return(p1 == q1);
		if (strcmp(p1, q1) == 0)
			return 1;
		else
			return 0;

}

bool Text::operator <( const Text& other ) const
{
	char*p1;
	p1 = buffer;
	char *q1;
	q1 = other.buffer;
	//return(p1 < q1);
	if (strcmp(p1, q1) < 0)
		return 1;
	else
		return 0;
}

bool Text::operator> ( const Text& other ) const 
{
	char*p1;
	p1 = buffer;
	char *q1;
	q1 = other.buffer;
	//return(p1 > q1);
	
	if (strcmp(p1, q1) > 0)
		return 1;
	else
		return 0;
}






