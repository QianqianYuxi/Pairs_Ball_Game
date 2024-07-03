#include"c++ballgame.h"


//定义＋初始化
Rk rk[2];
board p1, p2;
ball b;
Prop* head = new Prop(NULL, 'h'), * pc = new Prop(head, 'c'), * pb = new Prop(pc, 'b'), * pa = new Prop(pb, 'a');

//主函数
int main() {
	srand(GetTickCount());
	draw_style();
	p1.init(60, 240, 5, 20);
	p2.init(580, 240, 5, 20);
	b.init(rand() % 440 + 100, rand() % 260 + 110, 10, (rand() % 2 * 2 - 1) * 2, (rand() % 2 * 2 - 1) * 2);
	if (ch == 'q' || ch == 'Q') {
		cleardevice();
		mciSendString(L"stop 游戏模式2.mp3", NULL, 0, NULL);
		mciSendString(L"close 游戏模式2.mp3", NULL, 0, NULL);
		if (bestscore()) {
			if (bestscore() == 1) {
				FILE* pfile;
				fopen_s(&pfile, "data.txt", "w");
				fclose(pfile);
			}
			record();
			printrecord();
		}
		else printrecord();
		exit(0);
	}
	if (ch == 'x' || ch == 'X') {
		begin_window1();
		ch = 'r';
	}
	if (ch == 'r' || ch == 'R')
		prg();
	return 0;
}

void count_score() {
	if (win == 1) {
		rk[0].score++;
		ch = 'r';
		PlaySound(L"输球.wav", NULL, SND_FILENAME | SND_ASYNC);
		main();
	}
	if (win == 2) {
		rk[1].score++;
		ch = 'r';
		PlaySound(L"输球.wav", NULL, SND_FILENAME | SND_ASYNC);
		main();
	}
}
void ed_fuc() {
	while (_kbhit) {
		ch = _getch();
		if (ch == 27) {
			exit(0);
		}
		else if (ch == 'r' || ch == 'x' || ch == 'R' || ch == 'X') {
			EndBatchDraw();
			PlaySound(L"选择.wav", NULL, SND_FILENAME | SND_ASYNC);
			main();
		}
	}
}
void pause_fuc() {
	while (_kbhit) {
		ch = _getch();
		if (ch == 27) {
			prg_draw();
			PlaySound(L"选择.wav", NULL, SND_FILENAME | SND_ASYNC);
			return;
		}
		else if (ch == 'r' || ch == 'x' || ch == 'R' || ch == 'X') {
			EndBatchDraw();
			PlaySound(L"选择.wav", NULL, SND_FILENAME | SND_ASYNC);
			main();
		}
		else if (ch == 'Q' || ch == 'q') {
			EndBatchDraw();
			PlaySound(L"选择.wav", NULL, SND_FILENAME | SND_ASYNC);
			main();
		}
	}
}



