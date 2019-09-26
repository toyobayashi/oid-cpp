#include <iostream>
#ifdef _WIN32
#include <cstdlib>
#endif
#include <oid/oid.hpp>
#include "mocha.h"

static int should_correctly_handle_objectId_timestamps() {
  ObjectId a = ObjectId::createFromTime(1);
  expect(a.getTimestamp() == 1);
  return 0;
}

static int should_correctly_interpret_timestamps_beyond_2038() {
  ObjectId id(ObjectId::generate(2208988800));
  expect(id.getTimestamp() == 2208988800);
  return 0;
}

static int should_correctly_create_ObjectId_from_uppercase_hexstring() {
  std::string a = "AAAAAAAAAAAAAAAAAAAAAAAA";
  ObjectId b(a);
  expect(b.equals(a) == true);

  a = "aaaaaaaaaaaaaaaaaaaaaaaa";
  b = ObjectId(a);
  expect(b.equals(a) == true);
  expect(b.toHexString() == a);
  return 0;
}

int main () {
#ifdef _WIN32
  system("chcp 65001");
#endif
  int res = 0;
  res = describe("ObjectId",
    should_correctly_handle_objectId_timestamps,
    should_correctly_interpret_timestamps_beyond_2038,
    should_correctly_create_ObjectId_from_uppercase_hexstring);
  return res;
}
