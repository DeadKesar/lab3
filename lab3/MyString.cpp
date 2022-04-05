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
		temp[i] = this->array[i];
	}
	delete[] this->array;
	this->array = temp;
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
			while (size / 2 > length)
			{
				size /= 2;
			}
			RestructString(size);
		}
		else
		{
			RestructString(length);
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
MyString::MyString() : size(8), length(0)
{
	this->array = new char[size];
}
MyString::MyString(char arr[], int length)
{
	this->array = new char[length];
	for (int i = 0; i < length; i++)
	{
		array[i] = arr[i];
	}
	this->length = length;
	this->size = length;
}
MyString::MyString(const char arr[])
{
	int count = 0;
	while (arr[count] != '\0')
	{
		count++;
	}
	RestructString(count);
	for (int i = 0; i < count; i++)
	{
		this->array[i] = arr[i];
	}
	length = count;
}
MyString::~MyString()
{
	delete[] this->array;
}

char& MyString::operator[](const int index)
{
	if (index > length)
	{
		throw "index out of range";
	}
	return this->array[index];
}
void MyString::Push(char elem)
{
	if (this->size < length + 1)
	{
		this->MoreMemory();
	}
	this->array[length] = elem;
	length++;
}
char MyString::Pop()
{
	if (length <= 0)
	{
		throw "Vector is empty";
	}
	char temp = array[length - 1];
	if (((size < 256 && size / 2 >length) || (size - length > 256)) && (size > 8))
	{
		LessMemory();
	}
	length--;
	return temp;
}
void MyString::Clear()
{
	delete[] array;
	array = new char[8];
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
			temp[i] = this->array[i];
		}
		temp[index] = elem;
		for (int i = index + 1; i < length + 1; i++)
		{
			temp[i] = this->array[i - 1];
		}
		length++;
		delete[] this->array;
		array = temp;
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
		this->array[index] = elem;
	}
	else
	{
		throw "Index out of range";
	}
}
void MyString::AddRange(char* arr, int length)
{
	int point = this->length;
	if (this->size < this->length + length)
	{
		MoreMemory(this->length + length);
	}
	this->length += length;
	for (int i = point, j = 0; i < this->length; i++, j++)
	{
		this->array[i] = arr[j];
	}

}
bool MyString::EndsWith(MyString str)
{
	if (str.length > this->length)
	{
		return false;
	}
	for (int i = str.length - 1; i >= 0; i--)
	{
		if (this->array[this->length - str.length + i] != str[i])
		{
			return false;
		}
	}
	return true;
}
bool MyString::StartsWith(MyString str)
{
	if (str.length > this->length)
	{
		return false;
	}
	for (int i = 0; i > str.length; i++)
	{
		if (this->array[i] != str[i])
		{
			return false;
		}
	}
	return true;
}
/*
int MyString::IndexOf(MyString str)
{
	if (this->length < str.length)
		return -1;
	for (int i = 0; i <= this->length - str.length; i++)
	{
		if (this->array[i] == str[0])
		{
			bool isSame = true;
			for (int j = 0; j < str.length; j++)
			{
				if (array[i + j] != str[j])
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
	*/
MyString* MyString::Split(char separator)
{
	if (this->length < 2)
		return nullptr;
	int count = 0;
	for (int i = 1; i < length - 1; i++)
	{
		if (this->array[i] == separator && this->array[i - 1] != separator)
		{
			count++;
		}
	}
	if (this->array[this->length - 2] == separator && this->array[this->length - 1] == separator)
	{
		count--;
	}
	if (count <= 0)
	{
		return nullptr;
	}
	if (this->array[this->length - 1] != separator)
		count++;
	MyString* answer = new MyString[count];
	count = 0;
	int start = 0, len = 0;
	for (int i = 1; i < this->length; i++)
	{	
		if (this->array[start] = separator)
		{
			start++;
		}
		if (this->array[i] == separator && this->array[i-1] != separator)
		{
			len = i - start;
			answer[count] = *(new MyString(GetSubstring(this->array, start, len),len));
			start = i + 1;
		}
	}
	return answer;
}
const char* MyString::GetStr()
{
	return this->array;
}