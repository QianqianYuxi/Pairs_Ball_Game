#ifndef ��ͷ
#define ��ͷ
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <string>
#include<fstream>
#include <mmsystem.h> 
#pragma comment(lib, "winmm.lib") 
using namespace std;
constexpr int R = 15;
//��������
wchar_t ch = 'x';
int win = 0;//��λ��һ�ʤ
int turn = 0;//��λ������һ�ν���
wchar_t pattern = 0;//��Ϸģʽ
const int tp = 100;//�ϱ߽�
const int btm = 380;//�±߽�
int ploop;//���߳��ֵ�ѭ��������¼

class cod {
public:
	int x;
	int y;
	void set_cod(int a,int b) {
		x = a;
		y = b;
	}
};
/*����*/
class Prop :public cod{
	char t;
	Prop* next;
public:
	Prop(Prop* n, char c = 'h', int a = rand() % 440 + 100, int b = rand() % 260 + 110){
		set_cod(a, b);
		t = c;
		next = n;
	};
	void set_next(Prop* a) {
		next = a;
	}
	friend void prg_propget(int i, Prop* temp);
	friend Prop* nextprop(Prop* temp);
	friend void prg_fuc3();
};
/*����*/;
class board :public cod {
	int size_x;
	int size_y;
public:
	void init(int a, int b, int c, int d){
		set_cod(a, b);
		size_x = c;
		size_y = d;
	}
	friend void board_move();
	friend void ball_move();
	friend void prg_rulewin();
	friend void prop1();
	friend void prg_fuc1();
	friend void prg_fuc2();
	friend void prg_fuc3();
};
/*����*/;
class ball :public cod {
	int r;
	int xv;
	int yv;
public:
	void init(int a, int b, int c, int d, int e) {
		set_cod(a, b);
		r = c;
		xv = d;
		yv = e;
	};
	friend void ball_move();
	friend void b_speedqiuck();
	friend void b_speedslow();
	friend void prg_rulewin();
	friend void prg_propget(int i, Prop* temp);
	friend void prop2();
	friend void prg_fuc1();
	friend void prg_fuc2();
	friend void prg_fuc3();
};

//���Ǳ����û��������Ӧ��������
class Rk
{
	wchar_t name[10];
	int score;
public:
	Rk() {
		wmemset(name, '\0', sizeof(name) / sizeof(wchar_t));
		score = 0;
	};
	friend int bestscore();
	friend void prg_fuc2();
	friend void players_info();
	friend void record();
	friend void count_score();
};

//���士��ʼ��

//��������
void draw_style();//�趨��ͼ��������ɫ�ȣ�������������趨��
void begin_window1();//��Ϸ��ʼ�������
void begin_window2();//��Ϸѡ��ģʽ�������

void prg();//��Ϸ���н���
void prg_draw();//��Ϸ���н�����ƣ������Ӻ���
void prg_fuc1();//��ͨģʽ��Ϸ���н��涯��������
void prg_fuc2();//�޾�ģʽ��Ϸ���н��涯��������
void prg_fuc3();//����ģʽ��Ϸ���н��涯��������

void ball_move();//С���˶�
void board_move();//˫���˶�
void b_speedqiuck();//��ÿ�����ײһ�ν���һ����
void prg_rulewin();//���Ƿ�Խ�����ұ߽���δ��������ж�����Ӯ�ж���

void prg_propget(int i, Prop* temp);//�Ƿ�����ߴ���

//void deleteprops(Prop* temp);//�жϽ�������ʹ��ʱ�޼�������߹���

void prop1();//���Ӽӳ�
void prop2();//��Ӵ�
void b_speedslow();//���ٶȼ�С
Prop* nextprop(Prop* temp);//���߱�Ϊ��һ��


void ed1();//��Ϸ�����������
void ed_fuc();//��Ϸ�������湦��ed_fuc()(ͬpause_fuc())


void pause1();//��Ϸ��ͣ����
void pause2();//�޾�ģʽ��Ϸ��ͣ����
void pause_fuc();//��Ϸ��ͣ����Ĺ���

//�޾�ģʽ���Ʒ�,������������
void players_info();//p1,p2�û�����
void count_score();//��¼��������
void record();//��¼��Ϸ��¼���ļ�data.txt
void printrecord();//���ļ���¼�ļ�¼���
int bestscore();//�жϸôγɼ��Ƿ�Խ��ʷ���
#endif