void bkg1() {
	IMAGE bkg;
	loadimage(&bkg, L"砖墙1试.png");
	putimage(0, 0, &bkg);
}
void bkg2() {
	IMAGE bkg;
	loadimage(&bkg, L"砖墙2试.png");
	putimage(0, 0, &bkg);
}
void bkg3() {
	IMAGE bkg;
	loadimage(&bkg, L"砖墙3试.png");
	putimage(0, 0, &bkg);
}
void prg() {
	if (pattern == '1') {
		cleardevice();
		mciSendString(L"stop 游戏界面.mp3", NULL, 0, NULL);
		mciSendString(L"close 游戏界面.mp3", NULL, 0, NULL);
		prg_fuc1();
		cleardevice();
		ed1();
		return;
	}
	else if (pattern == '2') {
		mciSendString(L"stop 游戏界面.mp3", NULL, 0, NULL);
		mciSendString(L"close 游戏界面.mp3", NULL, 0, NULL);
		if (win == 0)
			players_info();
		cleardevice();
		prg_fuc2();
		cleardevice();
		return;
	}
	else if (pattern == '3') {
		mciSendString(L"stop 游戏界面.mp3", NULL, 0, NULL);
		mciSendString(L"close 游戏界面.mp3", NULL, 0, NULL);
		cleardevice();
		prg_fuc3();
		cleardevice();
		ed1();
		return;
	}
}
void draw_style() {
	//设置界面大小及各颜色
	initgraph(640, 480);
	setbkmode(TRANSPARENT);//使文字背景颜色变透明
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(GREEN);
	setlinecolor(GREEN);
	//设置字体
	settextcolor(YELLOW);
	return;
}
void begin_window1() {
	cleardevice();
	settextstyle(50, 0, L"verdana");
	IMAGE bkg;
	loadimage(&bkg, L"开始界面.jpg");
	putimage(0, 0, &bkg);
	mciSendString(L"stop 游戏模式1.mp3", NULL, 0, NULL);
	mciSendString(L"close 游戏模式1.mp3", NULL, 0, NULL);
	mciSendString(L"stop 游戏模式2.mp3", NULL, 0, NULL);
	mciSendString(L"close 游戏模式2.mp3", NULL, 0, NULL);
	mciSendString(L"stop 游戏模式3.mp3", NULL, 0, NULL);
	mciSendString(L"close 游戏模式3.mp3", NULL, 0, NULL);
	mciSendString(L"open 游戏界面.mp3", NULL, 0, NULL);
	mciSendString(L"play 游戏界面.mp3", NULL, 0, NULL);
	outtextxy(100, 200, L"按下 ENTER 键开始游戏!");
	wchar_t key = 0;
	while (key = _getch()) {
		if (key == 13) {
			PlaySound(L"选择.wav", NULL, SND_FILENAME | SND_ASYNC);
			begin_window2();
			return;
		}
	}
}
void begin_window2() {
	cleardevice();
	settextstyle(50, 0, L"verdana");
	IMAGE bkg;
	loadimage(&bkg, L"开始界面.jpg");
	putimage(0, 0, &bkg);
	outtextxy(100, 100, L"请选择模式");
	settextstyle(35, 0, L"verdana");
	outtextxy(100, 175, L"普通模式   1");
	outtextxy(100, 235, L"无尽模式   2");
	outtextxy(100, 295, L"道具模式   3");
	while (pattern = _getch()) {
		if (pattern == '1' || pattern == '2' || pattern == '3')
		{
			PlaySound(L"选择.wav", NULL, SND_FILENAME | SND_ASYNC);
			return;
		}
	}
}
void board_move() {
	wchar_t key = 0;
	if (_kbhit()) {
		key = _getch();
		if (p1.y >= tp + p1.size_y * 2)
			if (key == 'w' || key == 'W')
				p1.y -= p1.size_y;
		if (p2.y >= tp + p2.size_y * 2)
			if (key == 'o' || key == 'O')
				p2.y -= p2.size_y;
		if (p1.y <= btm - p1.size_y * 2)
			if (key == 's' || key == 'S')
				p1.y += p1.size_y;
		if (p2.y <= btm - p2.size_y * 2)
			if (key == 'l' || key == 'L')
				p2.y += p2.size_y;
		if (key == 27 && pattern == '1')
			pause1();
		else if (key == 27 && pattern == '2')
			pause2();
	}
	solidrectangle(p1.x - p1.size_x, p1.y - p1.size_y, p1.x + p1.size_x, p1.y + p1.size_y);
	solidrectangle(p2.x - p2.size_x, p2.y - p2.size_y, p2.x + p2.size_x, p2.y + p2.size_y);
	return;
}
void ball_move() {
	if (b.y<tp + 10 || b.y>btm - 10)
	{
		b.yv = -b.yv;
		PlaySound(L"击球.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	else if (b.x < p1.x + p1.size_x + b.r)
	{
		if (b.y > p1.y - p1.size_y - b.r && b.y < p1.y + p1.size_y + b.r) {
			b.xv = -b.xv;
			turn = 1;
			b_speedqiuck();
			PlaySound(L"击球.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		else
			prg_rulewin();
	}
	else if (b.x > p2.x - p2.size_x - b.r) {
		if (b.y > p2.y - p2.size_y - b.r && b.y < p2.y + p2.size_y + b.r) {
			b.xv = -b.xv;
			turn = 2;
			b_speedqiuck();
			PlaySound(L"击球.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		else
			prg_rulewin();
	}
	b.x += b.xv;
	b.y += b.yv;
	solidcircle(b.x, b.y, b.r);
	return;
}
void b_speedqiuck() {
	if (b.yv < 0 && b.yv>-12) b.yv -= 1;
	else if (b.yv > 0 && b.yv < 12) b.yv += 1;
	if (b.xv < 0 && b.xv>-12)b.xv -= 1;
	else if (b.xv > 0 && b.xv < 12) b.xv += 1;
	return;
}
void b_speedslow() {
	if (b.yv < 0 && b.yv < -2) b.yv += 2;
	else if (b.yv > 0 && b.yv > 2) b.yv -= 2;
	if (b.xv < 0 && b.xv < -2)b.xv += 2;
	else if (b.xv > 0 && b.xv > 2) b.xv -= 2;
	return;
}
void prg_rulewin() {
	if (b.x < p1.x - b.r) win = 2;
	else if (b.x > p2.x + b.r) win = 1;
	return;
}
void prg_propget(int i, Prop* temp) {
	int dec = 0;
	dec = (temp->x - b.x) * (temp->x - b.x) + (temp->y - b.y) * (temp->y - b.y);
	if (dec <= (b.r + R) * (b.r + R)) {
		ploop = 200;
		if (temp->t == 'a')
		{
			PlaySound(L"吃道具.wav", NULL, SND_FILENAME | SND_ASYNC);
			prop1();
		}
		if (temp->t == 'b') {
			PlaySound(L"吃道具.wav", NULL, SND_FILENAME | SND_ASYNC);
			prop2();
		}

		if (temp->t == 'c') {
			PlaySound(L"吃道具.wav", NULL, SND_FILENAME | SND_ASYNC);
			b_speedslow();
		}
	}
	return;
}
Prop* nextprop(Prop* temp) {
	temp = temp->next;
	temp->x = rand() % 440 + 100;
	temp->y = rand() % 260 + 110;
	return temp;
}
void prop1() {
	if (turn == 1) p1.size_y += 5;
	if (turn == 2)p2.size_y += 5;

}
void prop2() {
	b.r += 5;
}
void prg_draw() {
	settextstyle(20, 0, L"verdana");
	settextcolor(WHITE);
	//player1
	outtextxy(20, 50, L"player 1");
	outtextxy(20, 400, L" w 向上 ");
	outtextxy(20, 440, L" s 向下 ");
	//player2
	outtextxy(565, 50, L"player 2");
	outtextxy(565, 400, L" o 向上 ");
	outtextxy(565, 440, L" l 向下 ");
	//暂停提示
	outtextxy(290, 0, L"Esc 暂停");
}
void prg_fuc1() {
	win = 0;
	mciSendString(L"open 游戏模式1.mp3", NULL, 0, NULL);
	mciSendString(L"play 游戏模式1.mp3", NULL, 0, NULL);
	BeginBatchDraw();
	while (win == 0) {
		clearrectangle(p1.x - p1.size_x, p1.y - p1.size_y, p1.x + p1.size_x, p1.y + p1.size_y);
		clearrectangle(p2.x - p2.size_x, p2.y - p2.size_y, p2.x + p2.size_x, p2.y + p2.size_y);
		clearcircle(b.x, b.y, b.r);
		bkg1();
		prg_draw();
		board_move();
		ball_move();
		FlushBatchDraw();
		Sleep(10);
	}
	EndBatchDraw();
	return;
}
void prg_fuc2() {
	mciSendString(L"open 游戏模式2.mp3", NULL, 0, NULL);
	mciSendString(L"play 游戏模式2.mp3", NULL, 0, NULL);
	BeginBatchDraw();
	TCHAR s1[5], s2[5];
	while (1) {
		win = 0;
		clearrectangle(p1.x - p1.size_x, p1.y - p1.size_y, p1.x + p1.size_x, p1.y + p1.size_y);
		clearrectangle(p2.x - p2.size_x, p2.y - p2.size_y, p2.x + p2.size_x, p2.y + p2.size_y);
		clearcircle(b.x, b.y, b.r);
		bkg2();
		prg_draw();
		board_move();
		ball_move();
		_stprintf_s(s1, _T("%d"), rk[0].score);
		_stprintf_s(s2, _T("%d"), rk[1].score);
		settextstyle(20, 0, L"verdana");
		outtextxy(15, 20, L"玩家名称：");
		outtextxy(550, 20, L"：玩家名称");
		outtextxy(100, 20, rk[0].name);
		outtextxy(535, 20, rk[1].name);
		outtextxy(100, 50, s1);
		outtextxy(535, 50, s2);
		FlushBatchDraw();
		if (win != 0)
			count_score();
		Sleep(10);
	}
	EndBatchDraw();
	return;
}
void prg_fuc3() {
	mciSendString(L"open 游戏模式3.mp3", NULL, 0, NULL);
	mciSendString(L"play 游戏模式3.mp3", NULL, 0, NULL);
	ploop = 0;
	head->set_next(pa);
	Prop* temp = head;
	win = 0;
	BeginBatchDraw();
	while (win == 0) {
		setfillcolor(WHITE);
		clearrectangle(p1.x - p1.size_x, p1.y - p1.size_y, p1.x + p1.size_x, p1.y + p1.size_y);
		clearrectangle(p2.x - p2.size_x, p2.y - p2.size_y, p2.x + p2.size_x, p2.y + p2.size_y);
		clearcircle(b.x, b.y, b.r);
		bkg3();
		prg_draw();
		board_move();
		ball_move();
		if (ploop == 0) {
			temp = nextprop(temp);
		}
		if (ploop > 50 && temp->t == 'a') {
			setfillcolor(GREEN);
			solidcircle(temp->x, temp->y, R);
			setfillcolor(WHITE);
			prg_propget(ploop, temp);
		}
		else if (ploop > 50 && temp->t == 'b') {
			setfillcolor(RED);
			solidcircle(temp->x, temp->y, R);
			setfillcolor(WHITE);
			prg_propget(ploop, temp);
		}
		else if (ploop > 50 && temp->t == 'c') {
			setfillcolor(BLUE);
			solidcircle(temp->x, temp->y, R);
			setfillcolor(WHITE);
			prg_propget(ploop, temp);
		}
		ploop++;
		if (ploop >= 200) {
			clearcircle(temp->x, temp->y, R);
			ploop = 0;
		}
		FlushBatchDraw();
		Sleep(10);
	}
	EndBatchDraw();
	return;
}
void ed1() {
	settextstyle(35, 0, L"verdana");
	IMAGE bkg;
	loadimage(&bkg, L"结束界面.jpg");
	putimage(0, 0, &bkg);
	settextcolor(YELLOW);
	outtextxy(175, 175, L"按 Esc 键 退出游戏");
	outtextxy(175, 235, L"按 R 键 重新开始游戏");
	outtextxy(175, 295, L"按 X 键 返回开始界面");

	settextstyle(50, 0, L"verdana");
	if (win == 1)
		outtextxy(200, 100, L"恭喜 P1 获胜！");
	else if (win == 2)
		outtextxy(200, 100, L"恭喜 P2 获胜！");
	win = 0;
	ed_fuc();
}

void pause1() {
	PlaySound(L"暂停.wav", NULL, SND_FILENAME | SND_ASYNC);
	cleardevice();
	IMAGE bkg;
	loadimage(&bkg, L"暂停界面.jpg");
	putimage(0, 0, &bkg);
	settextstyle(50, 0, L"verdana");
	settextcolor(BLACK);
	outtextxy(225, 100, L"游戏暂停");
	settextstyle(35, 0, L"verdana");
	outtextxy(175, 175, L"按 Esc 键 继续游戏");
	outtextxy(175, 235, L"按 R 键 重新开始游戏");
	outtextxy(175, 305, L"按 X 键 返回开始界面");
	FlushBatchDraw();
	pause_fuc();
	return;
}
void pause2() {
	PlaySound(L"暂停.wav", NULL, SND_FILENAME | SND_ASYNC);
	cleardevice();
	IMAGE bkg;
	loadimage(&bkg, L"暂停界面.jpg");
	putimage(0, 0, &bkg);
	settextstyle(50, 0, L"verdana");
	settextcolor(BLACK);
	outtextxy(225, 50, L"游戏暂停");
	settextstyle(35, 0, L"verdana");
	outtextxy(200, 125, L"按 Esc 键 继续游戏");
	outtextxy(200, 185, L"按 R 键 重新开始游戏");
	outtextxy(200, 245, L"按 X 键 返回开始界面");
	outtextxy(200, 305, L"按 Q 键 结束游戏");
	FlushBatchDraw();
	pause_fuc();
	return;
}

int bestscore() {
	Rk best[2];
	char buf[40];
	int mx;
	FILE* fp;
	fopen_s(&fp, "data.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	rewind(fp);
	if (len == 0) {
		fclose(fp);
		return 1;
	}
	fgets(buf, 40, fp);
	sscanf_s(buf, "%*7s%12d%*7s%12d", &best[0].score, &best[1].score);
	mx = (best[0].score > best[1].score) ? best[0].score : best[1].score;
	if (mx < rk[0].score || mx < rk[1].score) {
		fclose(fp);
		return 1;
	}
	fclose(fp);
	return 0;
}
void players_info() {
	cleardevice();
	settextcolor(YELLOW);
	IMAGE bkg;
	loadimage(&bkg, L"砖墙2.png");
	putimage(0, 0, &bkg);
	settextstyle(50, 0, L"verdana");
	outtextxy(225, 25, L"无尽模式");
	settextstyle(25, 0, L"verdana");
	outtextxy(225, 100, L"请输入玩家名称:");
	InputBox(rk[0].name, 10, L"Player 1:");
	InputBox(rk[1].name, 10, L"Player 2:");
	return;
}
void record() {
	FILE* fp;
	fopen_s(&fp, "data.txt", "w");
	for (int i = 0; i < 2; i++)
	{
		fprintf(fp, "%7s%12d", (rk + i)->name, (rk + i)->score);
	}
	fclose(fp);
}
void printrecord()
{
	cleardevice();
	IMAGE bkg;
	loadimage(&bkg, L"结束界面.jpg");
	putimage(0, 0, &bkg);
	settextstyle(50, 0, L"verdana");
	settextcolor(YELLOW);
	outtextxy(175, 150, L"历史最高得分纪录：");
	outtextxy(2, 225, L"  玩家1  |  分数    玩家2  |  分数  ");
	FILE* pfile;
	fopen_s(&pfile, "data.txt", "rb");
	if (pfile == NULL) {
		return;
	}
	//读取文件长度,读完后把文件指针复位到开头
	fseek(pfile, 0, SEEK_END);
	int file_length = ftell(pfile);
	rewind(pfile);
	//申请一段内存空间用来放文件中的文本内容，并置零
	int text_length = file_length * sizeof(char) + 1;
	char* ctext_buffer = (char*)malloc(text_length);
	memset(ctext_buffer, 0, text_length);
	//把文件文本内容读到申请的内存空间中
	int read_length = fread(ctext_buffer, 1, file_length, pfile);
	if (read_length != file_length) {
		return;
	}
	//将char转换为wchar_t
	size_t len = strlen(ctext_buffer) + 1;
	size_t converted = 0;
	wchar_t* wtext_buffer = (wchar_t*)malloc(len * sizeof(wchar_t));;
	mbstowcs_s(&converted, wtext_buffer, len, ctext_buffer, _TRUNCATE);
	//打印文件文本内容，释放申请的内存空间，关闭文件流
	outtextxy(0, 275, wtext_buffer);
	_getch();
	ch = 'x';
	free(wtext_buffer);
	delete[]ctext_buffer;
	fclose(pfile);
	return;
}
//这是读取文件
