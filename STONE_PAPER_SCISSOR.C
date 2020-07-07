#include<stdio.h>
#include"all_func.c"
#include<conio.h>

pfig(int y,int colour)
{
	int i;
       for(i=-100;i<=100;i++)
       {
	   breshenham(320+i,y+300,324+i,y+318,colour);
	   breshenham(324+i,y+318,325+i,y+336,colour);
	   breshenham(325+i,y+336,322+i,y+354,colour);
	   breshenham(322+i,y+354,320+i,y+375,colour);
	   breshenham(320+i,y+375,315+i,y+393,colour);
	   breshenham(315+i,y+393,313+i,y+411,colour);
	   breshenham(313+i,y+411,314+i,y+429,colour);
	   breshenham(314+i,y+429,320+i,y+450,colour);
	   }
}

scfig(int y,int colour)
{
	    breshenham(200,y+445,440,y+360,colour);
	    breshenham(200,y+446,440,y+361,colour);
	    breshenham(200,y+375,440,y+460,colour);
	    breshenham(200,y+376,440,y+461,colour);

	    breshenham_circle(215,y+460,20,colour);
	    breshenham_circle(215,y+460,19,colour);
	    breshenham_circle(215,y+360,20,colour);
	    breshenham_circle(215,y+360,19,colour);
}

sfig(int y,int colour)
{   int i;
	for(i=1;i<=80;i++)
	breshenham_circle(320,y+399,i,colour);
}

win()
{
    gotoxy(40,15);
    printf("YOU WIN");
}

lose()
{
    gotoxy(40,15);
    printf("YOU LOSE");
}

draw()
{
    gotoxy(40,15);
    printf("It's a DRAW");
}

main()
{
    char ask,choice;
    int n;
    start_graph();

    gotoxy(55,25);
    printf("PLAYER");
    gotoxy(55,2);
    printf("COMPUTER");

    while(33)
    {
	printf("\ndo you want to continue(y/n) ");
	ask=getche();

	if(ask=='n')
	break;

	printf("\nenter your choice \n1.Stone\n2.paper\n3.scissor");
	choice = getch();
	printf("%c",choice);
	cleardevice();

	gotoxy(55,25);
	printf("PLAYER");
	gotoxy(55,2);
	printf("COMPUTER");

	if(choice=='1')
	{
	    sfig(0,WHITE);//1 for player ;2 for computer
	}
	else if(choice=='2')
	{
	    pfig(0,WHITE);
	}
	else if(choice=='3')
	{
	    scfig(0,WHITE);
	}
	else
	{
	    printf("\n\nINVALID CHOICE ");
	    gotoxy(1,1);
	    delay(1000);
	    cleardevice();
	    continue;
	}
	//getchar();
	n = rand()%3;
	if(n==0)
	{
	    sfig(-300,WHITE);
	}
	if(n==1)
	{
	    pfig(-300,WHITE);
	}
	if(n==2)
	{
	    scfig(-300,WHITE);
	}
	if(choice=='1')//stone
	{
	   if(n==1)//paper
	   {
	       lose();
	   }
	   else if(n==2)//scissor
	   {
	       win();
	   }
	   else
	   draw();
	}
	if(choice=='2')//paper
	{
	   if(n==0)//stone
	   {
	       win();
	   }
	   else if(n==2)//scissor
	   {
	       lose();
	   }
	   else
	   draw();
	}
	if(choice=='3')//scissor
	{
	   if(n==1)//paper
	   {
	       win();
	   }
	   else if(n==0)//stone
	   {
	       lose();
	   }
	   else
	   draw();
	}

	getchar();
	cleardevice();
	gotoxy(1,1);

    }

    getchar();
    stop_graph();
}

