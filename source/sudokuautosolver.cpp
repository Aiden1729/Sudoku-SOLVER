#define N1 9
#include<simplecpp>
#include<fstream>
int rako=0;
bool findunassingnedlocation(int grid[N1][N1],int &row,int &col)//checking the unassigned location
{
    for(row=0;row<N1;row++)
        for(col=0;col<N1;col++)
            if(grid[row][col]==0)
            return true;
    return false;
}
bool usedinrow(int grid[N1][N1],int row,int num)//checking whether num is safe in row
{
    for(int col=0;col<N1;col++)
        if(grid[row][col]==num)
            return true;
    return false;
}
bool usedincol(int grid[N1][N1],int col,int num)//checking whether num is safe in column
{
    for(int row=0;row<N1;row++)
        if(grid[row][col]==num)
            return true;
    return false;
}
bool usedinbox(int grid[N1][N1], int boxStartRow, int boxStartCol, int num)//checking whether num is safe in the 3*3 grid
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
bool issafe(int grid[N1][N1],int row,int col,int num)//if num is safe in row,column.grid then it returns true
{

    if(rako>100000)
    {return 0;}
    else
     {return !usedinrow(grid, row, num) &&
           !usedincol(grid, col, num) &&
           !usedinbox(grid, row - row%3 , col - col%3, num);
    }
}
bool solvesudoku(int grid[N1][N1])
{
    rako++;
    int row,col;
    if(!findunassingnedlocation(grid,row,col))
        return true;
    for(int num=1;num<=9;num++)
    {
        if(issafe(grid,row,col,num))
        {
            grid[row][col]=num;//allocating number
            if(solvesudoku(grid))//recursive calling
                return true;//back tracking
            grid[row][col]=0;
        }
    }
    return false;//end of backtracking
}
int main()
{
    int grid[N1][N1],solution[N1][N1];
    initCanvas();
    Rectangle sud(150,150,100,30);
    Text t1(150,150,"play sudoku");
    Rectangle pla(150,200,100,30);
    Text t2(150,200,"sudoku solver");
    int s1=getClick(),r1=s1/65536,r2=(s1%65536);
    if(r1>=100&&r1<=200&&r2>=135&&r2<=175)
    {
        sud.hide();
        t1.hide();
        pla.hide();
        t2.hide();
        Rectangle ea(150,150,100,30);
        Text es(150,150,"easy");
        Rectangle me(150,200,100,30);
        Text md(150,200,"medium");
        Rectangle di(150,250,100,30);
        Text df(150,250,"difficult");
        int ra=getClick(),bi=ra/65536,si=(ra%65536),v4=150,v5=150,v6=1;
        repeat(3)
        {
            if(bi>=v4-50&&bi<=v4+50&&si>=v5-15&&si<=v5+15)
            {
                ea.hide();
                es.hide();
                me.hide();
                md.hide();
                di.hide();
                df.hide();
                int m1=1,x2=150,y2=150;
                Rectangle n1(x2,y2,30,30);
                Text n2(x2,y2,"1");
                Rectangle n3(x2+50,y2,30,30);
                Text n4(x2+50,y2,"2");
                Rectangle n5(x2+100,y2,30,30);
                Text n6(x2+100,y2,"3");
                int k3=getClick(),k4=k3/65536,k5=(k3%65536),x3=150,y3=150;
                repeat(3)
                {
                    if(k4>=x3-15&&k4<=x3+15&&k5>=y3-15&&k5<=y3+15)
                    {
                        n1.hide();
                        n2.hide();
                        n3.hide();
                        n4.hide();
                        n5.hide();
                        n6.hide();
                        ifstream inf;
                        switch(v6)
                        {
                            case 1://if clicked on easy
                            {
                                switch(m1)
                                {
                                    case 1://if clicked on 1
                                    {inf.open("easy 1");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;
                                        }
                                    case 2://if clicked on 2
                                    {
                                        inf.open("easy 2");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;
                                    }
                                    case 3://if clicked on 3
                                    {
                                        inf.open("easy 3");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;
                                    }
                                }
                                break;//end of easy case
                            }
                            case 2://if clicked on medium
                            {
                                switch(m1)
                                {
                                    case 1://if clicked on 1
                                    {
                                        inf.open("medium 1");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;
                                    }
                                    case 2://if clicked on 2
                                    {
                                        inf.open("medium 2");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;
                                    }
                                    case 3://if clicked on 3
                                    {
                                        inf.open("medium 3");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;

                                    }
                                }
                                break;//closing medium
                            }
                            case 3://if clicked on difficult
                            {
                                switch(m1)
                                {
                                    case 1://if clicked on 1
                                    {
                                        inf.open("hard 1");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;

                                    }
                                    case 2://if clicked on 2
                                    {
                                        inf.open("hard 2");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;
                                    }
                                    case 3://if clicked on 3
                                    {
                                        inf.open("hard 3");
                                        for(int k1=0;k1<9;k1++)
                                        {
                                            for(int k2=0;k2<9;k2++)
                                            {
                                                inf>>grid[k1][k2];//copying contents of file into array
                                                solution[k1][k2]=grid[k1][k2];

                                            }
                                        }
                                        inf.close();
                                        break;
                                    }
                                    break;//end of difficult case

                                }
                            }
                            break;//end of switch
                        }
                        int x=100,y=100,a=130,b=130,i=1,i1=0,i2=0;
                        repeat(9)
                        {
                            repeat(9)
                            {
                                Rectangle r(x,y,30,30);
                                r.imprint();
                                if(grid[i1][i2]!=0)
                                {
                                    Text t1(x,y,grid[i1][i2]);
                                     t1.setColor(COLOR("blue"));
                                    t1.imprint();

                                }
                                x=x+30;
                                i2++;
                            }
                            i2=0;
                            i1++;
                            x=100;
                            y=y+30;
                        }
                        repeat(3)
                        {
                            repeat(3)
                            {
                                Rectangle s(a,b,90,90);
                                s.setColor(COLOR("red"));
                                s.imprint();
                                a=a+90;
                            }
                            a=130;
                            b=b+90;
                        }
                        repeat(9)
                        {
                            Text t(x,y+20,i);
                            t.imprint();
                            Rectangle r(x,y+20,30,30);
                            r.imprint();
                            x=x+30;
                            i++;
                        }
                        Rectangle r12(420,100,100,30);
                        Text s12(420,100,"see solution");
                        Rectangle r13(420,150,100,30);
                        Text s13(420,150,"verify");
                        Text s14(220,50,"Click on the number and then click on box");
                        Text s15(220,70,"in which you want the number to placed.");
                        Text s16(220,450,"For solution click on see solution.");
                        Text s17(220,470,"After filling all entries click on verify");
                        Text s18(220,490,"to check your answer.");

                        repeat(81)
                        {
                            int w=getClick();
                            int p=w/65536,q=w%65536,n=1,d=y+5,c=85,e,f;
                            e=85;
                            f=y+15;
                            repeat(9)
                            {
                                if(p<c+30&&p>c&&q>d&&q<d+30)
                                {
                                    int v=getClick();
                                    int k=v/65536,l=v%65536;
                                    repeat(10)
                                    {
                                        repeat(9)
                                        {
                                            if(k<e+30&&k>e&&l<f&&l>f-30)
                                            {
                                                int o=(e+15),p=(f-15);
                                                int q=((o-100)/30),s=((p-100)/30);
                                                grid[s][q]=n;
                                                Text z(e+15,f-15,n);
                                                z.setColor(COLOR("blue"));
                                                z.imprint();
                                                Rectangle r3(e+15,f-15,30,30);
                                                r3.setColor(COLOR("blue"));
                                                r3.imprint();
                                            }
                                            e=e+30;
                                        }
                                        e=85;
                                        f=f-30;
                                    }
                                }
                                c=c+30;
                                n++;
                            }
                            if(p>=370&&p<=470&&q>=85&&q<=115)
                            {

                                if(solvesudoku(solution)==true)
                                {
                                    int x11=100,y11=100,sh=0,hi=0;
                                    repeat(9)
                                    {
                                        repeat(9)
                                        {
                                            Text x12(x11,y11,solution[sh][hi]);
                                            x12.imprint();
                                            x11=x11+30;
                                            hi++;
                                        }
                                        x11=100;
                                        hi=0;
                                        sh++;
                                        y11=y11+30;
                                    }

                                }
                                break;
                            }
                            if(p>=370&&p<=470&&q>=135&&q<=165)
                            {
                                int t14;
                                if(solvesudoku(solution)==true)
                                {
                                    for(int v=0;v<9;v++)
                                    {
                                        for(int v1=0;v1<9;v++)
                                        {
                                            if(grid[v][v1]!=solution[v][v1])
                                            {
                                                Text v2(420,200,"wrong answer");
                                                v2.imprint();
                                                t14=1;
                                                break;

                                            }
                                            if(grid[v][v1]==solution[v][v1]&&v==8&&v1==8)
                                            {
                                                Text v2(420,200,"right solution");
                                                v2.imprint();
                                            }


                                        }
                                        if(t14==1)
                                        break;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    x3=x3+50;
                    m1++;
                }
            }
            v5=v5+50;
            v6++;
        }
    }
    else
    {
        sud.hide();
        t1.hide();
        pla.hide();
        t2.hide();
        for(int a1=0;a1<9;a1++)
        {
            for(int a2=0;a2<9;a2++)
            {
                grid[a1][a2]=0;
            }
        }
        int x=100,y=100,a=130,b=130,i=1;
        repeat(9)
        {
            repeat(9)
            {
                Rectangle r(x,y,30,30);
                r.imprint();
                x=x+30;
            }
            x=100;
            y=y+30;
        }
        repeat(3)
        {
            repeat(3)
            {
                Rectangle s(a,b,90,90);
                s.setColor(COLOR("red"));
                s.imprint();
                a=a+90;
            }
            a=130;
            b=b+90;
        }
        repeat(9)
        {
            Text t(x,y+20,i);
            t.imprint();
            Rectangle r(x,y+20,30,30);
            r.imprint();
            x=x+30;
            i++;
        }
        Rectangle b3(400,100,50,30);
        Text c3(400,100,"solve");
        Text s14(220,50,"Click on the number and then click on box");
        Text s15(220,70,"in which you want the number to placed.");
        Text s16(220,450,"After filling entries click on solve ");
        Text s17(220,470,"for solution.");

        repeat(81)
        {
            int w=getClick();
            int p=w/65536,q=w%65536,n=1,d=y+5,c=85,e,f;
            e=85;
            f=y+15;
            repeat(9)
            {
                if(p<c+30&&p>c&&q>d&&q<d+30)
                {
                    int v=getClick();
                    int k=v/65536,l=v%65536;
                    repeat(10)
                    {
                        repeat(9)
                        {
                            if(k<e+30&&k>e&&l<f&&l>f-30)
                            {
                                int o=(e+15),p=(f-15);
                                int q=((o-100)/30),s=((p-100)/30);
                                grid[s][q]=n;
                                Rectangle z2(e+15,f-15,30,30);
                                z2.setColor(COLOR("white"));
                                z2.setFill(1);
                                z2.imprint();
                                Text z(e+15,f-15,n);
                                z.setColor(COLOR("blue"));
                                z.imprint();
                                Rectangle r3(e+15,f-15,30,30);
                                r3.imprint();

                            }
                            e=e+30;
                        }
                        e=85;
                        f=f-30;
                    }
                }
                c=c+30;
                n++;
            }
            if(p>375&&p<425&&q>85&&q<115)
            break;

        }
        int w=100,z=100;
        if(solvesudoku(grid)==true)
        {
            for(int A=0;A<9;A++)
            {
                for(int B=0;B<9;B++)
                {
                    Text t2(w,z,grid[A][B]);
                    t2.imprint();
                    w=w+30;

                }
                w=100;
                z=z+30;
            }


        }
        else
        {
            Rectangle r1(420,340,100,30);
            r1.imprint();
            Text t11(420,340,"no solution");
            t11.imprint();

        }


    }
    wait(5);
}
