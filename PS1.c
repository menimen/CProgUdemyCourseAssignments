#include <stdio.h>
#include <math.h>
void Calc_Renumeration(double* ptr1, double* ptr2);
void Mission1();
void Mission2();
void Mission3();
void Mission4();
void Mission5();
void Mission6();
void Mission7();
void CalcRoots(int* a, int* b, int* c);
int main() {
	int num;
	while (1) {
		printf("choose mission:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			Mission1();
			break;
		case 2:
			Mission2();
			break;
		case 3:
			Mission3();
			break;
		case 4:
			Mission4();
			break;
		case 5:
			Mission5();
			break;
		case 6:
			Mission6();
			break;
		case 7:
			Mission7();
			break;
		default:
			break;
		}
	}
}
void Mission1() {
	double beginning_odometer_reading = 0;
	double ending_odometer_reading = 0;
	double* ptr1 = &beginning_odometer_reading, * ptr2 = &ending_odometer_reading;
	printf("enter Enter beginning odometer reading\n");
	scanf("%lf", &beginning_odometer_reading);
	printf("enter Enter ending odometer reading\n");
	while (ending_odometer_reading < beginning_odometer_reading) {
		scanf("%lf", &ending_odometer_reading);
	}
	Calc_Renumeration(ptr1, ptr2);
}
void Mission2() {
	double distKM = 0, distMile = 0 , distFoot = 0;
	printf("enter the distance between two cities:");
	scanf("%lf", &distKM);
	distMile = distKM * 0.621371;
	distFoot = distKM * 3280.84;
	printf("The distance between two cities is %.2lfkm or %.2lfmiles or %.2lffoot.", distKM, distMile, distFoot);
}
void Mission3() {
	int population = 80000;
	int Menpopulation = 0.52 * population;
	int Womenpopulation = population - Menpopulation;
	int LiterateMen = 0.35 * population;
	int Literacy = 0.48 * 80000;
	int LiterateWomen = Literacy - LiterateMen;
	int NotLiterateMen = Menpopulation - LiterateMen;
	int NotLiterateWomen = Womenpopulation - LiterateWomen;
	printf("Total no. of men in the town: %d\n", Menpopulation);
	printf("Total no. of literate people: %d\n", Literacy);
	printf("Total no. of literate men: %d\n", LiterateMen);
	printf("Total no. of women: %d\n", Womenpopulation);
	printf("Total no illiterate men is %d and women is %d\n", NotLiterateMen, NotLiterateWomen);
}
void Mission4() {
	int units = 0;
	double res = 0;
	printf("enter units\n");
	scanf("%d", &units);
	res = (units < 100)? (1) : ((units >= 100 && units <= 500) ? 1.5 : 3);
	printf("%lf\n", res);
}
void Mission5() {
	int a, b, c;
	printf("Enter the values for a, b and c:");
	scanf("%d %d %d", &a, &b, &c);
	CalcRoots(&a, &b, &c);
}
void CalcRoots(int* a, int* b, int* c) {
	double root1 = 0, root2 = 0;
	root1 =(-(*b) + sqrt(pow(*b, 2) - (double)4 * (*a) * (*c))) / ((double)2 * (*a));
	root2 = (-(*b) - sqrt(pow(*b, 2) - (double)4 * (*a) * (*c))) / ((double)2 * (*a));
	printf("The roots are: %lf and %lf\n", root1, root2);
}
void Mission6() {
	float height = 0, weight = 0, BMI = 0;
	printf("enter weight and height:\n");
	scanf("%f %f", &weight, &height);
	BMI = weight / pow(height, 2);
	printf("your BMI is : %f\n", BMI);
}
void Mission7() {
	float TotalMiles = 0, MilesPerGallon = 0, GasolineCost = 0, ParkingFees = 0, Tolls = 0, DailyDrivingCost = 0;
	printf("please enter TotalMiles, MilesPerGallon, GasolineCost, ParkingFees, Tolls per day: ");
	scanf("%f %f %f %f %f", &TotalMiles, &MilesPerGallon, &GasolineCost, &ParkingFees, &Tolls);
	DailyDrivingCost = DailyDrivingCost = (TotalMiles / MilesPerGallon) * GasolineCost + ParkingFees + Tolls;
	printf("your daily driving cost is : %f\n", DailyDrivingCost);
}
void Calc_Renumeration(double* ptr1, double* ptr2) {
	double travel_total = (*ptr2 - *ptr1);
	printf("You traveled %.1lf miles. At Rs.25 per mile, your remuneration is Rs.%.1lf", travel_total, travel_total * 25);
}
