/*Find the Town Judge

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1

Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3


Note:

    1 <= N <= 1000
    trust.length <= 10000
    trust[i] are all different
    trust[i][0] != trust[i][1]
    1 <= trust[i][0], trust[i][1] <= N

*/

int findJudge(int N, int** trust, int trustSize, int* trustColSize){

    int i,j,a,b,row = -1;
    int mat[N][N];
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            mat[i][j]=0;
        }
    }
  //  memset( boardAux, 0, length*length*sizeof(int) );
    //printf("1\n");
    for(i = 0; i < trustSize; i++)
    {
        a = trust[i][0];
        b = trust[i][1];
        mat[a-1][b-1] = 1;
    }
    //printf("inside fun\n");
    for(i=0;i<N;i++)
    {
    	for(j=0;j<N;j++)
    	{
    		if(mat[i][j]==1)
    		{
    			break;
			}
		}
		if(j==N)
		{
			row = i;
            break;
          //  flag = 1;
		}
	}
    if(row == -1)
	{
		//printf("\n -1 hi return kre\n");
        return -1;
	}
	else 
	{
		for(i=0;i<N;i++)
	    {
	    	//printf("\n%d\n", mat[i][row]);
	    	if(mat[i][row]==0 && i!=row)
	    	{
	    		//printf("nahi hai\n");
	    		//break;
                return -1;
			}
		}
	}
    return row+1;
    
}
