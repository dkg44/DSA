
// TC = O(n)
// SC = O(n)

int permutationCoeff(int n, int k)
{
    int fact[n + 1];
 
    // Base case
    fact[0] = 1;
 
    // Calculate value
    // factorials up to n
    for(int i = 1; i <= n; i++)
    fact[i] = i * fact[i - 1];
 
    // P(n,k) = n! / (n - k)!
    return fact[n] / fact[n - k];
}
 
// TC = O(n)
// SC = O(1)

int PermutationCoeff(int n, int k)
{
    int P = 1;
 
    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P *= (n-i) ;
 
    return P;
}