#pragma once
#include "MyString.h"
//private:

void MyString::RestructString(int newSize)
{
	if (newSize < 8)
		newSize = 8;
	char* temp = new char[newSize];
	for (int i = 0; i < length; i++)
	{
		temp[i] = this->string[i];
	}
	temp[length] = '\0';
	this->string = temp;
	this->size = newSize;
}

void MyString::MoreMemory()
{
	if (size < 256)
	{
		RestructString(size * 2);
	}
	else
	{
		if (size % 256 != 0)
		{
			size += size % 256;
		}
		RestructString(size + 256);
	}
}
void  MyString::MoreMemory(int size)
{
	if (this->size < size)
	{
		if (size > 256)
		{
			RestructString(size + (256 - size % 256));
		}
		else
		{
			RestructString(size);
		}
	}
}
void  MyString::LessMemory()
{
	if (size > 8)
	{
		if (size < 256)
		{
			while (size / 2 > length+1)
			{
				size /= 2;
			}
			RestructString(size);
		}
		else
		{
			RestructString(length+1);
		}
	}
}
char* MyString::GetSubstring(char text[], int start, int size)
{
	char* str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		str[i] = text[i + start];
	}
	str[size] = '\0';
	return str;
}
//public:
void MyString::Reverse()
{
	char* temp = new char[this->size];
	for (int i = 0, j = this->length-1; i < this->length; i++, j--)
	{
		temp[i] = this->string[j];
	}
	temp[length] = '\0';
//	delete[] this->string;
	this->string = temp;
}
											
MyString::MyString() : size(8), length(0)
{
	this->string = new char[size];
}
MyString::MyString(const char arr[], int length)
{
	this->string = new char[length+1];
	for (int i = 0; i < length; i++)
	{
		string[i] = arr[i];
	}
	this->length = length;
	this->string[length] = '\0';
	this->size = length+1;
}
MyString::MyString(const char arr[])
{
	int count = 0;
	while (arr[count] != '\0')
	{
		count++;
	}
	RestructString(count+1);
	for (int i = 0; i < count; i++)
	{
		this->string[i] = arr[i];
	}
	this->length = count;
	this->string[count] = '\0';
}
MyString::~MyString()
{
	delete[] string;
}

char& MyString::operator[](const int index)
{
	if (index > length)
	{
		throw "index out of range";
	}
	return this->string[index];
}
void MyString::Push(char elem)
{
	if (this->size < length + 1)
	{
		this->MoreMemory();
	}
	this->string[length]  =elem;
	this->string[length+1] = '\0';
	length++;
}
char MyString::Pop()
{
	if (length <= 0)
	{
		throw "Vector is empty";
	}
	char temp = string[length - 1];
	if (((size < 256 && size / 2 >length) || (size - length > 256)) && (size > 8))
	{
		LessMemory();
	}
	length--;
	return temp;
}
void MyString::Clear()
{
	delete[] string;
	string = new char[8];
	size = 8;
	length = 0;
}
void MyString::Insert(char elem, int index)
{
	if (index <= length)
	{
		if (size < length + 1)
		{
			MoreMemory();
		}
		char* temp = new char[this->size];
		for (int i = 0; i < index; i++)
		{
			temp[i] = this->string[i];
		}
		temp[index] = elem;
		for (int i = index + 1; i < length + 1; i++)
		{
			temp[i] = this->string[i - 1];
		}
		length++;
		delete[] this->string;
		string = temp;
	}
	else
	{
		throw "Index out of range";
	}
}
void MyString::Replace(char elem, int index)
{
	if (index < length)
	{
		this->string[index] = elem;
	}
	else
	{
		throw "Index out of range";
	}
}
void MyString::AddRange(const char* arr, int length)
{
	int point = this->length;
	if (this->size < this->length + length+1)
	{
		MoreMemory(this->length + length+1);
	}
	this->length += length;
	for (int i = point, j = 0; i < this->length; i++, j++)
	{
		this->string[i] = arr[j];
	}
	this->string[this->length] = '\0';
}
bool MyString::EndsWith(MyString &str)
{
	if (str.length > this->length)
	{
		return false;
	}
	for (int i = str.length - 1; i >= 0; i--)
	{
		if (this->string[this->length - str.length + i] != str[i])
		{
			return false;
		}
	}
	return true;
}
bool MyString::StartsWith(MyString &str)
{
	if (str.length > this->length)
	{
		return false;
	}
	for (int i = 0; i < str.length; i++)
	{
		if (this->string[i] != str[i])
		{
			return false;
		}
	}
	return true;
}
int MyString::IndexOf(MyString &str)
{
	if (this->length < str.length)
		return -1;
	for (int i = 0; i <= this->length - str.length; i++)
	{
		if (this->string[i] == str[0])
		{
			bool isSame = true;
			for (int j = 0; j < str.length; j++)
			{
				if (string[i + j] != str[j])
				{
					isSame = false;
					break;
				}
			}
			if (isSame)
			{
				return i;
			}
		}
	}
	return -1;
}
MyStringCollection* MyString::Split(char separator)
{
	if (this->length < 2)
		return nullptr;
	int count = 0;
	for (int i = 1; i < length - 1; i++)
	{
		if (this->string[i] == separator && this->string[i - 1] != separator)
		{
			count++;
		}
	}
	if (this->string[this->length - 2] == separator && this->string[this->length - 1] == separator)
	{
		count--;
	}
	if (count <= 0)
	{
		return nullptr;
	}
	if (this->string[this->length - 1] != separator)
		count++;
	MyString* answer = new MyString[count];
	int index = 0;
	int start = 0, len = 0;
	for (int i = 1; i < this->length; i++)
	{	
		if (this->string[start] == separator)
		{
			start++;
		}
		if (this->string[i] == separator && this->string[i-1] != separator)
		{
			len = i - start;
			answer[index] = *(new MyString(GetSubstring(this->string, start, len),len));
			start = i + 1;
			index++;
		}
	}
	if (this->string[this->length] != separator && index < count)
	{
		answer[index] = *(new MyString(GetSubstring(this->string, start, this->length), this->length));
	}
	MyStringCollection* answ = new MyStringCollection(answer, count);
	return answ;
}
const char* MyString::GetStr()
{
	return this->string;
}
int MyString::Length()
{
	return this->length;
}

MyStringCollection::MyStringCollection(MyString* arr, int length)
{
	this->collection = arr;
	this->length = length;
}
MyStringCollection::~MyStringCollection()
{
	for (int i = 0; i < length; i++)
	{
		delete[] &collection[i];
	}
	delete[] collection;
}
void MyString::GetInput()
{

	bool isNotEnd = true;
	while (isNotEnd)
	{
		MyString *str = new MyString();
		char ch = ' ';
		while (ch != '\n')
		{
			ch = std::getchar();
			if (ch == '\n')
			{
				isNotEnd = false;
				continue;
			}
			str->Push(ch);
		}
		this->RestructString(str->size);
		for (int i = 0; i < str->length; i++)
		{
			this->string[i] = str->string[i];
		}
		this->length = str->length;
		this->string[length] = '\0';

	}
}

