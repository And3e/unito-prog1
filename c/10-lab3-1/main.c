#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // Usiamo il tipo "bool", che e' definito in <stdbool.h>
    // Come avete visto a lezione, il tipo bool e' convertibile in int
    bool vero = true;
    printf("vero: %d\n", vero);
    bool falso = false;
    printf("falso: %d\n", falso);

    // Per il linguaggio C il tipo bool 
    // ed il tipo int sono interconvertibili
    int negazione1 = !vero;
    printf("negazione1: %d\n", negazione1);
    int negazione2 = !falso;
    printf("negazione2: %d\n", negazione2);

    printf("congiunzione: vero  AND vero  = %d\n", (true  && true));
    printf("congiunzione: falso AND vero  = %d\n", (false && true));
    printf("congiunzione: vero  AND falso = %d\n", (true  && false));
    printf("congiunzione: falso AND falso = %d\n", (false && false));

    printf("disgiunzione: vero  OR vero  = %d\n", (true  || true));
    printf("disgiunzione: falso OR vero  = %d\n", (false || true));
    printf("disgiunzione: vero  OR falso = %d\n", (true  || false));
    printf("disgiunzione: falso OR falso = %d\n", (false || false));

    // Comparazione di valori interi
    bool b1 = 2 == 2; // true
    bool b2 = 2 >= 2; // true
    bool b3 = 2 > 3;  // false
    bool b4 = 2 != 2; // false
    bool b5 = 2 == 3; // false
    bool b6 = 2 <= 3; // true
    bool b7 = 3 < 3;  // false
    bool b8 = 2 != 3; // true

    // stampiamo un boolean come testo invece che come valore intero 0/1
    printf("b8 (come testo): %s\n", b8 ? "true" : "false");


    // Leggi di De Morgan
    //   not(a and b)  =  not(a) or  not(b)
    bool dM1 = !(b1 && b4) == (!b1 || !b4);
    printf("dM1: %d\n", dM1);

    //   not(a or  b)  =  not(a) and not(b)
    bool dM2 = (b1 && b4) == !(!b1 || !b4);
    printf("dM2: %d\n", dM2);

    // Espressioni booleane arbitrarie
    // ATTENZIONE: non mettere sullo stesso livello || ed &&,
    //   perchè && ha priorità su ||
    b7 = (b1 && b2) || ((!b5 || b6) && (b3 && !b1));
    printf("b7: %d\n", b7);

    /* Massimo tra due variabili usando max tale che:
     *   max == true  se x >= y
     *   max == false altrimenti   (cioe' se x < y)
     */
    int x = 8;
    int y = 5;
    bool max = (x >= y);
    printf("max prima soluzione: %d\n", max);

    // equivalente alla seguente soluzione (inutilmente piu' lunga):
    if (x >= y) {
        max = true;
    } else {
        max = false;
    }
    printf("max seconda soluzione: %d\n", max);


    // Valutazione lazy (pigra) degli operatori booleani && e ||
    bool b9 = false && (10 / 0) == 1;
    printf("b9: %d\n", b9);

    // ESERCIZIO: scambiare l'ordine dei termini della congiunzione
    // bool b9_2 = (10 / 0) == 1 && false; // termini scambiati
    // printf("b9_2: %d\n", b9_2);
    // --> danno errore, la compare finisce appena trova un valore che non rispetti la porta logica

    bool b10 = true || (10 / 0) == 1; 
    printf("b10: %d\n", b10);

    // ESERCIZIO: scambiare l'ordine dei termini della disgiunzione
    // bool b10_2 = (10 / 0) == 1 || true; // invertire scambiati
    // printf("b10_2: %d\n", b10_2);
    // --> danno errore, la compare finisce appena trova un valore che non rispetti la porta logica
}


