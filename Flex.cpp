#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class helper
{
public:

	static int stringlength(char* str)
	{
		int length = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			length++;
		}
		return length;
	}

	static void stringcopy(char*& dest , char *& src)
	{
		int length = stringlength(src);
		dest = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			dest[i] = src[i];
		}
		dest[length] = '\0';

	}

	static char* getstringfrombuffer(char* oldArr)
	{

		int strLen = stringlength(oldArr);
		char* str = 0;

		if (strLen > 0)
		{
			str = new char[strLen];
			char* tempDest = str;

			for (char* tempSrc = oldArr; *tempSrc != '\0'; tempSrc++, tempDest++)
			{
				*tempDest = *tempSrc;
			}
			*tempDest = '\0';
		}
		return str;
	}
};

class evalreport
{	
	friend void UpdateStatistics(evalreport* std, int count);
private:

	char rollnum[9];//8 digit roll num, 1 space for \0
	char* fname = 0;     //for first name
	char* lname = 0;     //for last name
	int index = 0;

	int grandtotal = 0; // stores the grand total of the students
	int* quizmarks = 0; // array to store obtained numbers in quizes
	int* asgmarks = 0; // array to store obtained numbers in assignments
	int total = 0;
	int* tot = 0;

	static int occur;
	static int totalstudents;
	static int* maxasg;
	static int* maxquiz;
	static int* minasg;
	static int* minquiz;
	static int  avg;
	static int totalquiz;
	static int totalasg;
	static int* maxofquiz;
	static int* maxofasg;
	static char* str;
	static int* totalOfasg;
	static int* totalOfquiz;

public:

	evalreport()
	{		
		fname = 0;
		lname = 0;
		total = 0;
	}

	evalreport(evalreport& rhs)
	{

		for (int i = 0; i < 8; i++)
		{
			rollnum[i] = rhs.rollnum[i];
		}
		//rollnum[8] = '\0';
		int temp = 0;
		for (int i = 0; rhs.fname[i] != '\0'; i++)
		{
			temp++;
		}
		if (fname != rhs.fname)
		{

			this->fname = new char[temp + 1];

		}
		helper::stringcopy(fname, rhs.fname);

		temp = helper::stringlength(rhs.lname);
		if (lname != rhs.lname)
		{

			this->lname = new char[temp + 1];

		}
		helper::stringcopy(lname, rhs.lname);
		
		quizmarks = new int[totalquiz];
		for (int i = 0; i < totalquiz; i++)
		{
			quizmarks[i] = rhs.quizmarks[i];
		}

		asgmarks = new int[totalasg];
		for (int i = 0; i < totalasg; i++)
		{
			asgmarks[i] = rhs.asgmarks[i];
		}

		total = rhs.total;
	}

	evalreport& operator=( evalreport& rhs)
	{
		for (int i = 0; i< 8; i++)
		{
			rollnum[i] = rhs.rollnum[i];
		}
		
		int temp = 0; 
		

		for (int i = 0; rhs.fname[i] != '\0'; i++)
		{
			temp++;
		}
		if (fname != rhs.fname)
		{ 
			
			this->fname = new char[temp + 1];
			
		}
		helper::stringcopy(fname,rhs.fname);

		temp = helper::stringlength(rhs.lname);
		if (lname != rhs.lname)
		{
			
			this->lname = new char[temp + 1];
			
		}
		helper::stringcopy(lname, rhs.lname);

			//delete[] quizmarks;
		quizmarks = new int[totalquiz];		
		for (int i = 0; i < totalquiz; i++)
		{
			quizmarks[i] = rhs.quizmarks[i];
		}

		//delete[] asgmarks;
		asgmarks = new int[totalasg];
		for (int i = 0; i < totalasg; i++)
		{
			asgmarks[i] = rhs.asgmarks[i];
		}

		// Copy total
		total = rhs.total;

		return *this;
	}

