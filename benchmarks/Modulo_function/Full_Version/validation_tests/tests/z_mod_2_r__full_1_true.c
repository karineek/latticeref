//z_mod_2_r_full  //a mod 2 \in {-1,0,1}

int nondet();
int main()	
{
    int a,b,m;
    m = (a%2);	

     assert(m == 0 || m == 1 || m == -1);	
}
