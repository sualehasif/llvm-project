# RUN: llvm-mc -triple=ve --show-encoding < %s \
# RUN:     | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: llvm-mc -triple=ve -filetype=obj < %s | llvm-objdump -d - \
# RUN:     | FileCheck %s --check-prefixes=CHECK-INST

# CHECK-INST: vadds.l %v11, %s20, %v22
# CHECK-ENCODING: encoding: [0x00,0x16,0x00,0x0b,0x00,0x94,0x20,0x8b]
vadds.l %v11, %s20, %v22

# CHECK-INST: vadds.l %vix, %vix, %vix
# CHECK-ENCODING: encoding: [0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x8b]
vadds.l %vix, %vix, %vix

# CHECK-INST: vadds.l %vix, 22, %v22
# CHECK-ENCODING: encoding: [0x00,0x16,0x00,0xff,0x00,0x16,0x20,0x8b]
vadds.l %vix, 22, %v22

# CHECK-INST: vadds.l %v11, 63, %v22, %vm11
# CHECK-ENCODING: encoding: [0x00,0x16,0x00,0x0b,0x00,0x3f,0x2b,0x8b]
vadds.l %v11, 63, %v22, %vm11

# CHECK-INST: vadds.l %v11, %v23, %v22, %vm11
# CHECK-ENCODING: encoding: [0x00,0x16,0x17,0x0b,0x00,0x00,0x0b,0x8b]
vadds.l %v11, %v23, %v22, %vm11
