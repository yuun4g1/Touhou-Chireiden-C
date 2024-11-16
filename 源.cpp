#pragma warning(disable:4996)
#pragma comment(lib,"Winmm.lib")
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include<graphics.h>
#include <math.h>
#include <time.h>
#define PI 3.1415
#define len 30
#define bspeed1 5
#define width 900
#define high1 960
#define max1 1000

IMAGE menu;		//定义图片变量
IMAGE bk;
IMAGE reimu;
IMAGE reimu_mask;
IMAGE reimu_left;
IMAGE reimu_left_mask;
IMAGE reimu_right;
IMAGE reimu_right_mask;
IMAGE bullet_reimu;
IMAGE bullet_reimu_mask;
IMAGE enemy_br;
IMAGE enemy_br_mask;
IMAGE enemy_rl;
IMAGE enemy_rl_mask;
IMAGE enemydead;
IMAGE enemydead_mask;
IMAGE enemybullet;
IMAGE enemybullet_mask;
IMAGE window;
IMAGE window_mask;
IMAGE start0;
IMAGE start0_mask;
IMAGE start1;
IMAGE start1_mask;
IMAGE playerdata0;
IMAGE playerdata0_mask;
IMAGE playerdata1;
IMAGE playerdata1_mask;
IMAGE quit0;
IMAGE quit0_mask;
IMAGE quit1;
IMAGE quit1_mask;
IMAGE pencent0;
IMAGE pencent0_mask;
IMAGE pencent1;
IMAGE pencent1_mask;
IMAGE zero;
IMAGE zero_mask;
IMAGE zero0;
IMAGE zero0_mask;
IMAGE zero1;
IMAGE zero1_mask;
IMAGE one;
IMAGE one_mask;
IMAGE one0;
IMAGE one0_mask;
IMAGE one1;
IMAGE one1_mask;
IMAGE two;
IMAGE two_mask;
IMAGE two0;
IMAGE two0_mask;
IMAGE two1;
IMAGE two1_mask;
IMAGE three;
IMAGE three_mask;
IMAGE three0;
IMAGE three0_mask;
IMAGE three1;
IMAGE three1_mask;
IMAGE four;
IMAGE four_mask;
IMAGE four0;
IMAGE four0_mask;
IMAGE four1;
IMAGE four1_mask;
IMAGE five;
IMAGE five_mask;
IMAGE five0;
IMAGE five0_mask;
IMAGE five1;
IMAGE five1_mask;
IMAGE six;
IMAGE six_mask;
IMAGE six0;
IMAGE six0_mask;
IMAGE six1;
IMAGE six1_mask;
IMAGE seven;
IMAGE seven_mask;
IMAGE seven0;
IMAGE seven0_mask;
IMAGE seven1;
IMAGE seven1_mask;
IMAGE eight;
IMAGE eight_mask;
IMAGE eight0;
IMAGE eight0_mask;
IMAGE eight1;
IMAGE eight1_mask;
IMAGE nine;
IMAGE nine_mask;
IMAGE nine0;
IMAGE nine0_mask;
IMAGE nine1;
IMAGE nine1_mask;
IMAGE yamame;
IMAGE yamame_mask;
IMAGE front;
IMAGE front_mask;
IMAGE star;
IMAGE star_mask;
IMAGE dummy;
IMAGE dummy_mask;
IMAGE bullet_boss1;
IMAGE bullet_boss1_mask;
IMAGE bullet_boss2;
IMAGE bullet_boss2_mask;
IMAGE bullet_boss3;
IMAGE bullet_boss3_mask;
IMAGE point_b;
IMAGE point_b_mask;
IMAGE point_r;
IMAGE point_r_mask;
IMAGE point_g;
IMAGE point_g_mask;
IMAGE back1;
IMAGE back1_mask;
IMAGE back2;
IMAGE back2_mask;
IMAGE back3;
IMAGE back3_mask;
IMAGE back4;
IMAGE back4_mask;
IMAGE card;
IMAGE card_mask;

int position_x,position_y;	//定义关键全局变量
float boss_x, boss_y,boss_hp;
int quitjudge = 0;
int hurtjudge = 1;
int cardjudge = 0;
int turn = 0;
int reimu_move = 0;
int bullet1_x[15];	//定义每发子弹的x和y值
int bullet1_y[15];
int bullet2_x[15];
int bullet2_y[15];
struct bossbullet {		//定义boss的三种子弹
	float x = -1;
	float y = -1;
	float vx = max1;
	float vy = 0;
};
struct bossbullet b1[10000];
struct bossbullet b2[10000];
struct bossbullet b3[10000];
struct enemy {		//定义敌人数据
	int hp = 2;
	float x;
	float y;
	int bullet_x;
	int bullet_y;
	int point;
	int point_x;
	int point_y;
	int speed;
};
struct enemy enemy01[5];
double angle1 = 0;
double angle2 = 0;
double angle3 = 0;
time_t starttime;	//定义初始时间用于后续计时
time_t cardstart, cardend = 0;

