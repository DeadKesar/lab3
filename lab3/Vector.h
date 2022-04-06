#pragma once
#include <exception> 



class Vector
{
private:
	int *array;
	int size;
	int length;
	void RestructVector(int newSize);
	void MoreMemory();
	void MoreMemory(int size);
	void LessMemory();
public:
	Vector(); 
	Vector(int arr[], int length);
	Vector(const Vector &vec);
	~Vector();
	int& operator[](const int index);
	void Push(int elem);
	int Pop();
	void Clear();
	void Insert(int num, int index);
	void Replace(int num, int index);
	void AddRange(int *arr, int length);

	int Length();
};

