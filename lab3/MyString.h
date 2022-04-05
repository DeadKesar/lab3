#pragma once
#include "Vector.h"
class MyString :
    public Vector
{
private:
    char* array;
	int size;
	int length;
	void RestructString(int newSize);
	void MoreMemory();
	void MoreMemory(int size);
	void LessMemory();
	char* GetSubstring(char text[], int start, int size);
public:
	MyString();
	MyString(char arr[], int length);
	MyString(const char arr[]);
	~MyString();
	char& operator[](const int index);
	void Push(char elem);
	char Pop();
	void Clear();
	void Insert(char elem, int index);
	void Replace(char elem, int index);
	void AddRange(char* str, int length);
	



    bool EndsWith(MyString str);
	bool StartsWith(MyString str);
	int IndexOf(MyString str);
	MyString* Split(char separator);
	const char* GetStr();
};

