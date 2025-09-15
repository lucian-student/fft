# Fuourier tranform

https://www.youtube.com/watch?v=spUNpyF58BY

* máme nějakou vlnu, třeba cosinus/sinus
* z nějakýho důvodu namapuje vlnu na kruh
* vlna je tak namapovaná, že 2sekundy tvoří kruh -> z toho vyplívá, že máme 0.5 cyklu/sekunda, jelikož 2sekundy tvoří kruh


## Potom tam hovoří něco a nějkým středu hmoty(center of mass) grafu

Ai tvrdí, že circle je tvořen takto $g(t) * e^{-2\pi i f t}$
* g(t) je asi ta vlna, která udává váhu v čase a tvoří tu mandalu
* center of mass můžeme vypočítat podle odvozeného vzorce:
    * nějak bych to snad spočítal, ale asi to nechám zatím na později

Příklad v blue one brownově videu

![alt text](image.png)
* mám squigle s frekvencí 3hz -> číli 3 vlnky za sekundu
* kdbychom chtěli nastavit funkci $g(t) * e^{-2\pi i f t}$, tak aby za 2 sekundy se vykonal jeden cyklus, tak musíme nastavit $f=2$


Jelikož máme frekvenci 3, tak pro 3 cycly/sekundu -> tak se centr of mass posune výrazně doprava
* úplně nevím proč tomu, tak je -> nemám žádný rigorzní důkaz


Říká, že furierova transformace je zchopná získat z kombinovaného "squigglu" všechny využité frekvence.


Centr of mass získaneme:
* buď vyprůměrováním sáplnutých bodů
    * takže z toho, co jsem pochopil lze aproximovat integrál průměrem bodů
* nebo integrálem

why do we calculate to get center of mass using this formula
$\dfrac{1}{t_2 - t_1}\int_{t_1}^{t_2}g(t)e^{-2\pi i f t} dt$
* 

instead of:
$\dfrac{1}{\text{area}}\int_{t_1}^{t_2} x g(t)e^{-2\pi i f t} dt$

like we would calculate x-coordinate of center of mass:
$\dfrac{1}{\text{area}}\int{a}^{b} x (f(x) - g(x)) dx$

## Ohledně integrálu

* ignerujeme škálování
* čím delší využijeme squigle tím větší má maginitude furierova transformace


Takže furierova tranformace vytvoří novou funkci z původní.
* nová funkce má parametr frekvenci, naozdíl od času