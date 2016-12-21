#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

#define n1 26
#define maxsize 9999

int path[n1+1][n1+1];

void floyd(int A[][n1+1],int C[][n1+1], int p , int q);

	IMAGE MAIN_PAGE,SEARCHING_PAGE,DIRECTION_PAGE,AUTHOR_MAINPAGE;
    IMAGE SEARCHING_PAGE1,SEARCHING_PAGE2;
    IMAGE MAINPAGE_ICON[4],SEARCHINGPAGE_ICON[2],SEARCHINGPAGE1_ICON[4];
    IMAGE BACK_SMALL,BACK_BIG,BACK_DORM,BACK_TO_MAIN,BACK_TO_MAIN_DORM,BIGPOINT;
    IMAGE SEARCHING_DORM,SEARCHING_CANTEEN,SEARCHING_STUBUILDING,ELSE;
    IMAGE DORM[2],DORM_ICON[2];
	IMAGE STUBUILDING[3],STUBUILDING_ICON[3];
	IMAGE CANTEEN,CANTEEN_ICON;
	IMAGE LIBRARY,ENTRANCE,ACTIVITY_CENTER,GYM;

void LoadImage()
{
	loadimage(&MAINPAGE_ICON[0],_T("C:\\Frames\\mainpage_icon_1.jpg"));
	loadimage(&MAINPAGE_ICON[1],_T("C:\\Frames\\mainpage_icon_2.jpg"));
	loadimage(&MAINPAGE_ICON[2],_T("C:\\Frames\\mainpage_icon_3.jpg"));
	loadimage(&MAINPAGE_ICON[3],_T("C:\\Frames\\mainpage_icon_4.jpg"));
	loadimage(&MAIN_PAGE,_T("C:\\Frames\\main_page.jpg"));
	loadimage(&SEARCHING_PAGE,_T("C:\\Frames\\searching_page.jpg"));
	loadimage(&DIRECTION_PAGE,_T("C:\\Frames\\direction_page.jpg"));
	loadimage(&AUTHOR_MAINPAGE,_T("C:\\Frames\\author.jpg"));
	loadimage(&BACK_SMALL,_T("C:\\Frames\\back_small.jpg"));
	loadimage(&BACK_BIG,_T("C:\\Frames\\back_big.jpg"));
	loadimage(&BIGPOINT,_T("C:\\Frames\\bigpoint.jpg"));
	loadimage(&BACK_DORM,_T("C:\\Frames\\back_dorm.jpg"));
	loadimage(&BACK_TO_MAIN,_T("C:\\Frames\\back_to_main.jpg"));
	loadimage(&BACK_TO_MAIN_DORM,_T("C:\\Frames\\back_to_main_big.jpg"));
	loadimage(&SEARCHINGPAGE_ICON[0],_T("C:\\Frames\\searchingpage_icon_1.jpg"));
	loadimage(&SEARCHINGPAGE_ICON[1],_T("C:\\Frames\\searchingpage_icon_2.jpg"));
	loadimage(&SEARCHINGPAGE1_ICON[0],_T("C:\\Frames\\searchingpage1_icon_1.jpg"));
	loadimage(&SEARCHINGPAGE1_ICON[1],_T("C:\\Frames\\searchingpage1_icon_2.jpg"));
	loadimage(&SEARCHINGPAGE1_ICON[2],_T("C:\\Frames\\searchingpage1_icon_3.jpg"));
	loadimage(&SEARCHINGPAGE1_ICON[3],_T("C:\\Frames\\searchingpage1_icon_4.jpg"));
	loadimage(&SEARCHING_PAGE1,_T("C:\\Frames\\searching_page1.jpg"));
	loadimage(&SEARCHING_PAGE2,_T("C:\\Frames\\searching_page2.jpg"));
	loadimage(&SEARCHING_DORM,_T("C:\\Frames\\searching_dorm.jpg"));
	loadimage(&SEARCHING_CANTEEN,_T("C:\\Frames\\searching_canteen.jpg"));
	loadimage(&SEARCHING_STUBUILDING,_T("C:\\Frames\\searching_stubuilding.jpg"));
	loadimage(&DORM[0],_T("C:\\Frames\\dorm_loc.jpg"));
	loadimage(&DORM[1],_T("C:\\Frames\\dorm_inner.jpg"));
	loadimage(&DORM_ICON[0],_T("C:\\Frames\\dorm_icon1.jpg"));
	loadimage(&DORM_ICON[1],_T("C:\\Frames\\dorm_icon2.jpg"));
	loadimage(&STUBUILDING[0],_T("C:\\Frames\\stubuilding_1.jpg"));
	loadimage(&STUBUILDING[1],_T("C:\\Frames\\stubuilding_2.jpg"));
	loadimage(&STUBUILDING[2],_T("C:\\Frames\\stubuilding_3.jpg"));
	loadimage(&STUBUILDING_ICON[0],_T("C:\\Frames\\stubuilding_icon1.jpg"));
	loadimage(&STUBUILDING_ICON[1],_T("C:\\Frames\\stubuilding_icon2.jpg"));
	loadimage(&STUBUILDING_ICON[2],_T("C:\\Frames\\stubuilding_icon3.jpg"));
	loadimage(&CANTEEN,_T("C:\\Frames\\canteen.jpg"));
	loadimage(&CANTEEN_ICON,_T("C:\\Frames\\canteen_icon.jpg"));
	loadimage(&LIBRARY,_T("C:\\Frames\\library.jpg"));
	loadimage(&GYM,_T("C:\\Frames\\gym.jpg"));
	loadimage(&ENTRANCE,_T("C:\\Frames\\entrance.jpg"));
	loadimage(&ACTIVITY_CENTER,_T("C:\\Frames\\activity_center.jpg"));
	loadimage(&ELSE,_T("C:\\Frames\\else.jpg"));
}

