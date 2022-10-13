#include <iostream>
#include "Book.h"

using namespace std;

int main()
{
  float discount;
  int set_discount = 0;

  Book book1;
  book1.SetId(1);
  book1.SetAuthor("Dmitry Tavern");
  book1.SetGenre("History");
  book1.SetPrice(100);
  book1.Print();

  cout << "Enter discount for book: ";
  cin >> discount;

  cout << "New price: " << book1.CalcDiscount(discount) << endl;

  cout << "Do you want to set discount? (1/0): ";
  cin >> set_discount;

  if (set_discount)
  {
    book1.SetDiscount(discount);
    cout << "Discount setted!" << endl;
  }

  book1.Print();
}
