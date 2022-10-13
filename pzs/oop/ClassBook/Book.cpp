#include "Book.h"

using namespace std;

Book::Book()
{
  this->id = 0;
  this->price = 0;
  this->author = "";
  this->genre = "";
}

Book::Book(int id, float price, string author, string genre)
{
  this->id = id;
  this->price = price;
  this->author = author;
  this->genre = genre;
}

void Book::SetId(int id)
{
  this->id = id;
}

void Book::SetPrice(float price)
{
  this->price = price;
}

void Book::SetAuthor(string author)
{
  this->author = author;
}

void Book::SetGenre(string genre)
{
  this->genre = genre;
}

int Book::GetId()
{
  return this->id;
}

float Book::GetPrice()
{
  return this->price;
}

string Book::GetAuthor()
{
  return this->author;
}

string Book::GetGenre()
{
  return this->genre;
}

float Book::CalcDiscount(float discount)
{
  return this->price - (this->price * discount);
}

void Book::SetDiscount(float discount)
{
  this->price = this->CalcDiscount(discount);
}

void Book::Print()
{
  cout << "Book #" << this->id << endl;
  cout << "  Author: " << this->author << endl;
  cout << "  Genre: " << this->genre << endl;
  cout << "  Price: " << this->price << endl;
}
