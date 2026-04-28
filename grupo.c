#include <stdio.h>

int main() 
{
    // 1. Definición de constantes y variables
    int estudiantes = 5;
    int asignaturas = 3;
    float notas[5][3];
    
    // Variables para cálculos
    float sumaEstudiante, sumaAsignatura;
    float promedioEstudiante[5];
    float promedioAsignatura[3];
    int aprobados[3] = {0, 0, 0};
    int reprobados[3] = {0, 0, 0};

    // 2. Ingreso de datos con validación obligatoria
    for (int i = 0; i < estudiantes; i++) {
        printf("\n--- Registro Estudiante %d ---\n", i + 1);
        for (int j = 0; j < asignaturas; j++) {
            do {
                printf("  Nota Asignatura %d: ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("  [Error] La nota debe estar entre 0 y 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

// 3. Procesamiento y Reporte por Estudiante (Promedios, Max y Min)
    printf("\n==========================================================\n");
    printf("            REPORTE DE RENDIMIENTO POR ESTUDIANTE         \n");
    printf("==========================================================\n");
    printf("Est. | Promedio | Nota Max | Nota Min \n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < estudiantes; i++) {
        sumaEstudiante = 0;
        float maxEst = notas[i][0]; 
        float minEst = notas[i][0];

        for (int j = 0; j < asignaturas; j++) {
            sumaEstudiante += notas[i][j];
            if (notas[i][j] > maxEst) maxEst = notas[i][j];
            if (notas[i][j] < minEst) minEst = notas[i][j];
        }
        printf(" #%d  |   %.2f   |   %.2f   |   %.2f\n", 
               i + 1, sumaEstudiante / asignaturas, maxEst, minEst);
    }

    // 4. Procesamiento y Reporte por Asignatura (Promedios, Max, Min, Aprobados)
    printf("\n==========================================================\n");
    printf("            ESTADISTICAS POR ASIGNATURA                   \n");
    printf("==========================================================\n");
    printf("Asig.| Promedio | Nota Max | Nota Min | Aprob. | Reprob.\n");
    printf("----------------------------------------------------------\n");

    for (int j = 0; j < asignaturas; j++) {
        sumaAsignatura = 0;
        float maxAsig = notas[0][j]; 
        float minAsig = notas[0][j];
        int countAprob = 0, countReprob = 0;

        for (int i = 0; i < estudiantes; i++) {
            sumaAsignatura += notas[i][j];
            if (notas[i][j] > maxAsig) maxAsig = notas[i][j];
            if (notas[i][j] < minAsig) minAsig = notas[i][j];

            if (notas[i][j] >= 6.0) countAprob++; // Nota aprobatoria >= 6
            else countReprob++;
        }
        printf(" #%d  |   %.2f   |   %.2f   |   %.2f   |   %d    |   %d\n", 
                j + 1, sumaAsignatura / estudiantes, maxAsig, minAsig, countAprob, countReprob);
    }
