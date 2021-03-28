#include <iostream>
#include <string>
using namespace std;
int main () {
 cout << "Please, enter a number or a word: ";
 /*
 Here the program gets the first character in the input
 and is stored in char c.
 */
 char c = cin.get();
 /*
 After that this if statement checks if the character is a number
 */
 if ( (c >= '0') && (c <= '9') )
 {
 int n;
 /*
 If it is a number then the character gets put back into the stream buffer
 This means that next cin will take the input starting from the character, and not after that
 */
 cin.putback (c);
 /*
 This cin then takes the number, starting from "c".
 The rest of characters in the buffer are discarded
 That means all the characters that are not numbers
 */
 cin >> n;
 /*
 And now it prints the number it took.
 */
 cout << "You entered a number: " << n << '\n';
 }
 else
 {
 /*
 This section runs if the "c" character was not a number
 */
 string str;
 /*
 A string variable is created and the "c" character extracted is put back into the buffer
 */
 cin.putback (c);
 /*
 Now the program gets the line and stores it in the string variable
 Starting from the "c" character and not after that
 */
 getline(cin,str);
 /*
 Now the string is printed
 */
 cout << "You entered a word: " << str << '\n';
 }
 /*
 Note: Some of the steps could have been ommited if the function "peek" was used instead
 */
 return 0;
}
