#ifndef FRAME_H
#define FRAME_H

IMAGE MAIN_PAGE,SECOND_PAGE,AUTHOR_MAINPAGE;
IMAGE DIRECTION_PAGE1,DIRECTION_PAGE2,SEARCHING_PAGE1,SEARCHING_PAGE2;
IMAGE ICON_1[5],ICON_2[2],ICON_3[4];
IMAGE BACK_SMALL,BACK_BIG,BACK_TO_MAIN,BACK_TO_MAIN_DORM;
IMAGE SEARCHING_DORM,SEARCHING_CANTEEN,SEARCHING_STUBUILDING,SEARCHING_ELSE;
IMAGE DORM_LOC,DORM_INNER;

void LoadImage()
{
	loadimage(&ICON_1[0],_T("File:icon1_1.jpg"));
	loadimage(&ICON_1[1],_T("File:icon1_2.jpg"));
	loadimage(&ICON_1[2],_T("File:quit.jpg"));
	loadimage(&ICON_1[3],_T("File:mute.jpg"));
	loadimage(&MAIN_PAGE,_T("File:main_page.jpg"));
	loadimage(&SECOND_PAGE,_T("File:second_page.jpg"));
	loadimage(&AUTHOR_MAINPAGE,_T("File:author_mainpage.jpg"));
	loadimage(&BACK_SMALL,_T("File:back_small.jpg"));
	loadimage(&BACK_BIG,_T("File:back_big.jpg"));
	loadimage(&BACK_TO_MAIN,_T("File:back_to_main.jpg"));
	loadimage(&ICON_2[0],_T("File:icon2_1.jpg"));
	loadimage(&ICON_2[1],_T("File:icon2_2.jpg"));
	loadimage(&ICON_3[0],_T("File:icon3_1.jpg"));
	loadimage(&ICON_3[1],_T("File:icon3_2.jpg"));
	loadimage(&ICON_3[2],_T("File:icon3_2.jpg"));
	loadimage(&SEARCHING_PAGE1,_T("File:searching_page1.jpg"));
	loadimage(&SEARCHING_PAGE2,_T("File:searching_page2.jpg"));
	loadimage(&DIRECTION_PAGE1,_T("File:direction_page1.jpg"));
	loadimage(&DIRECTION_PAGE2,_T("File:direction_page2.jpg"));
	loadimage(&SEARCHING_DORM,_T("File:searching_dorm.jpg"));
	loadimage(&SEARCHING_CANTEEN,_T("File:searching_canteen.jpg"));
	loadimage(&SEARCHING_STUBUILDING,_T("File:searching_stubuilding.jpg"));
	loadimage(&DORM_LOC,_T("File:dorm_loc.jpg"));
	loadimage(&DORM_INNER,_T("File:dorm_inner.jpg"));

}

int abs(int a){
	if(a<0)a*=-1;
	return a;
}

void PutImage(int dstX,int dstY,IMAGE *pimg,int avoid_color,int deviation)
{
	int width= pimg->getwidth();// 图像的宽
	int height= pimg->getheight();// 图像的高
    int x,y,color,num;
    int avoid_r=GetRValue(avoid_color);
    int avoid_g=GetGValue(avoid_color);
    int avoid_b=GetBValue(avoid_color);
    IMAGE pSrcImg;//背景图
    SetWorkingImage(NULL);//对默认绘图窗口的绘图操作
    getimage(&pSrcImg,dstX,dstY,width,height);

    DWORD* bk_pMem = GetImageBuffer(&pSrcImg);// 获取背景指向显存的指针
    DWORD* pMem = GetImageBuffer(pimg);//获取贴图指向显存的指针

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

#endif