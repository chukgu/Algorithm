/*
A graphics programme
that shows Date & Time.

Programme Name: GUI CALENDAR & CLOCK
Programmer    : Manish Kumar

WEBSITE : justcoding.in
E-MAIL  : manish@justcoding.in

Check Out other programmes at www.justcoding.in

Software Details
====================
Developed in   : C++
Compiler used  : TC++ 3.0
OS             : Window 98,2000,XP,
Vista,Windows7(only safemode)

Licence   : Freeware (Please give the credit of programming to author.)


*/


#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


#define X 470
#define Y 185
#define R 120
#define PI 3.14159265
#define color LIGHTGRAY


float angle_sec = 0, angle_min = 0, angle_hr = 0;
int init_sec = 0, init_min = 0, init_hr = 0;
int start_sec = 0, start_min = 0, start_hr = 0;
float x_hr, y_hr, x_min, y_min;



int Left = 100, Top = 120, Width = 210, Height = 210;
double _YYYY, _MM, _DD, _tempyy, _tempmm;


/************************** Functions for Designing Program ***************************************/

void DrawBox(int left, int top, int width, int height, int bgcolor)
{
	setfillstyle(SOLID_FILL, bgcolor);
	bar(left, top, left + width, top + height);

	setcolor(BLACK);
	line(left + 1, top + 1, left + width - 1, top + 1);
	line(left + 1, top + 1, left + 1, top + height - 1);
	setcolor(DARKGRAY);
	line(left, top, left + width, top);
	line(left, top, left, top + height);
	setcolor(DARKGRAY);
	line(left + 1, top + height - 1, left + width - 1, top + height - 1);
	line(left + width - 1, top + 1, left + width - 1, top + height - 1);

}

void DrawThinBox(int left, int top, int width, int height, int bgcolor)
{

	setfillstyle(SOLID_FILL, bgcolor);
	bar(left, top, left + width, top + height);


	setcolor(DARKGRAY);
	line(left + 1, top + 1, left + width - 1, top + 1);
	line(left + 1, top + 1, left + 1, top + height - 1);

	setcolor(WHITE);
	line(left + 2, top + 2, left + width - 1, top + 2);
	line(left + 2, top + 2, left + 2, top + height - 1);

	setcolor(DARKGRAY);
	line(left + 1, top + height - 1, left + width - 1, top + height - 1);
	line(left + width - 1, top + 1, left + width - 1, top + height - 1);

	setcolor(WHITE);
	line(left + 1, top + height, left + width - 1, top + height);
	line(left + width, top + 1, left + width, top + height - 1);

}

void DrawSimpleBox(int left, int top, int width, int height, int bgcolor)
{

	setfillstyle(SOLID_FILL, bgcolor);
	bar(left, top, left + width, top + height);


	setcolor(WHITE);
	line(left, top, left + width, top);
	line(left, top, left, top + height);

	setcolor(BLACK);
	line(left, top + height, left + width, top + height);
	line(left + width, top, left + width, top + height);
}



void DrawCaption(int left, int top, int width, int height, char *str, int col)
{
	setcolor(col);
	outtextxy(left + (width / 2) - (textwidth(str) / 2) + 1,
		top + (height / 2) - (textheight(str) / 2) + 1, str);
}


/******************************* Functions for Calendar *******************************************/

char *_output(double cap)
{
	double dd;
	char CDD[6], CD[6];
	int l = 0;


	dd = cap;

	gcvt(dd, 10, CDD);

	l = strlen(CDD);

	if (l == 1)
	{

		strcpy(CD, "0");
		strcat(CD, CDD);

	}

	else
	{

		strcpy(CD, CDD);

	}

	return(CD);
}

