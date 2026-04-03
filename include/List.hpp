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
  //Constructor
  List ();
  List (Node* n);
  //1. Destructor
  ~List ();
  //2. Copy constructor
  List (const List& other);
  //3. Move constructor
  List (List&& other) noexcept;
  //4. Copy assignment
  List& operator= (const List& other);
  //5. Move assignment
  List& operator= (List&& other) noexcept;
  void add (int value);
  void print (void) const;
};
