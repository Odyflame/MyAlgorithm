#include<stdio.h>

long long int stairnumber[15][103];
#define mod 1000000000

int main(void) {
	int N;
	scanf("%d", &N);
	int i;
	for (i = 1; i <= 9; i++) stairnumber[1][i] = 1;
	for (i = 2; i <= N; i++) {
		stairnumber[i][0] = (stairnumber[i - 1][1]) % mod;
		stairnumber[i][1] = (stairnumber[i - 1][0] % mod + stairnumber[i - 1][2] % mod) % mod;
		stairnumber[i][2] = (stairnumber[i - 1][1] % mod + stairnumber[i - 1][3] % mod) % mod;
		stairnumber[i][3] = (stairnumber[i - 1][2] % mod + stairnumber[i - 1][4] % mod) % mod;
		stairnumber[i][4] = (stairnumber[i - 1][3] % mod + stairnumber[i - 1][5] % mod) % mod;
		stairnumber[i][5] = (stairnumber[i - 1][4] % mod + stairnumber[i - 1][6] % mod) % mod;
		stairnumber[i][6] = (stairnumber[i - 1][5] % mod + stairnumber[i - 1][7] % mod) % mod;
		stairnumber[i][7] = (stairnumber[i - 1][6] % mod + stairnumber[i - 1][8] % mod) % mod;
		stairnumber[i][8] = (stairnumber[i - 1][7] % mod + stairnumber[i - 1][9] % mod) % mod;
		stairnumber[i][9] = stairnumber[i - 1][8] % mod;

	}
	long long int res = 0;
	for (i = 0; i <= 9; i++) res = (res + stairnumber[N][i] % mod) % mod;
	//	for(i=0;i<=9;i++) printf("%d : %d\n",i,stairnumber[N][i]);
	printf("%lld", res%mod);

}