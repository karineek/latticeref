//z_div_nz_opp_r		// forall a b:Z, a mod b <> 0 -> a/(-b) = -(a/b)-1. - only under mod!

int nondet();
int main()	
{
    int a=nondet();
    int b=nondet();

    int m = a%b;	
    __CPROVER_assume(b != 0);
    __CPROVER_assume(m != 0);

    int m1 = (a/(-b))%b; 
    int m2 = (-(a/b)-1)%b;
    assert(m1 == m2);	
}
