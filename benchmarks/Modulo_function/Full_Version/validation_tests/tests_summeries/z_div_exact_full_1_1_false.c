//z_div_exact_full_1	// forall a b:Z, a = b*(a/b) -> a mod b = 0.

int nondet();

int main()	
{
    int a=nondet();
    int b=nondet();
    __CPROVER_assume(b != 0);

    int m = a%b;	

    assert(((b*(a/b)) != a) || (m > 0));	
}