void startup(int* bossjudge,int* player,int* power,int* point)
{
	int i;
	initgraph(1280, 960 ,0);	//设定画布大小并载入图片
	loadimage(&menu, "image\\menu.png");
	loadimage(&reimu_left, "image\\reimu_left.bmp");
	loadimage(&reimu_left_mask, "image\\reimu_left_mask.bmp");
	loadimage(&reimu_right, "image\\reimu_right.bmp");
	loadimage(&reimu_right_mask, "image\\reimu_right_mask.bmp");
	loadimage(&reimu, "image\\reimu.bmp");
	loadimage(&reimu_mask, "image\\reimu_mask.bmp");
	loadimage(&bk, "image\\bk.png");
	loadimage(&bullet_reimu, "image\\bullet_reimu.bmp");
	loadimage(&bullet_reimu_mask, "image\\bullet_reimu_mask.bmp");
	loadimage(&enemy_br, "image\\enemy_br.bmp");
	loadimage(&enemy_br_mask, "image\\enemy_br_mask.bmp");
	loadimage(&enemy_rl, "image\\enemy_rl.bmp");
	loadimage(&enemy_rl_mask, "image\\enemy_rl_mask.bmp");
	loadimage(&enemydead, "image\\enemydead.bmp");
	loadimage(&enemydead_mask, "image\\enemydead_mask.bmp");
	loadimage(&enemybullet, "image\\enemybullet.bmp");
	loadimage(&enemybullet_mask, "image\\enemybullet_mask.bmp");
	loadimage(&window, "image\\window.bmp");
	loadimage(&window_mask, "image\\window_mask.bmp");
	loadimage(&start0, "image\\start0.bmp");
	loadimage(&start0_mask, "image\\start0_mask.bmp");
	loadimage(&start1, "image\\start1.bmp");
	loadimage(&start1_mask, "image\\start1_mask.bmp");
	loadimage(&playerdata0, "image\\playerdata0.bmp");
	loadimage(&playerdata0_mask, "image\\playerdata0_mask.bmp");
	loadimage(&playerdata1, "image\\playerdata1.bmp");
	loadimage(&playerdata1_mask, "image\\playerdata1_mask.bmp");
	loadimage(&quit0, "image\\quit0.bmp");
	loadimage(&quit0_mask, "image\\quit0_mask.bmp");
	loadimage(&quit1, "image\\quit1.bmp");
	loadimage(&quit1_mask, "image\\quit1_mask.bmp");
	loadimage(&pencent0, "image\\pencent0.bmp");
	loadimage(&pencent0_mask, "image\\pencent0_mask.bmp");
	loadimage(&pencent1, "image\\pencent1.bmp");
	loadimage(&pencent1_mask, "image\\pencent1_mask.bmp");
	loadimage(&zero, "image\\0.bmp");
	loadimage(&zero_mask, "image\\0_mask.bmp");
	loadimage(&zero0, "image\\00.bmp");
	loadimage(&zero0_mask, "image\\00_mask.bmp");
	loadimage(&zero1, "image\\01.bmp");
	loadimage(&zero1_mask, "image\\01_mask.bmp");
	loadimage(&one, "image\\1.bmp");
	loadimage(&one_mask, "image\\1_mask.bmp");
	loadimage(&one0, "image\\10.bmp");
	loadimage(&one0_mask, "image\\10_mask.bmp");
	loadimage(&one1, "image\\11.bmp");
	loadimage(&one1_mask, "image\\11_mask.bmp");
	loadimage(&two, "image\\2.bmp");
	loadimage(&two_mask, "image\\2_mask.bmp");
	loadimage(&two0, "image\\20.bmp");
	loadimage(&two0_mask, "image\\20_mask.bmp");
	loadimage(&two1, "image\\21.bmp");
	loadimage(&two1_mask, "image\\21_mask.bmp");
	loadimage(&three, "image\\3.bmp");
	loadimage(&three_mask, "image\\3_mask.bmp");
	loadimage(&three0, "image\\30.bmp");
	loadimage(&three0_mask, "image\\30_mask.bmp");
	loadimage(&three1, "image\\31.bmp");
	loadimage(&three1_mask, "image\\31_mask.bmp");
	loadimage(&four, "image\\4.bmp");
	loadimage(&four_mask, "image\\4_mask.bmp");
	loadimage(&four0, "image\\40.bmp");
	loadimage(&four0_mask, "image\\40_mask.bmp");
	loadimage(&four1, "image\\41.bmp");
	loadimage(&four1_mask, "image\\41_mask.bmp");
	loadimage(&five, "image\\5.bmp");
	loadimage(&five_mask, "image\\5_mask.bmp");
	loadimage(&five0, "image\\50.bmp");
	loadimage(&five0_mask, "image\\50_mask.bmp");
	loadimage(&five1, "image\\51.bmp");
	loadimage(&five1_mask, "image\\51_mask.bmp");
	loadimage(&six, "image\\6.bmp");
	loadimage(&six_mask, "image\\6_mask.bmp");
	loadimage(&six0, "image\\60.bmp");
	loadimage(&six0_mask, "image\\60_mask.bmp");
	loadimage(&six1, "image\\61.bmp");
	loadimage(&six1_mask, "image\\61_mask.bmp");
	loadimage(&seven, "image\\7.bmp");
	loadimage(&seven_mask, "image\\7_mask.bmp");
	loadimage(&seven0, "image\\70.bmp");
	loadimage(&seven0_mask, "image\\70_mask.bmp");
	loadimage(&seven1, "image\\71.bmp");
	loadimage(&seven1_mask, "image\\71_mask.bmp");
	loadimage(&eight, "image\\8.bmp");
	loadimage(&eight_mask, "image\\8_mask.bmp");
	loadimage(&eight0, "image\\80.bmp");
	loadimage(&eight0_mask, "image\\80_mask.bmp");
	loadimage(&eight1, "image\\81.bmp");
	loadimage(&eight1_mask, "image\\81_mask.bmp");
	loadimage(&nine, "image\\9.bmp");
	loadimage(&nine_mask, "image\\9_mask.bmp");
	loadimage(&nine0, "image\\90.bmp");
	loadimage(&nine0_mask, "image\\90_mask.bmp");
	loadimage(&nine1, "image\\91.bmp");
	loadimage(&nine1_mask, "image\\91_mask.bmp");
	loadimage(&yamame, "image\\yamame.bmp");
	loadimage(&yamame_mask, "image\\yamame_mask.bmp");
	loadimage(&front, "image\\front.bmp");
	loadimage(&front_mask, "image\\front_mask.bmp");
	loadimage(&star, "image\\star.bmp");
	loadimage(&star_mask, "image\\star_mask.bmp");
	loadimage(&dummy, "image\\dummy.bmp");
	loadimage(&dummy_mask, "image\\dummy_mask.bmp");
	loadimage(&bullet_boss1, "image\\bullet_boss1.bmp");
	loadimage(&bullet_boss1_mask, "image\\bullet_boss1_mask.bmp");
	loadimage(&bullet_boss2, "image\\bullet_boss2.bmp");
	loadimage(&bullet_boss2_mask, "image\\bullet_boss2_mask.bmp");
	loadimage(&bullet_boss3, "image\\bullet_boss3.bmp");
	loadimage(&bullet_boss3_mask, "image\\bullet_boss3_mask.bmp");
	loadimage(&point_b, "image\\point_b.bmp");
	loadimage(&point_b_mask, "image\\point_b_mask.bmp");
	loadimage(&point_r, "image\\point_r.bmp");
	loadimage(&point_r_mask, "image\\point_r_mask.bmp");
	loadimage(&point_g, "image\\point_g.bmp");
	loadimage(&point_g_mask, "image\\point_g_mask.bmp");
	loadimage(&back1, "image\\back1.bmp");
	loadimage(&back1_mask, "image\\back1_mask.bmp");
	loadimage(&back2, "image\\back2.bmp");
	loadimage(&back2_mask, "image\\back2_mask.bmp");
	loadimage(&back3, "image\\back3.bmp");
	loadimage(&back3_mask, "image\\back3_mask.bmp");
	loadimage(&back4, "image\\back4.bmp");
	loadimage(&back4_mask, "image\\back4_mask.bmp");
	loadimage(&card, "image\\card.bmp");
	loadimage(&card_mask, "image\\card_mask.bmp");
	mciSendString("open sound\\select.mp3 alias select", NULL, 0, NULL);
	mciSendString("open sound\\break_reimu.mp3 alias break_reimu", NULL, 0, NULL);
	position_x = 420;	//初始化数据
	position_y = 800;
	boss_x = 420;
	boss_y = 300;
	boss_hp = 100;
	quitjudge = 0;
	hurtjudge = 1;
	cardjudge = 0;
	turn = 0;
	reimu_move = 0;
	*bossjudge = 0;
	*player = 3;
	*power = 2;
	*point = 0;
	starttime = time(NULL);
	for (i = 0;i < 15;i++) {
		bullet1_x[i] = 1000;
		bullet1_y[i] = -100;
		bullet2_x[i] = 1000;
		bullet2_y[i] = -100;
	}
	for (i = 0;i < 5;i++) {
		enemy01[i].x = 0 - i * 100;
		enemy01[i].y = 80 + i * 5;
		enemy01[i].hp = 8;
		enemy01[i].bullet_x = -10;
		enemy01[i].bullet_y = -10;
		enemy01[i].point = rand() % 2;
		enemy01[i].point_x = -10;
		enemy01[i].point_y = -10;
		enemy01[i].speed = 1.8;
	}
}

