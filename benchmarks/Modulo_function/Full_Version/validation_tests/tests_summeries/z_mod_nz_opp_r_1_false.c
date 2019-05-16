//z_mod_nz_opp_r	        //forall a b:Z, a mod b <> 0 -> a mod (-b) = (a mod b) - b
//Run: ./hifrog --logic qflra --load-summaries ../model/__summaries_z_mod_lra --load-sum-model ../model/z_mod_lattice_lra_z_mod_opp_r z_mod_nz_opp_r_1_false.c 

int nondet();

int main()	
{
    int a = nondet();
    int m_p = a%(-7);	
    int m = a%7;
    __CPROVER_assume(m != 0);

    assert(m_p == m + 6);
}
