#pragma once

struct Node {
  int value;
  Node* next;
  Node ();
  Node (int v);
  ~Node ();
};

struct List {
  Node* head;
  List ();
  List (Node* n);
  ~List ();
  List (const List& other);
  List (List&& other) noexcept;
  List& operator= (const List& other);
  List& operator= (List&& other) noexcept;
  void add (int value);
  void print (void) const;
};
