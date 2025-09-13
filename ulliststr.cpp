#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val)
{
  // If list is empty, create first node
  if (tail_ == NULL) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    head_ = tail_ = newItem;
    size_++;
    return;
  }
  
  // If tail has room, add to tail
  if (tail_->last < ARRSIZE) {
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  } else {
    // Tail is full, create new node
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = newItem;
    size_++;
  }
}

void ULListStr::pop_back()
{
  if (size_ == 0) return;
  
  // Remove last element from tail
  tail_->last--;
  size_--;
  
  // If tail becomes empty, remove it
  if (tail_->first == tail_->last) {
    Item* oldTail = tail_;
    tail_ = tail_->prev;
    
    if (tail_ != NULL) {
      tail_->next = NULL;
    } else {
      // List becomes empty
      head_ = NULL;
    }
    
    delete oldTail;
  }
}

void ULListStr::push_front(const std::string& val)
{
  // If list is empty, create first node
  if (head_ == NULL) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    head_ = tail_ = newItem;
    size_++;
    return;
  }
  
  // If head has room before first element, add there
  if (head_->first > 0) {
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
  } else {
    // Head has no room, create new node
    Item* newItem = new Item();
    newItem->val[ARRSIZE - 1] = val;
    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    size_++;
  }
}

void ULListStr::pop_front()
{
  if (size_ == 0) return;
  
  // Remove first element from head
  head_->first++;
  size_--;
  
  // If head becomes empty, remove it
  if (head_->first == head_->last) {
    Item* oldHead = head_;
    head_ = head_->next;
    
    if (head_ != NULL) {
      head_->prev = NULL;
    } else {
      // List becomes empty
      tail_ = NULL;
    }
    
    delete oldHead;
  }
}

std::string const & ULListStr::back() const
{
  if (size_ == 0) {
    throw std::invalid_argument("List is empty");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  if (size_ == 0) {
    throw std::invalid_argument("List is empty");
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_) {
    return NULL;
  }
  
  Item* current = head_;
  size_t currentPos = 0;
  
  while (current != NULL) {
    size_t itemSize = current->last - current->first;
    
    if (currentPos + itemSize > loc) {
      // Found the item containing our location
      size_t indexInItem = loc - currentPos + current->first;
      return &(current->val[indexInItem]);
    }
    
    currentPos += itemSize;
    current = current->next;
  }
  
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}