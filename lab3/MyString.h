#pragma once
#include "Vector.h"

class MyString;
struct MyStringCollection
{
	MyString* collection;
	int length;
	MyStringCollection(MyString* arr, int length);
	~MyStringCollection();
};

class MyString :
    public Vector
{
private:
    char* string;
	int size;
	int length = 0;
	void RestructString(int newSize);
	void MoreMemory();
	void MoreMemory(int size);
	void LessMemory();
	char* GetSubstring(char text[], int start, int size);
public:
	void Reverse();
	MyString();
	MyString(const char arr[], int length);
	MyString(const char arr[]);
	~MyString();
	char& operator[](const int index);
	void Push(char elem);
	char Pop();
	void Clear();
	void Insert(char elem, int index);
	void Replace(char elem, int index);
	void AddRange(const char* str, int length);
	int Length();



    bool EndsWith(MyString &str);
	bool StartsWith(MyString &str);
	int IndexOf(MyString &str);
	MyStringCollection* Split(char separator);
	const char* GetStr();
};

