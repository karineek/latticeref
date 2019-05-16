//z_mod_eq     //Lemma Zmod_eq a b : b>0 -> a mod b = a - (a/b)*b

int nondet();

int main()	
{
    int a,b,m;
    b=5;
    m = a%b;	

    int m2 = ((a - (a/b)*b) % b);
     assert(m != m2); // In LRA, m == 0 always!	
}
