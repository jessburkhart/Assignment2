#include "linked.h"
#include "stack.h"

using namespace std;

int main() {
   Single_Linked_List<int> list;

   //Asks user for numbers to add to the list
   int num;
   cout << "What numbers would you like to add to the list?\n";
   for (int i = 0; i < 4; i++) {
       cin >> num;
       list.push_back(num);
       
   }

   //Asks user for number to add to the front
   int front;
   cout << "What number would you like to add to the front?\n";
   cin >> front;
   list.push_front(front);
   cout << "Front of the list: " << list.front() << std::endl;

   //Removes the first and last numbers and returns the new first and last numbers
   cout << "Let's remove the first and last numbers in the list\n";
   list.pop_front();
   list.pop_back();
   cout << "Now the first and last numbers are: " << list.front() << " and " << list.back();

   //Asks the user for a number and index to insert into the list
   int insert;
   int index;
   cout << "\nWhat number would you like to insert in the list?\n";
   cin >> insert;
   cout << "What index would you like to insert the number?\n";
   cin >> index;
   list.insert(index, insert);

   //Asks the user what the index of the number they want to remove is
   int remove;
   cout << "What is the index of the number you would like to remove from the list?\n";
   cin >> remove;
   list.remove(remove);

   //Asks the user for what number to find and returns the index
   int find;
   cout << "What number do you want to find in the list?\n";
   cin >> find;
   cout << "Number found at index: " << list.find(find);

   cout << "\n\n";

   Stack stack;

   //Checks if the stack is empty
   if (stack.isEmpty() == true) {
       cout << "\nThe stack is empty\n";
   }
   else {
       cout << "The stack is not empty\n";
   }

   //Asks the user for numbers to add to the stack
   int addnum;
   cout << "What numbers would you like to add to the stack?\n";
   for (int i = 0; i < 4; i++) {
       cin >> addnum;
       stack.push(addnum);
   }

   //Checks if the stack is empty after adding numbers to the stack
   if (stack.isEmpty() == true) {
       cout << "\nThe stack is empty\n";
   }
   else {
       cout << "The stack is not empty\n";
   }

   //Tells user what the top of the stack is
   cout << "Top of the stack: " << stack.top();

   //Removes the top of the stack and tells the user the new top of the stack
   stack.pop();
   cout << "\nAfter removing the top of the stack, the new top of the stack: " << stack.top();

   //Tells the user the average of the numbers in the stack
   cout << "\nThe average of the numbers in the stack: " << stack.average();
   cout << "\n\n";
}