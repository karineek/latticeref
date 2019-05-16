//z_mod_plus_full		// forall a b c:Z, (a + b * c) mod c = a mod c.

int nondet();

int main()	
{
    int a=nondet();
    int b=-5;
    int c=-2;

    int m = (a%c);	
    int m_p = (a + b*c)%c;	
    assert(m > m_p);	
}
