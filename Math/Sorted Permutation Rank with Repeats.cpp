/* editorial */

long long int pow_mod(long long int a, long long int b) {
	long long MOD = 1000003;
	if (a == 1)
		return 1;
	long long int x = 1, y = a;
	while (b > 0) {
		if (b % 2) {
			x = (x * y) % MOD;
		}
		y = (y * y) % MOD;
		b = b >> 1;
	}
	return x;
}

int Solution::findRank(string A) {
	long long ans = 0;
	long long mod = 1000003;
	long long arr[300];
	long long n = A.length();
	long long fact[n];
	fact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
	}
	for (long long i = 0; i < 300; i++)
		arr[i] = 0;

	for (long long i = 0; i < n; i++) {

		arr[A[i]]++;
	}
	// for(long long i=0;i<26;i++)
	//   cout<<arr[i]<<" ";

	for (long long i = 0; i < n; i++) {

		long long cnt = 0;
		long long di = 1;

		for (long long j = (A[i] - 1); j >= 0; j--) {
			cnt += arr[j];
		}

		// cout<<cnt<<" ";

		for (int j = 0; j < 300; j++) {

			di = (di % mod * fact[arr[j]] % mod) % mod;
		}
		long long a = pow_mod(di, (mod - 2)) % mod;

		// cout<<di<<" ";

		ans = (ans + ((cnt * fact[n - i - 1]) % mod * a) % mod) % mod;

		//  cout<<ans<<" ";
		arr[A[i]]--;
	}
	++ans;
	return ans % mod;
}