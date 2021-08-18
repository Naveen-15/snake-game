#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std ;
bool gameover;
const int width=20;
const int height=20;
int x,y,fx,fy,score,ntail=0;
int tailx[100],taily[100];
enum edir{ STOP=0,LEFT,RIGHT,UP,DOWN};
edir dir;
void setup()
{
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fx=rand() % width;
    fy=rand() % height;
    score=0;

}
void draw()
{
    system("cls");
    for(int i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                cout<<"#";
            if(i==y&&j==x)
                cout<<"O";
            else if(i==fy&&j==fx)
                cout<<"f";
            else
            {bool print=false;
                for(int k=0;k<ntail;k++)
                {
                    if(tailx[k]==j&&taily[k]==i)
                    {
                            cout<<"0";
                            print=true;
                    }
                }
                if(!print)
                {
                    cout<<" ";
                }
                
            }
            if(j==width-1)
                cout<<"#";

        }

             cout<<endl;
    }
    
    for(int i=0;i<width+2;i++)
        cout<<"#";
    
    cout<<endl;
    cout<<"score:"<<score;
}
void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':dir=LEFT;
                        break;
            case 'd':dir=RIGHT;
                        break;
            case 'w':dir=UP;
                        break;
            case 's':dir=DOWN;
                        break;
            case 'x':gameover=true;
                        break;
            
            
        }
    }

}
void logic()
{
    
    int prex=tailx[0];
    int prey=taily[0];
    tailx[0]=x;
    taily[0]=y;
    int prex2,prey2;
    for(int i=1;i<ntail;i++)
    {
        prex2=tailx[i];
        prey2=taily[i];
        tailx[i]=prex;
        taily[i]=prey;
        prex=prex2;
        prey=prey2;

    }
    switch(dir)
    {
        case LEFT:x--;break;
        case RIGHT:x++; break;
        case UP:y--;break;
        case DOWN:y++;break;
    }
    if(x<0||x>width||y<-2||y>height)
            gameover=true;
    for(int i=0;i<ntail;i++)
    {
        if(x==tailx[i]&&y==taily[i])
                gameover=true;
    }
    if(x==fx&&y==fy)
    {
        score+=10;
        fx=rand() % width;
        fy=rand() % height;
        ntail++;
    }
}

int main()
{
    setup();
    while(!gameover)
    {
        draw();
        input();
        logic(); 
        Sleep(10);
    }

}