int abs(int a){
	if(a<0)a*=-1;
	return a;
}

void PutImage(int dstX,int dstY,IMAGE *pimg,int avoid_color,int deviation)
{
	int width= pimg->getwidth();
	int height= pimg->getheight();
    int x,y,color,num;
    int avoid_r=GetRValue(avoid_color);
    int avoid_g=GetGValue(avoid_color);
    int avoid_b=GetBValue(avoid_color);
    IMAGE pSrcImg;
    SetWorkingImage(NULL);
    getimage(&pSrcImg,dstX,dstY,width,height);

    DWORD* bk_pMem = GetImageBuffer(&pSrcImg);
    DWORD* pMem = GetImageBuffer(pimg);

	for(y=0;y<height;y++){
		for(x=0;x<width;x++){
			num = y*width+x;
			color = pMem[num];
			if(abs(GetRValue(color)-avoid_r)<deviation){
				if(abs(GetGValue(color)-avoid_g)<deviation){
					if(abs(GetBValue(color)-avoid_b)<deviation)
						pMem[num] = bk_pMem[num];
				}
			}
		}
	}
	putimage(dstX, dstY, pimg);
}

void MouseControl_MainPage(MOUSEMSG x);
void MouseControl_SearchingMainPage(MOUSEMSG x);
void MouseControl_DirectionMainPage(MOUSEMSG x);
void MouseControl_SearchingPage1(MOUSEMSG x);
void MouseControl_SearchingDorm(MOUSEMSG x);
void MouseControl_DormLocation(MOUSEMSG x);
void MouseControl_DormInner(MOUSEMSG x);
void MouseControl_SearchingStuBuilding(MOUSEMSG x);
void MouseControl_SearchingCanteen(MOUSEMSG x);
void MouseControl_StuBuilding1(MOUSEMSG x);
void MouseControl_StuBuilding2(MOUSEMSG x);
void MouseControl_StuBuilding3(MOUSEMSG x);
void MouseControl_Canteen(MOUSEMSG x);
void MouseControl_SearchingPage2(MOUSEMSG x);
void MouseControl_AuthorPage(MOUSEMSG x);
void MouseControl_DirectionPage2(MOUSEMSG x);
void MouseControl_Library(MOUSEMSG x);
void MouseControl_Gym(MOUSEMSG x);
void MouseControl_ActivityCenter(MOUSEMSG x);
void MouseControl_Entrance(MOUSEMSG x);
void MouseControl_SearchingElse(MOUSEMSG x);

int main()
{
	
    
	initgraph(900,533);
	LoadImage();
	putimage(0,0,&MAIN_PAGE);
	MOUSEMSG x;
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, _T("南地图 V2.0"));
	
	while(true){
		x=GetMouseMsg();
	MouseControl_MainPage(x);
	}
	closegraph();
}

void MouseControl_MainPage(MOUSEMSG x)
{
	int X=x.x,Y=x.y; 
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int r=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>737&&X<851&&Y>94&&Y<138&&r==0){
				PutImage(737,94,&MAINPAGE_ICON[0],0x000000,40);
				r=1;
			}
			else if(X>738&&X<852&&Y>166&&Y<210&&r==0){
				PutImage(738,166,&MAINPAGE_ICON[1],0x000000,40);
				r=1;
			}
			else if(X>715&&X<819&&Y>482&&Y<527&&r==0){
				PutImage(715,482,&MAINPAGE_ICON[2],0x000000,40);
				r=1;
			}
			else if(X>840&&X<876&&Y>490&&Y<524&&r==0){
				PutImage(840,490,&MAINPAGE_ICON[3],0x000000,40);
				r=1;
			}
			else {
				putimage(0,0,&MAIN_PAGE);
				r=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>737&&X<851&&Y>94&&Y<138){
				putimage(0,0,&SEARCHING_PAGE);
			    MouseControl_SearchingMainPage(x);
			}
		    else if(X>738&&X<852&&Y>166&&Y<210){
			    putimage(0,0,&DIRECTION_PAGE);
			    MouseControl_DirectionMainPage(x);
			}
			else if(X>840&&X<876&&Y>490&&Y<524){
			    putimage(0,0,&AUTHOR_MAINPAGE);
			    MouseControl_AuthorPage(x);
			}
			else if(X>715&&X<819&&Y>482&&Y<527){
				closegraph();
				break;
			}
            else{
			    putimage(0,0,&MAIN_PAGE);
		    }
			break;
		}
	}
}

