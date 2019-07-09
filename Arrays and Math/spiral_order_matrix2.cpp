/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order. Example: Given n = 3, You should return the following matrix:
[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> v(A,vector<int>(A,0));
    int l=0,r=A-1,t=0,b=A-1;
    int n=1,direction=1;
    while(l<=r && t<=b)
    {
        if(direction==1)
        {
            for(int i=l;i<=r;i++)
            {
                v[t][i]=n++;
            }
            direction=2;
            t++;
        }
        else if(direction==2)
        {
            for(int i=t;i<=b;i++)
                v[i][r]=n++;
            direction=3;
            r--;
        }
        else if(direction==3)
        {
            for(int i=r;i>=l;i--)
                v[b][i]=n++;
            direction=4;
            b--;
        }
        else if(direction==4)
        {
            for(int i=b;i>=t;i--)
                v[i][l]=n++;
            direction=1;
            l++;
        }
    }
    return v;
}
