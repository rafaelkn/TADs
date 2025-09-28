#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct {
    int a;
    int b;
    int c;
} trngl;

void setTriangle(trngl *t, int lado1, int lado2, int lado3);
int getType(trngl t);
void showTriangle(trngl t);
int getPerimeter(trngl t);
double getArea(trngl t);
int isSimilar(trngl t1, trngl t2);

#endif
