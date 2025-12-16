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
void fopy(const Stud * const * src, const Stud** dst, size_t k) {
  for (size_t i = 0; i < k; ++i) {
    dst[i] = src[i];
  }
}
const Stud** cut(const Stud* const* src, size_t k) {
  const Stud** r = new const Stud*[k];
  fopy(src, r, k);
  return r;
}
bool contains(const Stud* const* s, size_t k, const Stud* stud) {
  for (size_t i = 0; i < k; ++i) {
    if (s[i] == stud) {
      return true;
    }
  }
  return false;
}
const Stud** stud_union(size_t& r, const Subj& s1, size_t k1, const Subj& s2, size_t k2) {
  const Stud ** uni = new const Stud*[k1+k2];
  size_t count = 0;
  fopy(s1, uni, k1);
  count += k1;
  for (size_t i = 0; i < k2; ++i) {
    if (!contains(uni, count, s2[i])) {
      uni[count++] = s2[i];
    }
  //skpirovat iz perovogo, proverit ih nalichie vo vtorom. Esli net - dobavit.
  try {
    const Stud ** tmp = cut(uni, count);
    delete[] uni;
    uni = tmp;
    //dobavit, videlaem novi, delete stari.
  } catch (...) {
    delete[] uni;
    throw;
  }
  r = count;
  return nullptr;
}
const Stud** stud_union(size_t& r, const Subj& s1, const Subj& s2) {
  return stud_union(r, s1.studs, s1.people, s2.studs, s2.people); 
}
const Stud** stud_union(size_t& r, const Subj* ss, size_t k) {
  if (!k) {
    r = 0;
    return nullptr;
  } else if (k == 1) {
    const Stud** uni = new const Stud*[ss[0].people];
    fopy(ss[0].studs, uni, ss[0].people);
    r = ss[0].people;
    return uni;
  }
  size_t count = 0;
  const Stud** uni = stud_union(count, ss[0], ss[1]);
  for (size_t i = 2; i < k; ++i) {
    try {
      size_t tmp_count = 0;
      const Stud** tmp_uni = stud_union(tmp_count, uni, count, ss[i].studs, ss[i].people);
      delete[] uni;
      uni = tmp_uni;
      count = tmp_count;
    } catch (...) {
      delete[] uni;
      throw;
    }
  }
  r = count;
  return uni;
}
//Найти студентов, удовлетворяющих условию (хз какому, любому)
const Stud** filter(size_t& r, const Stud* const* studs, size_t k,
  bool (*condition)(const Stud*)) {
  const Stud** f = new const Stud*[k];
  size_t count = 0;
  for (size_t i = 0; i < k; ++i) {
    if (condition(studs[i])) {
      f[count++] = studs[i];
    }
  }
  try {
    const Stud** tmp = cut(f, count);
    delete[] f;
    f = tmp;
  } catch (...) {
    delete [] f;
    throw;
  }
  r = count;
  return f;
}
bool is_Magister(const Stud* s) {
  return s->year > 4;
}
bool is_Bachalor(const Stud* s) {
  return s->year && (s->year < 5);
}
template < size_t Y >
bool is_stud_year(const Stud* s) {
  return s->year == Y;
}
bool (*year_filter(int y))(const Stud* s) {
  bool (*year_filter(int y))(const Stud* s) { 
    switch (y) {
      case 1: return is_stud_year< 1 >;
      default: throw std::logic_error("bad year");
    }
  }
}
const Stud** stut_union_year(size_t& r, const Subj* ss, size_t k, int y) {
  size_t count = 0
  const Stud** bach = stud_union(count, ss, k);
  try {
    size_t tmp_count = 0;
    const Stud** tmp = filter(tmp_count, bach, count, year_filter(y));
    delete[] bach;
    bach = tmp;
  } catch (...) {
    delete[] bach;
    throw;
  }
  r = count;
  return bach;
}
/*Найти дисциплины, на которых у каждого слушателя-магистра посещаемость(в пределах дисциплины) выше заданной. 
Дана функция отношения нормальной.
*/
 
