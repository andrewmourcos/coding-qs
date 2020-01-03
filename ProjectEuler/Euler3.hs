{-
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
-}
-- Attempt #3:

primes = 2 : filter ((==1) . length . primeFactors) [3,5..]

primeFactors n = factor n primes
  where
    factor n (p:ps)
        | p*p > n = [n]
        | n `mod` p == 0 = p : factor (n `div` p) (p:ps)
        | otherwise      = factor n ps

solution = last (primeFactors 600851475143)

-- Attempt #2:
{-
primeFactors :: Integer -> [Integer]

primeFactors 1 = []
primeFactors n
  | factors == []  = [n]
  | otherwise = factors ++ primeFactors (n `div` (head factors))
  where factors = [x | x <- [2..n-1], n `mod` x == 0]

solution = tail(primeFactors 600851475143)
-}

-- Attempt #1:
{-
divisors :: Integer -> [Integer]
divisors 1 = [1]
divisors y = 1: [x | x <- [2..(y `div` 2)], y `mod` x == 0] ++ [y]

isPrime :: Integer -> Bool
isPrime n
  | divisorNum > 2 = False
  | otherwise = True
  where divisorNum = length(divisors n)

primeDivisors :: Integer -> [Integer]
primeDivisors pd = [x | x <- [1..(pd `div` 2)], isPrime x == True && pd `mod` x == 0]
-}
