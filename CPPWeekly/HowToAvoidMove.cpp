//Please see the reference : https://www.youtube.com/watch?v=6SaUwqw4ueE
#include <cstdio>
#include <array>

struct Lifetime {
  Lifetime() { std::puts("Lifetime() // default ctor"); }
  ~Lifetime() { std::puts("~Lifetime() // destructor"); }
  Lifetime(const Lifetime &) {
    std::puts("Lifetime(const Lifetime &) // copy ctor");
  }
  Lifetime(Lifetime &&) { std::puts("Lifetime(Lifetime &&) // move ctor"); }

  Lifetime &operator=(Lifetime &&) {
    std::puts("operator=(Lifetime &&) // move assign");
    return *this;
  }
  Lifetime &operator=(const Lifetime &) {
    std::puts("operator=(const Lifetime &) // copy assign");
    return *this;
  }

  int member_data;
};

int main()
{
  auto make_lifetime = [](const int value) {
    Lifetime l;
    l.member_data = value;
    return l;
  };

  // rely on simple composable functions instead of std::move
  std::array<Lifetime, 2> a{make_lifetime(42), make_lifetime(43)};
}
