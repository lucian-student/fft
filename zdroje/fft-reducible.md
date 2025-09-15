# FFT reducible

https://www.youtube.com/watch?v=h7apO7q16V0

## Přirovnání s polynomy

* polynom stupně $d$, lze reprezentovat pomocí $d+1$ body

### Násobení polynomu při vyjádření pomocí bodů

Kdybych měl dva polynomy 2stupně -> výsledný polynom je 4 stupně

* Potřebuji 5 bodů
* pro vytvoření násobku stačí vzít 5-bodů z obou polynomu s stejným $x$-em
* poté stačí přenásobit $y$-ny, tak získaneme bodovou reprezentaci

### Myšlenka rychlejšího násobení polynomů

1. převedou se polynomi do "value reprezentace"
2. vynásobí se
3. převede se zpět do "koeficientové reprezentace"

### Problém vyhodnocení bodů(převod koeficientů na value reprezentaci)

Jelikož výpočet pro n bodů d-stupňové polynomu by zabral: n*d času.

Ilustrace, že pro sudé a liché funkce stačí jenom vypočítat polovinu bodů.

### Rozdělení na sudé a liché koeficienty

Polynom můžeme vyjadřít jako součet dvou polynomů: $P(x) = P_e(x^2) + xP_o(x^2)$
* $P_e(x^2)$ -> even/sudý koeficienty
* $P_o(x^2)$ -> lichý/odd koeficienty
* takže máme dva polynomy stupně $n/2 - 1$


To můžeme aplikovat rekurzivně:
* jediný problém je, že teď jsou všechny body pozitivní kvůli $x^2$
* proto je potřeba použít komplexní čísla

Porotože potřebujeme na každé úrovni vyhodnotit pouze $n$ čísel asi dohromady
* ve skutečnosti se asi vyhodnocuje jenom dole potom se sčítá(moje doměnka)

### Vhodná incializace - roots of unity

