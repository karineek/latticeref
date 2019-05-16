//z_mod_plus_full		// forall a b c:Z, (a + b * c) mod c = a mod c.

int nondet();
int mod(int a, int n) { return a % n; }
//int z_mod_plus (int a, int n) { return mod(a,n);}

int main()	
{
    int a=nondet();
    int b=-5;
    int c=nondet();

    int m = mod(a,c);	
    //__CPROVER_assume(z_mod_plus_full(a,c) == m);  

    assert(m == mod(a + b*c,c));	
}
