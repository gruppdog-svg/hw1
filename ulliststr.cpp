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

// WRITE YOUR CODE HERE

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

void ULListStr::push_back(const std::string& val){
  if(tail_ == NULL){
    head_ = tail_ = new Item();
  }
  else if(tail_->last == ARRSIZE){
    Item* n = new Item();
    n->prev = tail_;
    tail_->next = n;
    tail_ = n;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if(head_ == NULL){
    head_ = tail_ = new Item();
    head_->first = head_->last = ARRSIZE;
  } else if(head_->first == 0){
    Item* n = new Item();
    n->first = n->last = ARRSIZE;
    n->next = head_;
    head_->prev = n;
    head_ = n;
  }
  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_back(){
  tail_->last--;
  size_--;
  if(tail_->first == tail_->last){
    Item* doomed = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL){
      tail_->next = NULL;
    } else{
      head_ = NULL;
    }
    delete doomed;
  }
}

void ULListStr::pop_front(){
  head_->first++;
  size_--;
  if(head_->last == head_->first){
    Item* doomed = head_;
    head_ = head_->next;
    if(head_ != NULL){
      head_->prev = NULL;
    }else{
      tail_ = NULL;
    }
    delete doomed;
  }
}

std::string* ULListStr::getValAtLoc(size_t loc)const{
  Item* cur = head_;
  size_t seen = 0;
  while(cur != NULL){
    size_t count = cur->last - cur->first;
    if(loc < seen + count){
      return &cur->val[cur->first + (loc - seen)];
    }
    seen += count;
    cur = cur->next;
  }
  return NULL;
}

std::string const & ULListStr::front()const{
  return head_->val[head_->first];
}

std::string const & ULListStr::back()const{
  return tail_->val[tail_->last-1];
}