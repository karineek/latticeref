int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_same_full(int a, int n) { return mod(a,n);}
int main()
{
    int a,m;
    m = mod(a,a);
    __CPROVER_assume(a != 0);
    __CPROVER_assume(z_mod_same_full(a,a) == m);

    assert(m<0);
}
