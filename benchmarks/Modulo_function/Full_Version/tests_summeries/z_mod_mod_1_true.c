//z_mod_mod		//forall a n, (a mod n) mod n = a mod n
// Run: ./../../../../../../hifrog_lra_lattice/hifrog/trunk/cprover/src/funfrog/hifrog --logic qflra --load-summaries ../model/__summaries_z_mod_lra --load-sum-model ../model/z_mod_lattice_lra_z_mod_mod z_mod_mod_1_true.c

int nondet();
int main()	
{
    int a = nondet();
    int b = nondet();
    __CPROVER_assume(b != 0);

    __CPROVER_assume(b < 99999999);
    __CPROVER_assume(b > -99999999);

    int m = a%b;
    int m_p = m%b;

    // Test
    assert(m == m_p);	
}
