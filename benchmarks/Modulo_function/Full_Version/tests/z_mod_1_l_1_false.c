//1 mod a = 1

int nondet();
int main()	
{
    int b = nondet();
    int m = 1%b;	
    __CPROVER_assume(b > 1);

    assert(m > 1);	
}
