#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<graphics.h>
#include<conio.h>
#include<string>
using namespace std;

class cars{  //20*40
public:
    int x,y;
    int fig(int colour)
    {
        int i;
        setcolor(colour);
        line(x,y+3,x,y+37);
        line(x+1,y+2,x+1,y+38);

        for(i=0;i<=16;i++)
        {

            line(x+2+i,y,x+2+i,y+10);
            line(x+2+i,y+20,x+2+i,y+30);
            line(x+2+i,y+37,x+2+i,y+40);
        }

        line(x+19,y+2,x+19,y+38);
        line(x+20,y+3,x+20,y+37);
    }

    int move(int flag)
    {
        if(flag==0)
        {

            //right part starts
            setcolor(WHITE);
            if((x+22)!=251&&(x+22)!=571)
            line(x+22,y+3,x+22,y+37);

            line(x+21,y+3,x+21,y+37);//last line set
            line(x+20,y+2,x+20,y+38);//second last line set
            line(x+19,y,x+19,y+40);

            setcolor(BLACK);
            line(x+19,y+11,x+19,y+19);
            line(x+19,y+31,x+19,y+36);

            //left part starts
            setcolor(BLACK);
            line(x,y,x,y+40);//erase the leftmost part as black

            line(x+1,y,x+1,y+40);//erase second last line
            line(x+2,y,x+2,y+40);//erasing the third line

            setcolor(WHITE);
            line(x+1,y+3,x+1,y+37);//setting the last line
            line(x+2,y+2,x+2,y+38);//setting the thirs line
            //left part done

            setcolor(WHITE);
            x=x+1;
        }
        else if (flag==1)//from right to left
        {
            //left part starts
            setcolor(WHITE);
            if((x-2)!=69&&(x-2)!=389)
            line(x-2,y+3,x-2,y+37);
            line(x-1,y+3,x-1,y+37);
            line(x,y+2,x,y+38);


            setcolor(BLACK);
            line(x+1,y+11,x+1,y+19);
            line(x+1,y+31,x+1,y+36);

            line(x+20,y,x+20,y+40);//erasing the last line
            line(x+19,y,x+19,y+40);//erasing the second last line
            line(x+18,y,x+18,y+40);//erasing the third last line


            setcolor(WHITE);
            line(x+19,y+3,x+19,y+37);
            line(x+18,y+2,x+18,y+38);
            x=x-1;
        }
    }

};

class box{ //30*30

public:
    int x,y;
    int fig(int colour)
    {
        int i;

        setcolor(colour);
        line(x,y+2,x,y+28);
        line(x+1,y+1,x+1,y+29);

        for(i=2;i<29;i++)
        {
            line(x+i,y,x+i,y+30);
        }

        line(x+29,y+1,x+29,y+29);
        line(x+30,y+2,x+30,y+28);
    }

    int move()//always moves down
    {
        setcolor(BLACK);
        line(x,y,x+30,y);
        line(x,y+1,x+30,y+1);
        line(x,y+2,x+30,y+2);//erased the top 3 lines

        //above erased

        setcolor(RED);
        line(x+2,y+1,x+28,y+1);
        line(x+1,y+2,x+29,y+1);//top two set

        line(x+1,y+29,x+29,y+29);
        line(x+2,y+30,x+28,y+30);

        setcolor(WHITE);
        y=y+1;


    }
};

int l=0,r=0;
float count=2;


int spawn_box(box *b)
{
    int n;
    static int spawned=0;
    char str[30];
    if(l==3)//can only allocate on right side
    {
        r++;
        n=rand()%2;//0 for left and 1 for right
        if(n==0)
        {
            b->x=390;
            b->y=-50;
            b->fig(RED);
        }
        else
        {
            b->x=550;
            b->y=-50;
            b->fig(RED);
        }
    }
    else if(r==3)//can only allocate to left side
    {
        l++;
        n=rand()%2;
        if(n==0)
        {
            b->x=70;
            b->y=-50;
            b->fig(RED);
        }
        else
        {
            b->x=230;
            b->y=-50;
            b->fig(RED);
        }
    }

    else//can allocate to any side
    {
        n=rand()%2;//0 for left and 1 for right
        if(n==0)
        {
            l++;
            n=rand()%2;
            if(n==0)
            {
                b->x=70;
                b->y=-50;
                b->fig(RED);
            }
            else
            {
                b->x=230;
                b->y=-50;
                b->fig(RED);
            }
        }
        else//right side ka left/right
        {
            r++;
            n=rand()%2;//0 for l and 1 for right
            if(n==0)
            {
                b->x=390;
                b->y=-50;
                b->fig(RED);
            }
            else
            {
                b->x=550;
                b->y=-50;
                b->fig(RED);
            }
        }
    }
    spawned++;
    //gotoxy(600,20);
    sprintf(str,"Score : %d",spawned-6);
    setcolor(WHITE);
    outtextxy(300,30,str);
    setcolor(RED);
    //printf("SCORE:%d",string);
    if(spawned%25==0)
    {
        count=count+0.4;
    }

}


