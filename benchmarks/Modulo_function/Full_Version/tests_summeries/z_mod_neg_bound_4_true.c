int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_neg_bound(int a, int n) { return mod(a,n);}
int main()
{
    int a,b,m;
    m = mod(a,b);
    __CPROVER_assume(b < 0);
    __CPROVER_assume(b > -100);
    __CPROVER_assume(z_mod_neg_bound(a,b) == m);    

     assert(m<=0 && m>b);
}
