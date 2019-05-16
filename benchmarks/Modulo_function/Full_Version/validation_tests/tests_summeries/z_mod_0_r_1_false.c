//Lemma Zmod_0_r: forall a, a mod 0 = 0
int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_0_r(int a, int n) { return mod(a,n);}

int main()	
{
    int a,b,m;
    m = mod(a,0);	
    __CPROVER_assume(z_mod_0_r(a,0) == m);  

     assert( m > 0 );	
}
