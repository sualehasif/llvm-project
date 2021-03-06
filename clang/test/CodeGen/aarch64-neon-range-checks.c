// RUN: %clang_cc1 -triple aarch64-linux-gnu -target-feature +neon -target-feature +crypto -verify %s

#include <arm_neon.h>

void test_range_check_vsm3tt1a(uint32x4_t a, uint32x4_t b, uint32x4_t c) {
  vsm3tt1aq_u32(a, b, c, 4); // expected-error {{argument value 4 is outside the valid range [0, 3]}}
  vsm3tt1aq_u32(a, b, c, -1); // expected-error {{argument value -1 is outside the valid range [0, 3]}}
  vsm3tt1aq_u32(a, b, c, 3);
  vsm3tt1aq_u32(a, b, c, 0);
}

void test_range_check_vsm3tt1b(uint32x4_t a, uint32x4_t b, uint32x4_t c) {
  vsm3tt1bq_u32(a, b, c, 4);// expected-error {{argument value 4 is outside the valid range [0, 3]}}
  vsm3tt1bq_u32(a, b, c, -1); // expected-error {{argument value -1 is outside the valid range [0, 3]}}
  vsm3tt1bq_u32(a, b, c, 3);
  vsm3tt1bq_u32(a, b, c, 0);
}

void test_range_check_vsm3tt2a(uint32x4_t a, uint32x4_t b, uint32x4_t c) {
  vsm3tt2aq_u32(a, b, c, 4);// expected-error {{argument value 4 is outside the valid range [0, 3]}}
  vsm3tt2aq_u32(a, b, c, -1); // expected-error {{argument value -1 is outside the valid range [0, 3]}}
  vsm3tt2aq_u32(a, b, c, 3);
  vsm3tt2aq_u32(a, b, c, 0);
}

void test_range_check_vsm3tt2b(uint32x4_t a, uint32x4_t b, uint32x4_t c) {
  vsm3tt2bq_u32(a, b, c, 4);// expected-error {{argument value 4 is outside the valid range [0, 3]}}
  vsm3tt2bq_u32(a, b, c, -1); // expected-error {{argument value -1 is outside the valid range [0, 3]}}
  vsm3tt2bq_u32(a, b, c, 3);
  vsm3tt2bq_u32(a, b, c, 0);
}

