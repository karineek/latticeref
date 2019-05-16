int nondet();

void main()
{
    int y = nondet();

    unsigned int z = (y%y);
    __CPROVER_assume(y != 0); 

    assert(z == 0);
}
