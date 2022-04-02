#pragma once



class Vector
{
private:
	int array[8];
	int size;
	int length;
	void FillArray(int *array, int length)
	{
		for (int i = 0; i < length; i++)
		{
			this->array[i] = array[i];
		}
	}
	void MoreMemory()
	{
		if (size < 256)
		{
			size *= 2;
			int *temp = new int[size]();
		}
		else
		{
			size += 256;
			int* temp = new int[size]();
		}
	}
	void MoreMemory(int dopSize)
	{
		size += dopSize;
		int* temp = new int[size]();
	}
	void LessMemory()
	{
		if (size < 256)
		{
			if (size / 2 > length);
		}
		if (size - length < 256)
		{

		}
	}

public:
	Vector() :size(8), length(0)
	{}
	Vector(int arr[], int length)
	{
		
	}
	int operrator[];



};

