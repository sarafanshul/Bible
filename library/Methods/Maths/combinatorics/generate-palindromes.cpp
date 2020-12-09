std::vector<ll> p_n;

ll createPalindrome(ll input, ll b, bool isOdd) { 
	ll n = input; 
	ll palin = input; 
	// checks if number of digits is odd or even if odd then neglect the last digit of input in finding reverse as in case of odd number of digits middle element occur once 
	if (isOdd)  n /= b; 
	// Creates palindrome by just appending reverse of number to itself 
	while (n > 0) { 
		palin = palin * b + (n % b); 
		n /= b; 
	} 
	return palin; 
} 
  
// Function to prll decimal palindromic number 
void generatePalindromes(ll n) { 
	ll number; 
	// Run two times for odd and even length palindromes 
	for (ll j = 0; j < 2; j++) { 
		// Creates palindrome numbers with first half as i.Value of j decided whether we need an odd length of even length palindrome. 
		ll i = 1; 
		while ((number = createPalindrome(i, 10, j % 2)) < n) { 
			p_n.PB(number)
			i++; 
		} 
	} 
} 