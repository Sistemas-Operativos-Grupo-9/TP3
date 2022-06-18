#include <stdlib.h>

void V_E() {
  int var;
  if (var == 0x12345678) {
    exit(1);
  }
}
void A_S() { V_E(); }
void L__() { A_S(); }
void G_G() { L__(); }
void R_E() { G_G(); }
void I_N() { R_E(); }
void N_I() { I_N(); }
void D_A() { N_I(); }
void __L() { D_A(); }
