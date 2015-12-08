#include "myString.h"

using namespace myString;

Ms::Ms():str_len(0),cstring(NULL){};
Ms::Ms(const char* input)
{
	if(NULL == input)
	{
		str_len = 0;
		cstring = NULL;
		return ;
	}

	str_len = strlen(input);
	cstring = new char[str_len+1];
	strcpy_s( cstring, str_len, input);

	++str_len;

	return;
}
Ms::Ms(const char* input, std::size_t len)
{
	if(NULL == input)
		return ;
	if( -1 == len )
	{
		Ms(input);
		return ;
	}
	str_len = len + 1;
	cstring = new char[len+1];
	strncpy(cstring, input, len);

	*(cstring + sizeof(char)*len) = '\0';

	return ;

}

Ms::~Ms()
{
	delete cstring;
	cstring = NULL;
	str_len = 0;

}

ostream& operator<<(ostream &os,Ms &ms)
{
	if(NULL != ms.get_str())
		os << ms.get_str() ;
	return os;
}
istream& operator>>(istream &is, Ms &ms)
{
	char* tmp = new char[100];
	size_t count = 0;
	while(is>>tmp)
	{
		++count ;

	}
	return is;
}

size_t Ms::length() const
{
	return str_len;
}
char* Ms::get_str() const
{
	return cstring;
}
bool Ms::empty() const
{
	if( (NULL == cstring) || (str_len <= 0))
		return true;
	else 
		return false;
}

Ms& Ms::operator=(const Ms& ms)
{
	char * tmp = new char[ms.length() +1];
	strcpy_s(tmp, ms.length()+1, ms.get_str());
	size_t len = ms.length();
	Ms ms_tmp(tmp);
	return ms_tmp;
}
Ms& Ms::operator=(const char * input)
{
	char * tmp = new char[strlen(input) +1];
	strcpy_s(tmp, strlen(input)+1, input);
	size_t len = strlen(input) + 1;
	Ms ms_tmp(tmp);
	return ms_tmp;
}

Ms operator+(const Ms &ms_f, const Ms &ms_s)
{
	Ms ms_tmp;
	if(NULL == ms_f.get_str() || NULL == ms_s.get_str() )
		return ms_tmp;
	char * str_tmp = new char[ms_f.length() + ms_s.length()+1];
	strcpy_s(str_tmp, ms_f.length(), ms_f.get_str());
	strcat_s(str_tmp, ms_f.length(), ms_s.get_str());
	ms_tmp = str_tmp;

	return ms_tmp;
}