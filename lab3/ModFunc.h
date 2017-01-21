#include <iostream>
#include <cmath>
class ZpVec
{
	private:
	int x,y,z;
	int p;
	ZpVec();
	ZpVec(int,int,int);

	public:
	void ZpVecSum(ZpVec);
	void ZpVec;
}

	int CheckInput(int a,int p)
	{
		if(p<0 || ((a>p) || (a<(-1)*p)))
		{
			std::cout<<"Bad input";
			return -1;
		}
		if(a<0)
		{
			a=p+a;
		}
		return a;
	}

    int ZpSum(int a,int b,int p)
	{
		a=CheckInput(a,p);
		b=CheckInput(b,p);
		if((a == -1) || (b == -1))
		{
			return -1;
		}
		return (a+b)%p;
	}
	void ZpMul(int a,int b,int p)
	{
		a=CheckInput(a,p);
		b=CheckInput(b,p);
		if((a == -1) || (b == -1))
		{
			return -1;
		}
		return (a*b)%p;
	}
    void InvMod(int a, int p);