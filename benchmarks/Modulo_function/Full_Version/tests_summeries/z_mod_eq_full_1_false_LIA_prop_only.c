//z_mod_eq_full  		// a b : b<>0 -> a mod b = a - (a/b)*b

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_eq_full(int a, int n) { return mod(a,n);}

int main()	
{
    int a,m;

    m = mod(a,2);	
    __CPROVER_assume(z_mod_eq_full(a,2) == m);  

     assert(m == mod(a - (a/2)*3,2));	 // In LRA, m == 0 always!
}
