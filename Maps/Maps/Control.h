
#ifndef CONTROL_H
#define CONTROL_H

#include "Frames.h"

MOUSEMSG m;
int X=m.x,Y=m.y;

void MouseControl_MainPage(MOUSEMSG m)
{
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>737&&X<851&&Y>94&&Y<138&&n==0){
				PutImage(737,94,&ICON_1[0],0x000000,40);
				n=1;
			}
			else if(X>738&&X<852&&Y>166&&Y<210&&n==0){
				PutImage(738,166,&ICON_1[1],0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&MAIN_PAGE);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;

		if(X>737&&X<851&&Y>94&&Y<138&&n==0){
			putimage(0,0,&SECOND_PAGE);
			MouseControl_SearchingMainPage(m);
			n=1;
		}
		else if(X>738&&X<852&&Y>166&&Y<210&&n==0){
			putimage(0,0,&SECOND_PAGE);
			MouseControl_DirectionMainPage(m);
			n=1;
		}else{
			putimage(0,0,&MAIN_PAGE);
			n=0;
		}
  }
}

void MouseControl_SearchingMainPage(MOUSEMSG m)
{
	putimage(0,0,&SECOND_PAGE);
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>676&&X<900&&Y>160&&Y<232&&n==0){
				putimage(676,160,&ICON_2[0]);
				n=1;
			}
			else if(X>676&&X<900&&Y>232&&Y<304&&n==0){
				putimage(676,303,&ICON_2[1]);
				n=1;
			}
			else if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&SECOND_PAGE);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;
		
		if(X>676&&X<900&&Y>160&&Y<232&&n==0){
			putimage(0,0,&SEARCHING_PAGE1);
			MouseControl_SearchingPage1(m);
			n=1;
		}
		else if(X>676&&X<900&&Y>232&&Y<304&&n==0){
			putimage(0,0,&SEARCHING_PAGE2);
			MouseControl_SearchingPage2(m);
			n=1;
		}
		else if(X>675&&X<900&&Y>460&&Y<533&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else{
			putimage(0,0,&SECOND_PAGE);
			n=0;
		}
  }
}

void MouseControl_DirectionMainPage(MOUSEMSG m)
{
	putimage(0,0,&SECOND_PAGE);
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>676&&X<900&&Y>160&&Y<232&&n==0){
				putimage(676,160,&ICON_1[0]);
				n=1;
			}
			else if(X>676&&X<900&&Y>232&&Y<304&&n==0){
				putimage(676,303,&ICON_1[1]);
				n=1;
			}
			else if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&SECOND_PAGE);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;
		
		if(X>676&&X<900&&Y>160&&Y<232&&n==0){
			putimage(0,0,&SEARCHING_PAGE1);
			MouseControl_DirectionPage1(m);
			n=1;
		}
		else if(X>676&&X<900&&Y>232&&Y<304&&n==0){
			putimage(0,0,&SEARCHING_PAGE2);
			MouseControl_DirectionPage2(m);
			n=1;
		}
		else if(X>675&&X<900&&Y>460&&Y<533&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else{
			putimage(0,0,&SECOND_PAGE);
			n=0;
		}
  }
}

void MouseControl_SearchingPage1(MOUSEMSG m)
{
	putimage(0,0,&SEARCHING_PAGE1);
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>160&&Y<232&&n==0){
				putimage(676,160,&ICON_3[0]);
				n=1;
			}
			else if(X>675&&X<900&&Y>232&&Y<304&&n==0){
				putimage(675,232,&ICON_3[1]);
				n=1;
			}
			else if(X>675&&X<900&&Y>304&&Y<376&&n==0){
				putimage(675,304,&ICON_3[2]);
				n=1;
			}
			else if(X>675&&X<900&&Y>376&&Y<448&&n==0){
				putimage(675,376,&ICON_3[3]);
				n=1;
			}
			else if(X>675&&X<900&&Y>448&&Y<533&&n==0){
				putimage(675,460,&BACK_BIG);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&SEARCHING_PAGE1);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;
		
		if(X>675&&X<900&&Y>160&&Y<232&&n==0){
			putimage(0,0,&SEARCHING_DORM);
			MouseControl_SearchingDorm(m);
			n=1;
		}
		else if(X>675&&X<900&&Y>232&&Y<304&&n==0){
			putimage(0,0,&SEARCHING_STUBUILDING);
			MouseControl_SearchingStuBuilding(m);
			n=1;
		}
		else if(X>675&&X<900&&Y>304&&Y<376&&n==0){
			putimage(0,0,&SEARCHING_CANTEEN);
			MouseControl_SearchingCanteen(m);
			n=1;
		}
		else if(X>675&&X<900&&Y>376&&Y<448&&n==0){
			putimage(0,0,&SEARCHING_ELSE);
			MouseControl_SearchingElse(m);
			n=1;
		}
		else if(X>675&&X<900&&Y>448&&Y<533&&n==0){
			putimage(0,0,&SECOND_PAGE);
			MouseControl_SearchingMainPage(m);
			n=1;
		}
		else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else{
			putimage(0,0,&SEARCHING_PAGE1);
			n=0;
		}
  }
}

