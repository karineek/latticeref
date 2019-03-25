int nondet();
int main()
{
    int a = nondet();
    __CPROVER_assume(a != 0);
	
    int m = a%a;

    assert(m==0);
}
