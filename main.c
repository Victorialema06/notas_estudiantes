#include <stdio.h>
#include <string.h>

#define ESTUDIANTES 5
#define MATERIAS 3

int main() {
    float notas[ESTUDIANTES][MATERIAS];
    float promEstudiante[ESTUDIANTES];
    float promMateria[MATERIAS];

    char nombres[ESTUDIANTES][50];

    int i, j;
    float suma, mayor, menor;

    int aprobados[MATERIAS] = {0};
    int reprobados[MATERIAS] = {0};

    
    printf("INGRESO DE ESTUDIANTES\n");
    for (i = 0; i < ESTUDIANTES; i++) {
        printf("Ingrese nombre del estudiante %d: ", i + 1);
        scanf(" %[^\n]", nombres[i]); 
    }

    
    for (i = 0; i < ESTUDIANTES; i++) {
        printf("\nEstudiante: %s\n", nombres[i]);
        for (j = 0; j < MATERIAS; j++) {
            do {
                printf("Nota materia %d (0-10): ", j + 1);
                scanf("%f", &notas[i][j]);

                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Error: nota invalida\n");
                }

            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    
    printf("\nPROMEDIO POR ESTUDIANTE\n");
    for (i = 0; i < ESTUDIANTES; i++) {
        suma = 0;
        mayor = notas[i][0];
        menor = notas[i][0];

        for (j = 0; j < MATERIAS; j++) {
            suma += notas[i][j];

            if (notas[i][j] > mayor) mayor = notas[i][j];
            if (notas[i][j] < menor) menor = notas[i][j];
        }

        promEstudiante[i] = suma / MATERIAS;

        printf("%s -> Promedio: %.2f  Mayor: %.2f  Menor: %.2f\n",
               nombres[i], promEstudiante[i], mayor, menor);
    }

    // PROMEDIO POR MATERIA
    printf("\nPROMEDIO POR MATERIA\n");
    for (j = 0; j < MATERIAS; j++) {
        suma = 0;
        mayor = notas[0][j];
        menor = notas[0][j];

        for (i = 0; i < ESTUDIANTES; i++) {
            suma += notas[i][j];

            if (notas[i][j] > mayor) mayor = notas[i][j];
            if (notas[i][j] < menor) menor = notas[i][j];

            if (notas[i][j] >= 6)
                aprobados[j]++;
            else
                reprobados[j]++;
        }

        promMateria[j] = suma / ESTUDIANTES;

        printf("Materia %d -> Promedio: %.2f  Mayor: %.2f  Menor: %.2f\n",
               j + 1, promMateria[j], mayor, menor);

        printf("Aprobados: %d  Reprobados: %d\n",
               aprobados[j], reprobados[j]);
    }

    return 0;
}