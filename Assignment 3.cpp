//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//
//void DeallocateMemory(char** matrix)
//{
//	//Deallocate matrix space
//	
//	for (int i =0 ; matrix[i]!=NULL ; i++)
//	{
//		delete[] matrix[i];
//	}
//	delete[] matrix;
//	
//	matrix = 0;
//}
//
//void StringPaste(char* str1, char* str2, int length)
//{
//
//	for (int i = 0; i <= length; i++)
//	{
//		str1[i] = str2[i];
//	}
//	str1[length] = ' ';
//}
//
//int countWords(char** str)
//{
//	int words = 0;
//
//	for (int i = 0; str[i] != NULL; i++)
//	{
//		words++;
//		
//	}
//	return words;
//}
//
//void printString(char * str)
//{
//
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		cout << str[i];	
//	}
//}
//
//void print(char** tokens)
//{
//	for (int i = 0; tokens[i] != 0 ; i++)
//	{
//		cout <<  tokens[i];
//		cout << endl;
//	}
//
//}
//
//int getLength(char* name)
//{
//	int length = 0;
//	for (int i = 0; name[i] != '\0'; i++)
//	{
//		length++;
//	}
//	return length;
//}
//
//int getCount(char* arr, int index)
//{
//	int k = index;
//	int count = 0;
//	while (arr[k] != ' ')
//	{
//		count++;
//		k++;
//	}
//	return count ;
//}
//
//char** StringTokens(char* str)
//{
//	int count = 0;
//	char** tokens = 0;
//	int spaces = 0;
//	int n = 0;
//	int m = 0;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		if (str[i] == ' ')
//		{
//			spaces++;
//		}
//	}
//
//	tokens = new char*[spaces+1];
//	tokens[spaces + 1] = 0;
//
//	for (int i = 0; i <= spaces; i++)
//	{
//
//		count = getCount(str, n);
//		tokens[i] = new char[count + 1];
//		
//		for (int j = 0; j <= count; j++)
//		{
//			if (str[n] == ' ')
//			{
//				n++;
//				continue;
//			}
//			tokens[i][j] = str[n];
//			n++;
//		}
//		tokens[i][count] = '\0';
//	}
//		return tokens;
//}
//
//void swapping(char** arr, int spaces)
//{
//	char* temp = 0;
//	for (int i = 0; i <= (spaces / 2)+1; i++)
//	{
//		temp = arr[i];
//		arr[i] = arr[spaces];
//		arr[spaces] = temp;
//		spaces--;
//	}
//	temp = 0;
//}
//
//char** InverseStringTokens(char*str)
//{
//	int spaces = 0;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		if (str[i] == ' ')
//		{
//			spaces++;
//		}
//	}
//	cout << endl;
//	char** tokens = 0;
//	tokens = StringTokens(str);
//	swapping(tokens, spaces);
//	return tokens;
//}
//
//char* ReverseSentence(char* str)
//{
//	int num = 0,count=0,length=0;
//	int temp = getLength(str);
//	char * NewStr = new char [temp+1];
//	char** Tokens = InverseStringTokens(str);
//	num = countWords(Tokens);
//
//	for (int i = 0; i < num; i++)
//	{
//		length = getLength(Tokens[i]);
//		int temp = count + length;
//		char* ptr = 0;
//		ptr = Tokens[i];
//		for (int i = count,n=0; i < temp; i++,n++)
//		{
//			NewStr[i] = ptr[n];
//		}
//		count = count + length;
//		NewStr[count++] = ' ';
//	}
//	Tokens = 0;
//	NewStr[temp] = '\0';
//	return NewStr;
//}
//
//char* GetStringFromBuffer(char* buffer)  //reads from temp array
//{
//	int strLen = getLength(buffer);
//	char* str = 0;
//
//	if (strLen > 0)
//	{
//		str = new char[strLen + 1];
//		char* tempDest = str;
//
//		for (int i=0; i<strLen;  i++)
//		{
//			tempDest[i] = buffer[i];
//		}
//		tempDest[strLen] = '\0';
//	}
//	return str;
//}
//
//void StringConcatenate(char*&str1 ,char*&str2 )
//{
//	int length1 = getLength(str1);
//	int length2 = getLength(str2);
//	int size = length1 + length2;
//	char* temp = new char[size+1];
//	int n = 0;
//	for (int i = 0; i <= size; i++)
//	{
//		temp[i] = str1[i];
//
//		if (i==length1)
//		{
//			while (n < length2)
//			{
//				temp[i] = str2[n];
//				i++, n++;
//			}
//		}
//	}
//	temp[size] = '\0';
//	str1 = GetStringFromBuffer(temp);
//	delete[] temp;
//	temp = 0;
//}
//
//int CompareString(char* str1, char* str2)
//{
//	int check = 0;
//	int count = 0;
//	int length1 = getLength(str1);
//	int length2 = getLength(str2);
//	int length = 0;
//
//	if (length1 < length2)
//	{
//		length = length1;
//	}
//	else if (length1 > length2)
//	{
//		length = length2;
//	}
//	else 
//	{
//		length = length1;
//	}
//
//	char c1;
//	char c2;
//
//	for (int i = 0; i <= length; i++)
//	{
//		//ternary operators 
//		 c1 = str1[i] >= 'A' && str1[i] <= 'Z' ? str1[i] + 32 : str1[i];
//		 c2 = str2[i] >= 'A' && str2[i] <= 'Z' ? str2[i] + 32 : str2[i];
//
//		if ((str1[i]) < (str2[i])  )
//		{
//			return -1;
//		}
//		else if ((str2[i]) < (str1[i]))
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//char** SortedNames(char**str,int size)
//{
//	char** sorted = 0;
//	sorted = new char*[size+1];
//	int check = 0;
//
//	for (int i = 0; i <= size; i++)
//	{
//		sorted[i] = str[i];
//    }
//
//	for (int i = 0; i <= size-1; i++)
//	{
//		for (int j = i+1; j <= size; j++)
//		{
//			check = CompareString(sorted[i], sorted[j]);
//			if (check == 1)
//			{
//				char* temp = sorted[i];
//				sorted[i] = sorted[j];
//				sorted[j] = temp;
//			}
//			
//		}
//	}
//
//	return sorted;
//}
//
//void PrintAllNames(char** studentsList, int& size)
//{
//
//	for (int i = 0; i <= size; i++)
//	{
//		cout << studentsList[i] << endl;
//	}
//}
//
//char** ReadStudentsListFromFile(fstream& data, int size)
//{
//	char** names = 0;
//	int length = 0;
//	names = new char* [size];
//	for (int i = 0; i <= size; i++)
//	{
//		names[i] = new char[50];
//		data.getline(names[i], 50);
//		names[i] = GetStringFromBuffer(names[i]);
//	}
//	return names;
//}
//
//int main()
//{
//	fstream data;
//	char** tokens = 0;
//	char** sortedNames = 0;
//	int count = 0;
//	int check = 0;
//	char* str = 0;
//	char* str1 = 0,* str2 = 0;
//	char* cstring1 = 0, * cstring2 = 0;
//	int size;
//	data.open("Data.txt", ios::in);
//	char temp1[50], temp2[50];
//	cout << "Before concatenation : \n";
//	data.getline(temp1,50);
//	str1=GetStringFromBuffer(temp1);
//	cout << str1;
//	data.getline(temp2,50);
//	str2 = GetStringFromBuffer(temp2);
//	cout<<endl << str2;
//	cout << endl;
//	StringConcatenate( str1,str2 );
//	cout<<endl << "After concatenation : ";
//	cout << endl << str1;
//	cout << endl << str2;
//	cout << endl;
//	cout << "------------------------------------------------------------------------------------------------------------";
//	cout << endl;
//	tokens = StringTokens(str1);
//	print(tokens);
//	cout << "------------------------------------------------------------------------------------------------------------";
//	tokens = 0;
//	tokens = InverseStringTokens(str1);
//	print(tokens);
//	cout << "------------------------------------------------------------------------------------------------------------";
//	str = ReverseSentence(str1);
//	printString(str);
//	cout << endl;
//	cout << "------------------------------------------------------------------------------------------------------------";
//
//	cout << "\nEnter String 1 to compare : ";
//	cin.getline(temp1, 50);
//	str1 = GetStringFromBuffer(temp1);
//	cout << "\nEnter String 2 to compare : ";
//	cin.getline(temp2, 50);
//	str2 = GetStringFromBuffer(temp2);
//	check = CompareString(str1, str2);
//	if (check == 0)
//		cout << endl << "Strings are equal"<<endl;
//	else if (check == -1)
//		cout << endl << str2 << " is greater "<<endl;
//	else  if (check == 1)
//		cout << endl << str1 << " is greater"<<endl;
//	cout << "------------------------------------------------------------------------------------------------------------";
//
//	data >> size;
//	tokens = ReadStudentsListFromFile(data, size);
//	data.close();
//	
//	PrintAllNames(tokens, size);
//	cout << "------------------------------------------------------------------------------------------------------------";
//	cout << endl;
//
//	sortedNames = SortedNames(tokens, size);
//	PrintAllNames(sortedNames, size);
//	cout << "------------------------------------------------------------------------------------------------------------";
//
//	DeallocateMemory(tokens);
//	DeallocateMemory(sortedNames);
//	delete[] str;
//	delete[] str1;
//	delete[] str2;
//	delete[] cstring1;
//	delete[] cstring2;
//
//	str = 0;
//	str1 = 0;
//	str2 = 0;
//	cstring1 = 0;
//	cstring2 = 0;
//	tokens = 0;
//	sortedNames = 0;
//
//	return 0;
//}