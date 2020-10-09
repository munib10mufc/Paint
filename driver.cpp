#include "classes.h"
#include<iostream>
#include <vector>
using namespace std;
int main()
{
	vector<shape *> v;
	int point1,point2,x,y;
	int count_p=0;
	initwindow(800,600,"Paint");
	while(true)
	{
		drawplate();
		bgiout << "Hello World!!!";
		outstreamxy(61, 92);
		if(count_p>9)
		{
			count_p=0;
		}
		while(!ismouseclick(WM_LBUTTONDOWN))
		{}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		point1=x;
		point2=y;
		if((point1>0)&&(point1<30)&&(20<point2)&&(point2<51))
		{
			shape *l=new circles;
			l->draw();
			v.push_back(l);
		}

		else if((point1>30)&&(point1<55)&&(20<point2)&&(point2<51))
		{
			shape *l=new triangle;
			l->draw();
			delay(200);
			l->rotation90();
			v.push_back(l);
		}
		else if((point1>55)&&(point1<80)&&(20<point2)&&(point2<51))
		{
			shape *l=new ellipses;
			l->draw();
			v.push_back(l);
		}
		else if((point1>0)&&(point1<30)&&(51<point2)&&(point2<78))
		{
			shape *l=new rectangles;
			l->draw();
			v.push_back(l);
		}
		else if((point1>31)&&(point1<55)&&(51<point2)&&(point2<78))
		{
			shape *l=new lines;
			l->draw();
			v.push_back(l);
		}
		else if((point1>55)&&(point1<80)&&(51<point2)&&(point2<78))
		{
			shape *l=new square;
			l->draw();
			v.push_back(l);
		}
		else if((point1>85)&&(point1<115)&&(20<point2)&&(point2<49))
		{

			paint(5,count_p);
			count_p++;
		}
		else if((point1>115)&&(point1<145)&&(20<point2)&&(point2<49))
		{

			paint(2,count_p);
			count_p++;
		}
		else if((point1>145)&&(point1<175)&&(20<point2)&&(point2<49))
		{

			paint(6,count_p);
			count_p++;
		}
		else if((point1>175)&&(point1<205)&&(20<point2)&&(point2<49))
		{

			paint(8,count_p);
			count_p++;
		}
		else if((point1>85)&&(point1<115)&&(49<point2)&&(point2<78))
		{

			paint(9,count_p);
			count_p++;
		}
		else if((point1>115)&&(point1<145)&&(49<point2)&&(point2<78))
		{

			paint(12,count_p);
			count_p++;
		}
		else if((point1>145)&&(point1<175)&&(49<point2)&&(point2<78))
		{

			paint(14,count_p);
			count_p++;
		}
		else if((point1>175)&&(point1<205)&&(49<point2)&&(point2<78))
		{

			paint(1,count_p);
			count_p++;
		}
		else if((point1>335)&&(point1<435)&&(49<point2)&&(point2<78))
		{

			count_p--;
			if(count_p<0)
			{
				count_p=9;
			}
			undo(count_p);

		}
		else if((point1>335)&&(point1<435)&&(20<point2)&&(point2<49))
		{
			redo(count_p);
			count_p++;
		}
		else if((point1>440)&&(point1<540)&&(20<point2)&&(point2<49))
		{
			cleardevice();
			count_p=0;
			drawplate();
		}
		else if((point1>440)&&(point1<540)&&(49<point2)&&(point2<78))
		{
			addtext();
		}
		else if((point1>760)&&(point1<800)&&(0<point2)&&(point2<20))
		{
			closegraph();
		}
	}
	system("pause");
	return 0;
}
