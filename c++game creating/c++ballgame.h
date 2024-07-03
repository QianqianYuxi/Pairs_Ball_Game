#ifndef 标头
#define 标头
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <string>
#include<fstream>
#include <mmsystem.h> 
#pragma comment(lib, "winmm.lib") 
using namespace std;
constexpr int R = 15;
//变量设置
wchar_t ch = 'x';
int win = 0;//哪位玩家获胜
int turn = 0;//哪位玩家最近一次接球
wchar_t pattern = 0;//游戏模式
const int tp = 100;//上边界
const int btm = 380;//下边界
int ploop;//道具出现的循环次数记录

class cod {
public:
	int x;
	int y;
	void set_cod(int a,int b) {
		x = a;
		y = b;
	}
};
/*道具*/
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
/*板子*/;
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
/*弹球*/;
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

//这是保存用户名及其对应分数的类
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

//定义＋初始化

//函数设置
void draw_style();//设定绘图界面风格，颜色等（包括随机基础设定）
void begin_window1();//游戏开始界面绘制
void begin_window2();//游戏选择模式界面绘制

void prg();//游戏进行界面
void prg_draw();//游戏进行界面绘制（除板子和球）
void prg_fuc1();//普通模式游戏进行界面动画及功能
void prg_fuc2();//无尽模式游戏进行界面动画及功能
void prg_fuc3();//道具模式游戏进行界面动画及功能

void ball_move();//小球运动
void board_move();//双板运动
void b_speedqiuck();//球每与板碰撞一次将加一次速
void prg_rulewin();//球是否越过左右边界且未与板相碰判定（输赢判定）

void prg_propget(int i, Prop* temp);//是否与道具触碰

//void deleteprops(Prop* temp);//判断结束道具使用时限及解除道具功能

void prop1();//板子加长
void prop2();//球加大
void b_speedslow();//球速度减小
Prop* nextprop(Prop* temp);//道具变为下一个


void ed1();//游戏结束界面绘制
void ed_fuc();//游戏结束界面功能ed_fuc()(同pause_fuc())


void pause1();//游戏暂停界面
void pause2();//无尽模式游戏暂停界面
void pause_fuc();//游戏暂停界面的功能

//无尽模式（计分,需输入姓名）
void players_info();//p1,p2用户姓名
void count_score();//记录分数功能
void record();//记录游戏纪录到文件data.txt
void printrecord();//将文件记录的纪录打出
int bestscore();//判断该次成绩是否超越历史最高
#endif
