// Realizati interclasarea a 3 vectori predefiniti

#include    <iostream>
using namespace std;
int main()
{
	int A[100] = { 3,5,6,7 }, B[100] = { 1,4,8 }, C[200];
	int n=4, m=3, k = 0;

	//comparam elementele

	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (A[i] < B[j])
		{
			C[k] = A[i];
			k++;
			i++;
		}
		if (A[i] > B[j])
		{
			C[k] = B[j];
			k++;
			j++;
		}
	}
	//verificam daca a mai ramas ceva in vectori si adaugam in C
	if (i <= n)
	{
		for (int l = i; l < n; l++)
		{
			C[k] = A[l];
			k++;
		}
	}
	if (j <= m)
	{
		for (int l = j; l < m; l++)
		{
			C[k] = B[l];
			k++;
		}
	}

	cout << "Elementele lui C sunt:";
	for (int i = 0; i < k; i++)
		cout << C[i] << " ";
	return 0;
}