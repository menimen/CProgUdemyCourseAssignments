#include "ex4header.h"
//1.Write a program in C that prints all the perfect numbers between 1 and given input.
void mission1Menu() {
    int inputparam = 0;
    printf("choose the upper limit of perfect numbers you want to get:\n");
    scanf("%d",&inputparam);
    FindPerfectNumbers(inputparam);
}
void FindPerfectNumbers(int n) {
    int factor = 1, sum = 0, num = 2;
    while (num <= n) {
        sum = 0;
        factor = 1;
        while (factor <= num/2) {
            if (num % factor == 0) {
                sum += factor;
            }
            factor++;
        }
        if (sum == num) {
            printf("%d \n",num);  
        }
        num++;
    }
}

//2.Write a program in C displaying a menu with options CIRCLE, SQUARE, RECTANGLE, TRIANGLE and EXIT. Get the appropriate input from the user for calculating the AREA

void mission2Menu(){
    char str[MAX_LIMIT];
    while(strcmp(str,"exit") != 0) {
        printf("type the shape you want to calculate its area:\n");
        fseek(stdin,0,SEEK_END); 
        scanf("%s[^\n]", str);
        if (strcmp(str,"rectangle") == 0) {
            calcRecArea();
        }
        else if (strcmp(str,"rectangle") == 0) {
            calcRecArea();
        } else if (strcmp(str,"circle") == 0) {
            calcCircArea();
        } else if (strcmp(str,"triangle") == 0) {
            calcTriangleArea();
        } else if (strcmp(str,"square") == 0) {
            calcSquareArea();
        } else if (strcmp(str,"exit") == 0) {
            // do nothing. loop will break at next iteratioin
        }  else {
            printf("you typed wrong input. try again...\n");
        }
    }
}
void calcRecArea() {
    int width = 0, height = 0;
    printf("enter hegith and width size:\n");
    scanf("%d %d", &height, &width);
    printf("the area of the rectangle is %d\n", height*width);
}
void calcTriangleArea() {
    int base = 0, height = 0;
    printf("enter base and height size:\n");
    scanf("%d %d", &base, &height);
    printf("the area of the triangle is %d\n", ((base*height)/2));
}
void calcCircArea() {
    int radius = 0;
    printf("enter radius size:\n");
    scanf("%d",  &radius);
    printf("the area of the circle is %f\n", M_PI*pow(radius,2));
}
void calcSquareArea() {

    int side = 0;
    printf("enter side size:\n");
    scanf("%d",  &side);
    printf("the area of the square is %f\n", pow(side,2));
}


//3. Write a program which asks the user to enter a character.
//Check whether the user has typed a character (either uppercase or lowercase) or digit and display the result (using if…else if ladder)
void mission3Menu() {
    char c;
    printf("enter your character:");
    c =getchar();
    c =getchar();
    printf("the ASCII value for the char you pressed is : %d\n", c);
}
//4. Write a program to find all Armstrong numbers in the range of 0 and 999.
void mission4Menu() {
    for (int i =0; i <= 999; i++) {
        if (i > 99 && i < 1000) {
            checkifArmstrongNum(i);
        }
    }
}
void checkifArmstrongNum(int i) {
    int a = 0, b = 0, c = 0, sum = 0 , j = i ;
    a = i % 10;
    i = i / 10;
    b = i % 10;
    i = i / 10;
    c = i % 10;
    sum = pow(a,3) + pow(b,3) + pow(c,3);
    if (sum == j) {
        printf("%d\n", sum);
    }
}