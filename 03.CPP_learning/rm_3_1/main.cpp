#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
	char* data;
public:
	MyString();
	MyString(const char* s);
	MyString(const MyString& s);
	~MyString();
	MyString& operator=(const MyString& s);
	MyString& operator=(const char* s);
	char& operator[] (size_t index);
	MyString operator+(const MyString& s) const;
	MyString operator+(const char* s) const;
	MyString& operator+=(const MyString& s);
	bool operator<(const MyString& s) const;
	bool operator==(const MyString& s) const;
	bool operator>(const MyString& s) const;
	MyString operator()(size_t start, size_t length)const;
	friend ostream& operator<<(ostream& out, const MyString& str);
};

MyString::MyString() :data(new char[1])
{
	data[0] = '\0';
}

MyString::MyString(const char* s)
{
	size_t len = strlen(s);
	data = new char[len + 1];
	strcpy(data, s);
}

MyString::MyString(const MyString& s)
{
	size_t len = strlen(s.data);
	this->data = new char[len + 1];
	strcpy(this->data, s.data);
}

MyString::~MyString()
{
	delete[]data;
}

MyString& MyString::operator=(const MyString& s)
{
	if (this != &s)
	{
		delete[] data;
		size_t len = strlen(s.data);
		this->data = new char[len + 1];
		strcpy(this->data, s.data);
	}
	return *this;
}

MyString& MyString::operator=(const char* s)
{
	delete[]data;
	size_t len = strlen(s);
	this->data = new char[len + 1];
	strcpy(data, s);
	return *this;
}

char& MyString:: operator[] (size_t index)
{
	return data[index];
}

MyString MyString::operator+(const MyString& s) const
{
	size_t len1 = strlen(data);
	size_t len2 = strlen(s.data);
	size_t len3 = len1 + len2+1;
	MyString s3;
	s3.data = new char[len3 + 1];
	strcpy(s3.data, data);
	strcat(s3.data, s.data);
	return s3;
}

bool MyString::operator<(const MyString& s) const
{
	return strcmp(data, s.data) < 0;
}

bool MyString::operator==(const MyString& s) const
{
	return strcmp(data, s.data) == 0;
}

bool MyString::operator>(const MyString& s) const
{
	return strcmp(data, s.data) > 0;
}

ostream& operator<<(ostream& out, const MyString& str)
{
	out << str.data;
	return out;
}

MyString MyString::operator()(size_t start, size_t length)const
{
	size_t len = strlen(data);
	if (start<0 || start>len)
	{
		return MyString("");
	}
	size_t n_len = (start + length <= len) ? length : len - start;
	char* temp = new char[n_len + 1];
	for (int i = 0; i < n_len; i++)
	{
		temp[i] = data[start + i];
	}
	temp[n_len] = '\0';
	MyString s3(temp);
	delete[]temp;
	return s3;
}

MyString MyString::operator+(const char* s) const
{
	size_t len = strlen(s) + strlen(data) + 1;
	char* temp = new char[len];
	strcpy(temp, data);
	strcat(temp, s);
	temp[len-1] = '\0';
	MyString s3(temp);
	delete[] temp;
	return s3;
}

MyString& MyString::operator+=(const MyString& s)
{
	size_t len = strlen(s.data)+strlen(data)+1;
	char* temp = new char[len];
	strcpy(temp, data);
	strcat(temp, s.data);
	temp[len-1] = '\0';
	delete[]data;
	data = temp;
	return *this;
}

MyString operator+(const char* s, const MyString& ms) {
	MyString temp(s);
	return temp + ms;  
}

int CompareString(const void* e1, const void* e2)
{
	MyString* s1 = (MyString*)e1;
	MyString* s2 = (MyString*)e2;
	if (*s1 < *s2)
		return -1;
	else if (*s1 == *s2)
		return 0;
	else if (*s1 > *s2)
		return 1;
}

int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; i++)
		cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}