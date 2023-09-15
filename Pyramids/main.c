#include <stdio.h>
#include <stdlib.h>
int i,j,space;
void pyramid_1  (void);
void pyramid_2  (void);
void pyramid_3  (void);
void pyramid_4  (void);
void pyramid_5  (void);
void pyramid_6  (void);
void pyramid_7  (void);
void pyramid_8  (void);
void pyramid_9  (void);
void pyramid_10 (void);
void pyramid_11 (void);
void pyramid_12 (void);
void pyramid_13 (void);
void pyramid_14 (void);
void pyramid_15 (void);
void pyramid_16 (void);
void pyramid_17 (void);
void pyramid_18 (void);
void pyramid_19 (void);
void pyramid_20 (void);
void pyramid_21 (void);
void pyramid_22 (void);
void pyramid_23 (void);
void pyramid_24 (void);
void pyramid_25 (void);
void pyramid_26 (void);

int main()
{
    /*
    pyramid_1 ();
    pyramid_2 ();
    pyramid_3 ();
    pyramid_4 ();
    pyramid_5 ();
    pyramid_6 ();
    pyramid_7 ();
    pyramid_8 ();
    pyramid_9 ();
    pyramid_10 ();
    pyramid_11 ();
    pyramid_13 ();
    pyramid_14 ();
    pyramid_15 ();
    pyramid_16 ();
    pyramid_17 ();
    pyramid_18 ();
    pyramid_19 ();
    pyramid_20 ();
    pyramid_21 ();
    pyramid_22 ();
    pyramid_23 ();
    pyramid_24 ();
    pyramid_25 ();
    */
    pyramid_26 ();
    return 0;
}
void pyramid_1  (void)
{
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
void pyramid_2  (void)
{
    for(i=1;i<=7;i++)
    {
        for(j=5;j>=i;j--)
        {
            printf("*");
        }
        printf("\n");
    }
}
void pyramid_3  (void)
{
    /*
    int x=5;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {if(j<x){printf(" ");}
        else{printf("*");}}
        x--;
        printf("\n");
    }
    */
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {if((i+j)<=5){printf(" ");}
        else{printf("*");}}
        printf("\n");
    }
}
void pyramid_4  (void)
{
    
    for(i=1;i<=5;i++)
    {
        for(space=1;space<=(5-i);space++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void pyramid_5  (void)
{
    for(i=1;i<=6;i++)
    {
        for(j=6;j>=i;j--)
        {
            printf("%i ",j);
        }
        printf("\n");
    }
}
void pyramid_6  (void)
{
    int num;
    for(i=1;i<=6;i++)
    {
        num = 1;
        for(j=6;j>=i;j--)
        {
            printf("%i ",num);
            num++;
        }
        printf("\n");
    }
}
void pyramid_7  (void)
{
    //int num=1;
    for(i=1;i<=6;i++)
    {
        
        for(j=1;j<=i;j++)
        {
            printf("%i ",i);
            
        }
        //num++;
        printf("\n");
    }
}
void pyramid_8  (void)
{
    int num=1;
    for(i=1;i<=6;i++)
    {
        
        for(j=1;j<=i;j++)
        {
            printf("%i ",num);
           num++; 
        }
        
        printf("\n");
    }
}
void pyramid_9  (void)
{
    for(i=1;i<=6;i++)
    {
        for(space=1;space<=(6-i);space++)
        {
            printf(" ");
        }
        for(j = 1;j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void pyramid_10 (void)
{
    for(i=6;i>=1;i--)
    {
        for(space=1;space<=(6-i);space++)
        {
            printf(" ");
        }
        for(j=1;j<=(2*i-1);j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void pyramid_11 (void)
{
    for(i=1;i<=6;i++)
    {
        for(space=1;space<=(6-i);space++)
        {
            printf(" ");
        }
        for(j=1;j<=(2*i-1);j++)
        {
            printf("*");
        }
        printf("\n");
    }
     for(i=5;i>=1;i--)
    {
        for(space=1;space<=(6-i);space++)
        {
            printf(" ");
        }
        for(j=1;j<=(2*i-1);j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void pyramid_12 (void)
{
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=5;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void pyramid_13 (void)
{
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c ",j+64);
        }
        printf("\n");
    }
}
void pyramid_14 (void)
{
    for(i=1;i<=5;i++)
    {
        for(j=5;j>=i;j--)
        {
            printf("%c ",64+(6-j));
        }
        printf("\n");
    }
}
void pyramid_15 (void)
{
     for(i=1;i<=5;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c ",i+64);
        }
        printf("\n");
    }
}
void pyramid_16 (void)
{
    for(i = 1;i <= 6;i++)
    {
        for(j = 1;j <= 6;j++)
        {
            if(i > 1 && i < 6)
            {
                if((j == 1) || (j == 6))
                {
                    printf("* ");
                }
                else
                {
                printf("  ");
                }
            }
            else
            {
            printf("* ");
            }
        }

        printf("\n");
    }
}
void pyramid_17 (void)
{
    for(i = 6;i >= 1;i--)
    {
        for(j = i;j >= 1;j--)
        {
            if(i >2 && i < 6)
            {
                if(j == 1 || j == i)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            else
            {
            printf("* ");
            }
        }
        printf("\n");
    }
}
void pyramid_18 (void)
{
    
    for(i = 1; i <=6;i++)
    {
        for(space = 1;space <= (6-i);space++)
        {
            printf(" ");
        }
        for(j = 1; j <= i;j++)
        {
            if((i != 1) && (i != 6)  && (j > 1) && (j != i ))
            {
                printf("  ");
            }
            else
            {
            printf("* ");
            }
        }
        printf("\n");
    }

}
void pyramid_19 (void)
{
    for(i = 1; i <= 6; i++)
    {
        for(j =1; j <= i;j++)
        {
            if((j!=1) && (j!=i) && (i!=1) && (i!=6))
            {
                printf("  ");    
            }
            else
            {
                printf("%i ",j);
            }
            
        }
        printf("\n");
    }
}
void pyramid_20 (void)
{
    /*
            1
          2 3 2
        3 4 5 4 3
      4 5 6 7 6 5 4
    5 6 7 8 9 8 7 6 5
    */
    for(i = 1;i<=5;i++)
    {
        for(space = 4;space >= i ; space--)
        {
            printf("  ");
        }
        for(j = i ; j <= (2*i-1) ; j++)
        {
            if(j == 2*i-1)
            {
                printf("%i ",j);
                while(j != i)
                {
                j--;
                printf("%i ",j);
                }
                j = 2*i-1;
            }
            else
            {
                printf("%i ",j);
            }
        }
        printf("\n");
    }
}
void pyramid_21 (void)
{
    /*
           1
          1 2
         1   3
        1     4
       1       5
      1 2 3 4 5 6
    */
    for(i = 1 ; i <= 6 ; i++)
    {
        for(space=1;space<=(6-i);space++)
        {
                printf(" ");
        }
        for(j = 1 ; j <= i ; j++)
        {
            if((j != 1) && (j != i) && (i != 6))
            {
                printf("  ");
            }
            else
            {
                printf("%i ",j);    
            }
            
        }
        printf("\n");
    }

}
void pyramid_22 (void)
{
    /*
        1 2 3 4 5 6
        2       6
        3     6
        4   6
        5 6
        6
    */
    for(i = 1 ; i <= 6 ; i++)
    {
        for(j = i ; j <= 6 ; j++)
        {
            if((i != 1) && (j != i) && (j != 6))
            {
                printf("  ");
            }
            else
            {
                printf("%i ",j );
            }
        }
        printf("\n");
    }
}
void pyramid_23 (void)
{
    /*
        1
        1 2 1
        1 2 3 2 1
        1 2 3 4 3 2 1
        1 2 3 4 5 4 3 2 1
        1 2 3 4 5 6 5 4 3 2 1
    */
    for(i = 1 ; i <= 6 ; i++)
    {
        for(j = 1 ; j <= (2*i-1) ; j++)
        {
            if(j == i)
            {
                printf("%i ",j);
                j--;
                while(j != 0)
                {
                    printf("%i ",j );
                    j--;
                }
                j = 2*i-1;
            }
            else
            {
                printf("%i ",j);
            }
            
        }
        printf("\n");
    }
}
void pyramid_24 (void)
{
    /*
                1
              1 2 1
            1 2 3 2 1
          1 2 3 4 3 2 1
        1 2 3 4 5 4 3 2 1
      1 2 3 4 5 6 5 4 3 2 1
    */
    for(i = 1 ; i <= 6 ; i++)
    {
        for(space = 1 ; space <= 6-i ; space++)
        {
            printf("  ");
        }
        for(j = 1 ; j <= (2*i-1) ; j++)
        {
            if(j == i)
            {
                printf("%i ",j);
                j--;
                while(j != 0)
                {
                    printf("%i ",j );
                    j--;
                }
                j = 2*i-1;
            }
            else
            {
                printf("%i ",j);
            }
            
        }
        printf("\n");
    }
}
void pyramid_25 (void)
{
    
     /*
        A
        A B A
        A B C B A
        A B C D C B A
        A B C D E D C B A
        A B C D E F E D C B A
    */
    for(i = 1 ; i <= 6 ; i++)
    {
        for(j = 65 ; j <= (2*i+64)-1 ; j++)
        {
            if((j-64) == i)
            {
                printf("%c ",j);
                j--;
                while(j != 64)
                {
                    printf("%c ",j );
                    j--;
                }
                j = (2*i+64)-1;
            }
            else
            {
                printf("%c ",j);
            }
            
        }
        printf("\n");
    }
}
void pyramid_26 (void)
{
    /*
       ********1*********
       *******2*2********
       ******3*3*3*******
       *****4*4*4*4******
       ****5*5*5*5*5*****
       ***6*6*6*6*6*6****
    
    
    */
   int x = 0;
    for(i=1;i<=6;i++)
    {
        
        for(space=1;space<=(6-i)+1;space++)
        {
            printf("");
        }
        
        for(j = 1;j <= 17; j++)
        {
            
            if((((21/2)-i) == j))
            {
                x = i;
                for(i ; i >= 1 ; i--)
                {
                    printf("%i*",i);
                }
                i = x;
               
            }
            else
            {
                printf("*");
            }
            
        }
        printf("\n");
    }
}