int _NumberOfDays(int month, int year)
{

	int No_of_days = 0;
	switch (month)
	{
	case 1:
		No_of_days = 31;
		break;
	case 2:
		if (!((year % 4) || !(year % 100) && (year % 400)))
			No_of_days = 29;
		else
			No_of_days = 28;
		break;
	case 3:
		No_of_days = 31;
		break;
	case 4:
		No_of_days = 30;
		break;
	case 5:
		No_of_days = 31;
		break;
	case 6:
		No_of_days = 30;
		break;
	case 7:
		No_of_days = 31;
		break;
	case 8:
		No_of_days = 31;
		break;
	case 9:
		No_of_days = 30;
		break;
	case 10:
		No_of_days = 31;
		break;
	case 11:
		No_of_days = 30;
		break;
	case 12:
		No_of_days = 31;
		break;
	}

	return No_of_days;
}


char *month(double mon)
{
	char month_name[][80] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

	return (month_name[mon - 1]);
}

int No_Of_Days(char date1[], char date2[])
{
	int d1, m1, y1;
	int d2, m2, y2;
	int _D, _M, _Y;
	int Arr[12];
	int i, count;
	y1 = (date1[6] - 48) * 1000 + (date1[7] - 48) * 100 + (date1[8] - 48) * 10 + (date1[9] - 48);
	m1 = (date1[3] - 48) * 10 + (date1[4] - 48);
	d1 = (date1[0] - 48) * 10 + (date1[1] - 48);


	y2 = (date2[6] - 48) * 1000 + (date2[7] - 48) * 100 + (date2[8] - 48) * 10 + (date2[9] - 48);
	m2 = (date2[3] - 48) * 10 + (date2[4] - 48);
	d2 = (date2[0] - 48) * 10 + (date2[1] - 48);

	if (y1 > y2 || (m1 > m2 && y1 == y2))
	{
		_D = d1;
		_M = m1;
		_Y = y1;

		d1 = d2;
		m1 = m2;
		y1 = y2;

		d2 = _D;
		m2 = _M;
		y2 = _Y;

	}



	count = 0;

	for (i = m1; i < (m2 + (y2 - y1) * 12); i++)

	{

		if (i > 12)
		{

			i = 1;
			y1 = y1 + 1;
		}



		Arr[0] = 31;
		if (!((y1 % 4) || !(y1 % 100) && (y1 % 400)))
		{
			Arr[1] = 29;
		}
		else
		{
			Arr[1] = 28;
		}
		Arr[2] = 31;
		Arr[3] = 30;
		Arr[4] = 31;
		Arr[5] = 30;
		Arr[6] = 31;
		Arr[7] = 31;
		Arr[8] = 30;
		Arr[9] = 31;
		Arr[10] = 30;
		Arr[11] = 31;

		count = count + (Arr[i - 1]);



	}

	count = count + d2 - d1;

	if (count < 0)
		count = count * -1;



	return count;
}

int Name_Of_Day()
{
	/* Assuming in 2015 on first january the day was thrusday. */
	/* Let S-1 M-2 T-3 W-4 T-5 F-6 S-7 */


	char datebuff[20];
	int _day = 5;
	int total_days = 0;


	strcpy(datebuff, "01");
	strcat(datebuff, "/");
	strcat(datebuff, _output(_MM));
	strcat(datebuff, "/");
	strcat(datebuff, _output(_YYYY));

	total_days = No_Of_Days(datebuff, "01/01/2015");

	if (_YYYY >= 2015)
	{

		for (int k = 1; k <= total_days; k++)
		{
			_day++;
			if (_day> 7)
				_day = 1;
		}
	}
	else
	{
		for (int k = 1; k <= total_days; k++)
		{
			_day--;
			if (_day< 1)
				_day = 7;
		}
	}

	return _day;

}

void WriteDays(int left, int top)
{
	int No_of_days;
	char str[20];
	int _left = left, _top = top;
	int _col = 0;


	No_of_days = _NumberOfDays((int)_MM, (int)_YYYY);

	left = left + (Name_Of_Day() - 1) * 30;

	for (int i = 0; i< No_of_days; i++)
	{


		if (left >= _left + 210)
		{
			left = _left;
			top += 30;
		}



		/*****************************/
		if (_YYYY == _tempyy && _MM == _tempmm && _DD == i + 1)
		{
			setfillstyle(SOLID_FILL, BLUE);
			bar(left - 2, top - 5, left + 15, top + 10);
			_col = 1;

		}
		/*****************************/


		if (_col == 1)
		{
			setcolor(WHITE);
			_col = 0;
		}
		else if (left == _left)
			setcolor(RED);
		else
			setcolor(BLACK);
		outtextxy(left, top, gcvt(i + 1, 10, str));
		left += 30;

	}


}

