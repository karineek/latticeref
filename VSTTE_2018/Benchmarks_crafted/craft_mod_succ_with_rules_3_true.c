// Rules for the lattice
// 3.  a = 0 => m==0
int main()
{
    int b;		

    __CPROVER_assume(b != 0);
    int m = 0%b;

    assert(m == 0);
}

