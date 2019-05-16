//1 mod a = 1

int nondet();
int main()	
{
    int b = nondet();
    int m = (1%b);

     assert(m == 1);	
}
