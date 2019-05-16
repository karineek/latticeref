//z_mod_plus_full		// forall a b c:Z, (a + b * c) mod c = a mod c.

int nondet();

int main()	
{
    int a=nondet();
    int b=nondet();
    int c=nondet();

    int m = a%c;	
    //__CPROVER_assume(z_mod_plus_full(a,c) == m);  

    int m2 = (a + (b*c)) % c;
    assert(m == m2);	
}
