//z_div_exact_full_1	// forall a b:Z, a = b*(a/b) -> a mod b = 0.

int nondet();

int main()	
{
    int a=nondet();
    int m = a%11;	

    assert(((11*(a/11)) != a) || (m == 0));	
}