	static char* getstr()
	{
		return str;
	}
	static int gettotalstudents()
	{
		return totalstudents;
	}
	static int* getmaxasg()
	{
		return maxasg;
	}
	static int* getmaxquiz()
	{
		return maxquiz;
	}
	static int* getminasg()
	{
		return minasg;
	}
	static int* getminquiz()
	{
		return minquiz;
	}
	static int getavg()
	{
		return avg;
	}
	static int gettotalquiz()
	{
		return totalquiz;
	}
	static int gettotalasg()
	{
		return totalasg;
	}
	int gettotal()
	{
		return total;
	}
	int getindex()
	{
		return index;
	}
	static int* getmaxofquiz()
	{
		return maxofquiz;
	}
	static int* getmaxofasg()
	{
		return maxofasg;
	}
	static int* gettotalOfquiz()
	{
		return totalOfquiz;
	}
	static int* gettotalOfasg()
	{
		return totalOfasg;
	}
	static int getoccur()
	{
		return occur;
	}

	static void setoccur(int occurences)
	{
		occur = occurences;
	}
	void settotal(int markstotal)
	{
		total = markstotal;
	}
	void setindex(int i)
	{
		index = i;
	}
	static void settotalstudents(int count)
	{
		totalstudents = count;
	}
	static void setmaxasg(int* max)
	{
		maxasg = max;
	}
	static void setmaxquiz(int* max)
	{
		maxquiz = max;
	}
	static void settotalOfasg(int* tot)
	{
		totalOfasg = tot;
	}
	static void settotalOfquiz(int* tot)
	{
		totalOfquiz = tot;
	}
	static void setminasg(int* min)
	{
		minasg = min;
	}
	static void setminquiz(int* min)
	{
		minquiz = min;
	}
	static void setavg(int avg)
	{
		avg = avg;
	}
	static void settotalasg(int total)
	{
		totalasg = total;
	}
	static void settotalquiz(int total)
	{
		totalquiz = total;
	}
	static void setmaxofasg(int* max)
	{
		maxofasg = max;
	}
	static void setmaxofquiz(int* max)
	{
		maxofquiz = max;
	}
	static void setstr(char* ptr)
	{
		helper::stringcopy(str, ptr);
	}

	void display(evalreport* ptr, int count);
	void detailview();
	bool StudentInfo(evalreport* std);
	void FindStudent(evalreport* std, char search[]);
	evalreport** SearchStudentsByKeyword(evalreport* std);

	void readdatafromfile(ifstream& fin)
	{
		int numquiz = 0, numasg = 0;
		numquiz = this->gettotalquiz();
		//cout << numquiz;
		numasg = this->gettotalasg();
		//cout << endl << numasg;
		int total = 0;
		char temp[20];

		fin >> rollnum;
		rollnum[8] = '\0';
		fin >> temp;
		fname = helper::getstringfrombuffer(temp);

		fin >> temp;
		lname = helper::getstringfrombuffer(temp);

		quizmarks = new int[numquiz];
		asgmarks = new int[numasg];

		for (int i = 0; i < numquiz; i++)
		{
			fin >> quizmarks[i];
			
		}

		for (int i = 0; i < numasg; i++)
		{
			fin >> asgmarks[i];
			
		}

	}

	bool keywordMatch()
	{
		int length = helper::stringlength(str);		
		bool check = false;
		int compare = 0;
		for (int i = 0; rollnum[i] != '\0'; i++)
		{
			if ( rollnum[i] == str[compare])
			{
				int temp = i;
				while (rollnum[temp] == str[compare])
				{
					check = true;
					temp++, compare++;
					if (compare == length)
					{
						return true;
					}		

				}
				check = false;
			}
			compare = 0;
	    }

		for (int i = 0; fname[i] != '\0'; i++)
		{
			if (fname[i] == str[compare])
			{
				int temp = i;
				while (fname[temp] == str[compare])
				{
					check = true;
					temp++, compare++;
					if (compare == length)
					{
						return true;
					}

				}
				check = false;
			}
			compare = 0;
		}
		for (int i = 0; lname[i] != '\0'; i++)
		{
			if (lname[i] == str[compare])
			{
				int temp = i;
				while (lname[temp] == str[compare])
				{
					check = true;
					temp++, compare++;
					if (compare == length)
					{
						return true;
					}

				}
				check = false;
			}
			compare = 0;
		}
		return check;
	}

