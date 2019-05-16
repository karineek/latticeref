int nondet();

int main()
{
    int a = nondet();
    int m = (a%a);
    __CPROVER_assume(a != 0);

    assert(m==0);
}
