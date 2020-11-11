#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m,E,hcost,fcost,S,C,OTC,OTprice,W;
    cin>>m;
    int D[m];
    int maxval=0;
    for(int i=0;i<m;i++)
    {   
        cin>>D[i];
        maxval = max(maxval,D[i]);
    }
    cin>>E>>hcost>>fcost;
    cin>>S>>C;
    maxval = max(maxval,E);
    int lim = maxval/C+2;
    cin>>OTC>>OTprice;
    cin>>W;
    int Cost[m+1][lim][lim*OTC][2];
    for(int i=0;i<lim;i++)
    {
        for(int j=0;j<lim*OTC;j++)
        {
            Cost[0][i][j][0]=0;
            Cost[0][i][j][1]=0;
        }
    }
    
    int refer,refer2;
    for(int day=1;day<=m;day++)
    {
        for(int work=0;work<lim;work++)
        {
            for(int over=0;over<=work*OTC;over++)
            {   Cost[day][work][over][0]=-1;
                 if(day == 1)
                    {int prevwork = E;
                    int prevover=0;
                       refer = Cost[day][work][over][0];
                        refer2 = Cost[day-1][prevwork][prevover][1]-D[day-1]+over+C*work;
                        if(work>=prevwork && refer2>=0 && Cost[day-1][prevwork][prevover][0] != -1)
                        {
                        if(Cost[day][work][over][0]==-1)
                        Cost[day][work][over][0] = Cost[day-1][prevwork][prevover][0]+S*work+(work-prevwork)*hcost+Cost[day-1][0][0][1]*W+over*OTprice;
                        else
                        Cost[day][work][over][0] = min(Cost[day-1][prevwork][prevover][0]+S*work+(work-prevwork)*hcost+Cost[day-1][0][0][1]*W+over*OTprice,Cost[day][work][over][0]);
                        }
                        else if (work<prevwork && refer2>=0 && Cost[day-1][prevwork][prevover][0] != -1)
                        {
                        if(Cost[day][work][over][0]==-1)
                        Cost[day][work][over][0] = Cost[day-1][prevwork][prevover][0]+S*work+(-work+prevwork)*fcost+Cost[day-1][0][0][1]*W+over*OTprice;
                        else
                        Cost[day][work][over][0] = min(Cost[day-1][prevwork][prevover][0]+S*work+(-work+prevwork)*fcost+Cost[day-1][0][0][1]*W+over*OTprice,Cost[day][work][over][0]);
                        }                        
                        if (Cost[day][work][over][0]!=0)
                        Cost[day][work][over][1]=refer2;
                    
                    }
                else
                {                        Cost[day][work][over][1]=-1;
                for(int prevwork=0;prevwork<lim;prevwork++)
                {  
                    for(int prevover=0;prevover<=prevwork*OTC;prevover++)
                    {   refer = Cost[day][work][over][0];
                        refer2 = Cost[day-1][prevwork][prevover][1]-D[day-1]+over+C*work;
                        if(work>=prevwork && refer2>=0 && Cost[day-1][prevwork][prevover][0] != -1)
                        {
                        if(Cost[day][work][over][0]==-1)
                        Cost[day][work][over][0] = Cost[day-1][prevwork][prevover][0]+S*work+(work-prevwork)*hcost+Cost[day-1][prevwork][prevover][1]*W+over*OTprice;
                        else
                        Cost[day][work][over][0] = min(Cost[day-1][prevwork][prevover][0]+S*work+(work-prevwork)*hcost+Cost[day-1][prevwork][prevover][1]*W+over*OTprice,Cost[day][work][over][0]);
                        }
                        else if (work<prevwork && refer2>=0 && Cost[day-1][prevwork][prevover][0] != -1)
                        {
                        if(Cost[day][work][over][0]==-1)
                        Cost[day][work][over][0] = Cost[day-1][prevwork][prevover][0]+S*work+(-work+prevwork)*fcost+Cost[day-1][prevwork][prevover][1]*W+over*OTprice;
                        else
                        Cost[day][work][over][0] = min(Cost[day-1][prevwork][prevover][0]+S*work+(-work+prevwork)*fcost+Cost[day-1][prevwork][prevover][1]*W+over*OTprice,Cost[day][work][over][0]);
                        }                        
                        if (refer>Cost[day][work][over][0] || (refer == -1 && Cost[day][work][over][0] != -1))
                        Cost[day][work][over][1]=refer2;
                    }
                }
                }
            }
        }
    }
    int mincost = -1;
        for(int i=0;i<lim;i++)
        {
        for(int j=0;j<=i;j++)
        {  
            if(Cost[m][i][j][0]!=-1)
            {if (mincost != -1)
            {   if(i>=E)
                mincost = min(mincost,Cost[m][i][j][0]+(i-E)*fcost);
                else
                mincost = min(mincost,Cost[m][i][j][0]+(E-i)*hcost);
            }
            else
            {   if(i>=E)
                mincost = Cost[m][i][j][0]+(i-E)*fcost;
                else
                mincost = Cost[m][i][j][0]+(E-i)*hcost;
            }
            }
           // cout<<Cost[1][i][j][0]<<" ";
        }
        //cout<<endl;
        }
 /*       for(int i=0;i<lim;i++)
        {
        for(int j=0;j<=i;j++)
        {  
            cout<<Cost[1][i][j][1]<<" ";
        }
        cout<<endl;
        }
        for(int i=0;i<lim;i++)
        {
        for(int j=0;j<=i;j++)
        {  
            cout<<Cost[2][i][j][0]<<" ";
        }
        cout<<endl;
        }
        for(int i=0;i<lim;i++)
        {
        for(int j=0;j<=i;j++)
        {  
            cout<<Cost[2][i][j][1]<<" ";
        }
        cout<<endl;
        }
        */
        cout<<mincost<<endl;
    
}