	~evalreport()
	{
		if (fname!=0)
		{
			delete[] fname;
			fname = 0;
		}
		if (lname!=0)
		{
			delete[] lname;
			lname = 0;
		}
		if (quizmarks!=0)
		{
			delete[] quizmarks;
			quizmarks = 0;
		}
		if (asgmarks!=0)
		{
			delete[] asgmarks;
			asgmarks = 0;
		}
	}

	void deallocateStatic()
	{
		delete[] maxasg;
		maxasg = 0;
		delete[] minasg;
		minasg = 0;
		delete[] maxquiz;
		maxquiz = 0;
		delete[] minquiz;
		minquiz = 0;
		delete[] maxofasg;
		maxofasg = 0;
		delete[] maxofquiz;
		maxofquiz = 0;
		delete[] str;
		str = 0;
		totalOfasg = 0;
		totalOfquiz = 0;
	}

	void PrintAll(evalreport** matrix)
	{
		for (int i = 0; matrix[i] != NULL; i++)
		{
			cout << matrix[i]->rollnum << "   " << matrix[i]->fname << " " << matrix[i]->lname << "\t";
			int temp = gettotalquiz();
			for (int z = 0; z < temp; z++)
			{
				cout << matrix[i]->quizmarks[z] << "\t";
			}
			temp = gettotalasg();
			for (int l = 0; l < temp; l++)
			{
				cout << matrix[i]->asgmarks[l] << "\t";
			}
			cout << matrix[i]->total;
			cout << endl;
		}
	}

	void PrintSingle()
	{	
		int  total = 0;
		cout << rollnum << "\t" << fname << " " <<lname << "\t";
		int numquiz = 0, numasg = 0;
		numquiz = gettotalquiz();
		numasg = gettotalquiz();
		for (int n = 0; n < numquiz; n++)
		{
			cout <<quizmarks[n] << "\t";
			total = total + quizmarks[n];
		}

		for (int n = 0; n < numasg; n++)
		{
			cout <<asgmarks[n] << "\t";
			total = total + asgmarks[n];
		}
		total = total;
		cout << " " << total;
		settotal(total);
	}

	int StudentInfo()
	{
		int length = helper::stringlength(evalreport::getstr());
		int count = evalreport::gettotalstudents();
		int compare = 0;
		if (rollnum[compare] == evalreport::str[compare])
		{
			for (int n = 0; n < length; n++)
			{
				if (rollnum[compare] == evalreport::str[compare])
				{
					compare++;
				}
				else
				{
					return -1;
				}
			}
			if (compare == length)
			{
				return 1;
				
			}
		}
	}
			
};

void evalreport::detailview()
{
	cout << endl;
	cout << "Roll-No :\t" << rollnum;
	cout << endl << "Name :\t" << fname << " " << lname << endl;
	cout << "Quiz Marks :\n";
	int QuizNum = 0, AsgNum = 0;
	QuizNum = evalreport::gettotalquiz();
	AsgNum = evalreport::gettotalasg();
	int num = 1;
	int tot = 0;

	for (int i = 0; i < QuizNum; i++)
	{
		int* temp = evalreport::gettotalOfquiz();
		cout << "\tQ" << num << ":\t " << this->quizmarks[i] << "/" << temp[i];
		num++;
		tot = tot + quizmarks[i];
		cout << endl;
	}
	num = 1;
	for (int i = 0; i < AsgNum; i++)
	{
		int* temp2 = evalreport::gettotalOfasg();
		cout << "\tA" << num << ":\t " << this->asgmarks[i] << "/" << temp2[i];
		num++;
		tot = tot + asgmarks[i];
		cout << endl;
	}
	cout << endl;
	cout << "Total :\t\t\t " << tot;
}

