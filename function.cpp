#include "student.h"

float scoretogp(int sc)//��Ҫ��������score�ĺϷ��Լ��
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

//���캯��1���������ļ�ĩβ׷��
student::student()										
{
	ifstream infile1("student.dat", ios::in);			//��ȡ��Ϣ��Ŀ�����
	if (!infile1)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile1.seekg(-77, ios::end);
	infile1 >> num;
	num++;

	infile1.close();

	cout << endl << "������ѧ���ɼ���Ϣ������������ѧ���������γ����ơ�ѧ�ֺͰٷ��Ƴɼ������ûس���ո����:" << endl;
	cin >> name;
	cin >> cur;
	cin >> credit;
	cin >> score;
	if (score > 100)
		cout << "ע�⣬�ٷ��Ƴɼ�Խ�磡" << endl;
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
		cout << "ע�⣬�ٷ��Ƴɼ�Խ�磡" << endl;
	gp = scoretogp(score);									//gp��ת������
}

//���캯��2�����ڴ��ļ��ж�ȡ��֪��ŵĶ���
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
		cout << endl << "��ѯ��ϣ�û�����Ϊ" << n << "�ĳɼ���Ϣ" << endl;
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

//���캯��3�����ڹ�����֪��ŵĶ���
student::student(int n, int m)
{
	num = n;
	cout << endl << "�����ѧ���ɼ���Ϣ������������ѧ���������γ����ơ�ѧ�ֺͰٷ��Ƴɼ������ûس���ո����:" << endl;
	cin >> name;
	cin >> cur;
	cin >> credit;
	cin >> score;
	if (score > 100)
		cout << "ע�⣬�ٷ��Ƴɼ�Խ�磡" << endl;
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
		cout << "ע�⣬�ٷ��Ƴɼ�Խ�磡" << endl;
	gp = scoretogp(score);//gp��ת������
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
	cout << setiosflags(ios::left) << setw(5) << "���" << setw(10) << "����"
		<< setw(20) << "�γ�����" << setw(5) << "ѧ��" << setw(15) << "�ٷ��Ƴɼ�"
		<< setw(15) << "�ȼ��Ƴɼ�" << setw(5) << setiosflags(ios::fixed)
		<< setprecision(1) << "����" << resetiosflags(ios::fixed) << endl;
}