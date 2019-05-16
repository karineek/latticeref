//z_mod_eq_full  		// a b : b<>0 -> a mod b = a - (a/b)*b

int nondet();

int main()	
{
    int a = nondet();
    int m = (a%2);	

    assert(m == (a - (a/2)*2)%2);	 
}