int check_crash(cars car1,cars car2,box b1)
{
    if(b1.x>320)//check with car2
    {
        if((b1.x>=car2.x)&&(b1.x<=car2.x+20)||(b1.x+30>=car2.x&&b1.x+30<=car2.x+20))
        {
            if((b1.y>=400&&b1.y<=440)||b1.y+30>=400&&b1.y+30<=440)
            {
                return(1);
            }
        }
    }
    else
    {
        if((b1.x>=car1.x)&&(b1.x<=car1.x+20)||(b1.x+30>=car1.x&&b1.x+30<=car1.x+20))
        {
            if((b1.y>=400&&b1.y<=440)||b1.y+30>=400&&b1.y+30<=440)
            {
                return(1);
            }
        }
    }


    return(0);
}



int start()
{
    cars car1,car2;
    int i;
    car1.x=70;
    car2.x=390;
    car1.y=400;
    car2.y=400;
    //int x_car1=70,x_car2=390;
    car1.fig(WHITE);
    car2.fig(WHITE);
    int c1_flag=0,c2_flag=0;  //flag =0 :- go towards right

    box b1,b2,b3,b4,b5,b6;
    spawn_box(&b1);
    spawn_box(&b2);
    spawn_box(&b3);
    spawn_box(&b4);
    spawn_box(&b5);
    spawn_box(&b6);

    b3.y=b3.y-200;
    b4.y=b4.y-200;
    b5.y=b5.y-400;
    b6.y=b6.y-400;


    //box initialized
    int crashed=0;
    int m_flag=0,z_flag=0;

    while(1)
    {
        delay(7);
        if(GetKeyState('Z') & 0x8000)
        {
            z_flag=1;
        }
        if(GetKeyState('M') & 0x8000)
        {
            m_flag=1;
        }
        if(GetKeyState('Q') & 0x8000)
        {
            break;
        }
        if(z_flag==1)
        {
            for(i=0;i<10;i++)
            car1.move(c1_flag);
            if(car1.x>=230)
            {
                c1_flag=1;
                z_flag=0;
            }
            if(car1.x<=70)
            {
                c1_flag=0;
                z_flag=0;
            }
        }
        if(m_flag==1)
        {
            for(i=0;i<10;i++)
            car2.move(c2_flag);
            if(car2.x<=390)
            {
                c2_flag=0;
                m_flag=0;
            }
            if(car2.x>=550)
            {
                c2_flag=1;
                m_flag=0;
            }
        }

        for(i=0;i<count;i++)
        {

            b1.move();
            b1.move();

            b2.move();
            b2.move();

            b3.move();
            b3.move();

            b4.move();
            b4.move();

            b5.move();
            b5.move();

            b6.move();
            b6.move();
        }

        crashed=check_crash(car1,car2,b1);
        if(crashed==1)
            break;
        crashed=check_crash(car1,car2,b2);
        if(crashed==1)
            break;
        crashed=check_crash(car1,car2,b3);
        if(crashed==1)
            break;
        crashed=check_crash(car1,car2,b4);
        if(crashed==1)
            break;
        crashed=check_crash(car1,car2,b5);
        if(crashed==1)
            break;
        crashed=check_crash(car1,car2,b6);
        if(crashed==1)
            break;

        if(b1.y>480)
        {
            if(b1.x>320)
                r--;
            else
                l--;

            spawn_box(&b1);

            if(b2.x>320)
                r--;
            else
                l--;

            spawn_box(&b2);
        }
        if(b3.y>480)
        {
            if(b3.x>320)
                r--;
            else
                l--;

            spawn_box(&b3);

            if(b4.x>320)
                r--;
            else
                l--;

            spawn_box(&b4);
        }

        if(b5.y>480)
        {
            if(b5.x>320)
                r--;
            else
                l--;

            spawn_box(&b5);

             if(b6.x>320)
                r--;
            else
                l--;

            spawn_box(&b6);
        }
    }
    if(crashed==1)
    {
        printf("\nSORRY TRY AGAIN \n");
        printf("press enter to continue\n");
    }
    getchar();
}


main()
{
    int gd,gm;
    gd=DETECT;
    int n,i;
    initgraph(&gd,&gm,"");

    printf("M to shift right car and z to shift left car \n enter to continue");
    getchar();

    line(319,25,319,480);
    line(320,25,320,480);
    line(321,25,321,480);

    start();


    closegraph();
}