void StudentInfo(evalreport* std,int count)
{
	char temp[] = "15L-1234";
	cout << endl;
	cout << "Enter Student Roll Number: " << temp;
	evalreport::setstr(temp);
	int check;
	int compare = 0;
	check = -1;
	for (int i = 0; i < count; i++)
	{
		check = std[i].StudentInfo();
		if (check == 1)
		{
			std[i].detailview();
			break;
		}
		check = -1;
	}
	if (check == -1)
	{
		cout << endl << "Student not found ";
	}
	check = -1;

	char temp2[] = "15L-4023";
	cout << "\nEnter Student Roll Number: " << temp2;
	evalreport::setstr(temp2);
	
	for (int i = 0; i < count; i++)
	{
		check = std[i].StudentInfo();
		if (check == 1)
		{
			std[i].detailview();
			break;
		}
	}
	if (check == -1)
	{
		cout << endl << "Student not found ";
	}
	
}

void display(evalreport* ptr, int count)
{
	for (int i = 0; i < count; i++)
	{
		ptr[i].PrintSingle();
		cout << endl;
	}
}

void UpdateStatistics(evalreport* std, int count)
{
	int QuizNum = 0, AsgNum = 0;
	QuizNum = evalreport::gettotalquiz();
	AsgNum = evalreport::gettotalasg();
	int num = 1;
	int TotalMarks = QuizNum + AsgNum;


	cout << "\t\t";
	for (int i = 0; i < QuizNum; i++)
	{
		cout << "Q" << num << "\t";
		num++;
	}
	num = 1;
	for (int i = 0; i < AsgNum; i++)
	{
		cout << "A" << num << "\t";
		num++;
	}
	cout << endl;
	cout << "total\t\t";
	int* ptr = 0;
	ptr = evalreport::getmaxofquiz();
	for (int i = 0; i < QuizNum; i++)
	{
		cout << ptr[i] << "\t";
	}

	ptr = evalreport::getmaxofasg();
	for (int i = 0; i < AsgNum; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << endl;
	cout << "Maximum :\t";
	int max = 0, min = 0;

	for (int i = 0, j = 0; i < QuizNum; i++)
	{
		max = std[0].quizmarks[i];

		for (int j = 0; j < count - 1; j++)
		{
			if (std[j].quizmarks[i] > max)
			{
				max = std[j].quizmarks[i];
			}
		}
		cout << max << "\t";
	}

	for (int i = 0, j = 0; i < AsgNum; i++)
	{
		max = std[0].asgmarks[i];
		for (int j = 0; j < count - 1; j++)
		{
			if (std[j].asgmarks[i] > max)
			{
				max = std[j].asgmarks[i];
			}
		}
		cout << max << "\t";
	}
	cout << endl;
	cout << "Minimum :\t";
	min = 0;

	for (int i = 0, j = 0; i < QuizNum; i++)
	{
		min = std[0].quizmarks[i];

		for (int j = 0; j < count - 1; j++)
		{
			if (std[j].quizmarks[i] < min)
			{
				min = std[j].quizmarks[i];
			}
		}
		cout << min << "\t";
	}

	for (int i = 0, j = 0; i < AsgNum; i++)
	{
		min = std[0].asgmarks[i];

		for (int j = 0; j < count - 1; j++)
		{
			if (std[j].asgmarks[i] < min)
			{
				min = std[j].asgmarks[i];
			}
		}
		cout << min << "\t";
	}

	cout << "\nAverage :\t";

	for (int i = 0; i < QuizNum; i++)
	{
		int total = 0;
		for (int j = 0; j < count; j++)
		{
			total = total + std[j].quizmarks[i];
		}
		evalreport::avg = total / count;
		cout << evalreport::avg << "\t";
	}

	for (int i = 0; i < AsgNum; i++)
	{
		int total = 0;
		for (int j = 0; j < count; j++)
		{
			total = total + std[j].asgmarks[i];
		}
		evalreport::avg = total / count;
		cout << evalreport::avg << "\t";
	}

}

void SortList(evalreport* std, int count)
{
	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < count-1 ; i++)
	{
		for (int j = i+1; j < count; j++)
		{
			temp1 = std[i].gettotal();
			temp2 = std[j].gettotal();

			if (temp2 > temp1)
			{
				evalreport temp;
				temp = std[j];
				std[j] = std[i];
				std[i] = temp;
			}
			/*{
				evalreport temp = std[j];
				std[j] = std[i];
				std[i] = temp;
			}*/
		}
	}

}

