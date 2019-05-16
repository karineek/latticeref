//z_mod_le		//forall a b, 0 < b -> 0 <= a ---> a mod b <= a
// Run: ./hifrog --logic qflra --load-summaries ../model/__summaries_z_mod_lra --load-sum-model ../model/z_mod_lattice_lra_z_mod_le z_mod_le_1_true.c

int nondet();
int mod(int a, int n) { return a % n; }

int main()	
{
    unsigned int a = nondet();
    unsigned int b = nondet();

    __CPROVER_assume(0 == a || 0 < a);
    __CPROVER_assume(0 < b);

    int m = mod(a,b);	

    assert(m <= a);	
}
