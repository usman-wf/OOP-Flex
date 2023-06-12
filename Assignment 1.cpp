//#include<iostream>
//#include<fstream>
//using namespace std;
//// Merges two arrays into one sorted array
//int* MergedArray( int size, int* ptr1, int* ptr2, int* Array,int*Endpoint1,int* Endpoint2)
//{
//	int* temp = Array;
//	int *temp1 = ptr1,* temp2 = ptr2;
//	// while both arrays have elements
//	while (temp1 < Endpoint1 && temp2 < Endpoint2)
//	{
//		if (*(temp1) < *(temp2))
//		{
//			*(temp) = *temp1;
//			temp1++;
//			temp++;
//		}
//		else if(*(temp1) > *(temp2))
//		{
//			*(temp) = *temp2;
//			temp++;
//			temp2++;
//		}
//		else if  (*temp1 == *temp2) // add both elements in the merged array
//		{
//		*temp = *temp1,
//		temp1++, temp++;
//		*temp = *temp2;
//		temp2++,temp++;
//		}
//	}
//	while (temp1 < Endpoint1)// add remaining elements from the first array
//	{
//		*temp = *temp1;
//		temp++;
//		temp1++;
//	}
//	while (temp2 < Endpoint2)// add remaining elements from the second array
//	{
//		*temp = *temp2;
//		temp++;
//		temp2++;
//	}
//	return Array;// return the merged and sorted array
//}
//void display(int* Array, int size) // displays the elements of the array
//{
//	if (size > 0)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << Array[i] << " ";
//		}
//		cout << endl;
//	}
//}
//// sorts the elements of the array using bubble sort
//void bubbleSort(int* ptr, int size)
//{
//	int i, j, temp;
//	for (i = 0; i < size - 1; i++)
//	{
//		for (j = 0; j < size - i - 1; j++)
//		{
//			if (*(ptr + j) > *(ptr + j + 1)) 
//			{
//				temp = *(ptr + j);
//				*(ptr + j) = *(ptr + j + 1);
//				*(ptr + j + 1) = temp;
//			}
//		}
//	}
//}
//// reads the size and elements of an array from a file
//int* input(fstream& data, int& size)
//{
//	int* ptr = 0;
//	data >> size;
//
//	if (size < 0)
//	{
//		data.close();
//		cout << "\nArray Size should be greater than zero \n";
//		ptr = 0;
//		return ptr;
//	}
//	else if (size > 0)
//	{
//		ptr = new int[size];
//		cout << endl;
//		for (int i = 0; i < size; i++)
//		{
//			data >> ptr[i];
//		}
//		display(ptr, size);		
//	}
//
//	return ptr;
//}
//
//int main()
//{
//	cout << "----------------------------------------Bubble Sort Result-----------------------------------------";
//	fstream data;
//	int size = 0;
//	int* final = 0;
//	int size1 = 0, size2 = 0;
//	int* Array = 0;
//	int* ptr1 = 0, * ptr2 = 0,*Endpoint1=0,*Endpoint2=0;
//	data.open("Data1.txt", ios::in);
//	for (int index = 0; index < 3; index++)
//	{
//		cout << endl << "Test case " << index + 1 << " : " << endl;
//		cout << "Array Before Sorting : ";
//		Array = input(data, size);
//		bubbleSort(Array, size);
//		cout << endl;
//		cout << "Sorted Array : \n";
//		display(Array, size);
//	}
//	delete[] Array;
//	Array = 0;
//	data.close();
//	cout << "----------------------------------------Merge Arrays Result-----------------------------------------";
//	cout << endl;
//	data.open("Data2.txt", ios::in);
//	// to test for 3 cases
//	for (int index = 0; index < 3; index++)
//	{
//		cout << endl << "Test case " << index + 1 << " : " << endl;
//		cout << "Array 1 :";
//		ptr1 = input(data, size1);
//		cout << "Array 2 :";
//		ptr2 = input(data, size2);
//		size = size1 + size2;
//		Array = new int[size];
//		Endpoint1 = ptr1 + size1;
//		Endpoint2 = ptr2 + size2;
//		cout << "\nSorted Array :";
//	    final =  MergedArray( size, ptr1, ptr2, Array, Endpoint1, Endpoint2);
//	    cout << endl;
//		display(final, size);
//	}
//	delete[] Array; // memory deallocation
//	data.close();
//	return 0;
//}

