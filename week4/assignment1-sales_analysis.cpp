//-------------------------------+-------------+------------+
// Week 4 - Coding Assignment #1 | Calvin Losh | 05-05-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>

using namespace std;

int main() {
    double sales[7]{};
    double sales_high[2]{};
    double sales_low[2]{};
    double sales_tot{0};
    double sales_avg{0};

    string days[7]{
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    cout << "\nWEEKLY SALES ANALYSIS"
         << "\n---------------------\n";

    for (int i = 0; i < 7; i++) {
        cout << "Enter sales for " << days[i] << ": ";
        cin >> sales[i];
    }

    // Worst sales day
    sales_low[1] = sales[0];
    for (int i = 0; i < 7; i++) {
        if (sales[i] < sales_low[1]) {
            sales_low[0] = i;
            sales_low[1] = sales[i];
        }
    }

    // Best sales day
    for (int i = 0; i < 7; i++) {
        if (sales[i] > sales_high[1]) {
            sales_high[0] = i;
            sales_high[1] = sales[i];
        }
    }

    // Total sales
    for (int i = 0; i < 7; i++) {
        sales_tot += sales[i];
    }

    // Average daily sales
    sales_avg = sales_tot / 7;

    // Days above average
    int sales_abv_avg{};
    for (int i = 0; i < 7; i++) {
        if (sales[i] > sales_avg) {sales_abv_avg++;};
    }

    // Weekend sales
    double sales_wknd{sales[5] + sales[6]};

    cout << "\nSales Summary"
         << "\n-------------"
         << "\nTotal sales: $" << sales_tot
         << "\nAverage daily sales: $" << sales_avg
         << "\n"
         << "\nBest day: " << days[int(sales_high[0])] << " with $" << sales_high[1]
         << "\nWorst day: " << days[int(sales_low[0])] << " with $" << sales_low[1]
         << "\n"
         << "\nDays above average: " << sales_abv_avg
         << "\nWeekend sales: $" << sales_wknd << " (" << (sales_wknd / sales_tot) * 100 << "% of sales)" << endl;

    return 0;
}