/*
  Dynamic allocation of the TM2x·Tape header.  For static allocation use the AllocStatic() macro.
  This does not allocate data for the array itself.
*/

#ifdef TM2x·TEST
  extern address_t TM2x·test_after_allocation_n;
#endif

extern address_t TM2x·alloc_array_count;

TM2x·F_PREFIX continuation TM2x·resize_elements:{
  TM2x·Tape *tape                = TM2x·resize_elements·args.tape;
  address_t after_element_n = TM2x·resize_elements·args.after_element_n;
  address_t element_byte_n  = TM2x·resize_elements·args.element_byte_n;
  continuation nominal      = TM2x·resize_elements·args.nominal;
  continuation alloc_fail   = TM2x·resize_elements·args.alloc_fail;
  continuation index_gt_n    = TM2x·resize_elements·args.index_gt_n;

  address_t after_byte_n;
  #include "inclusive·mul_ext·args.h"
  inclusive·mul_ext·args.an = after_element_n;
  inclusive·mul_ext·args.bn = element_byte_n;
  inclusive·mul_ext·args.cn = &after_byte_n;
  inclusive·mul_ext·args.nominal = &&mul_ext·nominal;
  inclusive·mul_ext·args.gt_address_n = index_gt_n;
  continue_from inclusive·mul_ext;

  mul_ext·nominal:{
   resize·args.tape = tape;
   resize·args.after_byte_n = after_byte_n;
   resize·args.nominal = nominal;
   resize·args.alloc_fail = alloc_fail;
   contine_from TM2x·resize;
   cend;
  }

  cend;
}
