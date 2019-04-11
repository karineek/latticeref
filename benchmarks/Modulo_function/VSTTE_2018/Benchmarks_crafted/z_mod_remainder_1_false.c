int main()	
{
    int a,b,m;
    __CPROVER_assume(b != 0);
    m = a%b;	

     assert(m > b && b > 0);	
}
