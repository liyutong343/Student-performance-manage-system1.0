//ab.h
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//�����ࣨ����Ҫcpp�ļ���ʵ�֣�
class ab
{
public:
	//��ʾ��Ϣ
	virtual void display() = 0;
	//������Ϣ���
	virtual void set_no(int i) = 0;
	//��Ϣ���
	int no;
};