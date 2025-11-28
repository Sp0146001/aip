#include <iostream>

struct Stud {
  const car* fst;
  const char* snd;
  int year;
  int dep;
};
struct Subj {
  const char* name;
  size_t people, classes;
  const Stud * const * studs;
  const size_t * visited;
};

size_t count_year(const Stud * const * studs, size_t k, int y) {
  size_t r = 0;
  for (size_t i = 0; i < k; ++i) {
    r += (studs[i]->year == y) ? 1 : 0;//Стрелочкой обращаться к элепменту
  }
  return r;
}
//Считаем кол-во студентов в соответствующей кафедре
const Stud ** stud_dep(const Stud * const * studs, size_t k, int dep, size_t& found) {
  try {
    const Stud ** r = new const Stud*[20];
  } catch (...) {
    delete[] arr;
    throw;
  }
  size_t size = 0, cap = 20;
  for (size_t i = 0; i < k; ++i) {
    if (studs[i]->dep != dep) {
      continue;
    }
    if (size == cap) {
      try {
        const Stud ** tmp = new const Stud*[2*cap];
        for (size_t j = 0; j < size; ++j) {
          tmp[j] = r[j];
        }
        delete[] r;
        r = tmp;
        cap*=2;
      } catch (const std::bad_alloc& e) {
        delete[] r;
        throw;
      }
    }
    r[size++] = studs[i];
  }
  found = size;
  return r;
}

size_t max_visits ( const Subj * sub, int y) {
  size_t result = 0;
  for (size_t i = 0; i < Sub.people; ++i) {
    result += (Studs[i]->year == y) ? 1 : 0;
  }
  return result*sub.classes;
}
size_t real_visits ( const Subj * sub, int y) {
  size_t v = 0;
  for (size_t i = 0; i < sub.people; ++i) {
    v+= (sub.studs[i]->year == y) ? sub.visits[i] : 0;
  }
  return v;
}
bool is_better (const Subj & sub, int y1, int y2) {
  size_t max_y1 = max_visits(sub, y1);
  size_t max_y2 = max_visits(sub, y2);
  size_t re_y1 = real_visits(sub, y1);
  size_t re_y2 = real_visits(sub, y2);
  return re_y1*max_y2 > re_y2*max_y1;
}
const Stud ** dobsovs(const Subj & sub, size_t& dobs, size_t vis) {
  try {
    const Stud ** r = new const Stud*[20];
  } catch (...) {
    delete[] r;
    throw;
  }
  size_t size = 0, cap = 20;
  for (size_t i = 0; i < k; ++i) {
    if (sub[i]->visited >= vis) {
      continue;
    }
    if (size == cap) {
      try {
        const Stud ** tmp = new const Stud*[2*cap];
        for (size_t j = 0; j < size; ++j) {
          tmp[j] = r[j];
        }
        delete[] r;
        r = tmp;
        cap*=2;
      } catch (const std::bad_alloc& e) {
        delete[] r;
        throw;
      }
    }
    r[size++] = studs[i];
    dobs+=1;
  }
  found = size;
  return r;
}

int main() {

}
