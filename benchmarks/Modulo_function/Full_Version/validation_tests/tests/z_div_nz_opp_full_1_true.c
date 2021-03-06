//z_div_nz_opp_full	// forall a b:Z, a mod b <> 0 -> (-a)/b = -(a/b)-1. thus also equal under mod

int nondet();
int main()	
{
    int a=nondet();
    int b=nondet();

    int m = mod(a,b);
    __CPROVER_assume(b != 0);	
    __CPROVER_assume(m != 0);

    int m1 = ((-a)/b)%b;
    int m2 = (-(a/b)-1)%b;
    assert(m1 == m2);		
}