void shownumber(int number,int x,int y) //用来显示数字的函数（防止show函数太冗杂） 
{
	switch (number) {
	case 0:
		putimage(x, y, &zero_mask, SRCAND);
		putimage(x, y, &zero, SRCPAINT);
		break;
	case 1:
		putimage(x, y, &one_mask, SRCAND);
		putimage(x, y, &one, SRCPAINT);
		break;
	case 2:
		putimage(x, y, &two_mask, SRCAND);
		putimage(x, y, &two, SRCPAINT);
		break;
	case 3:
		putimage(x, y, &three_mask, SRCAND);
		putimage(x, y, &three, SRCPAINT);
		break;
	case 4:
		putimage(x, y, &four_mask, SRCAND);
		putimage(x, y, &four, SRCPAINT);
		break;
	case 5:
		putimage(x, y, &five_mask, SRCAND);
		putimage(x, y, &five, SRCPAINT);
		break;
	case 6:
		putimage(x, y, &six_mask, SRCAND);
		putimage(x, y, &six, SRCPAINT);
		break;
	case 7:
		putimage(x, y, &seven_mask, SRCAND);
		putimage(x, y, &seven, SRCPAINT);
		break;
	case 8:
		putimage(x, y, &eight_mask, SRCAND);
		putimage(x, y, &eight, SRCPAINT);
		break;
	case 9:
		putimage(x, y, &nine_mask, SRCAND);
		putimage(x, y, &nine, SRCPAINT);
		break;
	}
}

void showmenu()	//专门用来实现主菜单功能的函数
{
	mciSendString("open sound\\地霊達の起床.mp3 alias 01", NULL, 0, NULL);
	mciSendString("play 01 repeat", NULL, 0, NULL);
	putimage(0, 0, &menu);
	putimage(960, 680, &start0_mask, SRCAND);
	putimage(960, 680, &start0, SRCPAINT);
	putimage(960, 780, &playerdata1_mask, SRCAND);
	putimage(960, 780, &playerdata1, SRCPAINT);
	putimage(960, 880, &quit1_mask, SRCAND);
	putimage(960, 880, &quit1, SRCPAINT);
	char ch;
	int type = 0;
	quitjudge = 0;
	int score[10];
	int t,point0;
	int i = 0, j = 0;
	BeginBatchDraw();
	while (1) {
		if (kbhit()) {
			ch = getch();	//根据type不同显示不同图片（同一个单词的亮暗来表示是否被选中）
			if (ch == 'k'&&type<2) {	//输入“k”表示下一个选项，type+1
				mciSendString(("close select"), NULL, 0, NULL);
				mciSendString("open sound\\select.mp3 alias select", NULL, 0, NULL);
				mciSendString("play select", NULL, 0, NULL);
				type++;
			}
			else if (ch == 'i' && type > 0&&type<3) {	//输入“i”表示下一个选项，type-1
				mciSendString(("close select"), NULL, 0, NULL);
				mciSendString("open sound\\select.mp3 alias select", NULL, 0, NULL);
				mciSendString("play select", NULL, 0, NULL);
				type--;
			}
			if (ch == 13) {		//输入回车表示确认
				if (type == 0) {
					mciSendString(("close select"), NULL, 0, NULL);
					mciSendString("open sound\\select.mp3 alias select", NULL, 0, NULL);
					mciSendString("play select", NULL, 0, NULL);
					EndBatchDraw();
					return;
				}
				else if (type == 1) {
					mciSendString(("close select"), NULL, 0, NULL);
					mciSendString("open sound\\select.mp3 alias select", NULL, 0, NULL);
					mciSendString("play select", NULL, 0, NULL);
					type = 3;
				}
				else if (type == 2) {
					mciSendString(("close select"), NULL, 0, NULL);
					mciSendString("open sound\\select.mp3 alias select", NULL, 0, NULL);
					mciSendString("play select", NULL, 0, NULL);
					exit(0);
				}
			}
			switch (type)
			{
			case 0:
				putimage(960, 680, &start0_mask, SRCAND);
				putimage(960, 680, &start0, SRCPAINT);
				putimage(960, 780, &playerdata1_mask, SRCAND);
				putimage(960, 780, &playerdata1, SRCPAINT);
				putimage(960, 880, &quit1_mask, SRCAND);
				putimage(960, 880, &quit1, SRCPAINT);
				break;

			case 1:
				putimage(960, 680, &start1_mask, SRCAND);
				putimage(960, 680, &start1, SRCPAINT);
				putimage(960, 780, &playerdata0_mask, SRCAND);
				putimage(960, 780, &playerdata0, SRCPAINT);
				putimage(960, 880, &quit1_mask, SRCAND);
				putimage(960, 880, &quit1, SRCPAINT);
				break;

			case 2:
				putimage(960, 680, &start1_mask, SRCAND);
				putimage(960, 680, &start1, SRCPAINT);
				putimage(960, 780, &playerdata1_mask, SRCAND);
				putimage(960, 780, &playerdata1, SRCPAINT);
				putimage(960, 880, &quit0_mask, SRCAND);
				putimage(960, 880, &quit0, SRCPAINT);
				break;

			case 3:
				FILE * fp;
				fp = fopen("rank.txt", "r");
				fscanf(fp, "%d %d %d %d %d %d %d %d %d %d", &score[0], &score[1], &score[2], &score[3], &score[4], &score[5], &score[6], &score[7], &score[8], &score[9]);
				fclose(fp);
				for (i = 0;i < 10;i++) {
					if (i < 9) {
						shownumber(0, width + 200, high1 + i * 40);
						shownumber(i+1, width + 200, high1 + i * 40);
					}
					else {
						shownumber(1, width + 200, high1 + i * 40);
						shownumber(0, width + 200, high1 + i * 40);
					}
					point0 = score[i];
					for (j = 0, t = 1000;j < 4;j++) {
						shownumber(point0 / t, width+300+j*35, high1+i*40);
						point0 %= t;
						t /= 10;
					}
				}
				if (ch == 27) {
					type = 1;
				}
				break;
			}
		}
		FlushBatchDraw();
	}
}

