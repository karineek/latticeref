
int nondet();

int main()	
{
    int a,b,m;
     __CPROVER_assume(a >= 0 && a < b);

    m = a%b;	

    assert(m == a);	
}