void MouseControl_AuthorPage(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		if(x.uMsg==WM_MOUSEMOVE)
			putimage(0,0,&AUTHOR_MAINPAGE);
		else if(x.uMsg==WM_LBUTTONDOWN){
			putimage(0,0,&MAIN_PAGE);
			MouseControl_MainPage(x);
		}
	}
}

void MouseControl_SearchingMainPage(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int p=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>676&&X<900&&Y>170&&Y<222&&p==0){
				putimage(676,160,&SEARCHINGPAGE_ICON[0]);
				p=1;
			}
			else if(X>676&&X<900&&Y>242&&Y<294&&p==0){
				putimage(676,232,&SEARCHINGPAGE_ICON[1]);
				p=1;
			}
			else if(X>675&&X<900&&Y>460&&Y<533&&p==0){
				putimage(675,460,&BACK_SMALL);
				p=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&p==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				p=1;
			}
			else {
				putimage(0,0,&SEARCHING_PAGE);
				p=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>676&&X<900&&Y>160&&Y<232){
				putimage(0,0,&SEARCHING_PAGE1);
			    MouseControl_SearchingPage1(x);
		    }
		    else if(X>676&&X<900&&Y>232&&Y<304){
			    putimage(0,0,&SEARCHING_PAGE2);
			    MouseControl_SearchingPage2(x);
		    }
		    else if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&SEARCHING_PAGE);
		    }break;
		}
	}
}

void MouseControl_SearchingPage1(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>170&&Y<222&&n==0){
				putimage(676,160,&SEARCHINGPAGE1_ICON[0]);
				n=1;
			}
			else if(X>675&&X<900&&Y>242&&Y<294&&n==0){
				putimage(675,232,&SEARCHINGPAGE1_ICON[1]);
				n=1;
			}
			else if(X>675&&X<900&&Y>314&&Y<366&&n==0){
				putimage(675,304,&SEARCHINGPAGE1_ICON[2]);
				n=1;
			}
			else if(X>675&&X<900&&Y>386&&Y<438&&n==0){
				putimage(675,376,&SEARCHINGPAGE1_ICON[3]);
				n=1;
			}
			else if(X>675&&X<900&&Y>448&&Y<533&&n==0){
				putimage(675,460,&BACK_BIG);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else {
				putimage(0,0,&SEARCHING_PAGE1);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>160&&Y<232){
				putimage(0,0,&SEARCHING_DORM);
			    MouseControl_SearchingDorm(x);
			}
			else if(X>675&&X<900&&Y>232&&Y<304){
			    putimage(0,0,&SEARCHING_STUBUILDING);
			    MouseControl_SearchingStuBuilding(x);
			}
		    else if(X>675&&X<900&&Y>304&&Y<376){
			    putimage(0,0,&SEARCHING_CANTEEN);
			    MouseControl_SearchingCanteen(x);
		    }
		    else if(X>675&&X<900&&Y>376&&Y<448){
			    putimage(0,0,&ELSE);
			    MouseControl_SearchingElse(x);
		    }
		    else if(X>675&&X<900&&Y>448&&Y<533){
			    putimage(0,0,&SEARCHING_PAGE);
			    MouseControl_SearchingMainPage(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&SEARCHING_PAGE1);
			}break;
		}
	}
}

void MouseControl_SearchingDorm(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>170&&Y<222&&n==0){
				putimage(676,160,&DORM_ICON[0]);
				n=1;
			}
			else if(X>675&&X<900&&Y>242&&Y<294&&n==0){
				putimage(675,232,&DORM_ICON[1]);
				n=1;
			}
			else if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else {
				putimage(0,0,&SEARCHING_DORM);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN: 
			if(X>675&&X<900&&Y>160&&Y<232){
				initgraph(900,687);
				HWND hWnd = GetHWnd();
	            SetWindowText(hWnd, _T("南地图 V2.0"));
			    putimage(0,0,&DORM[0]);
			    MouseControl_DormLocation(x);
		    }
		    else if(X>675&&X<900&&Y>232&&Y<304){
			    putimage(0,0,&DORM[1]);
			    MouseControl_DormInner(x);
		    }
		    else if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&SEARCHING_PAGE1);
			    MouseControl_SearchingPage1(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&SEARCHING_DORM);
		    }break;
		}
	}
}

