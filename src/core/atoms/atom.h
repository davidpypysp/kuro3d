#ifndef SRC_CORE_ATOMS_ATOM_H_
#define SRC_CORE_ATOMS_ATOM_H_

#include <string>

namespace kuro {

class Atom {
 public:
  explicit Atom(const std::string& name);

 protected:
  std::string name_;
};

}  // namespace kuro

#endif  // SRC_CORE_ATOMS_ATOM_H_
