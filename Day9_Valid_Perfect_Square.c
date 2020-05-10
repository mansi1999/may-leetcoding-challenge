bool isPerfectSquare(int num){
    int i=0;
    if(num==1)
    {
      return true;  
    }
    int k = num%10;
    if(k==1 || k==4 || k==9 || k==6 || k==5 || k==0)
    {
        for(i=2;i<=num/2;i++)
        {
            if(i*i==num)
            {
                return true;
            }
        }
    }
    return false;
}


/*  The squares have a pattern. There last digits repeat in the order 1,4,9,6,5,0 */
