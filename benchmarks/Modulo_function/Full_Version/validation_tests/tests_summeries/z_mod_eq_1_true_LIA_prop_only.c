// z_mod_eq     //Lemma Zmod_eq a b : b>0 -> a mod b = a - (a/b)*b

int nondet();

int main()	
{
    int a = nondet();
    int m = a%5;	

    int m2 = ((a - ((a/5)*5))%5);
    assert(m == m2);  // In LRA, m == 0 always!

    // in lra (a/5)*5 is a, as the division is precise and this is not equal to div operator!
}
