//z_mod_plus		// forall a b c:Z, c > 0 -> (a + b * c) mod c = a mod c.

int nondet();
int mod(int a, int n) { return a % n; }
//int z_mod_plus (int a, int n) { return mod(a,n);}

int main()	
{
    int a=nondet();

    int m = mod(a,5);	
    //__CPROVER_assume(z_mod_plus(a,5) == m);  

    assert(m != mod(a + 10, 5));	
}