void show(int bossjudge,int player,int power,int point,int speed,int shifton)	//用来显示图片的函数
{
	static int i=0,k=0,mark=0;
	int choose = mark % 4;
	int j,t,point0;
	putimage(64, 0, 768, 960, &bk, 128, 1024 - i);	//显示动态背景
	if (i <= 1024) { i = i + 4; }
	else i = i - 1024 + 4;
	if (cardjudge) {
		putimage(position_x-32, position_y-16, &card_mask, SRCAND);
		putimage(position_x-32, position_y-16, &card, SRCPAINT);
	}
	if (reimu_move == 0) {
		putimage(position_x, position_y, &reimu_mask, SRCAND);
		putimage(position_x, position_y, &reimu, SRCPAINT);
	}
	else if (reimu_move == 1) {
		putimage(position_x, position_y, &reimu_left_mask, SRCAND);
		putimage(position_x, position_y, &reimu_left, SRCPAINT);
	}
	else if (reimu_move == 2) {
		putimage(position_x, position_y, &reimu_right_mask, SRCAND);
		putimage(position_x, position_y, &reimu_right, SRCPAINT);
	}
	if (shifton) {		//按住shift显示判定点
		putimage(position_x + 24, position_y + 40, &dummy_mask, SRCAND);
		putimage(position_x + 24, position_y + 40, &dummy, SRCPAINT);
	}
	for(j = 0;j < 5;j++) {
		if (enemy01[j].y > -100) {
			putimage(enemy01[j].x, enemy01[j].y, &enemy_br_mask, SRCAND);
			putimage(enemy01[j].x, enemy01[j].y, &enemy_br, SRCPAINT);
		}
	}
	for (j = 0;j < 5;j++) {
		if (enemy01[j].point_y > -10) {
			switch (enemy01[j].point) {
			case 0:
				putimage(enemy01[j].point_x, enemy01[j].point_y, &point_b_mask, SRCAND);
				putimage(enemy01[j].point_x, enemy01[j].point_y, &point_b, SRCPAINT);
				break;
			case 1:
				putimage(enemy01[j].point_x, enemy01[j].point_y, &point_r_mask, SRCAND);
				putimage(enemy01[j].point_x, enemy01[j].point_y, &point_r, SRCPAINT);
				break;
			case 2:
				putimage(enemy01[j].point_x, enemy01[j].point_y, &point_g_mask, SRCAND);
				putimage(enemy01[j].point_x, enemy01[j].point_y, &point_g, SRCPAINT);
				break;
			}
		}
	}
	for (j = 0;j < 15;j++) {
		if (bullet1_y[j] > -100) {
			putimage(bullet1_x[j], bullet1_y[j], &bullet_reimu_mask, SRCAND);
			putimage(bullet1_x[j], bullet1_y[j], &bullet_reimu, SRCPAINT);
			putimage(bullet2_x[j], bullet2_y[j], &bullet_reimu_mask, SRCAND);
			putimage(bullet2_x[j], bullet2_y[j], &bullet_reimu, SRCPAINT);
		}
	}
	if (bossjudge > 0) {	
		switch (choose) {
		case 0:
			putimage(boss_x - 64, boss_y - 64, &back1_mask, SRCAND);
			putimage(boss_x - 64, boss_y - 64, &back1, SRCPAINT);
			break;
		case 1:
			putimage(boss_x - 96, boss_y - 96, &back2_mask, SRCAND);
			putimage(boss_x - 96, boss_y - 96, &back2, SRCPAINT);
			break;
		case 2:
			putimage(boss_x - 128, boss_y - 128, &back3_mask, SRCAND);
			putimage(boss_x - 128, boss_y - 128, &back3, SRCPAINT);
			break;
		case 3:
			putimage(boss_x - 96, boss_y - 96, &back4_mask, SRCAND);
			putimage(boss_x - 96, boss_y - 96, &back4, SRCPAINT);
			break;
		}
		k++;
		if (k == 20) {
			mark++;
			k = 0;
		}
		putimage(boss_x - 32, boss_y - 32, &yamame_mask, SRCAND);
		putimage(boss_x - 32, boss_y - 32, &yamame, SRCPAINT);
		switch (bossjudge) {
		case 1:
			for ( t = 0; b1[t].vx != max1; t++) {
				if (b1[t].x > 0 && b1[t].x < high1 && b1[t].y>0 && b1[t].y < width) {//界内子弹才显示
					putimage(b1[t].x, b1[t].y, &bullet_boss1_mask, SRCAND);
					putimage(b1[t].x, b1[t].y, &bullet_boss1, SRCPAINT);
				}
			}
			break;
		case 2:
			for (t = 0; b2[t].vx != max1; t++) {
				if (b2[t].x > 0 && b2[t].x < high1 && b2[t].y>0 && b2[t].y < width) {//界内子弹才显示
					putimage(b2[t].x, b2[t].y, &bullet_boss2_mask, SRCAND);
					putimage(b2[t].x, b2[t].y, &bullet_boss2, SRCPAINT);
				}
			}
		case 3:
			for (t = 0; b3[t].vx != max1; t++) {
				if (b3[t].x > 0 && b3[t].x < high1 && b3[t].y>0 && b3[t].y < width) {//界内子弹才显示
					putimage(b3[t].x, b3[t].y, &bullet_boss3_mask, SRCAND);
					putimage(b3[t].x, b3[t].y, &bullet_boss3, SRCPAINT);
				}
			}
		}
	}
	
	
	putimage(0, 0, &window_mask, SRCAND);	//在所有画面之上显示窗口图片
	putimage(0, 0, &window, SRCPAINT);
	putimage(860, 200, &front_mask, SRCAND);
	putimage(860, 200, &front, SRCPAINT);
	point0 = point;
	for (j = 0,t=1000;j < 4;j++) {
		shownumber(point0 / t, 1040 + j * 32, 185);
		point0 %= t;
		t /= 10;
	}
	for (j = 0;j < player;j++) {
		putimage(1040 + j * 36, 235, &star_mask, SRCAND);
		putimage(1040 + j * 36, 235, &star, SRCPAINT);
	}
	for (j = 0;j < power;j++) {
		putimage(1040 + j * 36, 280, &star_mask, SRCAND);
		putimage(1040 + j * 36, 280, &star, SRCPAINT);
	}
	FlushBatchDraw();
}

