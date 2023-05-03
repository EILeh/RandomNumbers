/* Random Numbers
 *
 * Description
 *
 * Program draws random numbers by asking the user to give a lower bound and a
 * upper bound. Program checks that the upper bound is bigger than the lower
 * bound otherwise prints an error and program ends to a return value
 * EXIT_FAILURE.
 *
 * After givin correct upper and lower bounds, program asks a seed value from
 * user and generates a random number with the given inputs. Program then asks
 * if the user wants to close the program. Program closes if q is given and
 * continues if any other key is given.
 *
 *
 * Writer of the program
 *
 * Name: EILeh
 *
 */

#include <iostream>
#include <random>
#include <string>

using namespace std;

// Takes the lower and upper bounds that user has given and asks a seed value
// from user. Generates a random number from the user's inputs and then asks
// if the user wants to continue or close the program.
void produce_random_numbers(unsigned int& lower, unsigned int& upper)
{
    unsigned int seed_value;
    cout << "Enter a seed value: ";
    cin >> seed_value;
    cout << endl;

    string quit_command;
    string quit = "q";
    string con = "";

    int round = 1;

    default_random_engine gen(seed_value);

    // While round is 1 or quit_command any other key than q, program continues.
    while (( round == 1 ) or ( quit_command == con ))
    {
        uniform_int_distribution<int> distr(lower, upper);

        cout << "Your drawn random number is " << distr(gen) << endl;
        cout << "Press q to quit or any other key to continue: ";

        cin >> quit_command;
        cout << endl;

        if ( quit_command == quit )
        {
            return;
        }

    } ++round;

}

int main()
{
    unsigned int lower_bound, upper_bound;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;

    if(lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound"
             << endl;
        return EXIT_FAILURE;
    }

    produce_random_numbers(lower_bound, upper_bound);

    return EXIT_SUCCESS;
}
