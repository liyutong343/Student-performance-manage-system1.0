#include "student.h"

extern int researchflag;
extern void printtitle();
int main()
{
	int OPTION, option = 0,creditsum=0,scoresum=0,sum=0;
	float gpsum=0,gpa,avr;
	while (1)
	{
		system("cls");
		cout << endl << "☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ " << endl;
		cout << endl << "* * * * * * * * * 学生成绩管理系统 * * * * * * * * *" << endl;
		cout << endl << "☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ " << endl;
		cout << "                  _                          _ " << endl;
		cout << "    __      _____| | ___ ___  _ __ ___   ___| |" << endl;
		cout << "    \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ |" << endl;
		cout << "     \\ V  V /  __/ | (_| (_) | | | | | |  __/_|" << endl;
		cout << "      \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___(_)" << endl;
		cout << endl << "欢迎使用学生成绩管理系统！" << endl;
		cout << "请选择想要使用的功能：" << endl;
		cout << "1 录入学生成绩" << endl;					
		cout << "2 查询某条成绩信息" << endl;
		cout << "3 修改某条成绩信息" << endl;
		cout << "4 统计某个学生的全部成绩信息" << endl;
		cout << "5 统计某门课程的全部成绩信息" << endl;
		cout << "0 退出" << endl;
		cin >> OPTION;
		if (OPTION == 1)
		{
			while (1)
			{
				option = 0;
				student* stu;
				stu = new student;
				

				ofstream outfile("student.dat",ios::app);
				if (!outfile)
				{
					cerr << "open error!" << endl;
					exit(1);
				}
				outfile << *stu;
				outfile.close();

				cout << endl << "录入成功！录入结果为：" << endl;
				ifstream infile2("student.dat", ios::in);
				if (!infile2)
				{
					cerr << "open error!" << endl;
					exit(1);
				}
				infile2 >> *stu;
				infile2.close();
				printtitle();
				cout << *stu;
				delete[]stu;

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续录入？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
			
		}
		else if (OPTION == 2)
		{
			int goal;
			while (1)
			{
				cout << endl << "请输入想要查询的成绩条目序号：" << endl;
				cin >> goal;
				option = 0;

				student *stu;
				stu = new student(goal);
				if (researchflag)
				{
					cout << endl << "查询成功！" << endl;
					printtitle();
					cout << *stu;
				}
				delete[]stu;

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续查询？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
		}
		else if (OPTION == 3)
		{
			int goal,choice;
			while (1)
			{
				option = 0;
				choice = 0;
				cout << endl << "请输入你想修改的成绩条目序号：" << endl;
				cin >> goal;
				student *stu;
				stu = new student(goal);
				if (researchflag)
				{
					cout << endl << "查询成功！" << endl;
					printtitle();
					cout << *stu;
				}
				delete[]stu;
				
				if (researchflag)
				{
					while (choice != 1 && choice != 2)
					{
						cout << endl << "是否修改？" << endl << "1 是" << endl << "2 否" << endl;
						cin >> choice;
						if (choice == 1)
						{
							student* stu = new student(goal, 1);
							ofstream outfile("student.dat", ios::in|ios::out);
							if (!outfile)
							{
								cerr << "open error!" << endl;
								exit(1);
							}
							outfile.seekp(77 * (goal - 1), ios::beg);
							outfile << *stu;
							outfile.close();
							cout << endl << "修改成功！修改结果：" << endl;
							printtitle();
							cout << *stu;
							delete[]stu;
						}
						else if (choice != 2)
						{
							cout << "输入不正确！请输入1或2！" << endl;
						}
					}
				}

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续修改？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
		}
		else if (OPTION == 4)
		{
			while (1)
			{
				option = 0;
				creditsum = 0;
				gpsum = 0;
				char goalname[10];
				int i,lastno,nameflag=1;

				cout << endl << "请输入想要统计其成绩的学生姓名:" << endl;
				cin >> goalname;

				ifstream infile("student.dat", ios::in);
				if (!infile)
				{
					cerr << "open error!" << endl;
					exit(1);
				}
				infile.seekg(-77, ios::end);
				infile >> lastno;
				for (i = 1;i <= lastno;i++)
				{
					student* stu;
					stu = new student(i);
					if (strcmp(goalname, (*stu).name) == 0)
					{
						if (nameflag)
						{
							nameflag = 0;
							cout << endl << "查询成功！信息如下：" << endl;
							printtitle();
						}
						creditsum = creditsum + (*stu).credit_get();
						gpsum = gpsum + (*stu).gp_get()*(*stu).credit_get();
						cout << *stu;
					}
				}
				if (nameflag)
				{
					cout << "没有找到该学生的信息！" << endl;
				}
				else
				{
					gpa = gpsum / creditsum;
					cout << goalname << "的gpa为" << setiosflags(ios::fixed) << setprecision(2) << gpa << endl;
				}

				infile.close();

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续统计？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
		}
		else if (OPTION == 5)
		{
			while (1)
			{
				option = 0;
				scoresum = 0;
				sum = 0;
				char goalname[10];
				int i,lastno,nameflag=1;

				cout << endl << "请输入想要统计其成绩的课程名称:" << endl;
				cin >> goalname;

				ifstream infile("student.dat", ios::in);
				if (!infile)
				{
					cerr << "open error!" << endl;
					exit(1);
				}
				infile.seekg(-77, ios::end);
				infile >> lastno;
				for (i = 1;i <= lastno;i++)
				{
					student* stu;
					stu = new student(i);
					if (strcmp(goalname, (*stu).cur) == 0)
					{
						if (nameflag)
						{
							nameflag = 0;
							cout << endl << "查询成功！信息如下：" << endl;
							printtitle();
						}
						cout << *stu;
						scoresum = scoresum + (*stu).score_get();
						sum++;
					}
				}
				if (nameflag)
				{
					cout << "没有找到该课程的信息！" << endl;
				}
				else
				{
					avr = (float)scoresum / (float)sum;
					cout << goalname << "的平均百分制成绩为" << setiosflags(ios::fixed) << setprecision(2) << avr << endl;
				}

				infile.close();

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续统计？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
		}
		else if (!OPTION)
		{
			cout << endl << "感谢使用学生成绩管理系统！欢迎下次使用！" << endl;
			cout << endl << "      ____               _                _ " << endl;
			cout << "     | __ ) _   _  ___  | |__  _   _  ___| |" << endl;
			cout << "     |  _ \\| | | |/ _ \\ | '_ \\| | | |/ _ \\ |" << endl;
			cout << "     | |_) | |_| |  __/ | |_) | |_| |  __/_|" << endl;
			cout << "     |____/ \\__, |\\___| |_.__/ \\__, |\\___(_)" << endl;
			cout << "            |___/              |___/        " << endl;
			cout << endl << "☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ " << endl;
			cout << endl << "* * * * * * * * * 学生成绩管理系统 * * * * * * * * *" << endl;
			cout << endl << "☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ " << endl;
			exit(1);
		}
		else
			cout << "请输入0~5的整数！返回主菜单" << endl;
	}
	
	return 0;
}