void MouseControl_DormLocation(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int t=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>610&&X<900&&Y>593&&Y<687&&t==0){
				putimage(610,593,&BACK_DORM);
				t=1;
			}
			else if(X>708&&X<802&&Y>12&&Y<106&&t==0){
				PutImage(708,12,&BACK_TO_MAIN_DORM,0x000000,180);
				t=1;
			}
			else {
				putimage(0,0,&DORM[0]);
				t=0;
			}
			break;
		case WM_LBUTTONDOWN:
		    if(X>610&&X<900&&Y>593&&Y<687){
			    initgraph(900,533);
				HWND hWnd = GetHWnd();
	            SetWindowText(hWnd, _T("南地图 V2.0"));
			    putimage(0,0,&SEARCHING_DORM);
			    MouseControl_SearchingDorm(x);
		    }
		    else if(X>708&&X<802&&Y>12&&Y<106){
			    initgraph(900,533);
				HWND hWnd = GetHWnd();
	            SetWindowText(hWnd, _T("南地图 V2.0"));
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }  
		    else{
		      	putimage(0,0,&DORM[0]);
		    }break;
		}
	}
}

void MouseControl_DormInner(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else {
				putimage(0,0,&DORM[1]);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&SEARCHING_DORM);
			    MouseControl_SearchingDorm(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&DORM[1]);
		    }break;
		}
	}
}

void MouseControl_SearchingStuBuilding(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y;
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>448&&Y<533&&n==0){
				putimage(675,448,&BACK_BIG);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else if(X>675&&X<900&&Y>170&&Y<222&&n==0){
				putimage(675,160,&STUBUILDING_ICON[0]);
				n=1;
			}
			else if(X>675&&X<900&&Y>242&&Y<294&&n==0){
				putimage(675,232,&STUBUILDING_ICON[1]);
				n=1;
			}
			else if(X>675&&X<900&&Y>314&&Y<366&&n==0){
				putimage(675,304,&STUBUILDING_ICON[2]);
				n=1;
			}
			else {
				putimage(0,0,&SEARCHING_STUBUILDING);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&SEARCHING_PAGE1);
			    MouseControl_SearchingPage1(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
			else if(X>675&&X<900&&Y>170&&Y<222){
				putimage(0,0,&STUBUILDING[0]);
				MouseControl_StuBuilding1(x);
			}
			else if(X>675&&X<900&&Y>242&&Y<294){
				putimage(0,0,&STUBUILDING[1]);
				MouseControl_StuBuilding2(x);
			}
			else if(X>675&&X<900&&Y>314&&Y<366){
				putimage(0,0,&STUBUILDING[2]);
				MouseControl_StuBuilding3(x);
			}
		    else{
			    putimage(0,0,&SEARCHING_STUBUILDING);
			    n=0;
		    }break;
		}
	}
}

void MouseControl_StuBuilding1(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else {
				putimage(0,0,&STUBUILDING[0]);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&SEARCHING_STUBUILDING);
			    MouseControl_SearchingStuBuilding(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&STUBUILDING[0]);
		    }break;
		}
	}
}

void MouseControl_StuBuilding2(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else {
				putimage(0,0,&STUBUILDING[1]);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&SEARCHING_STUBUILDING);
			    MouseControl_SearchingStuBuilding(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&STUBUILDING[1]);
		    }break;
		}
	}
}

void MouseControl_StuBuilding3(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else {
				putimage(0,0,&STUBUILDING[2]);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&SEARCHING_STUBUILDING);
			    MouseControl_SearchingStuBuilding(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&STUBUILDING[2]);
		    }break;
		}
	}
}

int posX[n1+1]={0,418,374,240,205,214,337,440,344,285,347,259,410,333,285,245,184,156,217,312,131,193,107,359,328,174,399};
int posY[n1+1]={0,457,428,449,369,394,388,490,433,443,176,372,296,304,319,285,314,250,223,216,187,160,126,327,330,106,322};
    
void MouseControl_SearchingCanteen(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y;
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>448&&Y<533&&n==0){
				putimage(675,448,&BACK_BIG);
				n=1;
			}
			else if((X>675&&X<900&&Y>160&&Y<232)){
				putimage(675,160,&CANTEEN_ICON);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else {
				putimage(0,0,&SEARCHING_CANTEEN);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&SEARCHING_PAGE1);
			    MouseControl_SearchingPage1(x);
		    }
			else if(X>675&&X<900&&Y>160&&Y<232){
				putimage(0,0,&CANTEEN);
				MouseControl_Canteen(x);
			}
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&SEARCHING_CANTEEN);
		    }break;
		}
	}
}

void MouseControl_Canteen(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int n=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&n==0){
				putimage(675,460,&BACK_SMALL);
				n=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
				PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
				n=1;
			}
			else {
				putimage(0,0,&CANTEEN);
				n=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
			    putimage(0,0,&SEARCHING_CANTEEN);
			    MouseControl_SearchingCanteen(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&CANTEEN);
		    }break;
		}
	}
}

void MouseControl_SearchingElse(MOUSEMSG x)
{
	LoadImage();
	while(true){
		x=GetMouseMsg();
		if(x.uMsg==WM_MOUSEMOVE)
			putimage(0,0,&ELSE);
		else if(x.uMsg==WM_LBUTTONDOWN){
			putimage(0,0,&SEARCHING_PAGE1);
			MouseControl_SearchingPage1(x);
		}
	}
}

