int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_le(int a, int n) { return mod(a,n);}

void main()
{
    unsigned int a , b;
    unsigned int m = mod(4,b);
    __CPROVER_assume(z_mod_le(4,b) == m);
    __CPROVER_assume(b > 0 && a >= 0);
    assert(m == 10);
}
