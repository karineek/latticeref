//z_mod_zero_opp_full	//forall a b:Z, a mod b = 0 -> (-a) mod b = 0

// Run: ./hifrog --logic qflra --load-summaries ../model/__summaries_z_mod_lra --load-sum-model ../model/z_mod_lattice_lra_z_mod_opp_full z_mod_opp_full_2_false.c

int nondet();

int main()	
{
    int a = nondet();
    int b = nondet();
    __CPROVER_assume(b != 0);

    int m = a%b;	
    int m_p = (-a)%b;

    assert(m_p != 0);	
}
