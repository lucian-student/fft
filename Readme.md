Cpu verze fft

## Fourier series

## Fourier analysis

Prý aproximace obecných funkcí -> sumou trigonometrických funkcí funkcí 
* trignometrické/gonimetrické funkce: sinus, cosinus

## Discrete-time Fourier transform

https://en.wikipedia.org/wiki/Discrete-time_Fourier_transform

## Discrete Fourier transform

Mění konečnou sekvenci, stejně vzdálených prvků -> na stejně dlouhou sekvenci stejně vdzálených prvůků "diskrétním furierovy transformace"

$F(f) = \int_{t_1}^{t_2}g(t)e^{-i2\pi f t}$

$X_k = \sum_{n=0}^{N-1} x_n e^{-i2\pi k n/N}$

* $x_n$ jsou udájně komplexní čísla(ale to nedavá mi moc smysl, jelikož blue1brown říkal, že to určuje vzdálenost od středu, když namapujeme squiggle na kruh)
    * udajně $x_n$ je často real, asi Blue1Brown hovořil jenom o tom případu 


Jaký vliv má frequency sampling rate na výsledek:
$f_k = \dfrac{k}{N} f_s$
* $f_s$ -> sampling rate kolik samplů mam za sekundu
* vysvětelní vzorce:
    * kdybych měl $N=1000$ a $f_s=500$ $k=10$ -> $f_k = 5$
    * $k$ prý reprezentuje počet cyklů, který vykoná $k$cyklů za celý časový interval, proto je potřebné $k$ přenásobit abychom získal frekvenci za jednotku času 
    * v podstatě je to jakoby celý usek byla jednotka:
        * pokud máme 2 sekundy dat sinusoidy s frekvencí 3
        * chceme aby se vykonalo 6 cyklů, ale frekvence, kterou najdeme je 1/2, protože máme 2 sekundy

### Nějaká věta, co na mě vyplivnula AI

Any periodic discrete signal of length 𝑁 can be represented as a sum of 𝑁 complex exponentials (sinusoids) with different frequencies.

## Cool toorkey algorithm

* máme počet dat na vstupu velikosti $N$, pokud asi není $N$ prvočíslo tak se vypočítá $N = N_1 N_2$,  $N_1$ menších DFT o velikosti $N_2$
    * to se asi rekurzivně aplikuje

jelikož mcc vyžaduje tvar $2^k$ -> tak asi stačí cool toorkey algorithm

## Fourier tranform

https://en.wikipedia.org/wiki/Fast_Fourier_transform

