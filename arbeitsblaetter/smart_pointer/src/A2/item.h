#pragma once

class Item {
 public:
  explicit Item(int number);
  ~Item();

  int GetNumber() const;
  void SetNumber(int number);

 private:
  int number_;
};
