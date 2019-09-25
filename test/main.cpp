#include <iostream>
#include <oid/oid.hpp>

static void beyond2038() {
  ObjectId id(ObjectId::generate(2208988800));
  std::cout << id.getTimestamp() << std::endl;
}

int main () {
  beyond2038();
  return 0;
}
