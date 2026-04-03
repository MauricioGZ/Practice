#include "List.hpp"
#include <iostream>
#include <algorithm>

Node::Node () : value (0), next (nullptr) {}

Node::Node (int v) : value (v), next (nullptr) {}

Node::~Node () {}

List::List () : head (nullptr) {}

List::List (Node* n) : head (n) {}

List::~List () {
  Node* current_node = head;
  while (current_node != nullptr) {
    Node* next_node = current_node->next;
    delete current_node;
    current_node = next_node;
  }
}

List::List (const List& other) : head (nullptr) {
  if (other.head == nullptr) return;

  head = new Node (other.head->value);

  Node* current_node_this = head;
  Node* next_node_other = other.head->next;

  while (next_node_other != nullptr) {
    current_node_this->next = new Node (next_node_other->value);
    next_node_other = next_node_other->next;
    current_node_this = current_node_this->next;
  }
}

List::List (List&& other) noexcept : head (other.head) {
  other.head = nullptr;
}

List& List::operator= (const List& other) {
  if (this != &other) {
    List temp_list (other);
    std::swap (head, temp_list.head);
  }
  return *this;
}

List& List::operator= (List&& other) noexcept {
  if (this == &other) return;

  Node* current_node = head;

  while (current_node != nullptr) {
    Node* next_node = current_node->next;
    delete current_node;
    current_node = next_node;
  }
  head = other.head;
  other.head = nullptr;
  return *this;
}

void List::add (int value) {
  Node* new_node = new Node (value);
  if (head == nullptr) {
    head = new_node;
    return;
  }

  Node* current_node = head;
  while (current_node->next != nullptr) {
    current_node = current_node->next;
  }

  current_node->next = new_node;
}

void List::print (void) const {
  if (head == nullptr) return;

  Node* current_node = head;
  while (current_node != nullptr) {
    std::cout << current_node->value << "->";
    current_node = current_node->next;
  }

  std::cout << "nullptr\n";
}