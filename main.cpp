/*
El Reto: "Suma de dos números en una lista enlazada"
Contexto:
Se te dan dos listas enlazadas no vacías que representan dos números enteros no negativos. Los dígitos están almacenados en orden inverso, y cada uno de sus nodos contiene un solo dígito. Suma los dos números y devuelve la suma como una lista enlazada.
Ejemplo:
Entrada: (2 -> 4 -> 3) + (5 -> 6 -> 4) (Representan 342 + 465)
Salida: 7 -> 0 -> 8 (Representa 807)
Lo que el entrevistador evaluará:
Punteros: ¿Sabes manipular next y crear nuevos nodos sin fugas de memoria?
Lógica de acarreo (carry): ¿Cómo manejas cuando la suma de dos dígitos es >= 10?
Casos de borde: ¿Qué pasa si las listas tienen tamaños distintos o si la suma final genera un nuevo dígito (ej. 50 + 50 = 100)?
*/

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
    if ((l1 == nullptr) || (l2 == nullptr)) return nullptr;
    int sum = l1->val + l2->val;
    ListNode* new_list_node = new ListNode (sum % 10);
    ListNode* head = new_list_node;
    ListNode* current1 = l1->next;
    ListNode* current2 = l2->next;

    sum /= 10;

    while ((current1 != nullptr) || (current2 != nullptr)) {
      if (current1 != nullptr) {
        sum += current1->val;
        current1 = current1->next;
      }
      if (current2 != nullptr) {
        sum += current2->val;
        current2 = current2->next;
      }
      new_list_node->next = new ListNode (sum % 10);
      new_list_node = new_list_node->next;
      sum /= 10;
    }

    if (sum > 0) {
      new_list_node->next = new ListNode (sum);
    }
    return head;
  }

  void print (ListNode* l) const {
    ListNode* current_node = l;
    while (current_node != nullptr) {
      std::cout << current_node->val << "->";
      current_node = current_node->next;
    }
    std::cout << "nullptr\n";
  }
};

int main () {
  Solution solution;
  ListNode* l1 = new ListNode (1);
  ListNode* l2 = new ListNode (1);

  l1->next = new ListNode (2);
  l1->next->next = new ListNode (5);

  l2->next = new ListNode (2);
  l2->next->next = new ListNode (5);
  l2->next->next->next = new ListNode (9);
  l2->next->next->next->next = new ListNode (9);
  l2->next->next->next->next->next = new ListNode (9);

  ListNode* sum = solution.addTwoNumbers (l1, l2);

  solution.print (l1);
  solution.print (l2);
  solution.print (sum);

  return 0;
}