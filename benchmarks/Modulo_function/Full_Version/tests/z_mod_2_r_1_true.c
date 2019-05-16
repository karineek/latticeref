//z_mod_2_r  //a mod 2 \in {0,1}

int nondet();
int main()	
{
    int a,b,m;
    __CPROVER_assume(a >= 0);

    m = (a%2);	

     assert(m == 0 || m == 1);	
}
