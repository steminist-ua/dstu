#pragma once

#include <iostream>

using namespace std;

class Book
{
private:
  int id;
  float price;
  string author;
  string genre;

public:
  Book();
  Book(int id, float price, string author, string genre);

  void SetId(int id);
  void SetPrice(float price);
  void SetAuthor(string author);
  void SetGenre(string genre);

  int GetId();
  float GetPrice();
  string GetAuthor();
  string GetGenre();

  float CalcDiscount(float discount);
  void SetDiscount(float discount);

  void Print();
};
