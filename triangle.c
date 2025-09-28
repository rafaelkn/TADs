#include <stdio.h>
#include <math.h>
#include "triangle.h"

void setTriangle(trngl *t, int lado1, int lado2, int lado3) {
    t->a = lado1;
    t->b = lado2; 
    t->c = lado3;
}

void showTriangle(trngl t) {
    printf("AB: %d, BC: %d, CA: %d", t.a, t.b, t.c);
}

int getPerimeter(trngl t) {
    return t.a + t.b + t.c;
}

int getType(trngl t) {
    if (t.a + t.b <= t.c) {
        return 0;
    }
    if (t.a + t.c <= t.b) {
        return 0;  
    }
    if (t.b + t.c <= t.a) {
        return 0;
    }
    
    if (t.a == t.b && t.b == t.c) {
        return 1;
    }
    if (t.a == t.b || t.a == t.c || t.b == t.c) {
        return 2;
    }
    return 3;
}

double getArea(trngl t) {
    if (getType(t) == 0) {
        return 0.0;
    }
    
    double s = (t.a + t.b + t.c) / 2.0;
    double resultado = sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));
    
    return resultado;
}


int isSimilar(trngl t1, trngl t2) {
    if (getType(t1) == 0 || getType(t2) == 0) {
        return 0;
    }
    
    double cos1_A = (t1.b*t1.b + t1.c*t1.c - t1.a*t1.a) / (2.0 * t1.b * t1.c);
    double cos1_B = (t1.a*t1.a + t1.c*t1.c - t1.b*t1.b) / (2.0 * t1.a * t1.c);
    double cos1_C = (t1.a*t1.a + t1.b*t1.b - t1.c*t1.c) / (2.0 * t1.a * t1.b);
    
    double cos2_A = (t2.b*t2.b + t2.c*t2.c - t2.a*t2.a) / (2.0 * t2.b * t2.c);
    double cos2_B = (t2.a*t2.a + t2.c*t2.c - t2.b*t2.b) / (2.0 * t2.a * t2.c);
    double cos2_C = (t2.a*t2.a + t2.b*t2.b - t2.c*t2.c) / (2.0 * t2.a * t2.b);
    
    double dif1 = cos1_A - cos2_A;
    double dif2 = cos1_B - cos2_B;
    double dif3 = cos1_C - cos2_C;
    
    if (dif1 < 0) dif1 = -dif1;
    if (dif2 < 0) dif2 = -dif2;
    if (dif3 < 0) dif3 = -dif3;
    
    if (dif1 < 0.0001 && dif2 < 0.0001 && dif3 < 0.0001) {
        return 1;
    }
    
    dif1 = cos1_A - cos2_B;
    dif2 = cos1_B - cos2_C;
    dif3 = cos1_C - cos2_A;
    
    if (dif1 < 0) dif1 = -dif1;
    if (dif2 < 0) dif2 = -dif2;
    if (dif3 < 0) dif3 = -dif3;
    
    if (dif1 < 0.0001 && dif2 < 0.0001 && dif3 < 0.0001) {
        return 1;
    }
    
    dif1 = cos1_A - cos2_C;
    dif2 = cos1_B - cos2_A;
    dif3 = cos1_C - cos2_B;
    
    if (dif1 < 0) dif1 = -dif1;
    if (dif2 < 0) dif2 = -dif2;
    if (dif3 < 0) dif3 = -dif3;
    
    if (dif1 < 0.0001 && dif2 < 0.0001 && dif3 < 0.0001) {
        return 1;
    }
    
    return 0;
}