void bullet(int judge)	//用来计算和储存子弹的函数
{
	static int i = 0, time = 0 ;
	int j;
	if (judge == 1) {
		time++;		//用来控制子弹间隔
		if (time > 24) {
			bullet1_x[i] = position_x;
			bullet1_y[i] = position_y - 40;
			bullet2_x[i] = position_x + 36;
			bullet2_y[i] = position_y - 40;
			i++;
			time = 0;
		}
		
		for (j = 0;j < i;j++) {
			bullet1_y[j] -= 5;
			bullet2_y[j] -= 5;
		}
		for (j = i + 1;j < 10;j++) {
			bullet1_y[j] -= 5;
			bullet2_y[j] -= 5;
		}
		if (i == 9) {
			i = 0;
		}
	}
	else {
		time++;
		if (time > 24) {
			bullet1_y[i] = -100;
			bullet2_y[i] = -100;
			i++;
			time = 0;
		}
		
		for (j = 0;j < i;j++) {
			bullet1_y[j] -= 5;
			bullet2_y[j] -= 5;
		}
		for (j = i + 1;j < 10;j++) {
			bullet1_y[j] -= 5;
			bullet2_y[j] -= 5;
		}
		if (i == 9) {
			i = 0;
		}
	}
}

void updateWithoutInput(int* player,int* power,int* point,int* bossjudge)	//用来处理与用户输入无关的更新的函数
{
	static int move_x = 0, move_y = 0, enemyspeed = 2, t = 0;
	int i,j;
	static time_t sec ;		//通过现在时间减去初始时间来计时
	sec = time(NULL);
	if (turn == 0) {
		if (difftime(sec,starttime) >= 5) {
			for (i = 0;i < 5;i++) {
				enemy01[i].x += enemy01[i].speed;
				enemy01[i].y += 0.2;
				
				if (enemy01[i].x == width+80) {
					enemy01[i].speed = -enemy01[i].speed;
				}
			}

			for (i = 0;i < 10;i++) {
				for (j = 0;j < 5;j++) {
					if (bullet1_x[i]<enemy01[j].x + 64 && bullet1_x[i]>enemy01[j].x && bullet1_y[i]<enemy01[j].y + 64 && bullet1_y[i] >enemy01[j].y || bullet2_x[i]<enemy01[j].x + 64 && bullet2_x[i]>enemy01[j].x && bullet2_y[i] < enemy01[j].y + 64 && bullet2_y[i] + 32 > enemy01[j].y || bullet1_x[i] + 32 >= enemy01[j].x && bullet1_x[i]+32<=enemy01[j].x+64 && bullet1_y[i]<enemy01[j].y + 64 && bullet1_y[i] >enemy01[j].y || bullet2_x[i] + 32 >= enemy01[j].x && bullet2_x[i] + 32 <= enemy01[j].x + 64 && bullet2_y[i]<enemy01[j].y + 64 && bullet2_y[i] >enemy01[j].y) {
						enemy01[j].hp--;
						bullet1_y[i] = -100;
						bullet2_y[i] = -100;
						if (enemy01[j].hp == 0) {
							enemy01[j].point_x = enemy01[j].x + 32;
							enemy01[j].point_y = enemy01[j].y + 64;
							putimage(enemy01[j].x - 32, enemy01[j].y - 32, &enemydead_mask, SRCAND);
							putimage(enemy01[j].x-32, enemy01[j].y-32, &enemydead, SRCPAINT);
							FlushBatchDraw();
							enemy01[j].x = 1000;
							enemy01[j].y = 1000;
							bullet1_y[i] = -100;
							bullet2_y[i] = -100;
						}
					}
				}
			}
			for (i = 0;i < 5;i++) {
				if (enemy01[i].point_y > -10&&enemy01[i].point_y<2000) {
					enemy01[i].point_y += 1;
					if (enemy01[i].point_x + 32 >= position_x && enemy01[i].x + 32 <= position_x + 64 && enemy01[i].point_y + 32 <= position_y + 92 && enemy01[i].point_y + 32 >= position_y || enemy01[i].point_x<= position_x + 64 && enemy01[i].point_x>=position_x && enemy01[i].point_y + 32 >= position_y && enemy01[i].point_y + 32 <= position_y+92) {
						enemy01[i].point_y = -10;
						*point += 50;
					}
				}
			}
		}
		if (difftime(sec, starttime) == 17) {
			turn = 1;
			for (i = 0;i < 5;i++) {
				enemy01[i].x = width + i * 100 + 50;
				enemy01[i].y = 80 - i * 5;
				enemy01[i].hp = 8;
				enemy01[i].bullet_x = -10;
				enemy01[i].bullet_y = -10;
				enemy01[i].point = rand() % 2;
				enemy01[i].point_x = -10;
				enemy01[i].point_y = -10;
				enemy01[i].speed = -1.8;
			}
		}
	}
	if (turn == 1) {
		if (difftime(sec, starttime) >= 18) {
			for (i = 0;i < 5;i++) {
				enemy01[i].x += enemy01[i].speed;
				enemy01[i].y += 0.2;

				if (enemy01[i].x == 0) {
					enemy01[i].speed = -enemy01[i].speed;
				}
			}

			for (i = 0;i < 10;i++) {
				for (j = 0;j < 5;j++) {
					if (bullet1_x[i]<enemy01[j].x + 64 && bullet1_x[i]>enemy01[j].x && bullet1_y[i]<enemy01[j].y + 64 && bullet1_y[i] >enemy01[j].y || bullet2_x[i]<enemy01[j].x + 64 && bullet2_x[i]>enemy01[j].x && bullet2_y[i] < enemy01[j].y + 64 && bullet2_y[i] + 32 > enemy01[j].y || bullet1_x[i] + 32 >= enemy01[j].x && bullet1_x[i] + 32 <= enemy01[j].x + 64 && bullet1_y[i]<enemy01[j].y + 64 && bullet1_y[i] >enemy01[j].y || bullet2_x[i] + 32 >= enemy01[j].x && bullet2_x[i] + 32 <= enemy01[j].x + 64 && bullet2_y[i]<enemy01[j].y + 64 && bullet2_y[i] >enemy01[j].y) {
						enemy01[j].hp--;
						bullet1_y[i] = -100;
						bullet2_y[i] = -100;
						if (enemy01[j].hp == 0) {
							enemy01[j].point_x = enemy01[j].x + 32;
							enemy01[j].point_y = enemy01[j].y + 64;
							putimage(enemy01[j].x - 32, enemy01[j].y - 32, &enemydead_mask, SRCAND);
							putimage(enemy01[j].x - 32, enemy01[j].y - 32, &enemydead, SRCPAINT);
							FlushBatchDraw();
							enemy01[j].x = -100;
							enemy01[j].y = -100;
							bullet1_y[i] = -100;
							bullet2_y[i] = -100;
						}
					}
				}
			}
			for (i = 0;i < 5;i++) {
				if (enemy01[i].point_y > -10 && enemy01[i].point_y < 2000) {
					enemy01[i].point_y += 1;
					if (enemy01[i].point_x + 32 >= position_x && enemy01[i].x + 32 <= position_x + 64 && enemy01[i].point_y + 32 <= position_y + 92 && enemy01[i].point_y + 32 >= position_y || enemy01[i].point_x <= position_x + 64 && enemy01[i].point_x >= position_x && enemy01[i].point_y + 32 >= position_y && enemy01[i].point_y + 32 <= position_y + 92) {
						enemy01[i].point_y = -10;
						*point = *point + 50;
					}
				}
			}
		}
	}
	if (difftime(sec,starttime) == 36) {
		*bossjudge = 1;
		mciSendString(("close 02"), NULL, 0, NULL);
		mciSendString("open sound\\封じられた妖怪.mp3 alias 03", NULL, 0, NULL);
		mciSendString("play 03 repeat", NULL, 0, NULL);
		mciSendString("open sound\\break.mp3 alias select", NULL, 0, NULL);
		turn = 2;
	}
	if (cardjudge) {
		if (*power == 1) {
			static time_t cardstart1 = time(NULL);
			time_t cardend1;
			time(&cardend1);
			if (difftime(cardend1, cardstart1) == 3) {
				cardjudge = 0;
				hurtjudge = 1;
			}
		}
		else if (*power == 0) {
			static time_t cardstart2 = time(NULL);
			time_t cardend2;
			time(&cardend2);
			if (difftime(cardend2, cardstart2) == 3) {
				cardjudge = 0;
				hurtjudge = 1;
			}
		}
	}
	if (hurtjudge == 0&&cardjudge==0) {
		if (t==1) {
			mciSendString(("close break_reimu"), NULL, 0, NULL);
			mciSendString("open sound\\break_reimu.mp3 alias break_reimu", NULL, 0, NULL);
			mciSendString("play break_reimu", NULL, 0, NULL);
		}
		if (*player == 2) {
			t++;
			static time_t nohurtstart1 = time(NULL);
			time_t nohurtend1;
			time(&nohurtend1);
			if (difftime(nohurtend1, nohurtstart1) == 3) {
				hurtjudge = 1;
				t = 0;
			}
		}
		if (*player == 1) {
			t++;
			static time_t nohurtstart2 = time(NULL);
			time_t nohurtend2;
			time(&nohurtend2);
			if (difftime(nohurtend2, nohurtstart2) == 3) {
				hurtjudge = 1;
				t = 0;
			}
		}
		if (*player == 0) {
			t++;
			static time_t nohurtstart3 = time(NULL);
			time_t nohurtend3;
			time(&nohurtend3);
			if (difftime(nohurtend3, nohurtstart3) == 3) {
				hurtjudge = 1;
				t = 0;
			}
		}
	}

	if (*player == -1) {
		*point = *point + 10 * (100 - boss_hp);
		mciSendString(("close break_reimu"), NULL, 0, NULL);
		mciSendString("open sound\\break_reimu.mp3 alias break_reimu", NULL, 0, NULL);
		mciSendString("play break_reimu", NULL, 0, NULL);
		system("pause");
		quitjudge = 1;
	}
}

