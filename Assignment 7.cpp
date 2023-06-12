//#include<iostream>
//using namespace std;
//
//class MyString
//{
//	friend ostream& operator<<(ostream& out, MyString& obj);
//	friend istream& operator>>(istream& in, MyString& obj);
//	//You can add your code here
//private:
//
//	char* str=0;
//	int length=0; 
//	//not including the null char here
//	//Add GetStringFromBuffer as static private member (helper)
//	//Add Concatenate, CompareString as static private member (helper)
//	//You can add your class members here
//public:
//
//	//-------------DO_NOT_CHANGE REGION starts below---------------------
//	//Do not change the prototypes given below
//	MyString operator+(const MyString&);
//	MyString& operator=(const MyString&);
//	bool operator<(MyString&); //Comparison on the basis of ascii values
//	//-------------End of DO_NOT_CHANGE REGION---------------------
//	// 
//	//Add your class members here
//	
//	MyString()
//	{
//		length = 0;
//		str = 0;
//		str = new char[length + 1];
//		*str = '\0';
//	}
//
//	bool operator!()
//	{
//		if (length == 0 && *str == '\0')
//		{			
//		  return true;
//		}
//		else 
//		{
// 		 return false;
//		}
//	}	
//	
//	static int stringlength(char* str)
//	{
//		int length = 0;
//		for (int i = 0; str[i] != '\0'; i++)
//		{
//			length++;
//		}
//		return length;
//	}
//
//	static char* getstringfrombuffer(char* oldArr)
//	{
//
//		int strLen = stringlength(oldArr);
//		char* str = 0;
//
//		if (strLen > 0)
//		{
//			str = new char[strLen];
//			char* tempDest = str;
//
//			for (char* tempSrc = oldArr; *tempSrc != '\0'; tempSrc++, tempDest++)
//			{
//				*tempDest = *tempSrc;
//			}
//			*tempDest = '\0';
//		}
//		return str;
//	}
//
//	static MyString Concatenate(char* str1, char* str2)
//	{
//		MyString temp;
//		int length1 = MyString::stringlength(str1);
//		int length2 = MyString::stringlength(str2);
//		int size = length1 + length2 + 1;
//		cout << size;
//		temp.str = new char[size+1];
//		temp.length = size+1;
//		int index = 0;
//		while (index < length1)
//		{
//			temp.str[index] = str1[index];
//			index++;
//		}
//		int j = 0;
//		while (index < size)
//		{
//			temp.str[index] = str2[j];
//			index++, j++;
//		}
//		temp.str[size] = '\0';
//
//		return temp;
//	}
//
//	static bool Compare(char &str1, char& str2)
//	{
//		if (int(str1) < int(str2))
//		{
//			return 1;
//		}
//		else if (int(str2) < int(str1))
//		{
//			return 0;
//		}
//	}
//
//
//	char& operator[](int val)
//	{
//		return str[val];
//	}
//
//	char* operator()(int index, int strlength)
//	{
//		char* temp = 0;
//		int count = 0;	
//		
//		for (int i = index; str[i]!='\0' ; i++)
//		{
//			count++;
//		}
//		temp = new char[count];
//		int j = 0;
//		while (j < count)
//		{
//			temp[j] = str[index + j];
//			j++;
//		}
//		temp[j] = '\0';
//		return temp;
//	}
//
//	~MyString()
//	{
//		if (!str)
//		{
//			delete[] str;
//		}		
//	}
//
//};
//
// ostream& operator<<(ostream& out, MyString& obj)
//{
//	 out << obj.str;
//	 return out;
//}
//
//istream& operator>>(istream& in, MyString &obj)
// {
//	char temp[50];
//	in.getline(temp, 50);
//	obj.str = MyString::getstringfrombuffer(temp);
//	 return in;
// }
//
//MyString& MyString:: operator=(const MyString&obj)
//{
//	if (str != obj.str)
//	{
//		str=0;
//		length = MyString::stringlength(obj.str);
//		str = new char[length + 1];
//		for (int i = 0; i < length; i++)
//		{
//			str[i] = obj.str[i];
//		}
//		str[length] = '\0';
//	}
//	return *this;
//}
//
//MyString MyString::operator+(const MyString& rhs)
//{
//	MyString temp = Concatenate(str, rhs.str);
//	return temp;
//}
//
//bool MyString::operator<(MyString& rhs)
//{
//	bool check = 0;
//	int count = 0;
//	int length1 = MyString::stringlength(this->str);
//	int length2 = MyString::stringlength(rhs.str);
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
//	for (int i = 0; i < length; i++)
//	{
//	check = Compare(this->str[i], rhs.str[i]);
//	}
//	return 0;
//
//}
//
//
//
////--------------------------Add your code here----------------------
////-------------DO_NOT_CHANGE REGION starts below---------------------
//void main()
//{
//	MyString str1, str2, str3, str4; //Default constructor will make a string of lenght 0 but having null character(only) i.e.empty string
//		if (!str1)
//		{
//			cout << "String 1 is Empty.\n";
//			cout << "Str 1 = " << str1 << endl << endl << endl;
//		}
//	cout << "Enter String 1:\t";
//	cin >> str1;
//	cout << "Enter String 2:\t";
//	cin >> str2;
//	cout << "\n\n\nUser Entered:\n";
//	cout << "String 1 = " << str1 << endl;
//	cout << "String 2 = " << str2 << endl << endl << endl;
//	////What is following code testing?
//	cout << "Before str1 = str1; str1 = " << str1 << endl;
//	str1 = str1;
//	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;
//	cout << "Before str4 = str3 = str1+str2\n";
//	cout << "str1 = " << str1 << endl;
//	cout << "str2 = " << str2 << endl;
//	cout << "str3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//	str4 = str3 = str1 + str2;
//
//	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
//	cout << "str1 = " << str1 << endl;
//	cout << "str2 = " << str2 << endl;
//	cout << "str3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//
//	cout << "\n\n\nEnter String 3:\t";
//	cin >> str3;
//	cout << "\n\n\nEnter String 4:\t";
//	cin >> str4;
//	cout << "\n\n\nstr3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//	if (str3 < str4)
//		cout << "String 3 is Less than String 4.\n";
//	else
//		cout << "String 3 is NOT Less than String 4.\n";
//
//	MyString str5 = str1 + str2;
//	cout << "\n\n\nStr5:\t" << str5 << endl;
//	cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7).
//	str5[7] = '$';
//	cout << "\n\nStr5:\t" << str5 << endl;
//
//	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl; 
//	/*Substring of lenght 10
//	starting from index 5.Function Call str5.operator()(5, 10)
//	Let the returned MyString or char* leak*/
//}
////-------------End of DO_NOT_CHANGE REGION--------------------