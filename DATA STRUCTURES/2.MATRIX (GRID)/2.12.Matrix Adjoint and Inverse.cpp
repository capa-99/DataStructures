//Given a square matrix, find the adjoint and inverse of the matrix.
//Adjoint (or Adjugate) of a matrix is the matrix obtained by taking the transpose of the cofactor matrix of a given square matrix. The Adjoint of any square matrix ‘A’ is represented as Adj(A). 
//Important properties: 
//Product of a square matrix A with its adjoint yields a diagonal matrix, where each diagonal entry is equal to determinant of A. 
//A*adj(A) = det(A)*I 
//I  => Identity matrix of same order as of A.
//det(A) => Determinant value of A 
//A non-zero square matrix ‘A’ of order n is said to be invertible if there exists a unique square matrix ‘B’ of order n such that,
//A*B = B*A = I
//The matrix 'B' is said to be inverse of 'A'.
//B = A⁻¹
//adj(AB) = (adj B)(adj A)
//adj( k A) = kⁿ⁻¹ adj(A)
//A⁻¹ = (adj A) / |A|
//(A⁻¹)⁻¹ = A
//(AB)⁻¹ = B⁻¹A⁻¹
//How to find Adjoint? 
//Follow the definition given above. 
//Let A[N][N] be input matrix.
//1) Create a matrix adj[N][N] store the adjoint matrix.
//2) For every entry A[i][j] in input matrix where 0 <= i < N and 0 <= j < N.
//a) Find cofactor of A[i][j]
//b) Find sign of entry.  Sign is + if (i+j) is even else sign is odd.
//c) Place the cofactor at adj[j][i]
//How to find Inverse? 
//Inverse of a matrix exists only if the matrix is non-singular i.e., determinant should not be 0. 
//Using determinant and adjoint, we can easily find the inverse of a square matrix using the below formula,
//If det(A) != 0
//A⁻¹ = adj(A)/det(A)
//Else
//"Inverse doesn't exist"
void cofactor(int** A, int** cof, int n, int p, int q)
{
    int i = 0, j = 0;
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            if(p != row && q != col)
            {
                cof[i][j] = A[row][col];
                j++;
                if(j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
int determinant(int** A, int n)
{
    if(n == 1)
    {
        return A[0][0]
    }
    if(n == 2)
    {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
    int res = 0;
    int sign = 1;
    int** tmp = new int*[n-1];
    for(int i = 0; i < n - 1; i++)
    {
        tmp[i] = new int[n-1];
    }
    for (int col = 0; col < n; col++) 
    {
        for (int i = 1; i < n; i++) 
        {
            int subcol = 0;
            for (int j = 0; j < n; j++) 
            {
                if (j == col) 
                {
                    continue; 
                }
                tmp[i - 1][subcol] = A[i][j]; 
                subcol++;
            }
        }
        sign = sign * -1; 
        res = res + sign * A[0][col] * determinant(tmp, n - 1);
    }
    return res; 
}
void adjoint(int** A, int** adj)
{
    if(n == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    int** cof = new int*[n];
    for(int i = 0; i < n; i++)
    {
        cof[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cofactor(A, cof, n, i, j);
            if((i + j) % 2 == 0)
            {
                sign = 1;
            }
            else
            {
                sign = -1;
            }
            adj[j][i] = sign * determinant(cof, n - 1);
        }
    }
}
bool inverse(int** A, int** inv)
{
    int det = determinant(A, n);
    if(det == 0)
    {
        return false;
    }
    int** adj = new int*[n];
    for(int i = 0; i < n; i++)
    {
        adj[i] = new int[n];
    }
    adjoint(A,adj);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            inv[i][j] = adj[i][j] / (float)det;
        }
    }
    return true;
}