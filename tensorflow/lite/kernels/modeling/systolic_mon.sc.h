// Created by Nicolas Agostini
/* Copyright 2020 The TFLITE-SOC Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_LITE_KERNELS_MODELING_SYSTOLIC_MON_H_
#define TENSORFLOW_LITE_KERNELS_MODELING_SYSTOLIC_MON_H_

#include <systemc/systemc.h>

namespace tflite_soc {

SC_MODULE(SystolicMon) {
  // Signal Declarations =======================================================
  sc_in<bool> clock;

  // Methods and Processes Declarations ========================================
  void Method();
  
  // Constructors ==============================================================

  // This line must be uncommented if Default Constructor is removed
  // SC_HAS_PROCESS(SystolicMon);

  // Custom constructur with parameters
  SystolicMon(sc_module_name name_, bool debug_ = false);

  // Default Constructor
  SC_CTOR(SystolicMon) : debug(false) {
    SC_THREAD(Method);
    sensitive << clock.pos();
  }

  // Private Variables =========================================================
  const bool debug;
};

}  // namespace tflite_soc

#endif  // TENSORFLOW_LITE_KERNELS_MODELING_SYSTOLIC_MON_H_