int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_same_full(int a, int n) { return mod(a,n);}
int main()
{
    int a,m;
    int b = a;
    m = mod(a,b);
    __CPROVER_assume(a != 0);
    __CPROVER_assume(z_mod_same_full(a,b) == m);

    assert(m==0);
}
