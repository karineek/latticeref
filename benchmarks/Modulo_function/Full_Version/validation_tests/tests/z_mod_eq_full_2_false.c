// z_mod_eq     //Lemma Zmod_eq a b : b>0 -> a mod b = a - (a/b)*b

int nondet();

int main()	
{
    int a=nondet();
    int b=nondet();
    __CPROVER_assume(b != 0);

    int m = (a%b);	

    assert(m != (a - ((a/b)*b))%b );	
}