void MouseControl_SearchingDorm(MOUSEMSG m)
{
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>160&&Y<232&&n==0){
				putimage(676,160,&ICON_3[0]);
				n=1;
			}
			else if(X>675&&X<900&&Y>232&&Y<304&&n==0){
				putimage(675,232,&ICON_3[1]);
				n=1;
			}
			else if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&SEARCHING_DORM);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;
		
		if(X>675&&X<900&&Y>160&&Y<232&&n==0){
			initgraph(900,687);
			putimage(0,0,&DORM_LOC);
			MouseControl_DormLocation(m);
			n=1;
		}
		else if(X>675&&X<900&&Y>232&&Y<304&&n==0){
			putimage(0,0,&DORM_INNER);
			MouseControl_DormInner(m);
			n=1;
		}
		else if(X>675&&X<900&&Y>460&&Y<533&&n==0){
			putimage(0,0,&SEARCHING_PAGE1);
			MouseControl_SearchingPage1(m);
		}
		else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
		}
		else{
			putimage(0,0,&SEARCHING_DORM);
			n=0;
		}
  }
}

void MouseControl_DormLocation(MOUSEMSG m)
{
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>610&&X<900&&Y>593&&Y<687&&n==0){
				putimage(676,160,&ICON_2[0]);
				n=1;
			}
			else if(X>706&&X<800&&Y>10&&Y<104&&n==0){
				PutImage(706,10,&BACK_TO_MAIN_DORM,0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&DORM_LOC);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;
		
		if(X>610&&X<900&&Y>593&&Y<687&&n==0){
			initgraph(900,533);
			putimage(0,0,&SEARCHING_DORM);
			MouseControl_SearchingDorm(m);
			n=1;
		}
		else if(X>706&&X<800&&Y>10&&Y<104&&n==0){
			initgraph(900,533);
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else{
			putimage(0,0,&DORM_LOC);
			n=0;
		}
  }
}


void MouseControl_DormInner(MOUSEMSG m)
{
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(676,160,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(706,10,&BACK_TO_MAIN,0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&DORM_INNER);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;
		
		if(X>675&&X<900&&Y>460&&Y<533&&n==0){
			putimage(0,0,&SEARCHING_DORM);
			MouseControl_SearchingDorm(m);
			n=1;
		}
		else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else{
			putimage(0,0,&DORM_INNER);
			n=0;
		}
  }
}

void MouseControl_SearchingStuBuilding(MOUSEMSG m)
{
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>448&&Y<533&&n==0){
				putimage(676,160,&BACK_BIG);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(706,10,&BACK_TO_MAIN,0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&SEARCHING_STUBUILDING);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;
		
		if(X>675&&X<900&&Y>460&&Y<533&&n==0){
			putimage(0,0,&SEARCHING_PAGE1);
			MouseControl_SearchingPage1(m);
			n=1;
		}
		else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else{
			putimage(0,0,&SEARCHING_STUBUILDING);
			n=0;
		}
  }
}

void MouseControl_SearchingCanteen(MOUSEMSG m)
{
	LoadImage();
	while(true){
		m=GetMouseMsg();
		int n=0;

		switch(m.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>448&&Y<533&&n==0){
				putimage(676,160,&BACK_BIG);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(706,10,&BACK_TO_MAIN,0x000000,40);
				n=1;
			}
			else {
				putimage(0,0,&SEARCHING_CANTEEN);
				n=0;
			}
			break;
		case WM_LBUTTONDOWN:
			goto l;
		break;
		}
	}

l:{
		m=GetMouseMsg();
		int n=0;
		
		if(X>675&&X<900&&Y>460&&Y<533&&n==0){
			putimage(0,0,&SEARCHING_PAGE1);
			MouseControl_SearchingPage1(m);
			n=1;
		}
		else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(m);
			n=1;
		}
		else{
			putimage(0,0,&SEARCHING_CANTEEN);
			n=0;
		}
  }
}


void MouseControl_SearchingPage2(MOUSEMSG m);
void MouseControl_DirectionPage1(MOUSEMSG m);
void MouseControl_DirectionPage2(MOUSEMSG m);
void MouseControl_SearchingElse(MOUSEMSG m);

#endif