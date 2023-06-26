#include <fstream>
#include <vector>

#include "bdd.hpp"

// The import_node function takes a Board object b as input 
// and creates a new Node with a unique ID and the given board.
Node *BDD::import_node(const Board &b) {
  Node *node = new Node(fresh_id, b);
  fresh_id++;
  nodes.push_back(node);
  return node;
}

void BDD::connect(Node *parent, Node *children, bool if_true) {
  // If if_true is true
  if (if_true) {
  // the children node is set as the true child of the parent node 
  // using the "if_true" function of the Node class.
     parent->if_true = children;
  } else {  // if false
    //  the children node is set as the false child of the parent node
    parent->if_false = children;
  }
}

// The connect_true function connects the parent node 
// to either the true_node or false_node
void BDD::connect_true(Node *parent, bool if_true) {
  // if true, the true_node is selected as the child node.
  // if false, , the false_node is selected as the child node.
  connect(parent, true_node, if_true);
}

// The connect_false function is similar to the connect_true function
// but it connects the parent node to the opposite node.
void BDD::connect_false(Node *parent, bool if_true) {
  connect(parent, false_node, if_true);;
}

std::ostream &operator<<(std::ostream &stream, const BDD &bdd) {
  stream << "digraph BDD {\n";

  // Output the nodes
  for (const Node *node : bdd.nodes) {
    if (node == bdd.true_node || node == bdd.false_node) {
      continue;  // Skip the special nodes
    }
    stream << node;
  }

  stream << "}\n";
  return stream;
}

void BDD::write_dot_file(std::string file_path) const {
  std::ofstream myfile;
  myfile.open(file_path);
  if (myfile.is_open()) {
    myfile << *this;
    myfile.close();
  }
}

int BDD::count_true_path() const {
  /*TODO: Übungsblatt 9, Aufgabe 7*/
  assert(false);
  return 0;
}
