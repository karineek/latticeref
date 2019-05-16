int nondet();

int main()	
{
    int a=nondet();
    int b=nondet();

    int m = (a%b);	

    int m2 = (-a)%b;	

    assert((m+m2)%b > 0);	
}