void updateWithInput(int *speed,int *shifton,int *power)	//用来处理与用户输入有关的更新的函数
{
	if (GetAsyncKeyState(VK_UP) & 0x8000 && position_y > 40) {
		position_y -= *speed;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 && position_y < 840) {
		position_y += *speed;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && position_x > 70) {
		position_x -= *speed;
		reimu_move = 1;
	}else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && position_x < 770) {
		position_x += *speed;
		reimu_move = 2;
	}
	else {
		reimu_move = 0;
	}
	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000) {
		*speed = 1;
		*shifton = 1;
	}
	else {
		*speed = 2;
		*shifton = 0;
	}
	if (GetAsyncKeyState('Z') & 0x8000) {
		bullet(1);
	}
	else {
		bullet(0);
	}
	if (GetAsyncKeyState('X') & 0x1) {
		if (cardjudge == 0&&*power>0) {
			cardjudge = 1;
			hurtjudge = 0;
			*power = *power - 1;
		}
	}
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
		quitjudge = 1;
		return;
	}
}

void boss(int *bossjudge,int *bossbulletspeed,int *point,int *player)	//专门用来计算boss位置和boss弹幕的函数
{
	static int mark1 = 0;
	static int mark2 = 0;
	static int mark3 = 0;
	static int movejudge = 0;
	static time_t sec;
	sec = time(NULL);
	int i;

	if (*bossjudge > 0) {
		for (i = 0;i < 15;i++) {
			if (bullet1_x[i]<boss_x + 64 && bullet1_x[i]>boss_x && bullet1_y[i]<boss_y + 64 && bullet1_y[i]>boss_y || bullet2_x[i]<boss_x + 64 && bullet2_x[i]>boss_x && bullet2_y[i] < boss_y + 64 && bullet2_y[i] > boss_y) {
				boss_hp--;
				bullet1_y[i] = -1000;
				bullet2_y[i] = -1000;
			}
		}
	}
	switch (*bossjudge) {
	case 0:
		break;
	
	case 1:
		if (mark1 < 2000) {
			b1[mark1].x = boss_x + len * cos(angle1);
			b1[mark1].y = boss_y + len * sin(angle1); //通过数学计算得到初始位置，注意三角函数用弧度
			b1[mark1].vx = bspeed1 * cos(angle1);
			b1[mark1].vy = bspeed1 * sin(angle1)-2;      //通过数学计算得到初始速度
			angle1 = angle1 + 2 * PI / 5;               //5等分一个圆
			if (mark1 % 5 == 0 && mark1 % 400 < 200) {
				angle1 += PI / 15;                      //每五发控制偏转一次
			}
			if (mark1 % 5 == 0 && mark1 % 400 >= 200) {
				angle1 -= PI / 15;
			}
			for (int t = 0; b1[t].vx != max1; t++) {
				if (b1[t].x > 0 && b1[t].x < width && b1[t].y>0 && b1[t].y < high1) {//界内子弹才显示
					b1[t].x += b1[t].vx;
					b1[t].y += b1[t].vy;
				}
			}
			
			if (difftime(sec, starttime) >= 38 && difftime(sec, starttime) <= 41 || difftime(sec, starttime) >= 43 && difftime(sec, starttime) <= 46 || difftime(sec, starttime) >= 48 && difftime(sec, starttime) <= 51) {
				movejudge = 1;
				mark1++;
			}
			else if(movejudge) {
				boss_x = rand() % 750 + 125;
				movejudge = 0;
			}
			if (hurtjudge) {
				for (i = 0;i < mark1;i++) {
					if (b1[i].x > 0 && b1[i].x < width && b1[i].y>0 && b1[i].y < high1) {
						if (b1[i].x + 32 >= position_x + 24 && b1[i].x + 32 <= position_x + 40 && b1[i].y + 32 >= position_y + 40 && b1[i].y + 32 <= position_y + 56 || b1[i].x >= position_x + 24 && b1[i].x <= position_x + 40 && b1[i].y + 32 >= position_y + 40 && b1[i].y + 32 <= position_y + 56 ) {
							*player -= 1;
							hurtjudge = 0;
						}
					}
				}
			}
			if (difftime(sec, starttime) >= 52 || boss_hp <= 40) {
				mciSendString(("close break"), NULL, 0, NULL);
				mciSendString("open sound\\break.mp3 alias break", NULL, 0, NULL);
				mciSendString("play break", NULL, 0, NULL);
				boss_x = 300;
				boss_y = 260;
				*bossbulletspeed = 4;
				*bossjudge = 2;
				*point = *point + 10 * (100 - boss_hp);
			}
		}
		break;

	case 2:
		if (mark2 < 10000) {
			b2[mark2].x = boss_x + len * cos(angle2);
			b2[mark2].y = boss_y + len * sin(angle2); //通过数学计算得到初始位置，注意三角函数用弧度
			b2[mark2].vx = bspeed1 * cos(angle2);
			b2[mark2].vy = bspeed1 * sin(angle2) - 2;      //通过数学计算得到初始速度
			angle2 = angle2 + 2 * PI / 5;               //5等分一个圆
			if (mark2 % 5 == 0 && mark2 % 400 < 200) {
				angle2 += PI / 15;                      //每五发控制偏转一次
			}
			if (mark2 % 5 == 0 && mark2 % 400 >= 200) {
				angle2 -= PI / 15;
			}
			for (int t = 0; b2[t].vx != max1; t++) {
				if (b2[t].x > 0 && b2[t].x < width && b2[t].y>0 && b2[t].y < high1) {//界内子弹才显示
					b2[t].vy = b2[t].vy + 0.15;
					b2[t].x += b2[t].vx;
					b2[t].y += b2[t].vy;
				}
			}
			mark2++;
			boss_x += 0.2;
		}
		if (hurtjudge) {
			for (i = 0;i < mark1;i++) {
				if (b2[i].x > 0 && b2[i].x < width && b2[i].y>0 && b2[i].y < high1) {
					if (b2[i].x + 32 > position_x + 24 && b2[i].x + 32 < position_x + 40 && b2[i].y + 32 > position_y + 40 && b2[i].y + 32 < position_y + 56 || b2[i].x > position_x + 24 && b2[i].x < position_x + 40 && b2[i].y + 32 > position_y + 40 && b2[i].y + 32 < position_y + 56) {
						*player -= 1;
						hurtjudge = 0;
					}
				}
			}
		}
		if (boss_hp == 0 || sec - starttime == 110) {
			mciSendString(("close break"), NULL, 0, NULL);
			mciSendString("open sound\\break.mp3 alias break", NULL, 0, NULL);
			mciSendString("play break", NULL, 0, NULL);
			*point = *point + 10 * (100 - boss_hp);
			boss_hp = 100;
			boss_x = 420;
			*bossbulletspeed = 6;
			*bossjudge = 3;
		}
		break;

	case 3:
		if (mark3 < 10000) {
			b3[mark3].x = boss_x + len * cos(angle3);
			b3[mark3].y = boss_y + len * sin(angle3); //通过数学计算得到初始位置，注意三角函数用弧度
			b3[mark3].vx = bspeed1 * cos(angle3);
			b3[mark3].vy = bspeed1 * sin(angle3);      //通过数学计算得到初始速度
			angle3 = angle3 + 3 * PI / 5;               //5等分一个圆
			if (mark3 % 5 == 0) {
				angle3 += PI / 15;                      //每五发控制偏转一次
			}
			for (int t = 0; b3[t].vx != max1; t++) {
				if (b3[t].x > 0 && b3[t].x < width && b3[t].y>0 && b3[t].y < high1) {//界内子弹才显示
					double anglea = 0;
					double angleb = 0;
					double at = 0.1;
					anglea = atan(b3[t].vy / b3[t].vx);
					angleb = PI / 2 - anglea;
					double ax = at * cos(angleb);
					double ay = at * sin(angleb);
					if (b3[t].vx >= 0 && b3[t].vy <= 0) {
						b3[t].vy = b3[t].vy + ay;
						b3[t].vx = b3[t].vx + ax;
					}
					else if (b3[t].vx >= 0 && b3[t].vy >= 0) {
						b3[t].vy = b3[t].vy + ay;
						b3[t].vx = b3[t].vx - ax;
					}
					else if (b2[t].vx <= 0 && b2[t].vy >= 0) {
						b3[t].vy = b3[t].vy - ay;
						b3[t].vx = b3[t].vx - ax;
					}
					else {
						b3[t].vy = b3[t].vy - ay;
						b3[t].vx = b3[t].vx + ax;
					}
					b3[t].vy += 0.1;
					b3[t].x += b3[t].vx;
					b3[t].y += b3[t].vy;
				}
			}
			mark3++;
			if (hurtjudge) {
				for (i = 0;i < mark1;i++) {
					if (b3[i].x > 0 && b3[i].x < width && b3[i].y>0 && b3[i].y < high1) {
						if (b3[i].x + 32 > position_x + 24 && b3[i].x + 32 < position_x + 40 && b3[i].y + 32 > position_y + 40 && b3[i].y + 32 < position_y + 56 || b3[i].x > position_x + 24 && b3[i].x < position_x + 40 && b3[i].y + 32 > position_y + 40 && b3[i].y + 32 < position_y + 56) {
							*player -= 1;
							hurtjudge = 0;
						}
					}
				}
			}
			if (boss_hp == 0) {
				mciSendString(("close break"), NULL, 0, NULL);
				mciSendString("open sound\\break.mp3 alias break", NULL, 0, NULL);
				mciSendString("play break", NULL, 0, NULL);
				boss_y = -100;
				*point = *point + 10 * (100 - boss_hp);
				*bossjudge = 0;
				Sleep(100);
				system("pause");
				quitjudge = 1;
			}
		}
	}
}

