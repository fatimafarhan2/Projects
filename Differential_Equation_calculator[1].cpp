#include<iostream>
#include<string.h>
using namespace std;

int main()
{

char eq[100],px[100]={'\0'},qx[100]={'\0'};

cout<<"enter the equation for linear"<<endl
<<"enter in the form ' y'+(p(x))y=(q(x)) '"<<endl;
gets(eq);

int l=strlen(eq),c1=0,x1,n1=0,j;

//EXTRACTION OF PX
for(int i=0;i<l;i++)
{
    if(c1==1)
    {
        break;
    }
    else
    {
if(eq[i]==40)
    {
        c1++;
    for(j=i+1;eq[j]!=41;j++)
    {
        px[n1]=eq[j];
        n1++;
    }  
        x1=j;
    }
    }   
}

int n2=0;

//EXTRACTION OF QX
for(int i=x1+1;i<l;i++)
{
    if(eq[i]==40)
    {
    for(int j=i+1;eq[j]!=41;j++)
    {
        qx[n2]=eq[j];
        n2++;
    }  

    }
    
}

//----------------------------------------------------------------------------------------------------------------
//INTEGRATION OF P(X)
//Counting no.of terms in p(x)
int trm=0;
int l1=strlen(px);
for(int i=0;i<l1;i++)
{
    if(px[i]=='x')
    {
        trm++;
    }
    else
    {
        continue;
    }
}


//extraction of coeff
//EXTRACTION VARIABLES
float pow1[100]={'\0'},coef1[100]={'\0'},pow0[100]={'\0'};
int c=0;
char psgn[trm]={'\0'},tsgn[trm]={'\0'};
float coeff[trm]={'\0'},npow[100]{'\0'};

for(int i=0;i<l1;i++)
{
    if(i%6==0)
    {
        coef1[c]=(int)(px[i]-'0');
        c++;
    }
}



//Extraction for power
c=0;
int p=4;
for(int i=0;i<l1;i++)
{
    pow1[c]=(int)(px[p]-'0');
    
    //cout<<pow1[c]<<endl;
    c++;
    p=p+6;
    
}


//extraction of power sign
c=0;
int c4=3;
for(int i=0;i<l1;i++)
{
    if(i%3==0)
    {
        psgn[c]=px[c4];
        c++;
        c4=c4+6;
    }
}


//Extraction for term sign

c=0;
int c5=5;
for(int i=0;i<l1-1;i++)
{
    tsgn[c]=px[c5];
    c5=c5+5;
    c++;
}



  
//copying of before integrtion power
for(int i=0;i<trm;i++)
{
    pow0[i]=pow1[i];
}


//CALCULATION
//cout<<"term"<<trm<<endl;
for(int i=0;i<trm;i++)
{
    if(psgn[i]==45)
    {
        coeff[i]=coef1[i];
        continue;
    }
    else
    {
       //calculation for power 
            pow1[i]=pow1[i]+1;

        //calculation for coeff
            coef1[i]=coef1[i]/pow1[i];
             
           
        
    }
}







//adding coeff of power 1 in p(x) that will become power of ex
for(int i=0;i<trm;i++)
{
    if(trm>=2)
    {
if(pow0[i]==pow0[i+1])
    {
       
        coeff[i]=coef1[i]+coef1[i+1];
        
    }
    else 
    {
        coeff[i]=coef1[i];
    
    }
    }
    else 
    {
        coeff[i]=coef1[i];

    }
    
}


//-----------------------------------------------------------------------------------------

//counting negative x power terms
int minus=0;
for(int i=0;i<trm;i++)
{
    if(psgn[i]==45)
    {
        minus++;
    }
    continue;
}

//counting no.of ex terms
int ex=0,cs2=0;
for(int i=0;i<trm;i++)
{

    if(psgn[i]==45)
    {
        cs2++;
        continue;
    }
    else
    {
        ex++;
    }


}

//y'+(4x^+0+3x^-1)=(2x^+2)
//new power array i(x) ki power
for(int i=0;i<trm;i++)
{
    npow[i]=coeff[i];
}



//extraction of variables of q[x]
//counting the terms in qx
int trm1=0;
int ln=strlen(qx);
for(int i=0;i<ln;i++)
{
    if(qx[i]=='x')
    {
        trm1++;
    }
    else
    {
        continue;
    }
}

//extraction of coeff
float pow2[trm1]={'\0'},coef2[trm1];
int d=0;
char psgn1[trm1]={'\0'},tsgn1[trm1]={'\0'};
float coeff1[trm1];

for(int i=0;i<ln;i++)
{
    if(i%6==0)
    {
        coef2[d]=(int)(qx[i]-'0');
       // cout<<"coefficeient of qx "<<coef2[d]<<endl;
         d++;
    }
}
float ixpo[100]={'\0'};
// for(int i=0;npow[i]!={'\0'};i++)
// {
//     ixpo[i]=npow[i];
//     cout<<"ixpo= "<<ixpo[i]<<"i= "<<i;
// }
//Extracrion for power
 d=0;
int p1=4;
for(int i=0;i<ln;i++)
{
    
    pow2[d]=((int)(qx[p1]-'0'));
       //cout<<npow[0]<<" i= "<<i<<endl;
    d++;
 
    p1=p1+6;
    
}


//extraction of power sign
d=0;
int d1=3;
for(int i=0;i<l1;i++)
{
    if(i%3==0)
    {
        psgn1[d]=qx[d1];
        d++;
        d1=d1+6;
    }
}

//extraction of term sign 
d=0;
int d2=5;
for(int i=0;i<ln-1;i++)
{
    tsgn1[d]=px[d2];
    d2=d2+5;
    d++;
}



//COUNTING NO.OF TERMS AFTER INTEGRATION
int trms_int=0;
for(int i=0;npow[i]!='\0';i++)
{

    trms_int++;
   // cout<<"npow"<<npow[i]<<endl;

}
if(ex==0&&cs2==2)
{
   for(int i=0;i<trm1;i++)//no.of terms of pow2
{
pow2[i]=npow[0]+pow2[i];
//cout<<" new power of qx="<<pow2[i]<<endl;
} 
}

if(ex==1&&cs2==1)
{
for(int i=0;i<trm1;i++)//no.of terms of pow2
{
pow2[i]=npow[1]+pow2[i];//************powers of q(x) and owers of x from integrating factors are being added

}
}


//---------------------------------------------------------------------------------------------
                                    //BYPARTS
//---------------------------------------------------------------------------------------------

 float k[100],y=1;
//------------------------for q(x)----------------------------------//

//------------------------for i(x)-----------------------------------//
float ixcn[100]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
// ------------------------byparts ex--------------------------------//
float ex1[100][100]={'\0'};
float x2[100][100];
float powx[100][100],cons[100][100]{'\0'};

//***********************************************************************************//
//------------------------------CASES-----------------------------------------------//

for(int tt=0;tt<trm1;tt++)
{
k[tt]=pow2[tt]+2;
//case 1 x^0//
if(pow2[tt]==0&&ex==1)
{
        cout<<"case 1"<<endl;
ex1[tt][0]=npow[0];
ex1[tt][0]=coef2[tt]/ex1[tt][0];
cout<<ex1[tt][0]<<"e^"<<npow[0]<<"x"<<endl;
}

//---------------------------------------------------------------------------------------//
// case 2 exponential+polynomial///
else if(ex==2&&cs2==0)
{
    cout<<"case 2"<<endl;

ex1[tt][0]=npow[0];
y=npow[0];
p=ixcn[0];
//---------+++====----------------for exponential-----------------------------//
for(int i=1;i<k[tt]-1;i++)
{
    y=npow[0]*y;
   ex1[tt][i]=y;

}//y'+(4x^+0+3x^+0)=(2x^+1)
for(int j=0;j<k[tt]-1;j++)
   {
   ex1[tt][j]=p/ex1[tt][j];
   if(j%2==1)
   {
    ex1[tt][j]=ex1[tt][j]*-1;
   } 
   }
//--------------------------for x------------------------------------------//
int pl=0;
float pox[100][100];
pox[tt][0]=1;
pox[tt][1]=pow2[tt];

for(int u=2;u<k[tt];u++)
{
pox[tt][u]=pox[tt][u-1]-1;
if(pox[u]==0)
{
    break;
}
}
cout<<endl;
float rs=coef2[tt];
for(int y=0;y<k[tt];y++)
{
    rs=pox[tt][y]*rs;
    x2[tt][y]=rs;
    
}
for(int h=0;h<k[tt]-1;h++)
{
cons[tt][h]=x2[tt][h]*ex1[tt][h];
//cout<<"constant of x "<<x2[tt][y]<<endl;
}
//--------------for power of x-----------------------------------//

powx[tt][0]=pow2[tt];
int i;
for( i=1;powx[tt][i]>=0;i++)
{
powx[tt][i]=powx[tt][i-1]-1;
//cout<<"Power of x "<<powx[tt][i]<<endl;
if(powx[tt][i]==0)
{
    break;
}
}
//PRINTING
if(tt==0)
{
    cout<<"1/e^("<<npow[0]<<") ";
}
    for(int j=0;j<k[tt]-1;j++)
    {
    cout<<"("<<cons[tt][j]<<")x^("<<powx[tt][j]<<")e^("<<npow[0]<<"x)"<<" + ";
    }
}
//-----------------------------------case 3 in presence of lnx in p(x)--------------------------------//

else if(ex==1&&cs2==1)
{//y'+(4x^+0+3x^-1)=(2x^+2)
    cout<<"case 3"<<endl;
   
float d[111],con[100],inte[100];
int m=0;
ex1[tt][0]=npow[0];
y=npow[0];
p=ixcn[0];
//---------+++====----------------for exponential-----------------------------//
for(int i=1;i<k[tt]-1;i++)
{
    y=npow[0]*y;
   ex1[tt][i]=y;   
}
for(int j=0;j<k[tt]-1;j++)
   {
  ex1[tt][j]=p/ex1[tt][j];
   if(j%2==1)
   {
    ex1[tt][j]=ex1[tt][j]*-1;
   } 
   }

//--------------------------for x------------------------------------------//
int pl=0;
float pox[100][100];
pox[tt][0]=1;
pox[tt][1]=pow2[0];
for(int u=2;u<k[tt];u++)
{
pl++;
pox[tt][u]=pox[tt][u-1]-1;
if(pox[u]==0)
{
    break;
}
}
float rs=coef2[tt];
for(int y=0;y<k[tt];y++)
{
    rs=pox[tt][y]*rs;
    x2[tt][y]=rs;
    
}
for(int h=0;h<k[tt]-1;h++)
{
cons[tt][h]=x2[tt][h]*ex1[tt][h];
}
//--------------for power of x-----------------------------------//

powx[tt][0]=pow2[tt];
int i;
for( i=1;powx[tt][i]>=0;i++)
{
powx[tt][i]=powx[tt][i-1]-1;
if(powx[tt][i]==0)
{
    break;
}
}
cout<<"tt="<<tt<<endl;
//PRINTING
if(tt==0)
{
    cout<<"1/e^("<<npow[0]<<") ";
}
    for(int j=0;j<k[tt]-1;j++)
    {
    cout<<"("<<cons[tt][j]<<")x^("<<powx[tt][j]<<")e^("<<npow[0]<<"x)"<<" + ";
    }


}
//-----------------------------------------------------------------------------------------------------//


//case 4 when no exponential term is present//
else if(ex==0&&cs2==2)
{
    cout<<"case 4"<<endl;
float d[111],con[100],inte[100];
int m=0;


for(int i=0;i<trm1;i++)
{
d[i]=pow2[i]+1;
inte[i]=coef2[i]/d[i];
}

if(tt==0)
{
    cout<<"(1/x^("<<npow[0]<<"))";
}
//y'+(1x^-1+1x^-1)=(2x^+3+1x^+2)
//printing
for(int j=0;j<trm1;j++)
{
cout<<inte[j]<<"x^("<<pow2[j]<<") + ";
}
break;

}

}
cout<<"c";
}