#include "node.hpp"

// Overloaded stream insertion operator for Node class
std::ostream &operator<<(std::ostream &stream, const Node &node) {
  // Write the node ID and configuration
  stream << node.id << "[label=\"" << node.configuration << "\"]\n";

  // If the true branch exists then connect the current node to the true branch
  if (node.if_true != nullptr) {
    stream << node.id << " -> " << node.if_true->id << ";\n";
  }

  // If the false branch exists, connect the current node to the false branch with dotted style
  if (node.if_false != nullptr) {
    stream << node.id << " -> " << node.if_false->id << " [style=dotted];\n";
  }

  return stream;
}