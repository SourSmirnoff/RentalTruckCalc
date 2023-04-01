#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void largeTruck();
void determineTruck();
void mediumTruck();
void smallTruck();
void nowMath();

double milesDriven;
int MPG;
int daysRented;
double avgGasPrice = 2.89;
double taxRate = 1.09;
double totalGasCost;
double insurance;
double dailyRental;
double gallonsUsed;
double milesCharge;
double milesRate;
double total;
double finalTotal;
string beSmart;

int main() {
    while(true) {
        std::cout << "You rented the 26 foot truck, right?\n";
        std::string truck;
        std::cin >> truck;
        if(truck == "yes"){
            largeTruck();
            break; // break out of the loop if a valid option is selected
        }
        else if(truck == "no"){
            determineTruck();
            break; // break out of the loop if a valid option is selected
        }
        else{
            std::cout << "Invalid, try yes or no.\n";
            // continue the loop if an invalid option is selected
        }
    }
}

void largeTruck() {
    milesRate = 0.59;
    dailyRental = 49.92;
    insurance = 120;
    MPG = 10;
    nowMath();
}

void mediumTruck(){
    milesRate = 0.49;
    dailyRental = 29.89;
    insurance = 90;
    MPG = 14;
    nowMath();
}

void smallTruck(){
    milesRate = 0.39;
    dailyRental = 19.92;
    insurance = 75;
    MPG = 17;
    nowMath();
}
void nowMath(){
    std::cout << "Okay, how many miles will you use?\n";
    std::cin >> milesDriven;
    milesCharge = milesDriven * milesRate;
    std::cout << "How many days will you need?\n";
    std::cin >> daysRented;
    std::cout << "Okay, your mileage rate is $" << milesRate << " per mile, since you are driving a total of " << milesDriven
              << " miles, you will \nbe charged $" << milesCharge << " for mileage. Do you want insurance?\n";
    std::cin >> beSmart;
    std::transform(beSmart.begin(), beSmart.end(), beSmart.begin(), [](unsigned char c) { return std::tolower(c); });
    bool hasInsurance = (beSmart.compare(0, 1, "y") == 0);

    gallonsUsed = milesDriven / MPG;
    totalGasCost = gallonsUsed * avgGasPrice;
    if (hasInsurance){
        total = milesCharge + insurance + totalGasCost + (dailyRental * daysRented);
        finalTotal = total * taxRate;
        std::cout << "Okay, your final cost for this rental is $" << finalTotal << " after gas, fees, and tax.\n";
        system("pause");
    } else{
        total = milesCharge + totalGasCost + (dailyRental * daysRented);
        finalTotal = total * taxRate;
        std::cout << "Okay, your final cost for this rental is $" << finalTotal << " after gas, fees, and tax.\n";
        system("pause");
    }
}

void determineTruck() {
    enum TruckSize { SIZE_12, SIZE_18, SIZE_26 };
    TruckSize size; // set initial value
    std::string altAnswer;
    while (true) {
        std::cout << "Well what did you rent then?! We only have 26, 18, and 12 foot trucks.\n";
        std::cin >> altAnswer;

        if (altAnswer == "26" || altAnswer == "26 foot") {
            size = SIZE_26;
        } else if (altAnswer == "18" || altAnswer == "18 foot") {
            size = SIZE_18;
        } else if (altAnswer == "12" || altAnswer == "12 foot") {
            size = SIZE_12;
        } else {
            std::cout << "Invalid input. Try entering 12, 18, or 26.\n";
            continue;
        }

        switch (size) {
            case SIZE_26:
                largeTruck();
                break;
            case SIZE_18:
                mediumTruck();
                break;
            case SIZE_12:
                smallTruck();
                break;
        }
        break;
    }
}