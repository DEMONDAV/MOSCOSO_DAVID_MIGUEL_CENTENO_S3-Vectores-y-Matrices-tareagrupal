#include <stdio.h>

int main() 
{
    // 1. Definición de constantes y variables
    // Según el requerimiento: 5 estudiantes y 3 asignaturas [cite: 18]
    int estudiantes = 5;
    int asignaturas = 3;
    float notas[5][3]; // Matriz para almacenar las notas [cite: 13]
    
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

    // 3. Procesamiento de promedios por estudiante
    for (int i = 0; i < estudiantes; i++) {
        sumaEstudiante = 0;
        for (int j = 0; j < asignaturas; j++) {
            sumaEstudiante += notas[i][j];
        }
        promedioEstudiante[i] = sumaEstudiante / asignaturas;
    }
    printf("\n>> Cálculos de promedios finalizados.\n");
   // 4. Reporte Final de Calificaciones
    printf("\n============================================\n");
    printf("        REPORTE FINAL DE RENDIMIENTO        \n");
    printf("============================================\n");
    printf("Estudiante\tPromedio\tEstado\n");
    printf("--------------------------------------------\n");
    
    for (int i = 0; i < estudiantes; i++) {
        printf("   #%d\t\t %.2f\t\t%s\n", 
               i + 1, 
               promedioEstudiante[i], 
               (promedioEstudiante[i] >= 7.0) ? "APROBADO" : "REPROBADO");
        
        // Conteo de estados
        if (promedioEstudiante[i] >= 7.0) aprobados[0]++; // Usamos el primer índice para general
        else reprobados[0]++;
    }
    
}
