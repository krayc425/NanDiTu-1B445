
void PutSearchingButton()
{
	if(X>=737&&X<=851&&Y>=94&&Y<=138)
	{
		
		PutImage(737,94,&SEARCHING,0x000000,40);
	}
	else
	{
		putimage(0,0,&MAIN_PAGE);
	}
}

void PutDirectionButton()
{
	if(X>=738&&X<=852&&Y>=166&&Y<=210)
	{
		PutImage(738,166,&DIRECTION,0x000000,40);
	}
	else
	{
		putimage(0,0,&MAIN_PAGE);
	}
}

void PutMuteButton()
{
	if(X);
}

void PutAuthorButton()
{
	if(X>=717&&X<=821&&Y>=482&&Y<=527)
	{
		PutImage(717,482,&AUTHOR,0x000000,40);
	}
	else
	{
		putimage(0,0,&MAIN_PAGE);
	}
}

void PutSearchingIcon_1Button()
{
	if(X>=717&&X<=821&&Y>=482&&Y<=527)
	{
		PutImage(717,482,&SEARCHING_ICON[0],0x000000,40);
	}
	else
	{
		putimage(0,0,&SEARCHING_MAINPAGE);
	}
}

void PutSearchingIcon_2Button()
{
	if(X>=717&&X<=821&&Y>=482&&Y<=527)
	{
		PutImage(717,482,&SEARCHING_ICON[1],0x000000,40);
	}
	else
	{
		putimage(0,0,&SEARCHING_MAINPAGE);
	}
}

void PutDirectionIcon_1Button()
{
	if(X>=717&&X<=821&&Y>=482&&Y<=527)
	{
		PutImage(717,482,&DIRECTION_ICON[0],0x000000,40);
	}
	else
	{
		putimage(0,0,&DIRECTION_MAINPAGE);
	}
}

void PutDirectionIcon_2Button()
{
	if(X>=717&&X<=821&&Y>=482&&Y<=527)
	{
		PutImage(717,482,&DIRECTION_ICON[1],0x000000,40);
	}
	else
	{
		putimage(0,0,&DIRECTION_MAINPAGE);
	}
}

