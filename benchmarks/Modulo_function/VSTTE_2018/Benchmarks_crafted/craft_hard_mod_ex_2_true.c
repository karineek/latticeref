int main()
{
    int a;
    int n;
    __CPROVER_assume(n != 0);
    int m = a - ((a/n)*n); //c99 definition of mod
    int m2 = a%n;

    assert(m == m2);
}
