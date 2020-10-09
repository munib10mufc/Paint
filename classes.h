#ifndef CLASSES_H
#define CLASSES_H

#include <string.h>
#include "graphics.h"
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#define PI 3.14159
int count=0;
using namespace std;
void maketriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
}
void drawplate()
{
	line(0,80,800,80);//upper plate line
	rectangle(0,20,80,78);//shape rectangle
	rectangle(85,20,205,78);//color rectangle
	rectangle(760,0,800,20);//close button rectangle
	rectangle(210,20,330,78);//rotation rectangle
	rectangle(335,20,435,78);//rectangle undo
	rectangle(440,20,540,78);//rectangle clearscreen & add text
	rectangle(0,20,30,51);//rectangle circle
	rectangle(30,20,55,51);//rectangle triangle
	rectangle(55,20,80,51);//rectangle ellipse
	rectangle(0,51,30,78);//ractangle rectangle
	rectangle(30,51,55,78);//rectangle line
	rectangle(55,51,80,78);//rectangle square

	circle(16,35,12);
	rectangle(4,57,26,72);//rectangle
	ellipse(68,37,0,360,11,8);
	maketriangle(33,27,50,27,42,48);
	line (35,53,50,72);
	rectangle(59,56,73,70);//square
	outtextxy(2,2,"Shapes");
	outtextxy(100,2,"Colors");
	outtextxy(220,2,"Rotation");
	outtextxy(220,25,"Rotate 90*");
	outtextxy(220,55,"Rotate 180*");
	outtextxy(365,25,"Redo");
	outtextxy(365,55,"Undo");
	outtextxy(445,25,"Clear Screen");
	outtextxy(445,55,"Add Text");
	setfillstyle(SOLID_FILL,3);
	floodfill(1,1,15);

	//close button lines
	line(765,2,795,18);
	line(795,2,765,18);
	//close button color
	setfillstyle(SOLID_FILL,4);
	floodfill(766,6,15);

	//undo-redo line
	line(335,49,435,49);
	//clear screen/add text line
	line(440,49,540,49);

	//color plates lines
	line(115,20,115,78);
	line(145,20,145,78);
	line(175,20,175,78);
	line(85,49,205,49);

	//rotation rectangle line
	line(210,49,330,49);

	//colors inside shapes box
	setfillstyle(SOLID_FILL,4);
	floodfill(58,55,15);
	floodfill(4,24,15);
	floodfill(37,27,15);
	floodfill(3,60,15);
	floodfill(35,60,15);
	floodfill(53,38,15);
	floodfill(56,26,15);

	//colors inside rotation box
	setfillstyle(SOLID_FILL,4);
	floodfill(220,25,15);
	floodfill(220,65,15);

	//colors in undu-redoo
	setfillstyle(SOLID_FILL,4);
	floodfill(336,25,15);
	floodfill(336,55,15);

	//colors in clear screen & add text
	setfillstyle(SOLID_FILL,4);
	floodfill(441,25,15);
	floodfill(441,55,15);

	//colors in color plate
	setfillstyle(SOLID_FILL,5);//box1
	floodfill(99,39,15);
	setfillstyle(SOLID_FILL,2);//box2
	floodfill(126,27,15);
	setfillstyle(SOLID_FILL,6);//box3
	floodfill(160,40,15);
	setfillstyle(SOLID_FILL,8);//box4
	floodfill(190,38,15);
	setfillstyle(SOLID_FILL,9);//box5
	floodfill(98,69,15);
	setfillstyle(SOLID_FILL,12);//box6
	floodfill(123,67,15);
	setfillstyle(SOLID_FILL,14);//box7
	floodfill(163,69,15);
	setfillstyle(SOLID_FILL,1);//box8
	floodfill(195,69,15);
}
template <typename T>
string to_string(T const& value) {
	stringstream sstr;
	sstr << value;
	return sstr.str();
}
double calarea(int x1,int y1,int x2,int y2,int x3,int y3)
{
	double l1,l2,l3,tempx,tempy,sum,area,temp;
	tempx=abs(x2-x1);
	tempy=abs(y2-y1);
	tempx=pow(tempx,2);
	tempy=pow(tempy,2);
	l1=sqrt(tempx+tempy);

	tempx=abs(x3-x2);
	tempy=abs(y3-y2);
	tempx=pow(tempx,2);
	tempy=pow(tempy,2);
	l2=sqrt(tempx+tempy);

	tempx=abs(x1-x3);
	tempy=abs(y1-y3);
	tempx=pow(tempx,2);
	tempy=pow(tempy,2);
	l3=sqrt(tempx+tempy);

	sum=(l1+l2+l3)/2;
	temp=sum*(sum-l1)*(sum-l2)*(sum-l3);
	area=sqrt(temp);
	return area;
}
double calarea(int x1, int y1,int x2,int y2)
{
	double tempx,tempy,l1,l2,area;
	tempx =abs(x2-x1);
	l1=tempx;

	tempy=abs(y2-y1);
	l2=tempy;
	return l1*l2;
}
double calarea(int rad)
{
	double temp=rad;
	temp=pow(temp,2)*PI;
	return temp;
}
int callength(int pos1,int pos2,int x,int y)
{
	double Totx,Toty;
	int d;
	Totx=abs(pos1-x);
	Toty=abs(pos2-y);
	Totx=pow(Totx,2);
	Toty=pow(Toty,2);
	d=sqrt(Totx+Toty);
	return d;
}
class shape
{
public:
	virtual void draw()
	{}
	virtual void rotation90()
	{}
};
class circles: public shape 
{
	int x,y,rad;
	double area;
public:
	void draw()
	{
		int pos1,pos2,length;
		bool click=true,check=true;
		while (click==true)
		{
			while(!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, pos1, pos2);
			if((pos1>0&&pos1<600) && (pos2>81 && pos2<800))
			{
				click=false;
			}
		}
		putpixel(pos1,pos2,15);
		click=true;
		while (click==true)
		{
			while(!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if((x>0&&x<600) && (y>81 && y<800))
			{
				click=false;
			}
		}
		putpixel(x,y,15);
		length=callength(x,y,pos1,pos2);
		circle(x,y,length);
		area=calarea(pos1);
		char * arr=new char [20];
		const string s = to_string(area);
		strcpy(arr, s.c_str());
		outtextxy(1,82,"Area: ");
		char *temp=new char [20];
		for(int i=0;i<20;i++)
		{	
			temp[i]=' ';
			temp[19]='\0';
		}
		outtextxy(40,83,temp);
		outtextxy(40,83,arr);
	}
};
class ellipses: public shape
{
	int pos1,pos2,x,y,stangle,endangle,xrad,yrad;
	double area;
public:
	void draw()
	{
		int a,b,length;
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, pos1,pos2);
		putpixel(pos1,pos2,15);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		putpixel(x,y,15);
		if(pos1<x)
		{
			length=callength(pos1,pos2,x,y);
			ellipse(pos1,pos2,0,360,length,length-(length/2));
		}
		else 
		{
			length=callength(pos1,pos2,x,y);
			ellipse(pos1,pos2,0,360,length-(length/2),length);
		}
		a=abs(pos1-x);
		b=abs(pos2-y);
		area=PI*a*b;
		char * arr=new char [20];
		const string s = to_string(area);
		strcpy(arr, s.c_str());
		outtextxy(1,82,"Area: ");
		char *temp=new char [20];
		for(int i=0;i<20;i++)
		{	
			temp[i]=' ';
			temp[19]='\0';
		}
		outtextxy(40,83,temp);
		outtextxy(40,83,arr);
	}
};
class rectangles:public shape
{
	int x,y,pos1,pos2;
	double area;
public:
	void draw()
	{
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, pos1, pos2);
		putpixel(pos1,pos2,15);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		putpixel(x,y,15);
		if(pos1<=x&&pos2<=y)
		{
			rectangle(pos1,pos2,x,y);
		}
		else if (pos1>=x && pos2<=y)
		{
			rectangle(x,pos2,pos1,y);
		}
		else if (pos1<=x && pos2>=y)
		{
			rectangle(pos1,y,x,pos2);
		}
		else
		{
			rectangle(x,y,pos1,pos2);
		}
		area=calarea(pos1,pos2,x,y);
		char * arr=new char [20];
		const string s = to_string(area);
		strcpy(arr, s.c_str());
		outtextxy(1,82,"Area: ");
		char *temp=new char [20];
		for(int i=0;i<20;i++)
		{	
			temp[i]=' ';
			temp[19]='\0';
		}
		outtextxy(40,83,temp);
		outtextxy(40,83,arr);
	}

};
class lines: public shape
{
	int x,y,pos1,pos2;
	int length;
public:
	void draw()
	{
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, pos1, pos2);
		putpixel(pos1,pos2,15);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		putpixel(x,y,15);
		line(pos1,pos2,x,y);
		length=callength(pos1,pos2,x,y);
		char * arr=new char [20];
		const string s = to_string(length);
		strcpy(arr, s.c_str());
		outtextxy(1,82,"Length:  ");
		char *temp=new char [20];
		for(int i=0;i<20;i++)
		{	
			temp[i]=' ';
			temp[19]='\0';
		}
		outtextxy(40,83,temp);
		outtextxy(40,83,arr);
	}
};
class point: public shape
{
	int x,y;
public:
	void draw()
	{
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		putpixel(x,y,5);
	}
};
class triangle: public shape
{
	int x,y,x1,x2,y1,y2;
	double area;
public:
	void draw()
	{
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x1, y1);
		putpixel(x1,y1,15);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x2, y2);
		putpixel(x2,y2,15);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		putpixel(x,y,15);
		line(x1,y1,x2,y2);
		line(x2,y2,x,y);
		line(x,y,x1,y1);
		area=calarea(x1,y1,x2,y2,x,y);
		char * arr=new char [20];
		const string s = to_string(area);
		strcpy(arr, s.c_str());
		outtextxy(1,82,"Area: ");
		char *temp=new char [20];
		for(int i=0;i<20;i++)
		{	
			temp[i]=' ';
			temp[19]='\0';
		}
		outtextxy(40,83,temp);
		outtextxy(40,83,arr);
	}

	void rotate90()
	{
		line(abs(x2-x),y1,x,y1);
		line(x,y1,x,y);
		line(x,y,abs(x2-x),y1);
	}
};
class square: public shape
{
	int pos1,pos2,x,y;
	double area;
public:
	void draw()
	{
		bool check=true;
		int length=0;
		while(check==true)
		{
			check=true;
			while(!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, pos1, pos2);
			putpixel(pos1,pos2,15);
			while(!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, x, y);
			putpixel(x,y,15);
			check=false;
			if(y<80||pos2<80)
			{
				check=true;
			}

		}
		length=callength(pos1,pos2,x,y);
		rectangle(pos1,pos2,pos1+length,pos2+length);
		area=length*length;
		char * arr=new char [20];
		const string s = to_string(area);
		strcpy(arr, s.c_str());
		outtextxy(1,82,"Area: ");
		char *temp=new char [20];
		for(int i=0;i<20;i++)
		{	
			temp[i]=' ';
			temp[19]='\0';
		}
		outtextxy(40,83,temp);
		outtextxy(40,83,arr);
	}
};
class recordpaint
{
public:
	int old_x[10],old_y[10],old_paint[10];
	int new_x[10],new_y[10],new_paint[10];
	recordpaint()
	{
		for (int i=0;i<10;i++)
		{
			/*Default paint is Black*/
			old_paint[i]=0;
			new_paint[i]=0;
			/*Default corodinates*/
			old_x[i]=0;
			new_x[i]=0;
			old_y[i]=0;
			new_y[i]=0;
		}
	}
	void setpaint(int x1,int y1, int new_color, int & count_p)
	{

		//old_x[count_p]=
		//old_y[count_p]=
		new_x[count_p]=x1;
		new_y[count_p]=y1;
		/*if previously found any color, or else BLACK will be copied as old color*/	
		old_paint[count_p]=getpixel(x1,y1);
		new_paint[count_p]=new_color;
		//count++;
	}
};
recordpaint r_paint;
void paint(int col, int & count_p)
{
	int tempx,tempy,old_color,new_color;
	while(!ismouseclick(WM_LBUTTONDOWN))
	{}
	getmouseclick(WM_LBUTTONDOWN,tempx,tempy);

	new_color = col;
	r_paint.setpaint(tempx,tempy,new_color,count_p);
	setfillstyle(SOLID_FILL,new_color);
	floodfill(tempx,tempy,15);
}
void redo(int & count_p)
{
	
	setfillstyle(SOLID_FILL,r_paint.new_paint[count_p]);
	floodfill(r_paint.new_x[count_p],r_paint.new_y[count_p],15);
	
}
void undo(int & count_p)
{
	
	int local_count=count_p;

	setfillstyle(SOLID_FILL,r_paint.old_paint[local_count]);
	floodfill(r_paint.new_x[local_count],r_paint.new_y[local_count],15);
}
void addtext()
{
	
}
#endif