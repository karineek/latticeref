//z_wiki_opp_plus		// WIKI: [(-a mod n) + (a mod n)] mod n = 0

// ./hifrog z_wiki_opp_plus_1_true.c --logic qflia --save-summaries mainReg_output/z_wiki_opp_plus_1_true/__summaries_output_qflia --claim 1 --solver z3 --no-itp --load-summaries ../model/main_model/__summaries_z_mod_lia --load-sum-model ../model/main_model/z_mod_lattice_lia_flat_31

int nondet();
int mod(int a, int n) { return a % n; }
//int z_wiki_opp_plus (int a, int n) { return mod(a,n);}

int main()	
{
    int a=nondet();
    int b=nondet();

    int m = mod(a,b);	
    //__CPROVER_assume(z_wiki_opp_plus(a,b) == m);

    int m2 = mod(-a,b);	
    //__CPROVER_assume(z_wiki_opp_plus(-a,b) == m2);  

    assert(mod(m+m2,b) == 0);	
}