void MouseControl_SearchingPage2(MOUSEMSG x)
{
	int X=x.x,Y=x.y; 
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int r=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&r==0){
				putimage(675,460,&BACK_SMALL);
				r=1;
			}
			else if(X>750&&X<823&&Y>10&&Y<83&&r==0){
				putimage(750,10,&BACK_TO_MAIN);
				r=1;
			}
			else {
				putimage(0,0,&SEARCHING_PAGE2);
				r=0;
			}break;
			
		case WM_LBUTTONDOWN:
			if(X>409&&X<431&&Y>296&&Y<318){
				putimage(0,0,&LIBRARY);
			    MouseControl_Library(x);
			}
		    else if(X>433&&X<455&&Y>486&&Y<508){
			    putimage(0,0,&ENTRANCE);
			    MouseControl_Entrance(x);
			}
			else if(X>315&&X<337&&Y>297&&Y<319){
			    putimage(0,0,&ACTIVITY_CENTER);
			    MouseControl_ActivityCenter(x);
			}
			else if(X>252&&X<274&&Y>362&&Y<384){
				putimage(0,0,&GYM);
			    MouseControl_Gym(x);
			}
			else if(X>675&&X<900&&Y>448&&Y<533){
			    putimage(0,0,&SEARCHING_PAGE);
			    MouseControl_SearchingMainPage(x);
		    }
		    else if(X>750&&X<823&&Y>10&&Y<83){
			    putimage(0,0,&MAIN_PAGE);
			    MouseControl_MainPage(x);
		    }
		    else{
			    putimage(0,0,&SEARCHING_PAGE2);
			}break;
		}
	}
}

void MouseControl_Library(MOUSEMSG x)
{
	int X=x.x,Y=x.y;
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int r=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&r==0){
				putimage(675,460,&BACK_SMALL);
				r=1;
			}
			else{
				putimage(0,0,&LIBRARY);
				r=0;
			}
			break;
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
				putimage(0,0,&SEARCHING_PAGE2);
				MouseControl_SearchingPage2(x);
			}
			else
				putimage(0,0,&LIBRARY);
			break;
		}
	}
}

void MouseControl_Gym(MOUSEMSG x)
{
	int X=x.x,Y=x.y;
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int r=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&r==0){
				putimage(675,460,&BACK_SMALL);
				r=1;
			}
			else{
				putimage(0,0,&GYM);
				r=0;
			}
			break;
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
				putimage(0,0,&SEARCHING_PAGE2);
				MouseControl_SearchingPage2(x);
			}
			else
				putimage(0,0,&GYM);
			break;
		}
	}
}

void MouseControl_Entrance(MOUSEMSG x)
{
	int X=x.x,Y=x.y;
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int r=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&r==0){
				putimage(675,460,&BACK_SMALL);
				r=1;
			}
			else{
				putimage(0,0,&ENTRANCE);
				r=0;
			}
			break;
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
				putimage(0,0,&SEARCHING_PAGE2);
				MouseControl_SearchingPage2(x);
			}
			else
				putimage(0,0,&ENTRANCE);
			break;
		}
	}
}

void MouseControl_ActivityCenter(MOUSEMSG x)
{
	int X=x.x,Y=x.y;
	LoadImage();
	while(true){
		x=GetMouseMsg();
		int r=0;
		int X=x.x,Y=x.y; 
		switch(x.uMsg)
		{
		case WM_MOUSEMOVE:
			if(X>675&&X<900&&Y>460&&Y<533&&r==0){
				putimage(675,460,&BACK_SMALL);
				r=1;
			}
			else{
				putimage(0,0,&ACTIVITY_CENTER);
				r=0;
			}
			break;
		case WM_LBUTTONDOWN:
			if(X>675&&X<900&&Y>460&&Y<533){
				putimage(0,0,&SEARCHING_PAGE2);
				MouseControl_SearchingPage2(x);
			}
			else
				putimage(0,0,&ACTIVITY_CENTER);
			break;
		}
	}
}

