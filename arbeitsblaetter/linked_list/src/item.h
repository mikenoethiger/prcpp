
template<typename T>
class Item {
 public:
  bool operator==(const Item<T>& other) const {
    return data_ == other.data_ && next_ == other.next_ && prev_ == other.prev_;
  }

  T data_;
  Item<T>* next_;
  Item<T>* prev_;
};
