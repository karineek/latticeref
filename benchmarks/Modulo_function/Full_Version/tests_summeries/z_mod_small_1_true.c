//z_mod_small		//forall a n, 0 <= a < n ---> a mod n = a

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_small(int a, int n) { return mod(a,n);}

int main()	
{
    int a,b,m;
     __CPROVER_assume(a >= 0 && a < b);

    m = mod(a,b);	
    __CPROVER_assume(z_mod_small(a,b) == m);  

    assert(m == a);	
}