evalreport* readdatafromfile(char* filename)
{
	ifstream fin;
	int totalstd = 0;
	int numquiz = 0, numasg = 0;
	int total = 0, temp = 0;

	fin.open(filename);

	if (fin.is_open())
	{
		fin >> totalstd;

		evalreport::settotalstudents(totalstd);
		fin >> numquiz;
		evalreport::settotalquiz(numquiz);
		fin >> numasg;
		evalreport::settotalasg(numasg);

		int* totaleachquiz = new int[numquiz];
		int* totaleachasg = new int[numasg];
		evalreport::settotalOfquiz(totaleachquiz);
		evalreport::settotalOfasg(totaleachasg);
		for (int i = 0; i < numquiz; i++)
		{
			fin >> totaleachquiz[i];
		}

		for (int i = 0; i < numasg; i++)
		{
			fin >> totaleachasg[i];
		}

		evalreport::setmaxofquiz(totaleachquiz);
		evalreport::setmaxofasg(totaleachasg);
		int marks = numquiz + numasg + 1; //plus 1 for storing total column
		evalreport* studentslist = new evalreport[totalstd];

		for (int i = 0; i < totalstd; i++)
		{
			studentslist[i].readdatafromfile(fin);
		}

		fin.close();
		return studentslist;
	}
	else
	{
		return 0;
	}
}

evalreport** SearchStudentsByKeyWord(evalreport* std)
{
	evalreport** ptr = 0;
	bool check = 0;
	int occurs = 0;
	int count = evalreport::gettotalstudents();
	int matchingtokens = 0;
	for (int i = 0; i < count; i++)
	{
		check = std[i].keywordMatch();
		if (check == true)
		{
			occurs++;
		}
	}
	ptr = new evalreport *[occurs+1];
	evalreport::setoccur(occurs);
	int final = 0;
	for (int i = 0; i < count; i++)
	{
		check = std[i].keywordMatch();
		if (check == true)
		{
			ptr[final] = &std[i];
			final++;
		}
	}
	ptr[occurs] = NULL;
	return ptr;
}


int evalreport::occur = 0;
int evalreport::totalstudents = 0;
int* evalreport::maxasg = 0;
int* evalreport::maxquiz = 0;
int* evalreport::minasg = 0;
int* evalreport::minquiz = 0;
int evalreport::avg = 0;
int evalreport::totalasg = 0;
int evalreport::totalquiz = 0;
int* evalreport::maxofquiz = 0;
int* evalreport::maxofasg = 0;
char* evalreport::str = 0;
int* evalreport::totalOfasg = 0;
int* evalreport::totalOfquiz = 0;

int main()
{
	char name[] = "Gradesheet.txt";
	char* n = name;
	int count = 0;
	evalreport* studentslist = readdatafromfile(n);
	count = evalreport::gettotalstudents();
	evalreport print;
	UpdateStatistics(studentslist, count);
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------";
	cout << endl;
	display(studentslist, count);
	cout << "-------------------------------------------------------------------------------------";
	SortList(studentslist, count);
	cout << "\n\n\n";
	display(studentslist, count);

	char* str = evalreport::getstr();
	char buffer[20];
	cout << "\n Enter String to search : ";
	cin.getline(buffer, 20);
	n = helper::getstringfrombuffer(buffer);
	evalreport::setstr(n);
	evalreport** ptr = SearchStudentsByKeyWord(studentslist);
	int j = evalreport::getoccur();
	print.PrintAll(ptr);
	
	StudentInfo(studentslist,count);
	print.deallocateStatic();
 
      delete ptr[i];
		ptr[i] = 0;
	return 0;
}

