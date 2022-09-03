#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a[30], b[30], i, k, n;
	cout<<"razmer massiva k=";
	cin>>k;
	for (i = 0; i < k; i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
	cout<<"chislo sdviga n=";
	cin>>n;
	n = n % k;
	n = k - n;
	
	for (i = 0; i < k; i++)
	{
		b[i] = a[(int)fmod(i + n, k)];
	}
	for (i = 0; i < k; i++)
	{
		cout<<"b["<<i<<"]="<<b[i]<<endl;
	}
	return 0;
}