#include "List.hpp"
#include <iostream>

Node::Node () : value (0), next (nullptr) {}

Node::Node (int v) : value (v), next (nullptr) {}

Node::~Node () {}

List::List () : head (nullptr) {}

List::List (Node* n) : head (n) {}

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

void List::add (Node* node) {
  if (node == nullptr) return;
  if (head == nullptr) {
    head = node;
    return;
  }

  Node* current_node = head;
  while (current_node->next != nullptr) {
    current_node = current_node->next;
  }

  current_node->next = node;
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