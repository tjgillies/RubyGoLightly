#include "../test.h"
#include "tinyrb.h"

TEST_INIT;

void test_str()
{
  SETUP_VM;
  OBJ        o = tr_string_new(vm, "ohaie");
  tr_string *s = TR_CSTRING(o);
  
  assert_equal(TR_STRING, s->type);
  assert_equal(5, s->len);
  assert_str_equal("ohaie", TR_STR(o));
}

void test_concat()
{
  SETUP_VM;
  OBJ str1 = tr_string_new(vm, "oh");
  OBJ str2 = tr_string_new(vm, "aie");
  OBJ argv[] = { str2 };
  
  OBJ res = tr_send(vm, str1, tr_intern(vm, "+"), 1, argv);
  
  assert_str_equal("ohaie", TR_STR(res));
}

void test_slice()
{
  SETUP_VM;
  OBJ str = tr_string_new(vm, "ohaie");
  OBJ argv[] = { tr_fixnum_new(vm, 2), tr_fixnum_new(vm, 3) };
  OBJ ret;
  
  ret = tr_send(vm, str, tr_intern(vm, "[]"), 2, argv);
  assert_str_equal("aie", TR_STR(ret));
  
  argv[0] = tr_fixnum_new(vm, 10);
  ret = tr_send(vm, str, tr_intern(vm, "[]"), 2, argv);
  assert_equal(TR_NIL, ret);

  argv[0] = tr_fixnum_new(vm, 2);
  argv[1] = tr_fixnum_new(vm, 10);
  ret = tr_send(vm, str, tr_intern(vm, "[]"), 2, argv);
  assert_str_equal("aie", TR_STR(ret));
}

TEST_START;
  test_str();
  test_concat();
  test_slice();
TEST_END;