/* Drawing Calendar */

void Draw()
{

	int left = Left, top = Top;
	int _color = RED;
	char str[10];

	char days[][2] = { "S","M","T","W","T","F","S" };


	/******************************************/


	DrawBox(Left, Top, Width, Height, WHITE);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(Left + 3, Top + 3, Left + Width - 3, Top + 20);

	for (int i = 0; i<7; i++)
	{
		setcolor(_color);
		outtextxy(left + 10, top + 8, days[i]);
		left += 30;
		_color = LIGHTGRAY;
	}

	/*******************************************/


	DrawBox(Left, Top - 40, Width, 40, LIGHTGRAY);
	DrawBox(Left + 5, Top - 30, Width / 2 - 10, 20, WHITE);
	DrawBox(Left + Width / 2 + 5, Top - 30, Width / 2 - 10, 20, WHITE);

	DrawCaption(Left + 5, Top - 30, Width / 2 - 10, 20, gcvt(_YYYY, 10, str), BLUE);
	DrawCaption(Left + Width / 2 + 5, Top - 30, Width / 2 - 10, 20, month(_MM), BLUE);

}

/*************************** Functions for Clock ******************************************/

void Draw_Clock()
{
	char str[][3] = { "12","1","2","3","4","5","6","7","8","9","10","11" };
	float angle = 0, x, y;

	setcolor(WHITE);

	for (int i = 1; i <= 60; i++)
	{
		angle = angle + 6 * (PI / 180);
		x = X + (R - 32)*cos(-angle);
		y = Y - (R - 32)*sin(-angle);

		if (i % 5 != 0)
		{
			putpixel(x, y, 0);
			putpixel(x + 1, y + 1, 15);
		}
	}

	angle = 0;

	for (int j = 0; j<12; j++)
	{
		x = X + (R - 30)*sin(angle) - 6;
		y = Y - (R - 30)*cos(angle);
		angle = angle + (30 * (PI / 180));
		setcolor(0);
		outtextxy(x, y - 2, str[j]);
		setcolor(15);
		outtextxy(x + 1, y - 1, str[j]);
	}

}

void Second_Hand()
{

	float x, y, angle, x1, y1;
	char timebuf[9];
	int second;

	_strtime(timebuf);

	second = (timebuf[6] - 48) * 10 + timebuf[7] - 48;

	if (init_sec == 0)
	{
		angle_sec = angle_sec + (second * 6)*(PI / 180);
		angle_sec = angle_sec - 6 * (PI / 180);
		init_sec = 1;
		start_sec = second;
	}
	else
		angle_sec = angle_sec + 6 * (PI / 180);
	angle = angle_sec - 6 * (PI / 180);

	x = X + (R - 50)*sin(angle_sec);
	y = Y - (R - 50)*cos(angle_sec);

	x1 = X + (R - 50)*sin(angle);
	y1 = Y - (R - 50)*cos(angle);

	setlinestyle(0, 3, 1);

	/* Draw line */

	setcolor(BLACK);
	line(X, Y, x, y);

	/* Erase old line */

	setcolor(color);
	line(X, Y, x1, y1);


}


