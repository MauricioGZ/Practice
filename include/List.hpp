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
  void add (int value);
  void add (Node* node);
  void print (void) const;
};
