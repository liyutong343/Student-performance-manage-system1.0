#include "student.h"

float scoretogp(int sc)//不要忘记输入score的合法性检查
{
	if (sc > 100)
		return 0.0f;
	else if (sc >= 90)
		return 4.0f;
	else if (sc >= 85)
		return 3.6f;
	else if (sc >= 80)
		return 3.3f;
	else if (sc >= 77)
		return 3.0f;
	else if (sc >= 73)
		return 2.6f;
	else if (sc >= 70)
		return 2.3f;
	else if (sc >= 67)
		return 2.0f;
	else if (sc >= 63)
		return 1.6f;
	else if (sc >= 60)
		return 1.3f;
	else 
		return 0.0f;
}

//构造函数1，用于在文件末尾追加
student::student()										
{
	ifstream infile1("student.dat", ios::in);			//读取信息条目的序号
	if (!infile1)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile1.seekg(-77, ios::end);
	infile1 >> num;
	num++;

	infile1.close();

	cout << endl << "请输入学生成绩信息，请依次输入学生姓名、课程名称、学分和百分制成绩，并用回车或空格隔开:" << endl;
	cin >> name;
	cin >> cur;
	cin >> credit;
	cin >> score;
	if (score > 100)
		cout << "注意，百分制成绩越界！" << endl;
	else if (score == 100)
	{
		grade[0] = 'A';
		grade[1] = '+';
	}
	else if (score >= 95)
		grade[0] = 'A';
	else if (score >= 90)
	{
		grade[0] = 'A';
		grade[1] = '-';
	}
	else if (score >= 85)
	{
		grade[0] = 'B';
		grade[1] = '+';
	}
	else if (score >= 80)
		grade[0] = 'B';
	else if (score >= 77)
	{
		grade[0] = 'B';
		grade[1] = '-';
	}
	else if (score >= 73)
	{
		grade[0] = 'C';
		grade[1] = '+';
	}
	else if (score >= 70)
		grade[0] = 'C';
	else if (score >= 67)
	{
		grade[0] = 'C';
		grade[1] = '-';
	}
	else if (score >= 63)
	{
		grade[0] = 'D';
		grade[1] = '+';
	}
	else if (score >= 60)
		grade[0] = 'D';
	else if (score >= 0)
		grade[0] = 'F';
	else
		cout << "注意，百分制成绩越界！" << endl;
	gp = scoretogp(score);									//gp的转换函数
}

//构造函数2，用于从文件中读取已知序号的对象
int researchflag;
student::student(int n)
{
	int lastno;
	ifstream infile("student.dat", ios::in);
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}

	infile.seekg(-77, ios::end);
	infile >> lastno;
	if (lastno < n || n < 1 )
	{
		cout << endl << "查询完毕！没有序号为" << n << "的成绩信息" << endl;
		researchflag = 0;
	}
	else
	{
		infile.seekg((n - 1) * 77, ios::beg);
		infile >> num >> name >> cur >> credit >> score >> grade >> gp;
		researchflag = 1;
	}
		
	infile.close();
}

//构造函数3，用于构造已知序号的对象
student::student(int n, int m)
{
	num = n;
	cout << endl << "请更新学生成绩信息，请依次输入学生姓名、课程名称、学分和百分制成绩，并用回车或空格隔开:" << endl;
	cin >> name;
	cin >> cur;
	cin >> credit;
	cin >> score;
	if (score > 100)
		cout << "注意，百分制成绩越界！" << endl;
	else if (score == 100)
	{
		grade[0] = 'A';
		grade[1] = '+';
	}
	else if (score >= 95)
		grade[0] = 'A';
	else if (score >= 90)
	{
		grade[0] = 'A';
		grade[1] = '-';
	}
	else if (score >= 85)
	{
		grade[0] = 'B';
		grade[1] = '+';
	}
	else if (score >= 80)
		grade[0] = 'B';
	else if (score >= 77)
	{
		grade[0] = 'B';
		grade[1] = '-';
	}
	else if (score >= 73)
	{
		grade[0] = 'C';
		grade[1] = '+';
	}
	else if (score >= 70)
		grade[0] = 'C';
	else if (score >= 67)
	{
		grade[0] = 'C';
		grade[1] = '-';
	}
	else if (score >= 63)
	{
		grade[0] = 'D';
		grade[1] = '+';
	}
	else if (score >= 60)
		grade[0] = 'D';
	else if (score >= 0)
		grade[0] = 'F';
	else
		cout << "注意，百分制成绩越界！" << endl;
	gp = scoretogp(score);//gp的转换函数
}

ostream& operator << (ostream& output, student& s)
{
	output << setiosflags(ios::left) << setw(5) << s.num << setw(10) << s.name 
		<< setw(20) << s.cur << setw(5) << s.credit << setw(15) << s.score
		<< setw(15) << s.grade << setw(5) << setiosflags(ios::fixed) 
		<< setprecision(1) << s.gp << resetiosflags(ios::fixed) << endl;
	return output;
}

istream& operator >> (istream& input, student& s)	
{
	return input;
}	

fstream& operator << (fstream& output, student& s)
{
	output << setiosflags(ios::left) << setw(5) << s.num << setw(10) << s.name
		<< setw(20) << s.cur << setw(5) << s.credit << setw(15) << s.score
		<< setw(15) << s.grade << setw(5) << setiosflags(ios::fixed)
		<< setprecision(1) << s.gp << resetiosflags(ios::fixed) << endl;
	return output;
}

fstream& operator >> (fstream& input, student& s)
{
	input >> s.num >> s.name >> s.cur >> s.credit >> s.score >> s.grade >> s.gp;
	return input;
}

int student::credit_get()
{
	return credit;
}

float student::gp_get()
{
	return gp;
}

int student::score_get()
{
	return score;
}

void printtitle()
{
	cout << setiosflags(ios::left) << setw(5) << "序号" << setw(10) << "姓名"
		<< setw(20) << "课程名称" << setw(5) << "学分" << setw(15) << "百分制成绩"
		<< setw(15) << "等级制成绩" << setw(5) << setiosflags(ios::fixed)
		<< setprecision(1) << "绩点" << resetiosflags(ios::fixed) << endl;
}