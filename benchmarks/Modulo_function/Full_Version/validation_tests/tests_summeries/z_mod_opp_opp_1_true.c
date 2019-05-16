//z_mod_opp_opp           //forall a b:Z, (-a) mod (-b) = - (a mod b)
// Run: ./hifrog --logic qflra --load-summaries ../model/__summaries_z_mod_lra --load-sum-model ../model/z_mod_lattice_lra_z_mod_opp_full z_mod_opp_opp_1_true.c 

int nondet();

int main()	
{
    int m = (-8) % (-3);
    int m_p = 8%3;	

    assert(m + m_p == 0);	
}
