class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    
int rows=matrix.size();
int columns=matrix[0].size();

    int columnZero=1;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(matrix[i][j]==0)
            {
                if(j==0)
                {
                    matrix[i][0]=0;
                    columnZero=0;
                }
                else
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
    }

    for(int i=rows-1; i>0; i--)
    {
        for(int j=columns-1; j>0; j--)
        {
            if(matrix[i][0]==0 || matrix[0][j]==0)
            {
                matrix[i][j]=0;
            }
        }
    }
    // 0th row
    if(matrix[0][0]==0)
    {
        for(int i=0; i<columns; i++)
        {
            matrix[0][i]=0;
        }
    }
    // 0th column
    if(columnZero==0)
    {
        for(int i=0; i<rows; i++)
        {
            matrix[i][0]=0;
        }
    }
}
    
};