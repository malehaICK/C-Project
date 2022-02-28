#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

unsigned long long int arr[5000][5000];

int main (){
  unsigned long long int i,j, n,degrees,sum1=0,sum2=0,indegree=0,outdegree=0;
  printf("Please enter the dimention of adjucency matrix :");
    scanf("%llu", &n);
    printf("\n");
 clock_t start,end;
 //float time1,time2;
 double time1,time2;
                    ///Directed graph
start= clock();

for(i=0; i<n; i++){
        for(j=0; j<n; j++)
    {
            arr[i][j]=rand()%2;
            arr[j][i]=rand()%2;


    }

}
                                    ///I N D E G R E E(Terminal->Initial)
 //start= clock();

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if((arr[i][j]==1 || arr[j][i]) && i==j){
            indegree+=(arr[j][i]-1)+2;
            sum1=sum1+(arr[j][i]-1)+2;
            }

            else{
            indegree+=arr[j][i];
            sum1=sum1+arr[j][i];
            }
            //printf("i=%llu",);

        }

            //printf("%llu->in-degree=%llu\n",i,indegree);
            indegree=0;
    }

                                /// O U T D E G R E E (Initial->Terminal)
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if((arr[i][j]==1 || arr[j][i]==1)&& i==j){
            outdegree+=(arr[i][j]-1)+2;
            sum2=sum2+(arr[i][j]-1)+2;
                }

            else{
            outdegree+=arr[i][j];
            sum2=sum2+arr[i][j];
            }

        }

            //printf("\n%llu->out-degree=%llu ",i,outdegree);
            outdegree=0;
    }

    end = clock();

                ///P R I N T
/*     printf("Adjacency matrix: \n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%llu ",arr[i][j]);
        }
        printf("\n");
    }

*/
    printf("\nTotal in-degree:%llu\n",sum1);
    printf("\nTotal Out-degree:%llu\n",sum2);

     if (sum1=sum2){
        printf("\n\nSum of in-degree = Sum of out-degree\n");
            }

   time1=((double)end-(double)start)/CLOCKS_PER_SEC;
    time2=(((double)end-(double)start)/CLOCKS_PER_SEC)*(pow(10,9));

    printf("\nComputational time: %lf seconds\n",time1);
    printf("\nComputational time: %lf nano seconds\n",time2);

    }



