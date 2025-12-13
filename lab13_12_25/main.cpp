#include <iostream>
struct Stud {
  const char * fst;
  const char * scnd;
  int year;
  int dep;
};
struct Subj {
  const char* name;
  size_t people, classes;
  const Stud * const * studs;
  const size_t * visited;
};
const Stud** stud_union(size_t& r, const Subj& s1, size_t k1, const Subj& s2, size_t k2) {
  const Stud ** uni = new const Stud*[k1+k2];
  return nullptr;
}
const Stud** stud_union(size_t& r, const Subj& s1, const Subj& s2) {
  return stud_union(r, s1.studs, s1.people, s2.studs, s2.people); 
}

