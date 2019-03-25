int main()
{
    int a;
    int n;
    __CPROVER_assume(n != 0);
    int m = a - ((a/n)*n); //c99 definition of mod
    int temp_m = mod(a,n); // Cannot parse two calls of mod in the same line
    int m2 = mod(temp_m,n); // (a%n)%n;

    assert(m == m2);
}
