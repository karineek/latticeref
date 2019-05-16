//z_mod_1_r  //a mod 1 = 0

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_1_r(int a, int n) { return mod(a,n);}

int main()	
{
    int a,b,m;
    m = mod(a,1);	
    __CPROVER_assume(z_mod_1_r(a,1) == m);  

     assert(m != 0);	
}
