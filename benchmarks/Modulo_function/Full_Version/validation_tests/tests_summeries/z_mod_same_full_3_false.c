int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_same_full(int a, int n) { return mod(a,n);}
void main()
{
    int y = nondet();

    unsigned int z = mod(y,y);
    __CPROVER_assume(y != 0); 
    __CPROVER_assume(z_mod_same_full(y,y) == z);
    assert(z > 0);
}
