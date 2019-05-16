//z_mod_remainder	        //b<>0 -> Remainder (a mod b) b

int nondet();

int main()	
{
    int a,b,m;
    __CPROVER_assume(b != 0);
    m = (a%b);	

     assert(m < b || b < 0);	
}
