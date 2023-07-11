#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
void calcularPerimetro(float puntos[4][3], float *perimetro, float *lado1, float *lado2, float *lado3, float *lado4, float *lado5, float *lado6);
float calcularArea(float perimetro, float lado1, float lado2, float lado3, float lado4, float lado5, float lado6);
void calcularVolumen(float areaBase, float altura, float *volumen);

int main(int argc, char *argv[]) {
    float puntos[4][3] = {{0, 0, 3}, {3, 0, 0}, {0, 0, 0}, {1, 7, 1}};
    float perimetro, lado1, lado2, lado3, lado4, lado5, lado6;
    calcularPerimetro(puntos, &perimetro, &lado1, &lado2, &lado3, &lado4, &lado5, &lado6);
    float areaBase = calcularArea(perimetro, lado1, lado2, lado3, lado4, lado5, lado6);
    float altura = 8.0;
    float volumen;
    calcularVolumen(areaBase, altura, &volumen);
    float areaSuperficial = areaBase + lado1 * altura + lado2 * altura + lado3 * altura + lado4 * altura + lado5 * altura + lado6 * altura;

    printf("Perimetro de la base: %f\n", perimetro);
    printf("Area de la base: %f\n", areaBase);
    printf("Altura de la piramide: %f\n", altura);
    printf("Volumen de la piramide: %f\n", volumen);
    printf("Area superficial de la piramide: %f\n", areaSuperficial);

    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2) {
    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    return dist;
}

void calcularPerimetro(float puntos[4][3], float *perimetro, float *lado1, float *lado2, float *lado3, float *lado4, float *lado5, float *lado6) {
    *lado1 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *lado2 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *lado3 = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *lado4 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *lado5 = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *lado6 = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
}

float calcularArea(float perimetro, float lado1, float lado2, float lado3, float lado4, float lado5, float lado6) {
    float s = perimetro / 2;
    float area = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3)) + sqrt(s * (s - lado4) * (s - lado5) * (s - lado6));
    return area;
}

void calcularVolumen(float areaBase, float altura, float *volumen) {
    *volumen = (areaBase * altura) / 3;
}
