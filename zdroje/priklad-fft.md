## algoritmus: The radix-2 DIT case

$X_k = \sum_{n=0}^{N-1}x_n e^{-i 2\pi k n/N}$
* 

## Příklad 

Vstup: n=8

řekněme, že moje data jsou z $sin(2\pi f t + \phi)$
* $f = 2$

$sin(4\pi t)$
samply:
* t=0 -> 0
* t=1/8 -> $sin(\pi/2) = 1$
* t=2/8 -> $sin(\pi) = 0$
* t=3/8 -> $sin(3\pi/2) = -1$
* 0
* 1
* 0
* -1

Task description:
* sampling frequency 8, N= 8
* 0,1,0,-1,0,1,0,-1
* DFT formula = $X_k = \sum_{n=0}^{N-1}x_n e^{-i 2\pi k n/N}$

Algorithm steps(radix-2 cool turkey algorithm):
1. split data: 
