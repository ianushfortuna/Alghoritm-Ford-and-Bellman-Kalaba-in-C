#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define inf 999
int x[50][50],H[20],B[55][55],v,V[10][10],Vect[50],q1[30],start,sf;
void meniu()
{
    printf("_______________________________MENIU___________________________________\n");
    printf("1.Introduceti matricea adiacenta ponderata.\n");
    printf("2.Afisati matricea.\n");
    printf("3.Determinati drumul minim cu ajutorul algoritmului Ford.\n");
    printf("4.Determinati drumul minim cu ajutorul algoritmului Bellman-Kalaba.\n");
    printf("0.EXIT.\n");
    printf("_______________________________________________________________________\n");
}
void matrice_ponderata()
{
    int i,j;
    printf("Dati gradul matricei: ");
    scanf("%d",&v);
    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            printf("x[%d][%d]= ",i+1,j+1);
            scanf("%d",&x[i][j]);
        }
    }
}
void afis_matrice()
{
    int i,j;
    printf("\nMatricea ponderata este:\n");
    for( i=0; i<v; i++)
    {
        printf("\t[x%d]",i+1);
    }
    for(i=0; i<=v; i++)
    {
        printf("\t");
    }
    printf("\n");
    for(i=0; i<v; i++)
    {
        printf("[x%d]\t",i+1);
        for(j=0; j<v; j++)
        {
            printf(" %d\t",x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int cautare(int Vect[50],int c)
{
    for(int i=0;i<50;i++)
    {
        if(Vect[i]==c)
            return i;
    }
}
void cautare_ford(int start)
{
    int i,sf;
    q1[start]=1;
    for(i=1; i<=sf; i++)
    {
        if(x[start][i]!=0 && q1[i]==0)
            cautare_ford(i);
    }
    printf("%d<-",start);
    return 0;
}
void ford_min()
{
    int i,j,k,v;
    printf("\nDati varful pana in care trebuie de aflat drumul minim: ");
    scanf("%d",&k);
    H[0]=NULL;
    for(i=1; i<k; i++)
    {
        H[i]=inf;
    }
    for(i=0; i<k; i++)
    {
        for(j=0; j<k; j++)
        {
            if(x[i][j]!=0 && i!=j)
            {
                if(H[j]-H[i]>x[i][j])
                {
                    H[j]=H[i]+x[i][j];

                }

            }
        }
    }
    printf("Drumul minim este:%d\n",H[k-1]);
}
void Bellman_min()
{

    int b[v][v];
    int v0[v],v1[v],temp[50];
    int mat[2][v];


    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            b[i][j]=x[i][j];
        }
    }
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
        {
            if(b[i][j]==0)
                b[i][j]=inf;
            if(i==j)
                b[i][j]=0;
        }
    for( int i=0; i<v; i++)
    {
        printf("\t[b%d]",i+1);
    }
    for(int i=0; i<v; i++)
    {
        printf("\t");
    }
    printf("\n");
    for(int i=0; i<v; i++)
    {
        printf("[b%d]\t",i+1);
        for(int j=0; j<v; j++)
        {
            printf(" %d\t",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    for(int i=0; i<v; i++)
    {
        v0[i]=0;
        v1[i]=0;
    }

    for(int i=0; i<v; i++)
        v0[i]=b[i][v-1];
        printf("Valoarea drumului minim!");
            printf("%d ",v1[1]);

    int count1=0,count2=inf;
    int temp1,temp2;
    while(temp1!=temp2)
    {
        temp1=0;
        temp2=0;
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                count1=v0[j]+b[i][j];
                if(count2>count1)
                {
                    count2=count1;
                }
                count1=0;
            }
            v1[i]=count2;
            count2=inf;
        }

        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                count1=v1[j]+b[i][j];
                if(count2>count1)
                {
                    count2=count1;
                }
                count1=0;
            }
            v0[i]=count2;
            count2=inf;
        }
        for(int i=0; i<v; i++)
            temp1+=v0[i];
        for(int i=0; i<v; i++)
            temp2+=v1[i];
    }
    for(int i=0; i<v; i++)
        mat[0][i]=v0[i];
    for(int i=0; i<v; i++)
        mat[1][i]=v1[i];
    printf("Valoarea drumului minim!");
            printf("%d ",mat[1][0]);


    for(int i=0; i<50; i++)
        temp[i]=0;

    int check=0;
    int z=0;
    for(int i=0; i<v; i++)
    {
        for( int j=z+1; j<v; j++)
        {
            if(mat[1][i]-mat[0][j]==b[i][j])
            {
                Vect[check]=i+1;
                Vect[check+1]=j+1;
                check+=2;
            }
        }
        z++;

    }
    int adr1,adr2;
    int final[20];
    for(int i=0; i<20; i++)
        final[i]=0;

    for(int i=0; i<50; i++)
        if(Vect[i]==0)
        {
            adr2=Vect[i-1];
            adr1=i-1;
            break;
        }
    printf("\n");
    int q=2;
    int prs,prev;
    prs=adr2;
    prev=Vect[adr1-1];
    final[1]=prs;
    while(prev!=1)
    {
        final[q]=prev;
        q++;
        prs=Vect[cautare(Vect,prev)];
        prev=Vect[(cautare(Vect,prev))-1];
    }

    int nr;
    for(int i=0;i<20;i++)
        if(final[i]!=0)
        nr++;

    printf("\nDrumul minim :\n");
     printf("1 ");
    for(int i=nr;i>=1;i--)
        printf("%d ",final[i]);

        printf("\n");
}
int main()
{
    int nm,q,k;
    do
    {
        system("cls");
        meniu();
        printf("\nAlegeti optiunea din menu: ");
        scanf("%d", &nm);
        switch(nm)
        {
        case 1:
            matrice_ponderata();
            printf("Pentru a continua tastati ENTER!!!");
            getch();
            break;
        case 2:
            afis_matrice();
            printf("Pentru a continua tastati ENTER!!!");
            getch();
            break;
        case 3:
            ford_min();
            printf("Pentru a continua tastati ENTER!!!");
            getch();
            break;
        case 4:
            Bellman_min();
            printf("Pentru a continua tastati ENTER!!!");
            getch();
            break;
            case 5:
                printf("Inceput",start);
                scanf("%d",&start);
                printf("Sfarsit",sf);
                scanf("%d",&sf);
//            printf("Dati varful din care se incepe parcurgerea:");
//            scanf("%d",&start,&finish);
            printf("\nParcurgerea grafului in adancime:\n");
            cautare_ford(start);
            printf("\nPentru a continua tastati ENTER!!!");
            getch();
            break;
        case 0:
            printf("Doriti sa iesiti din program? (1/0): ");
            scanf("%d", &q);
            if(q==1) return 0;
            printf("\nPentru a continua apasati tasta Enter");
            getch();
            break;
        default:
            printf("\nAlegeti optiunea corecta din menu! ");
            printf("\nPentru a continua apasati tasta Enter");
            getch();

        }
    }
    while(nm!=0);
}
