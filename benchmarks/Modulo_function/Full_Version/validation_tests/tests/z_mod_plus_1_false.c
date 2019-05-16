//z_mod_plus		// forall a b c:Z, c > 0 -> (a + b * c) mod c = a mod c.

int nondet();
int main()	
{
    int a=nondet();
    int b=nondet();
    int c=nondet();
    __CPROVER_assume(c >= 1);

    int m = (a%c);	

    assert(m != (a + b*c)%c);	
}