void rank(int point)
{
	int score[10]={0};
	int i, j, t;
	FILE* fp;
	int n = 0;
	fp = fopen("rank.txt", "r");
	if (fp == NULL)
	{
		printf("cannot open the files\n");
		system("pause");
	}
	fscanf(fp, "%d %d %d %d %d %d %d %d %d %d", &score[0], &score[1], &score[2], &score[3], &score[4], &score[5], &score[6], &score[7], &score[8], &score[9] );
	for (i = 0;i < 9;i++) {
		for (j = 0;j < 9;j++){
			if (score[j] > score[j + 1])
			{
				t = score[j];
				score[j] = score[j + 1];
				score[j+1] = t;
			}
		}
	}
	for (i = 9;i >= 0;i--) {
		if (point > score[i]) {
			score[i] = point;
			break;
		}
	}
	/*while (i < 10 && fscanf(fp, "%d", score[i]) != EOF)
	{
		if (point >= score[i])
		{
			score[i] = point;
		}
		i++;
	}*/
	fclose(fp);
	FILE* fp1;
	fp1 = fopen("rank.txt", "w");
	for (i = 9;i >= 0; i--)
		fprintf(fp1, "%d ", score[i]);
	fclose(fp1);
}

int main()
{
	int bossjudge = 0;	//用来判断boss阶段的变量，为0时表示boss战未开始
	int bossbulletspeed = 1;	//用来控制boss间隔的变量
	int player = 2;		//玩家生命值
	int power = 2;		//玩家能量值
	int point = 0;		//玩家分数
	int shifton = 0;	//判断玩家是否按住shift
	int speed = 2;		//玩家速度
quit:	
	startup(&bossjudge, &player, &power, &point);
	showmenu();
	mciSendString(("close 01"), NULL, 0, NULL);		//关闭主菜单音乐
	mciSendString("open sound\\暗闇の風穴.mp3 alias 02", NULL, 0, NULL);
	mciSendString("play 02 repeat", NULL, 0, NULL);		//播放道中音乐
	BeginBatchDraw();
	int i = 0;
	starttime = time(NULL);
	while (1) {
		show(bossjudge,player,power,point,speed,shifton);
		updateWithoutInput(&player,&power,&point,&bossjudge);
		if (bossjudge > 0) {
			i++;
			if (i >= bossbulletspeed) {
				boss(&bossjudge, &bossbulletspeed,&point,&player);
				i = 0;
			}
		}
		updateWithInput(&speed,&shifton,&power);
		if (quitjudge) {
			rank(point);
			if (bossjudge == 0) {
				mciSendString(("close 02"), NULL, 0, NULL);
				EndBatchDraw();
				goto quit;
			}
			else {
				mciSendString(("close 03"), NULL, 0, NULL);
				EndBatchDraw();
				goto quit;
			}
		}
	}
}
