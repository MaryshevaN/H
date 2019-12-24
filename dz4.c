#include <stdlib.h>
#include <stdio.h>

int main() {
    int n, t, s, k;
    
    printf("Введите количество вершин графа: ");
    scanf("%d", &n);
    
    int **a = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = -1;

    printf("Введите матрицу смежности:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j==i) a[i][j] = 0;
            if (a[i][j] == -1) {
                scanf("%d", &a[i][j]);
                a[j][i] = a[i][j];
            } else
                printf("%d ", a[i][j]);
        }
    }
    printf("\n");
    
    printf("Введите вершины, между которыми нужно создать ребро\n (Вершины нумеруются с 1 - ЕДИНИЦЫ!\n");
    int v1, v2;
    scanf("%d %d", &v1, &v2);
	v1--; v2--;
    if (v1 < n && v2 < n && v1 >= 0 && v2 >= 0 && v1 != v2)
        if (a[v1][v2] == 1) printf("Такое ребро уже есть!\n");
        else {
            a[v1][v2] = 1;
            a[v2][v1] = 1;
        }
	else printf("Недопустимое значение вершины!\n");
    
    printf("Теперь матрица выглядит так:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
   
    
   
    return 0;
}
