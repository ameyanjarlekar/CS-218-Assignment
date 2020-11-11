#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m,E,hcost,fcost,S,C,OTC,OTprice,W; //declare variables
    cin>>m;                                 //take input
    int D[m];
    int maxval=0;
    for(int i=0;i<m;i++)
    {   
        cin>>D[i];                      // take input 
        maxval = max(maxval,D[i]);      
    }
    cin>>E>>hcost>>fcost;
    cin>>S>>C;
    maxval = max(maxval,E);
    int lim = maxval/C+2;               // upper limit on number of workers daily
    cin>>OTC>>OTprice;
    cin>>W;
    int Cost[m+1][lim][lim*OTC][2];     // dim 1 cost upto day i, dim 2 no of workers used on day i, dim 3 no of overtime hours on day i, dim 4 first element is cost upto day i second is excess carpets produced on day i
    for(int i=0;i<lim;i++)
    {
        for(int j=0;j<lim*OTC;j++)
        {
            Cost[0][i][j][0]=0;        // initialize cost of day 0
            Cost[0][i][j][1]=0;         // initialize excess carpets for day 0
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
                    int prevover=0;             // for day 1 we had E workers initally and none did overtime
                       refer = Cost[day][work][over][0];
                        refer2 = Cost[day-1][prevwork][prevover][1]-D[day-1]+over+C*work;       // excess carpets produced
                        if(work>=prevwork && refer2>=0 && Cost[day-1][prevwork][prevover][0] != -1) // consider if excess hours >=0
                        {
                        if(Cost[day][work][over][0]==-1)
                        Cost[day][work][over][0] = Cost[day-1][prevwork][prevover][0]+S*work+(work-prevwork)*hcost+Cost[day-1][0][0][1]*W+over*OTprice; // cost = prev cost + S*workers+increase in workers * hire cost + storage cost for excess produced last time + overtime*OTcost
                        else
                        Cost[day][work][over][0] = min(Cost[day-1][prevwork][prevover][0]+S*work+(work-prevwork)*hcost+Cost[day-1][0][0][1]*W+over*OTprice,Cost[day][work][over][0]);
                        }
                        else if (work<prevwork && refer2>=0 && Cost[day-1][prevwork][prevover][0] != -1)  // consider if excess hours >=0
                        {
                        if(Cost[day][work][over][0]==-1)
                        Cost[day][work][over][0] = Cost[day-1][prevwork][prevover][0]+S*work+(-work+prevwork)*fcost+Cost[day-1][0][0][1]*W+over*OTprice; // cost = prev cost + S*workers+decrease in workers * fire cost + storage cost for excess produced last time + overtime*OTcost
                        else
                        Cost[day][work][over][0] = min(Cost[day-1][prevwork][prevover][0]+S*work+(-work+prevwork)*fcost+Cost[day-1][0][0][1]*W+over*OTprice,Cost[day][work][over][0]);
                        }                        
                        if (Cost[day][work][over][0]!=0)
                        Cost[day][work][over][1]=refer2;        // update excess carpets
                    
                    }
                else
                {                        Cost[day][work][over][1]=-1;
                for(int prevwork=0;prevwork<lim;prevwork++) // prev workers could range from 0 to lim for day>1
                {  
                    for(int prevover=0;prevover<=prevwork*OTC;prevover++)  // over time carpets could range from 0 to workers*OTC for day>1
                    {   refer = Cost[day][work][over][0];
                        refer2 = Cost[day-1][prevwork][prevover][1]-D[day-1]+over+C*work;   // calc excess hours
                        if(work>=prevwork && refer2>=0 && Cost[day-1][prevwork][prevover][0] != -1) // consider if excess hours >=0
                        {
                        if(Cost[day][work][over][0]==-1)
                        Cost[day][work][over][0] = Cost[day-1][prevwork][prevover][0]+S*work+(work-prevwork)*hcost+Cost[day-1][prevwork][prevover][1]*W+over*OTprice;      // cost = prev cost + S*workers+increase in workers * hire cost + storage cost for excess produced last time + overtime*OTcost
                        else
                        Cost[day][work][over][0] = min(Cost[day-1][prevwork][prevover][0]+S*work+(work-prevwork)*hcost+Cost[day-1][prevwork][prevover][1]*W+over*OTprice,Cost[day][work][over][0]);
                        }
                        else if (work<prevwork && refer2>=0 && Cost[day-1][prevwork][prevover][0] != -1) // consider if excess hours >=0
                        {
                        if(Cost[day][work][over][0]==-1)
                        Cost[day][work][over][0] = Cost[day-1][prevwork][prevover][0]+S*work+(-work+prevwork)*fcost+Cost[day-1][prevwork][prevover][1]*W+over*OTprice;  // cost = prev cost + S*workers+decrease in workers * fire cost + storage cost for excess produced last time + overtime*OTcost
                        else
                        Cost[day][work][over][0] = min(Cost[day-1][prevwork][prevover][0]+S*work+(-work+prevwork)*fcost+Cost[day-1][prevwork][prevover][1]*W+over*OTprice,Cost[day][work][over][0]);
                        }                        
                        if (refer>Cost[day][work][over][0] || (refer == -1 && Cost[day][work][over][0] != -1))
                        Cost[day][work][over][1]=refer2;  // update excess carpets
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
                mincost = min(mincost,Cost[m][i][j][0]+(i-E)*fcost);  // fire workers to make final workers = E
                else
                mincost = min(mincost,Cost[m][i][j][0]+(E-i)*hcost);     // hire workers to make final workers = E
            }
            else
            {   if(i>=E)
                mincost = Cost[m][i][j][0]+(i-E)*fcost;
                else
                mincost = Cost[m][i][j][0]+(E-i)*hcost;
            }
            }
        }
        }

        cout<<mincost<<endl;        // print optimal final answer
    
}