void Minute_Hand(int rotate)
{

	float angle, x1, y1;
	char timebuf[9];
	int minute;

	if (rotate == 1)
	{

		_strtime(timebuf);

		minute = (timebuf[3] - 48) * 10 + timebuf[4] - 48;

		if (init_min == 0)
		{
			angle_min = angle_min + (minute * 6)*(PI / 180);
			init_min = 1;
			start_min = minute;
		}
		else
			angle_min = angle_min + 6 * (PI / 180);
		angle = angle_min - 6 * (PI / 180);

		x_min = X + (R - 50)*sin(angle_min);
		y_min = Y - (R - 50)*cos(angle_min);

		x1 = X + (R - 50)*sin(angle);
		y1 = Y - (R - 50)*cos(angle);

		setlinestyle(0, 3, 3);

		/* Draw line */

		setcolor(BLACK);
		line(X, Y, x_min, y_min);

		/* Erase old line */

		setcolor(color);
		line(X, Y, x1, y1);

	}
	else
	{
		/* Draw line */

		setcolor(BLACK);
		line(X, Y, x_min, y_min);

	}

}

void Hour_Hand(int rotate, int min)
{

	float angle, x1, y1;
	char timebuf[9];
	int hour;

	if (rotate == 1)
	{

		_strtime(timebuf);

		hour = (timebuf[0] - 48) * 10 + timebuf[1] - 48;
		if (hour > 12)
			hour = hour - 12;
		start_hr = hour;

		if (init_hr == 0)
		{
			angle_hr = angle_hr + ((hour * 30))*(PI / 180);
			angle_hr += (min * 6)*(PI / 180);
			init_hr = 1;
		}
		else
			angle_hr = angle_hr + 6 * (PI / 180);

		angle = angle_hr - 6 * (PI / 180);

		x_hr = X + (R - 80)*sin(angle_hr);
		y_hr = Y - (R - 80)*cos(angle_hr);

		x1 = X + (R - 80)*sin(angle);
		y1 = Y - (R - 80)*cos(angle);

		setlinestyle(0, 1, 3);

		/* Draw line */

		setcolor(BLACK);
		line(X, Y, x_hr, y_hr);

		/* Erase old line */

		setcolor(color);
		line(X, Y, x1, y1);

	}

	else
	{
		/* Draw line */

		setcolor(BLACK);
		line(X, Y, x_hr, y_hr);
	}


}


/********************************* Designing the Program **************************/


void Init()
{
	char datebuff[9];
	_strdate(datebuff);
	char up[2] = { 24 };
	char down[2] = { 25 };
	char left[2] = { 27 };
	char right[2] = { 26 };

	_YYYY = 2000 + (datebuff[6] - 48) * 10 + datebuff[7] - 48;
	_MM = (datebuff[0] - 48) * 10 + datebuff[1] - 48;
	_DD = (datebuff[3] - 48) * 10 + datebuff[4] - 48;

	_tempyy = _YYYY;
	_tempmm = _MM;

	DrawSimpleBox(50, 10, 570, 450, LIGHTGRAY);
	setfillstyle(SOLID_FILL, BLUE);
	bar(55, 15, 65 + 550, 15 + 20);

	DrawThinBox(Left - 20, Top - 50, Width + 40, Height + 60, LIGHTGRAY);

	DrawThinBox(Left + Width + 40, Top - 50, Width + 20, Height + 60, LIGHTGRAY);
	DrawBox(420, 300, 90, 20, WHITE);

	DrawThinBox(150, 355, 380, 97, LIGHTGRAY);

	setcolor(WHITE);
	outtextxy(70, 22, "Date & Time");
	setcolor(0);

	outtextxy(Left, Top - 70, "Calendar");
	outtextxy(Left + Width + 60, Top - 70, "Clock");
	setcolor(1);
	outtextxy(200, 370, "Using Keys :");
	setcolor(4);
	outtextxy(202, 390, up);
	setcolor(0);
	outtextxy(204, 390, " : Increase Year,");
	setcolor(4);
	outtextxy(347, 390, down);
	setcolor(0);
	outtextxy(349, 390, " : Decrease Year");
	setcolor(4);
	outtextxy(200, 405, right);
	setcolor(0);
	outtextxy(204, 405, " : Increase Month,");
	setcolor(4);
	outtextxy(347, 405, left);
	setcolor(0);
	outtextxy(349, 405, " : Decrease Month");
	setcolor(4);
	outtextxy(200, 420, "Esc");
	setcolor(0);
	outtextxy(230, 420, ": Exit");
	setcolor(15);
	outtextxy(199, 439, "Copyright(c) Manish Kumar, 2016");
	setcolor(0);
	outtextxy(200, 440, "Copyright(c) Manish Kumar, 2016");
}



