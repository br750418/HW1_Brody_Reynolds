/**
 *    @file: invoice.cc
 *  @author: Brody Reynolds
 *    @date: 9/11/2021
 *   @brief: Selling a certain monitor based on quantity, price, state tax, and discounted price.
 *  
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
    // 1: Declare variables
    string brand, resident, mtype;
    int quant;

    double price, tprice, disc, stotal, tax, total;

    // 2: Assinging variable prices, tax, and discount
    int const sp = 190, vp = 170;
    const double discperc = 0.05, taxperc = 0.07;

    // 3: Input of monitor type for user
    cout << "Enter a monitor type (s, v) followed by the quantity:  ";
    cin >> mtype >> quant;

    // 4: Error output if the input is the wrong character. Calculations
    if (mtype == "s")
    {
        brand = "Samsung";
        price = 190;
        tprice = quant * sp;
    }
    else if (mtype == "v")
    {
        brand = "ViewSonic";
        price = 170;
        tprice = quant * vp;
    }
    else
    {
        cout << "Error: Entered wrong character(s) within monitor type." << endl;
        cout << "Ending Program... " << endl;
        exit(0);
    }

    // 5: Applying discount if quantity is over 3 and error output if the input is the wrong #. Calculations 
    if (quant >= 3)
    {
        disc = tprice * discperc;
    }
    else if (quant <= 0)
    {
        cout << "Error: Entered wrong character(s) within quantity." << endl;
        cout << "Ending Program... " << endl;
        exit(0);
    }
    stotal = tprice - disc;

    // 6: Applying state tax if input is 'yes'. Calculations 
    cout << "Do you live in Ohio (yes/no)? ";
    cin >> resident;

    if (resident == "yes")
    {
        tax = stotal * taxperc;
    }

    total = stotal + tax;

    // 7: End results after calculations. Providing output of input information
    cout << fixed << setprecision(2);

    cout << "Hard Monitors Invoice" << endl;
    cout << "-----------------------------" << endl;
    cout << "  Monitor Brand: " << brand << endl;
    cout << "       Quantity: " << quant << endl;
    cout << "          Price: $" << price << endl;
    cout << "  Ohio Resident: " << resident << endl;
    cout << "    Total Price: $" << tprice << endl;
    cout << "-----------------------------" << endl;
    cout << "       Discount: $" << disc << endl;
    cout << "       Subtotal: $" << stotal << endl;
    cout << "          Taxes: $" << tax << endl;
    cout << "=============================" << endl;
    cout << "          Total: $" << total << endl;
    cout << "=============================" << endl;
}