//#include<iostream>
//using namespace std;
//
//class ComplexNumber
//{
//private:
//	int real;
//	int imaginary;
//public:
//	
//	ComplexNumber(int, int); //with default arguments 
//	void Input();
//	void Output();
//
//	ComplexNumber Conjugate();
//
//	bool IsEqual(ComplexNumber);
//
//	ComplexNumber Add(ComplexNumber);
//	
//	ComplexNumber Subtract(ComplexNumber);
//	
//	ComplexNumber Multiplication(ComplexNumber);
//	
//	float Magnitude();
//
//	float SquareRoot(float x);
//
//	//~ComplexNumber();
//};
//
//bool ComplexNumber :: IsEqual(ComplexNumber num)
//{
//	bool check = false;
//	if (real == num.real && imaginary == num.imaginary)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//ComplexNumber::ComplexNumber(int r=2, int i=3)
//{
//	real = r;
//	imaginary = i;
//
//}
//
//ComplexNumber ComplexNumber :: Multiplication(ComplexNumber c2)
//{
//	ComplexNumber mult;
//	
//	mult.real = (real * c2.real) + (imaginary * c2.imaginary * -1);
//	mult.imaginary = (real * c2.imaginary) + (c2.real * imaginary);
//
//		return mult;
//}
//
//ComplexNumber ComplexNumber::Subtract(ComplexNumber c2)
//{
//	ComplexNumber sub;
//	sub.real = real - c2.real;
//	sub.imaginary = imaginary - c2.imaginary;
//	return sub;
//}
//
//
//ComplexNumber ComplexNumber::Add(ComplexNumber c2)
//{
//	ComplexNumber add;
//	add.real = real + c2.real;
//	add.imaginary = imaginary + c2.imaginary;
//	return add;
//}
//
//ComplexNumber ComplexNumber :: Conjugate()
//{
//	ComplexNumber temp;
//	temp.real = real;
//	temp.imaginary = imaginary * (-1);
//	return temp;
//}
//
//float ComplexNumber::SquareRoot(float x)
//{
//	float guess = 1;
//
//	float result = (guess + x / guess) / 2;
//	int i = 0;
//	while (i < 10000)
//	{
//		result = (result + x / result) / 2;
//
//		i++;
//	}	
//	return result;
//}
//
//float ComplexNumber::Magnitude()
//{
//	float mg;
//	mg = (real * real) + (imaginary * imaginary);
//	mg=SquareRoot(mg);
//	return mg;
//}
//
//void ComplexNumber::Input()
//{
//	cout << "\nEnter real :\t";
//	cin >> real;
//	cout << "\nEnter imaginary :\t";
//	cin >> imaginary;
//}
//
//void ComplexNumber::Output()
//{
//	if(imaginary>0)
//	{
//		cout << " = " << real << " + " << imaginary << "i";
//	}
//	else
//	{
//		cout << " = " << real << " - " << -1 * imaginary << "i";
//	}
//}
//
//
////ComplexNumber :: ~ComplexNumber()
////{
////	cout << "\n Destructor Called for " << this << " :\t";
////}
//
//int main()
//{
//	cout << "Enter c1 ";
//	ComplexNumber c1;
//	c1.Input();
//	cout << endl;
//
//	cout << "Enter c2 ";
//	ComplexNumber c2;
//	c2.Input();
//	cout << endl;
//
//	cout << "c1";
//	c1.Output();
//	cout << endl;
//	cout << endl<<"c2";
//	c2.Output();
//	cout << endl;
//
//	cout << "------------------------------------------------------------------------------------------------------------\n";
//	bool check = 0;
//	check = c1.IsEqual(c2);
//	if (check == false)
//	{
//		cout << "\n c1 is not equal to c2 \n";
//	}
//	else if(check==true)
//	{
//		cout << "\n c1 is equal to c2 \n";
//	}
//
//	cout << "------------------------------------------------------------------------------------------------------------";
//	ComplexNumber conj;
//	cout<<endl << "Conjugate of c1 : ";
//	conj=c1.Conjugate();
//	conj.Output();
//	cout << "\n------------------------------------------------------------------------------------------------------------";
//	
//	cout << endl << "Conjugate of c2 : ";
//	conj = c2.Conjugate();
//	conj.Output();
//	cout << endl;
//
//	cout << "------------------------------------------------------------------------------------------------------------\n";
//	
//	ComplexNumber Add;
//	Add = c1.Add(c2);
//	cout << "c1 + c2 ";
//	Add.Output();
//	cout << "\n------------------------------------------------------------------------------------------------------------\n";
//
//	ComplexNumber sub;
//	sub = c1.Subtract(c2);
//	cout << "c1 - c2 ";
//	sub.Output();
//	cout << "\n------------------------------------------------------------------------------------------------------------\n";
//
//	ComplexNumber mult;
//	mult = c1.Multiplication(c2);
//	cout << "c1 * c2 ";
//	mult.Output();
//	cout << "\n------------------------------------------------------------------------------------------------------------\n";
//	
//	float mg;
//	mg = c1.Magnitude();
//	cout << "Magnitude of c1 = ";
//	cout << mg;
//	cout << "\n------------------------------------------------------------------------------------------------------------\n";
//
//	mg = c2.Magnitude();
//	cout << "Magnitude of c2 = ";
//	cout << mg;
//	cout << "\n------------------------------------------------------------------------------------------------------------\n";
//
//
//	return 0;
//}