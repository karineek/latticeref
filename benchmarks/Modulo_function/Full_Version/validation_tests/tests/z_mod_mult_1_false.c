//z_mod_mult		//forall a b, (a*b) mod b = 0

int nondet();

int main()	
{
    int b = nondet();
    __CPROVER_assume(b != 0);

    __CPROVER_assume(b < 99999999);
    __CPROVER_assume(b > -99999999);

    int m = (5*b)%b;	

     assert(m == 5);	
}
