#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

using namespace std;

namespace myString
{
	class Ms
	{

	public:

		//construct
		Ms();
		Ms(const char* input_cstring);//construct by a const string such as "abc"
		Ms(const char* input, size_t input_len);//construct string by the front n char
		~Ms();

		//length of a str
		size_t length() const;
		char* get_str() const; 

		// whether is empty
		bool empty() const;
		//const char *c_str();// return C style

		//read and write
		friend ostream& operator<<(ostream &os, Ms &ms);
		friend istream& operator>>(istream &is, Ms &ms);

		//add
		friend Ms operator+(const Ms &ms_f, const Ms &ms_s);

		//compare operate
		friend bool operator==(const Ms& ms_f, const Ms& ms_s);
		friend bool operator!=(const Ms& ms_f, const Ms& ms_s);
		friend bool operator>(const Ms& ms_f, const Ms& ms_s);
		friend bool operator<(const Ms& ms_f, const Ms& ms_s);
		friend bool operator>=(const Ms& ms_f, const Ms& ms_s);
		friend bool operator<=(const Ms& ms_f, const Ms& ms_s);

		//operator []
		char& operator[](const size_t location);
		const char& operator[](const size_t location) const;

		//assignment operator
		Ms& operator=(const Ms&);
		Ms& operator=(const char *);

		//append operator +=
		Ms& operator+=(const Ms&);

		//substring
		Ms substr(size_t begin, size_t end);




	private:
		char *cstring;
		size_t str_len;

	};

}



#endif