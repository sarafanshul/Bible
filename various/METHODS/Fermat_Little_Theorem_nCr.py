'''
>>> Fermat’s little theorem and modular inverse
		Fermat’s little theorem states that if p is a prime number, 
		then for any integer a, the number ap – a is an 
		integer multiple of p. In the notation of 
		modular arithmetic, this is expressed as:
			ap = a (mod p)

>>> For example, if a = 2 and p = 7, 
		27 = 128, and 128 – 2 = 7 × 18 is 
		an integer multiple of 7.

>>> If a is not divisible by p, Fermat’s 
		little theorem is equivalent to the 
		statement a p – 1 – 1 is an integer multiple of p, i.e
			ap-1 = 1 (mod p)

>>> If we multiply both sides by a-1, we get.
		ap-2 = a-1 (mod p)

>>> So we can find modular inverse as p-2.

========================
Computation:

	We know the formula for  nCr 
	nCr = fact(n) / (fact(r) x fact(n-r)) 
	Here fact() means factorial.

		nCr % p = (fac[n]* modIverse(fac[r]) % p *
		            modIverse(fac[n-r]) % p) % p;

	Here modIverse() means modular inverse under
	modulo p.
	Following is the implementation of the above algorithm. 
	In the following implementation, an array fac[] 
	is used to store all the computed factorial values.
'''
# calculate nCr % p 
def ncr(n, r, p): 
	# initialize numerator 
	# and denominator 
	num = den = 1 
	for i in range(r): 
		num = (num * (n - i)) % p 
		den = (den * (i + 1)) % p 
	return (num * pow(den,  
			p - 2, p)) % p 
  
# p must be a prime 
# greater than n 
n, r, p = 10, 2, 13
print("Value of nCr % p is",  
			   ncr(n, r, p)) 