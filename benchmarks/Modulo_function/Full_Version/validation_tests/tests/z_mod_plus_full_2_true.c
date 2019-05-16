//z_mod_plus_full		// forall a b c:Z, (a + b * c) mod c = a mod c.

int nondet();

int main()	
{
    int a=nondet();
    int b=-5;
    int c=nondet();

    int m = (a%c);	

    assert(m == (a + b*c)%c);	
}
