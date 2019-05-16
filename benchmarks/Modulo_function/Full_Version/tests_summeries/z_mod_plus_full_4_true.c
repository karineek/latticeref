//z_mod_plus_full		// forall a b c:Z, (a + b * c) mod c = a mod c.

int nondet();
int mod(int a, int n) { return a % n; }
//int z_mod_plus (int a, int n) { return mod(a,n);}

int main()	
{
    int a=nondet();

    int m = mod(a,5);	
    //__CPROVER_assume(z_mod_plus_full(a,5) == m);  

    assert(m == mod(a + 10, 5));	
}
