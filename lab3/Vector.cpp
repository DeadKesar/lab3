#include "Vector.h"

//Private:
void Vector::RestructVector(int newSize)
{
	if (newSize < 8)
		newSize = 8;
	int* temp = new int[newSize];
	for (int i = 0; i < length; i++)
	{
		temp[i] = this->array[i];
	}
	delete[] this->array;
	this->array = temp;
	this->size = newSize;
}

void Vector::MoreMemory()
{
	if (size < 256)
	{
		RestructVector(size * 2);
	}
	else
	{
		if (size % 256 != 0)
		{
			size += size % 256;
		}
		RestructVector(size + 256);
	}
}
void Vector::MoreMemory(int size)
{
	if (this->size < size)
	{
		if (size > 256)
		{
			RestructVector(size + (256 - size % 256));
		}
		else
		{
			RestructVector(size);
		}
	}
}
void Vector::LessMemory()
{
	if (size > 8)
	{
		if (size < 256)
		{
			while (size / 2 > length)
			{
				size /= 2;
			}
			RestructVector(size);
		}
		else
		{
			RestructVector(length);
		}
	}
}
//public:
Vector::Vector() : size(8), length(0)
{
	this->array = new int[size];
}
Vector::Vector(int arr[], int length)
{
	this->array = new int[length];
	for (int i = 0; i < length; i++)
	{
		array[i] = arr[i];
	}
	this->length = length;
	this->size = length;
}
Vector::Vector(const Vector& vec)
{
	this->size = vec.size;
	this->length = vec.length;
	this->array = new int[this->size];
	for (int i = 0; i < length; i++)
	{
		this->array[i] = vec.array[i];
	}
}
Vector::~Vector()
{
	delete[] this->array;
}
int& Vector::operator[](const int index)
{
	if (index > length)
	{
		throw "index out of range";
	}
	return this->array[index];
}
void Vector::Push(int elem)
{
	if (this->size < length + 1)
	{
		this->MoreMemory();
	}
	this->array[length] = elem;
	length++;
}
int Vector::Pop()
{
	if (length <= 0)
	{
		throw "Vector is empty";
	}
	int temp = array[length - 1];
	if (((size < 256 && size / 2 >length) || (size - length > 256)) && (size > 8))
	{
		LessMemory();
	}
	length--;
	return temp;
}
void Vector::Clear()
{
	delete[] array;
	array = new int[8];
	size = 8;
	length = 0;
}
void Vector::Insert(int num, int index)
{
	if (index <= length)
	{
		if (size < length + 1)
		{
			MoreMemory();
		}
		int* temp = new int[this->size];
		for (int i = 0; i < index; i++)
		{
			temp[i] = this->array[i];
		}
		temp[index] = num;
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
void Vector::Replace(int num, int index)
{
	if (index < length)
	{
		this->array[index] = num;
	}
	else
	{
		throw "Index out of range";
	}
}
void Vector::AddRange(int* arr, int length)
{
	int point = this->length;
	if (this->size < this->length + length)
	{
		MoreMemory(this->length + length);
	}
	this->length += length;
	for (int i = point, j =0; i < this->length; i++, j++)
	{
		this->array[i] = arr[j];
	}
}
int Vector::Length()
{
	return this->length;
}
