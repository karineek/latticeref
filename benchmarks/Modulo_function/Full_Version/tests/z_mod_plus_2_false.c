//z_mod_plus		// forall a b c:Z, c > 0 -> (a + b * c) mod c = a mod c.

int nondet();

int main()	
{
    int a=nondet();

    int m = (a%5);	

    assert(m != (a + 10)% 5);	
}
