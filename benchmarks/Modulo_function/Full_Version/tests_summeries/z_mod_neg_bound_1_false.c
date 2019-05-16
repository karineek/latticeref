int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_neg_bound(int a, int n) { return mod(a,n);}
int main()
{
    int a,m;
    m = mod(a,-10);
    __CPROVER_assume(z_mod_neg_bound(a,-10) == m);  

     assert(m>0);
}
