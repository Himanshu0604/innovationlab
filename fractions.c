#include <stdio.h>
int lcm(int, int);

struct sumFractions {
    int num1,num2,den1,den2;
    int size;
    int add;
    int lcm;
};

struct sumFractions input() {
    struct sumFractions k;
    printf("Total No of elements : \n");
    scanf("%d",&k.size);
    printf("Enter %d elements \n",k.size);
    for (int i = 0; i < k.size; ++i) {
        scanf("%d%d",&k.num[i],&k.den[i]);
    }
    printf("Enter the values of 1st fraction : \n");
    scanf("%d %d",&k.num1,&k.den1);
    printf("Enter the values of 2nd Fraction : \n");
    scanf("%d %d",&k.num2,&k.den2);
    return k;
}

struct sumFractions compute(struct sumFractions k)  {
    k.add = 0;
    k.lcm = lcm(k.den1,k.den2);

    k.num1 = k.num1 * (k.lcm / k.den1);
    k.num2 = k.num2 * (k.lcm / k.den2);
    k.add = k.num1 + k.num2;

    return k;
}

int lcm(int num1,int num2)
{
    static int temp = 1;
    if(temp % num2 == 0 && temp % num1 == 0) {
        return temp;
    }
    temp++;
    lcm(num1,num2);
    return temp;
}

struct sumFractions output(struct sumFractions k)    {
    printf("Result : %d / %d",k.add,k.lcm);
    return k;
}

int main() {
    struct sumFractions fractions;
    fractions = input();
    fractions = compute(fractions);
    output(fractions);
    return 0;
}