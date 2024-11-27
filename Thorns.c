#include <stdio.h>


int maxNumberCoinsCollect(char path[], int lengthPath) {
    int coins = 0;

    for (int i = 0; i < lengthPath; i++) { // Incremento controlado pelo for
        if (path[i] == '@') {
            coins++;
            if (i + 1 < lengthPath && path[i + 1] == '*') {
                // Pulo simples: só avança normalmente no for
                i++;
                continue;
            }
        } else if (path[i] == '*') {
            return coins; // Fim do caminho
        } else if (i + 1 < lengthPath && (path[i + 1] == '.' || path[i + 1] == '*')) {
            // Pulo duplo: avanço do `for` já resolve
            i++;
        }
    }

    return coins;
}



int main() {

    int nTestCases;
    int lengthPath;
    
    scanf("%d", &nTestCases);

    for (int i = 0; i < nTestCases; i++) {
        scanf("%d", &lengthPath);
        char path[lengthPath];
        scanf("%s", path);
        printf("%d\n", maxNumberCoinsCollect(path, lengthPath));
    }

    return 0;
}

