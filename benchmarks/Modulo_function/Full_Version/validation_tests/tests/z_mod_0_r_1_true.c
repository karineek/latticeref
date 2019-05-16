//Lemma Zmod_0_r: forall a, a mod 0 = 0
int nondet();
int main()	
{
    int a,b,m;
    m = a%0;	

    assert(m == 0);	
}
