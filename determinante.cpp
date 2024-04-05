#include <bits/stdc++.h>
using namespace std;

int calc_det(int n, int* matriz){
    if (n == 1) return matriz[0];
    
    int soma = 0;
    for (int i = 0; i < n; i++){
        int det;
        int* nova_matriz = (int*) malloc((n-1) * (n-1) * sizeof(int));
        for (int y = 1; y < n; y++){
            int aux = 0;
            for(int x = 0; x < n; x++){
                if (x == i){
                    aux += 1;
                    continue;
                }
                nova_matriz[(y-1) * (n-1) + x - aux] = matriz[y * n + x];
            }
        }
        det = matriz[i] * calc_det(n-1, nova_matriz); 
        free(nova_matriz);
        if (i % 2) det = -det;
        soma += det;
    }
    return soma;
}

int main(){
    int n;
    cin >> n;

    int* m = (int*) malloc(n*n*sizeof(int)); 

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> m[i*n + j];
        }
    }

    cout << calc_det(n, m) << endl;
    free(m);

    return 0;
}