/* Display the Author Profile */

void Start()
{
	clrscr();
	textcolor(12);
	gotoxy(15, 6);
	cprintf("Program        : GUI Calendar & Clock");
	gotoxy(15, 8);
	cprintf("Programmer     : Manish Kumar");
	gotoxy(15, 10);
	cprintf("Email ID       : manish@justcoding.in");
	gotoxy(15, 12);
	cprintf("Developed in   : C++");
	gotoxy(15, 14);
	cprintf("Compiler used  : TC++ 3.0");
	gotoxy(15, 16);
	cprintf("Website        : www.justcoding.in");


	gotoxy(20, 20);
	cprintf("Press any key to continue.");
	getch();
	clrscr();
}



/************************************* Main Function *****************************************/

void main()
{
	int gd = DETECT, gm;
	int ch;

	int _min;
	int degree;
	char timebuff[9];

	Start();

	initgraph(&gd, &gm, "c://turboc3//bgi"/* path of bgi graphics */);

	/********************************************************/

	/*  Initialising Calendar  */

	Init();
	Draw();
	WriteDays(Left + 10, Top + 40);


	/********************************************************/

	/* Initialising Clock  */

	_strtime(timebuff);
	setcolor(0);
	outtextxy(435, 307, timebuff);

	/* Drawing clock, hour hand, minute hand and second hand */

	Draw_Clock();
	Minute_Hand(1);
	Second_Hand();

	_min = floor(start_min / 12);

	degree = start_min - (12 * _min);

	if (degree == 0)
		degree = 1;

	Hour_Hand(1, _min);

	/********************************************************/

	while (1) {


		for (int j = start_min; j <= 60; j++)
		{
			for (int i = start_sec; i<60; i++)
			{
				if (kbhit())
				{
					ch = getch();
					goto stop;
				}
				_strtime(timebuff);
				setcolor(0);
				outtextxy(435, 307, timebuff);

				/* Drawing dot at center of the clock */

				setcolor(0);
				setfillstyle(SOLID_FILL, 0);
				circle(X, Y, 3);
				floodfill(X, Y, 0);

				/* Drawing hour hand, minute hand and second hand */

				Second_Hand();
				Minute_Hand(0);
				Hour_Hand(0, _min);

				delay(1000);

				setcolor(15);
				outtextxy(435, 307, timebuff);
			}

			/* Drawing minute hand after 60 seconds completed */

			Minute_Hand(1);
			start_sec = 0;

			degree++;

			if (degree % 12 == 0)
				Hour_Hand(1, _min);

		}
		start_min = 1;
		degree = 1;



		/******************** Use of Arrow Key for Calendar *********************/

		while (kbhit()) {
			ch = getch();

		stop:

			switch (ch)
			{
			case 27: //Esc
				exit(0);
				break;
			case 72: // up arrow key - year increases
				if (_YYYY < 2070)
					_YYYY++;
				Draw();
				WriteDays(Left + 10, Top + 40);
				break;

			case 80: // Down arrow key - year decreases
				if (_YYYY > 1500)
					_YYYY--;

				Draw();
				WriteDays(Left + 10, Top + 40);
				break;

			case 77: // right arrow key - month increases

				if (_YYYY < 2070)
					_MM++;

				if (_MM>12 && _YYYY < 2070)
				{
					_MM = 1;
					_YYYY++;
				}

				Draw();
				WriteDays(Left + 10, Top + 40);
				break;

			case 75: // left arrow key - month decreases
				if (_YYYY>1500)
					_MM--;
				if (_MM < 1 && _YYYY > 1500)
				{
					_MM = 12;
					_YYYY--;
				}
				Draw();
				WriteDays(Left + 10, Top + 40);
				break;

			}

		}
		////////////////////////////////////////////////////////////////////
	}

}