void MouseControl_DirectionMainPage(MOUSEMSG x)
{
	LoadImage();

	int A[n1+1][n1+1],C[n1+1][n1+1];

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n1; j++){
            A[i][j] = C[i][j] = maxsize;
        }
    }
    
    C[1][7] = 153;
    C[1][2] = 142;
    C[2][8] = 89;
    C[8][9] = 119;
    C[9][3] = 110;
    C[8][6] = 83;
   // C[8][24] = 203;
    C[24][23] = 74;
    C[3][5] = 110;
    C[5][4] = 45;
    C[5][11] = 100;
    C[9][11] = 121;
    C[11][14] = 120;
    C[4][16] = 102;
    C[16][15] = 145;
    C[19][10] = 79;
    C[15][14] = 91;
    C[14][24] = 120;
    C[24][13] = 54;
    C[13][12] = 147;
    //C[12][1] = 272;
    C[16][17] = 143;
    C[17][18] = 143;
    C[18][15] = 145;
    C[15][19] = 148;
    C[17][20] = 124;
    C[20][22] = 113;
    C[22][25] = 103;
    C[25][21] = 89;
    C[21][18] = 143;
	C[24][6] = 120;
	C[26][1] = 252;
	C[26][12] = 110;
	C[23][26] = 78;

	A[26][12] = 110;
	A[23][26] = 78;
	A[26][1] = 252;
    A[1][7] = 153;
    A[1][2] = 142;
    A[2][8] = 89;
    A[8][9] = 119;
    A[9][3] = 110;
    A[8][6] = 83;
    //A[8][24] = 203;
    A[24][23] = 74;
    A[3][5] = 110;
    A[5][4] = 45;
    A[5][11] = 100;
    A[9][11] = 121;
    A[11][14] = 120;
    A[4][16] = 102;
    A[16][15] = 145;
    A[19][10] = 79;
    A[15][14] = 91;
    A[14][24] = 120;
    A[24][13] = 54;
    A[13][12] = 147;
    //A[12][1] = 272;
    A[16][17] = 143;
    A[17][18] = 143;
    A[18][15] = 145;
    A[15][19] = 148;
    A[17][20] = 124;
    A[20][22] = 113;
    A[22][25] = 103;
    A[25][21] = 89;
    A[21][18] = 143;
	A[24][6] = 120;
    
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n1; j++){
            if(C[i][j] != maxsize){
                C[j][i] = C[i][j];
            }
        }
    }
    
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n1; j++){
            if(A[i][j] != maxsize){
                A[j][i] = A[i][j];
            }
        }
    }

	int i = 0;
	int j = 0;
	int num = 0;

	while(true)
	{
		x=GetMouseMsg();
		int n=0;
		int max = 9999;
		int X=x.x,Y=x.y;
		switch(x.uMsg)
		{
			case WM_MOUSEMOVE:
				if(X>posX[1]&&(X<posX[1]+12)&&Y>posY[1]&&(Y<posY[1]+12)&&n==0){
					PutImage(posX[1]-6,posY[1]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[2]&&(X<posX[2]+12)&&Y>posY[2]&&(Y<posY[2]+12)&&n==0){
					PutImage(posX[2]-6,posY[2]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[3]&&(X<posX[3]+12)&&Y>posY[3]&&(Y<posY[3]+12)&&n==0){
					PutImage(posX[3]-6,posY[3]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[4]&&(X<posX[4]+12)&&Y>posY[4]&&(Y<posY[4]+12)&&n==0){
					PutImage(posX[4]-6,posY[4]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[5]&&(X<posX[5]+12)&&Y>posY[5]&&(Y<posY[5]+12)&&n==0){
					PutImage(posX[5]-6,posY[5]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[6]&&(X<posX[6]+12)&&Y>posY[6]&&(Y<posY[6]+12)&&n==0){
					PutImage(posX[6]-6,posY[6]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[7]&&(X<posX[7]+12)&&Y>posY[7]&&(Y<posY[7]+12)&&n==0){
					PutImage(posX[7]-6,posY[7]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[8]&&(X<posX[8]+12)&&Y>posY[8]&&(Y<posY[8]+12)&&n==0){
					PutImage(posX[8]-6,posY[8]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[9]&&(X<posX[9]+12)&&Y>posY[9]&&(Y<posY[9]+12)&&n==0){
					PutImage(posX[9]-6,posY[9]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[10]&&(X<posX[10]+12)&&Y>posY[10]&&(Y<posY[10]+12)&&n==0){
					PutImage(posX[10]-6,posY[10]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[11]&&(X<posX[11]+12)&&Y>posY[11]&&(Y<posY[11]+12)&&n==0){
					PutImage(posX[11]-6,posY[11]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[12]&&(X<posX[12]+12)&&Y>posY[12]&&(Y<posY[12]+12)&&n==0){
					PutImage(posX[12]-6,posY[12]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[13]&&(X<posX[13]+12)&&Y>posY[13]&&(Y<posY[13]+12)&&n==0){
					PutImage(posX[13]-6,posY[13]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[14]&&(X<posX[14]+12)&&Y>posY[14]&&(Y<posY[14]+12)&&n==0){
					PutImage(posX[14]-6,posY[14]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[15]&&(X<posX[15]+12)&&Y>posY[15]&&(Y<posY[15]+12)&&n==0){
					PutImage(posX[15]-6,posY[15]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[16]&&(X<posX[16]+12)&&Y>posY[16]&&(Y<posY[16]+12)&&n==0){
					PutImage(posX[16]-6,posY[16]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[17]&&(X<posX[17]+12)&&Y>posY[17]&&(Y<posY[17]+12)&&n==0){
					PutImage(posX[17]-6,posY[17]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[18]&&(X<posX[18]+12)&&Y>posY[18]&&(Y<posY[18]+12)&&n==0){
					PutImage(posX[18]-6,posY[18]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[19]&&(X<posX[19]+12)&&Y>posY[19]&&(Y<posY[19]+12)&&n==0){
					PutImage(posX[19]-6,posY[19]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[20]&&(X<posX[20]+12)&&Y>posY[20]&&(Y<posY[20]+12)&&n==0){
				    PutImage(posX[20]-6,posY[20]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[21]&&(X<posX[21]+12)&&Y>posY[21]&&(Y<posY[21]+12)&&n==0){
					PutImage(posX[21]-6,posY[21]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[22]&&(X<posX[22]+12)&&Y>posY[22]&&(Y<posY[22]+12)&&n==0){
					PutImage(posX[22]-6,posY[22]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[23]&&(X<posX[23]+12)&&Y>posY[23]&&(Y<posY[23]+12)&&n==0){
					PutImage(posX[23]-6,posY[23]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[24]&&(X<posX[24]+12)&&Y>posY[24]&&(Y<posY[24]+12)&&n==0){
					PutImage(posX[24]-6,posY[24]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[25]&&(X<posX[25]+12)&&Y>posY[25]&&(Y<posY[25]+12)&&n==0){
					PutImage(posX[25]-6,posY[25]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>posX[26]&&(X<posX[26]+12)&&Y>posY[26]&&(Y<posY[26]+12)&&n==0){
					PutImage(posX[26]-6,posY[26]-6,&BIGPOINT,0x000000,40);
					n=1;
				}else if(X>675&&X<900&&Y>460&&Y<533&&n==0){
					putimage(675,460,&BACK_SMALL);
					n=1;
				}
				else if(X>750&&X<823&&Y>10&&Y<83&&n==0){
					PutImage(750,10,&BACK_TO_MAIN,0x000000,200);
					n=1;
				}
				else{
					putimage(0,0,&DIRECTION_PAGE);
					n=0;
				}
				break;

			case WM_LBUTTONDOWN:
				
				if(X>posX[1]&&(X<posX[1]+12)&&Y>posY[1]&&(Y<posY[1]+12)){num++;
					if( num == 1 ){  i = 1 ;}else if(num == 2){ j = 1;}				
				}else if(X>posX[2]&&(X<posX[2]+12)&&Y>posY[2]&&(Y<posY[2]+12)){num++;
					if( num == 1 ){  i = 2 ;}else if(num == 2){ j = 2;}				
				}else if(X>posX[3]&&(X<posX[3]+12)&&Y>posY[3]&&(Y<posY[3]+12)){num++;
					if( num == 1 ){  i = 3 ;}else if(num == 2){ j = 3;}					
				}else if(X>posX[4]&&(X<posX[4]+12)&&Y>posY[4]&&(Y<posY[4]+12)){num++;
					if( num == 1 ){  i = 4 ;}else if(num == 2){ j = 4;}		
				}else if(X>posX[5]&&(X<posX[5]+12)&&Y>posY[5]&&(Y<posY[5]+12)){num++;
					if( num == 1 ){  i = 5 ;}else if(num == 2){ j = 5;}						
				}else if(X>posX[6]&&(X<posX[6]+12)&&Y>posY[6]&&(Y<posY[6]+12)){num++;
					if( num == 1 ){  i = 6 ;}else if(num == 2){ j = 6;}		;				
				}else if(X>posX[7]&&(X<posX[7]+12)&&Y>posY[7]&&(Y<posY[7]+12)){num++;
					if( num == 1 ){  i = 7 ;}else if(num == 2){ j = 7;}				
				}else if(X>posX[8]&&(X<posX[8]+12)&&Y>posY[8]&&(Y<posY[8]+12)){num++;
					if( num == 1 ){  i = 8 ;}else if(num == 2){ j = 8;}				
				}else if(X>posX[9]&&(X<posX[9]+12)&&Y>posY[9]&&(Y<posY[9]+12)){num++;
					if( num == 1 ){  i = 9 ;}else if(num == 2){ j = 9;}					
				}else if(X>posX[10]&&(X<posX[10]+12)&&Y>posY[10]&&(Y<posY[10]+12)){num++;
					if( num == 1 ){  i = 10 ;}else if(num == 2){ j = 10;	}					
				}else if(X>posX[11]&&(X<posX[11]+12)&&Y>posY[11]&&(Y<posY[11]+12)){num++;
					if( num == 1 ){  i = 11 ;}else if(num == 2){ j = 11;	}				
				}else if(X>posX[12]&&(X<posX[12]+12)&&Y>posY[12]&&(Y<posY[12]+12)){num++;
					if( num == 1 ){  i = 12 ;}else if(num == 2){ j = 12;	}			
				}else if(X>posX[13]&&(X<posX[13]+12)&&Y>posY[13]&&(Y<posY[13]+12)){num++;
					if( num == 1 ){  i = 13 ;}else if(num == 2){ j = 13;	}			
				}else if(X>posX[14]&&(X<posX[14]+12)&&Y>posY[14]&&(Y<posY[14]+12)){num++;
					if( num == 1 ){  i = 14 ;}else if(num == 2){ j = 14;	}			
				}else if(X>posX[15]&&(X<posX[15]+12)&&Y>posY[15]&&(Y<posY[15]+12)){num++;
					if( num == 1 ){  i = 15 ;}else if(num == 2){ j = 15;	}			
				}else if(X>posX[16]&&(X<posX[16]+12)&&Y>posY[16]&&(Y<posY[16]+12)){num++;
					if( num == 1 ){  i = 16 ;}else if(num == 2){ j = 16;	}			
				}else if(X>posX[17]&&(X<posX[17]+12)&&Y>posY[17]&&(Y<posY[17]+12)){num++;
					if( num == 1 ){  i = 17 ;}else if(num == 2){ j = 17;	}
				}else if(X>posX[18]&&(X<posX[18]+12)&&Y>posY[18]&&(Y<posY[18]+12)){num++;
					if( num == 1 ){  i = 18 ;}else if(num == 2){ j = 18;	}			
				}else if(X>posX[19]&&(X<posX[19]+12)&&Y>posY[19]&&(Y<posY[19]+12)){num++;
					if( num == 1 ){  i = 19 ;}else if(num == 2){ j = 19;	}			
				}else if(X>posX[20]&&(X<posX[20]+12)&&Y>posY[20]&&(Y<posY[20]+12)){num++;
					if( num == 1 ){  i = 20 ;}else if(num == 2){ j = 20;	}			
				}else if(X>posX[21]&&(X<posX[21]+12)&&Y>posY[21]&&(Y<posY[21]+12)){num++;
					if( num == 1 ){  i = 21 ;}else if(num == 2){ j = 21;	}			
				}else if(X>posX[22]&&(X<posX[22]+12)&&Y>posY[22]&&(Y<posY[22]+12)){num++;
					if( num == 1 ){  i = 22 ;}else if(num == 2){ j = 22;	}			
				}else if(X>posX[23]&&(X<posX[23]+12)&&Y>posY[23]&&(Y<posY[23]+12)){num++;
					if( num == 1 ){  i = 23 ;}else if(num == 2){ j = 23;	}			
				}else if(X>posX[24]&&(X<posX[24]+12)&&Y>posY[24]&&(Y<posY[24]+12)){num++;
					if( num == 1 ){  i = 24 ;}else if(num == 2){ j = 24;	}	
				}else if(X>posX[25]&&(X<posX[25]+12)&&Y>posY[25]&&(Y<posY[25]+12)){num++;
					if( num == 1 ){  i = 25 ;}else if(num == 2){ j = 25;	}
				}else if(X>posX[26]&&(X<posX[26]+12)&&Y>posY[26]&&(Y<posY[26]+12)){num++;
					if( num == 1 ){  i = 26 ;}else if(num == 2){ j = 26;	}
				}else if(X>675&&X<900&&Y>460&&Y<533){
					putimage(0,0,&MAIN_PAGE);
					MouseControl_MainPage(x);
				}
				else if(X>750&&X<823&&Y>10&&Y<83){
					putimage(0,0,&MAIN_PAGE);
					MouseControl_MainPage(x);
				}
				else {
					num = 0;
				}
				break;
			}

			if(num == 1){
				PutImage(posX[i]-6,posY[i]-6,&BIGPOINT,0x000000,40);	
			}else if(num == 2){
				PutImage(posX[i]-6,posY[i]-6,&BIGPOINT,0x000000,40);	
				PutImage(posX[j]-6,posY[j]-6,&BIGPOINT,0x000000,40);	
				floyd(A,C,i,j);
			}else{
				num = 0;
			}
		}
		_getch;
	}

	
void floyd(int A[][n1+1],int C[][n1+1],int p,int q){
    
    int i,j,k,next;
    int max = 9999;
    
    for(i = 1; i <= n1; i++){
        for(j = 1; j <= n1; j++){
            if(C[i][j] != max){
                path[i][j] = j;
            }
            else{
                path[i][j]= 0;
            }
            A[i][j] = C[i][j];
        }
    }
    
    for(k = 1; k <= n1; k++){
        for(i = 1; i <= n1; i++){
            for(j = 1; j <= n1; j++){
                if(A[i][j] > (A[i][k] + A[k][j])){
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
		TCHAR s[51];
		_stprintf(s, _T("%d"), A[p][q]);
		setbkmode(TRANSPARENT);
		outtextxy(750, 245, s);
		_stprintf(s, _T("%.2f"), A[p][q]/82.0); 
		setbkmode(TRANSPARENT);
		outtextxy(750,281, s);

		next = path[p][q];
		PutImage(posX[p]-6,posY[p]-6,&BIGPOINT,0x000000,40);
        while(next!=q){
			PutImage(posX[next]-6 ,posY[next]-6,&BIGPOINT,0x000000,40);
			next = path[next][q];
           }
		PutImage(posX[q]-6,posY[q]-6,&BIGPOINT,0x000000,40);
}