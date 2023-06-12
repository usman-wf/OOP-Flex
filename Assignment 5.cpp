//#include<iostream>
//using namespace std;
//
//class ComplexNumber
//{
//private:
//	int* real;
//	int* imaginary;
//
//public:
//	
//	ComplexNumber(int, int); 
//	void Input();
//	void Output();
//	bool IsEqual(ComplexNumber);
//	ComplexNumber Conjugate();
//	ComplexNumber Add(ComplexNumber);
//	ComplexNumber Subtract(ComplexNumber);
//	ComplexNumber Multiplication(ComplexNumber);
//	float Magnitude();
//	const ComplexNumber& operator=(const ComplexNumber& rhs);
//	ComplexNumber(const ComplexNumber& rhs);
//	~ComplexNumber();
//	
//};
//
//ComplexNumber::ComplexNumber(const ComplexNumber& rhs)
//{
//    real = new int(*rhs.real);
//	imaginary = new int(*rhs.imaginary);
//}
//const ComplexNumber& ComplexNumber::operator=(const ComplexNumber& rhs)
//{
//	
//	if (&rhs != this)	
//	{
//		*real = *rhs.real;
//		*imaginary = *rhs.imaginary;
//	}
//	return *this;
//}
//
//ComplexNumber::ComplexNumber(int r = 2, int i = 3)
//{
//	real = new int(r);
//	imaginary = new int(i);
//}
//
//float ComplexNumber::Magnitude()
//{
//	float mg;
//	mg = (*real * *real) + (*imaginary * *imaginary);
//	mg=sqrt(mg);
//	return mg;
//}
//
//ComplexNumber ComplexNumber :: Multiplication(ComplexNumber c2)
//{
//	ComplexNumber mult;
//	
//	*mult.real = (*real * (*c2.real)) + (*imaginary * (*c2.imaginary) * -1);
//	*mult.imaginary = (*real * (*c2.imaginary)) + (*c2.real * (*imaginary));
//
//		return mult;
//}
//
//ComplexNumber ComplexNumber::Subtract(ComplexNumber c2)
//{
//	ComplexNumber sub;
//	*sub.real = *real - *c2.real;
//	*sub.imaginary = *imaginary - *c2.imaginary;
//	return sub;
//}
//
//ComplexNumber ComplexNumber::Add(ComplexNumber c2)
//{
//	ComplexNumber add;
//	*add.real = *real + *c2.real;
//	*add.imaginary = *imaginary + *c2.imaginary;
//	return add;
//}
//
//ComplexNumber ComplexNumber::Conjugate()
//{
//	ComplexNumber  temp;
//	*temp.real = *real;
//    *temp.imaginary = *imaginary * (-1);
//	return temp;
//}
//
//bool ComplexNumber :: IsEqual(ComplexNumber num)
//{
//	bool check = false;
//	if (*real == *num.real && *imaginary == *num.imaginary)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//
//void ComplexNumber::Input()
//{
//	cout << "\nEnter real :\t";
//	cin >> *real;
//	cout << "\nEnter imaginary :\t";
//	cin >> *imaginary;
//}
//
//void ComplexNumber::Output()
//{
//	if(*imaginary>0)
//	{
//		cout << " = " << *real << " + " << *imaginary << "i";
//	}
//	else
//	{
//		cout << " = " << *real << " - " << -1 * (*imaginary) << "i";
//	}
//}
//
// ComplexNumber :: ~ComplexNumber()
//{
//	//cout << "\n Destructor Called for " << this << " :\t";
//	delete[] real;
//	delete[] imaginary;
//	real = 0;
//	imaginary = 0;
//}
//
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
//	bool check = 0;
//	check = c1.IsEqual(c2);
//	if (check == false)
//	{
//		cout<<endl << "c1 is not equal to c2 \n";
//	}
//	else if (check == true)
//	{
//		cout<<endl << "c1 is equal to c2 \n";
//	}
//	cout << "\n------------------------------------------------------------------------------------------------------------";
//
//	ComplexNumber conj;
//	cout << endl << "Conjugate of c1 : ";
//	conj = c1.Conjugate();
//	conj.Output();
//	
//	cout << endl << "Conjugate of c2 : ";
//	conj = c2.Conjugate();
//	conj.Output();
//	cout << endl;
//	cout << "------------------------------------------------------------------------------------------------------------"<<endl;
//
//	ComplexNumber Add;
//	Add = c1.Add(c2);
//	cout << "c1 + c2 ";
//	Add.Output();
//	cout << "\n------------------------------------------------------------------------------------------------------------\n";
//
//    ComplexNumber sub;
//	sub = c1.Subtract(c2);
//	cout << "c1 - c2 ";
//	sub.Output();
//	
//
//	ComplexNumber mult;
//	mult = c1.Multiplication(c2);
//	cout << "\tc1 * c2 ";
//	mult.Output();
//	
//
//	float mg;
//	mg = c1.Magnitude();
//	cout << "\tMagnitude of c1 = ";
//	cout << mg;
//	cout << "\n------------------------------------------------------------------------------------------------------------\n";
//
//	mg = c2.Magnitude();
//	cout << "Magnitude of c2 = ";
//	cout << mg;
//	
//	return 0;
//}