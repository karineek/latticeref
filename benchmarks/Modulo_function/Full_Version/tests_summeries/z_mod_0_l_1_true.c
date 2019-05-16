//0 mod a = 0

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_0_l(int a, int n) { return mod(a,n);}

int main()	
{
    int a,b,m;
    m = mod(0,b);	
    __CPROVER_assume(z_mod_0_l(0,b) == m);  

     assert(m == 0);	
}
