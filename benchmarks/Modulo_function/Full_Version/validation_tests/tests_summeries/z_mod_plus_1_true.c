//z_mod_plus		// forall a b c:Z, c > 0 -> (a + b * c) mod c = a mod c.

int nondet();
int mod(int a, int n) { return a % n; }
//int z_mod_plus (int a, int n) { return mod(a,n);}

int main()	
{
    int a=nondet();
    int b=nondet();
    int c=nondet();
    __CPROVER_assume(c >= 1);

    int m = a%c;	
    //__CPROVER_assume(z_mod_plus(a,c) == m);  

    int m2 = (a+b*c)%c;
    assert(m == m2);	
}
