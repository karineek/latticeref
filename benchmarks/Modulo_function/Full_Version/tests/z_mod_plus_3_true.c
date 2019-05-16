//z_mod_plus		// forall a b c:Z, c > 0 -> (a + b * c) mod c = a mod c.

int nondet();
int main()	
{
    int a=nondet();
    int b=5;
    int c=2;

    int m = (a%c);	

    assert(m == (a + b*c)%c);	
}
